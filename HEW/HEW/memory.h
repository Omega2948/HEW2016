#pragma once

#define	MEMORY_ONE_BLOCK_SIZE	(512)					/* メモリーブロックのサイズ - BYTEサイズ */
#define	MY_MEMORY_BLOCK_CNT		(0x1ecc0)	/* メモリーブロック数 */

typedef struct _MY_MEM_LIST{	/* 20Byte */
	struct _MY_MEM_LIST		*prev;		/* リスト用ポインタ */
	struct _MY_MEM_LIST		*next;		/* リスト用ポインタ */
	int						no;			/* メモリーブロックの番号 */
	int						*addr;		/* メモリーブロックのアドレス */
	struct _MY_MEM_LIST		*seq;		/* 連続領域のリスト */
}MY_MEM_LIST;



int InitMyMemory(void);		/* 0:成功、負:エラー */

/* メモリー確保関数 */
void *MyMemoryAlloc(int);	/* 成功:メモリーアドレス、0:エラー */

/* メモリー解放関数 */
void *MyMemoryFree(void *);	/* 成功:メモリーアドレス、0:エラー */

