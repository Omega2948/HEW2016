#include "memory.h"

#define	NULL	(void *)0

int	*my_memory_s_address;	/* �ݏo�������[�u���b�N�̊J�n�E�I���A�h���X */
int	*my_memory_e_address;	/* int�^�ɂ��Ă܂����A���̎��X�ŃL���X�g���Ďg���Ă������� */

int	my_memory_size;			/* �������[�u���b�N�̑��T�C�Y */
int	my_memory_block_cnt;	/* �������[�u���b�N�� */


#if 0	/* windows���Ȃǂ̏ꍇ */
int	my_memory[ (MEMORY_ONE_BLOCK_SIZE/4) * MY_MEMORY_BLOCK_CNT ];	/* int �� 4Byte�Ƃ����ꍇ */

MY_MEM_LIST	my_mem_list[MY_MEMORY_BLOCK_CNT];
#else
MY_MEM_LIST	*my_mem_list;
#endif


MY_MEM_LIST	*inactive_top, *inactive_end;
MY_MEM_LIST	*active_top, *active_end;

int			memory_block_using_cnt;		/* �g�p���������[�u���b�N�� */


int InitMyMemory(void)	/* 0:�����A��:�G���[ */
{
	int i;

#if 1	/* �Œ�A�h���X�̏ꍇ */
	my_mem_list = (MY_MEM_LIST*)0x94000000;	/* �������[�Ǘ��p�̃��X�g�z��i������g���������[�ɂƂ�悤�ɂ��܂����j */

	my_memory_s_address = (int *)(0x94000000 + (MY_MEMORY_BLOCK_CNT*20));		/* wii �J���@�p�g���������[ */
	my_memory_e_address = (int *)0x98000000;

	my_memory_size = (unsigned int)my_memory_e_address - (unsigned int)my_memory_s_address;
	my_memory_block_cnt	= my_memory_size / MEMORY_ONE_BLOCK_SIZE;

	if( my_memory_block_cnt < MY_MEMORY_BLOCK_CNT )	return -1;	/* �������[�s�� */

	my_memory_e_address = (int *)((int)my_memory_s_address * my_memory_block_cnt * MEMORY_ONE_BLOCK_SIZE);	/* �T�C�Y�ɍ��킹�ďI�[�A�h���X�̏C�� */

#else

	my_memory_block_cnt = MY_MEMORY_BLOCK_CNT;

	my_memory_s_address = (int *)my_memory;
	my_memory_e_address = (int *)((int)my_memory_s_address * my_memory_block_cnt * MEMORY_ONE_BLOCK_SIZE);

	my_memory_size = (int)my_memory_e_address - (int)my_memory_s_address;

#endif

	inactive_top	= &my_mem_list[0];						/* ���g�p�������[�̃��X�g�̃g�b�v */
	inactive_end	= &my_mem_list[MY_MEMORY_BLOCK_CNT-1];	/* ���g�p�������[�̃��X�g�̃G���h */

	active_top		= (MY_MEM_LIST*)NULL;					/* �g�p���������[�̃��X�g�g�b�v */
	active_end		= (MY_MEM_LIST*)NULL;					/* �g�p���������[�̃��X�g�G���h */

	for( i=0 ; i<MY_MEMORY_BLOCK_CNT ; i++ ){
		my_mem_list[i].no	= i;							/* ���X�g�ԍ� */
		my_mem_list[i].addr	= (int *)(((int)my_memory_s_address) + (i * MEMORY_ONE_BLOCK_SIZE));	/* �Ǘ����Ă郁�����[�u���b�N�A�h���X */
		my_mem_list[i].seq	= (MY_MEM_LIST*)NULL;			/* �A���̈�̊Ǘ��A�h���X */

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


/* �������[�m�ۊ֐� */
void *MyMemoryAlloc(int size)	/* ����:�������[�A�h���X�A0:�G���[ */
{
	int	block_num;
	int	seq_no, cnt;
	MY_MEM_LIST	*inactive_work, *loop_work;
	MY_MEM_LIST	*cnt_work = (MY_MEM_LIST*)NULL;		/* �A���̈�J�E���g�p�̃��[�N */

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
				inactive_work = cnt_work->prev;	/* �����ς݂̘A���������Ƃ΂��āA�������i�߂� */
				break;		/* �A�������A�������[�T�C�Y������Ȃ����� */
			}
			if( block_num <= cnt )		break;	/* �~�����������[�T�C�Y�ɍ������A���������[�u���b�N���������� */
			cnt_work = cnt_work->next;
		}
		if( block_num <= cnt )	break;		/* �������[�u���b�N���������� */
		inactive_work = inactive_work->next;
	}
	if( !inactive_work )	return NULL;	/* �������[�m�ێ��s */

	/* ���X�g�̂Ȃ��ւ� */
	loop_work = inactive_work;	/* �����ɓ��B���Ă���Ȃ� inactive_work ���� cnt_work ���~�����������[ */
	while( loop_work != cnt_work ){
		loop_work->seq = loop_work->next;	/* �A���u���b�N�̃A�h���X�����Ă��� */
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


/* �������[����֐� */
void *MyMemoryFree(void *mem)	/* ����:�������[�A�h���X�A0:�G���[ */
{
	MY_MEM_LIST	*loop_work, *loop_end_work=(MY_MEM_LIST*)NULL;

	loop_work = active_top;
	while( loop_work ){
		if( loop_work->addr == mem ){	/* ����������[�����������I */
			loop_end_work = loop_work;
			while( loop_end_work->seq ){
				loop_end_work->seq = (MY_MEM_LIST*)NULL;	/* �A�������폜���Ă��� */
				loop_end_work = loop_end_work->next;
			}
			break;
		}
		loop_work = loop_work->next;
	}
	if( !loop_work )	return NULL;	/* ����������[��������Ȃ������� */

	/* ���X�g�̂Ȃ��ւ� */
	/* �����ɓ��B���Ă���Ȃ� loop_work ���� loop_end_work ������������������[ */
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
