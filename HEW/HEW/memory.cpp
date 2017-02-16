#include "memory.h"

#define	NULL	(void *)0

int	*my_memory_s_address;	/* 貸出メモリーブロックの開始・終了アドレス */
int	*my_memory_e_address;	/* int型にしてますが、その時々でキャストして使ってください */

int	my_memory_size;			/* メモリーブロックの総サイズ */
int	my_memory_block_cnt;	/* メモリーブロック数 */


#if 0	/* windows環境などの場合 */
int	my_memory[ (MEMORY_ONE_BLOCK_SIZE/4) * MY_MEMORY_BLOCK_CNT ];	/* int を 4Byteとした場合 */

MY_MEM_LIST	my_mem_list[MY_MEMORY_BLOCK_CNT];
#else
MY_MEM_LIST	*my_mem_list;
#endif


MY_MEM_LIST	*inactive_top, *inactive_end;
MY_MEM_LIST	*active_top, *active_end;

int			memory_block_using_cnt;		/* 使用中メモリーブロック数 */


int InitMyMemory(void)	/* 0:成功、負:エラー */
{
	int i;

#if 1	/* 固定アドレスの場合 */
	my_mem_list = (MY_MEM_LIST*)0x94000000;	/* メモリー管理用のリスト配列（これも拡張メモリーにとるようにしました） */

	my_memory_s_address = (int *)(0x94000000 + (MY_MEMORY_BLOCK_CNT*20));		/* wii 開発機用拡張メモリー */
	my_memory_e_address = (int *)0x98000000;

	my_memory_size = (unsigned int)my_memory_e_address - (unsigned int)my_memory_s_address;
	my_memory_block_cnt	= my_memory_size / MEMORY_ONE_BLOCK_SIZE;

	if( my_memory_block_cnt < MY_MEMORY_BLOCK_CNT )	return -1;	/* メモリー不足 */

	my_memory_e_address = (int *)((int)my_memory_s_address * my_memory_block_cnt * MEMORY_ONE_BLOCK_SIZE);	/* サイズに合わせて終端アドレスの修正 */

#else

	my_memory_block_cnt = MY_MEMORY_BLOCK_CNT;

	my_memory_s_address = (int *)my_memory;
	my_memory_e_address = (int *)((int)my_memory_s_address * my_memory_block_cnt * MEMORY_ONE_BLOCK_SIZE);

	my_memory_size = (int)my_memory_e_address - (int)my_memory_s_address;

#endif

	inactive_top	= &my_mem_list[0];						/* 未使用メモリーのリストのトップ */
	inactive_end	= &my_mem_list[MY_MEMORY_BLOCK_CNT-1];	/* 未使用メモリーのリストのエンド */

	active_top		= (MY_MEM_LIST*)NULL;					/* 使用中メモリーのリストトップ */
	active_end		= (MY_MEM_LIST*)NULL;					/* 使用中メモリーのリストエンド */

	for( i=0 ; i<MY_MEMORY_BLOCK_CNT ; i++ ){
		my_mem_list[i].no	= i;							/* リスト番号 */
		my_mem_list[i].addr	= (int *)(((int)my_memory_s_address) + (i * MEMORY_ONE_BLOCK_SIZE));	/* 管理してるメモリーブロックアドレス */
		my_mem_list[i].seq	= (MY_MEM_LIST*)NULL;			/* 連結領域の管理アドレス */

		if( i==0 ){
			my_mem_list[i].prev = (MY_MEM_LIST*)NULL;
		}else{
			my_mem_list[i].prev = &(my_mem_list[i-1]);
		}

		if( i==(MY_MEMORY_BLOCK_CNT-1) ){
			my_mem_list[i].next = (MY_MEM_LIST*)NULL;
		}else{
			my_mem_list[i].next = &(my_mem_list[i+1]);
		}
	}
	return 0;
}


