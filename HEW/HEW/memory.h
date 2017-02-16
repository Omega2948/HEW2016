#pragma once

#define	MEMORY_ONE_BLOCK_SIZE	(512)					/* �������[�u���b�N�̃T�C�Y - BYTE�T�C�Y */
#define	MY_MEMORY_BLOCK_CNT		(0x1ecc0)	/* �������[�u���b�N�� */

typedef struct _MY_MEM_LIST{	/* 20Byte */
	struct _MY_MEM_LIST		*prev;		/* ���X�g�p�|�C���^ */
	struct _MY_MEM_LIST		*next;		/* ���X�g�p�|�C���^ */
	int						no;			/* �������[�u���b�N�̔ԍ� */
	int						*addr;		/* �������[�u���b�N�̃A�h���X */
	struct _MY_MEM_LIST		*seq;		/* �A���̈�̃��X�g */
}MY_MEM_LIST;



int InitMyMemory(void);		/* 0:�����A��:�G���[ */

/* �������[�m�ۊ֐� */
void *MyMemoryAlloc(int);	/* ����:�������[�A�h���X�A0:�G���[ */

/* �������[����֐� */
void *MyMemoryFree(void *);	/* ����:�������[�A�h���X�A0:�G���[ */