/* メモリー確保関数 */
void *MyMemoryAlloc(int size)	/* 成功:メモリーアドレス、0:エラー */
{
	int	block_num;
	int	seq_no, cnt;
	MY_MEM_LIST	*inactive_work, *loop_work;
	MY_MEM_LIST	*cnt_work = (MY_MEM_LIST*)NULL;		/* 連続領域カウント用のワーク */

	if( size <= 0 )	return NULL;
	block_num = (size/MEMORY_ONE_BLOCK_SIZE) + ((size%MEMORY_ONE_BLOCK_SIZE)?1:0);

	inactive_work = inactive_top;

	while( inactive_work ){
		cnt_work = inactive_work;
		cnt = 0;
		seq_no = cnt_work->no - 1;
		while( cnt_work ){
			cnt++;
			seq_no++;
			if( seq_no != cnt_work->no ){
				inactive_work = cnt_work->prev;	/* 調査済みの連続部分をとばして、検索先を進める */
				break;		/* 連続せず、メモリーサイズが足りなかった */
			}
			if( block_num <= cnt )		break;	/* 欲しいメモリーサイズに合った連続メモリーブロックが見つかった */
			cnt_work = cnt_work->next;
		}
		if( block_num <= cnt )	break;		/* メモリーブロックが見つかった */
		inactive_work = inactive_work->next;
	}
	if( !inactive_work )	return NULL;	/* メモリー確保失敗 */

	/* リストのつなぎ替え */
	loop_work = inactive_work;	/* ここに到達しているなら inactive_work から cnt_work が欲しいメモリー */
	while( loop_work != cnt_work ){
		loop_work->seq = loop_work->next;	/* 連続ブロックのアドレスを入れておく */
		loop_work = loop_work->next;
	}
	if( inactive_work == inactive_top ){
		inactive_top = cnt_work->next;
	}else{
		inactive_work->prev->next = cnt_work->next;
	}
	if( cnt_work == inactive_end ){
		inactive_end = inactive_work->prev;
	}else{
		cnt_work->next->prev = inactive_work->prev;
	}

	if( !active_end ){
		inactive_work->prev = (MY_MEM_LIST*)NULL;
		cnt_work->next = (MY_MEM_LIST*)NULL;

		active_top = inactive_work;
		active_end = cnt_work;
	}else{
		active_end->next = inactive_work;
		inactive_work->prev = active_end;

		cnt_work->next = (MY_MEM_LIST*)NULL;
		active_end = cnt_work;
	}

	return inactive_work->addr;
}


/* メモリー解放関数 */
void *MyMemoryFree(void *mem)	/* 成功:メモリーアドレス、0:エラー */
{
	MY_MEM_LIST	*loop_work, *loop_end_work=(MY_MEM_LIST*)NULL;

	loop_work = active_top;
	while( loop_work ){
		if( loop_work->addr == mem ){	/* 解放メモリーが見つかった！ */
			loop_end_work = loop_work;
			while( loop_end_work->seq ){
				loop_end_work->seq = (MY_MEM_LIST*)NULL;	/* 連続情報を削除しておく */
				loop_end_work = loop_end_work->next;
			}
			break;
		}
		loop_work = loop_work->next;
	}
	if( !loop_work )	return NULL;	/* 解放メモリーが見つからなかった時 */

	/* リストのつなぎ替え */
	/* ここに到達しているなら loop_work から loop_end_work が解放したいメモリー */
	if( loop_work == active_top ){
		active_top = loop_end_work->next;
	}else{
		loop_work->prev->next = loop_end_work->next;
	}
	if( loop_end_work == active_end ){
		active_end = loop_work->prev;
	}else{
		loop_end_work->next->prev = loop_work->prev;
	}

	if( !inactive_end ){
		loop_work->prev = (MY_MEM_LIST*)NULL;
		loop_end_work->next = (MY_MEM_LIST*)NULL;

		inactive_top = loop_work;
		inactive_end = loop_end_work;
	}else{
		inactive_end->next = loop_work;
		loop_work->prev = inactive_end;

		loop_end_work->next = (MY_MEM_LIST*)NULL;
		inactive_end = loop_end_work;
	}
	return mem;
}
