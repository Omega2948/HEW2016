#pragma once

//------------------------------------//
//----------�v���b�g�t�H�[��----------//
//------------------------------------//
#define DX

//#define WII
//--------------------------------------------------------------------------------------- 
// �C���N���[�h�t�@�C��
//---------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#include<Windows.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include<dinput.h>
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")

#ifdef DX
#include"Cross.h"
#include"Key.h"
#else
#include<revolution/wpad.h>
#include<revolution/kpad.h>
#include"MEMAllocator.h"
#include"KeyPad.h"
#endif




#define SCREEN_WIDTH (640.0f)
#define SCREEN_HEIGHT (480.0f)

#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FPS 60

#define CHARCTER_MAX (9)	//�ő�L������

#define STAGE_MAX (5)	//�X�e�[�W��

/*----------------------------------*/
/*----------�O���[�o���ϐ�----------*/
/*----------------------------------*/
#ifdef DX
#ifdef MAIN
LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;

#else
extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

#endif
#endif


/*------------------------*/
/*----------�萔----------*/
/*------------------------*/
//---�E---//
enum eJob{
	SWORDSMAN,	//���m
	MAGICIAN,	//���p�t
	ARCHER,		//�|��
	SHIELDER,	//����
	JOB_MAX
};

//---�e�N�X�`��---//
enum eTexture{
	TEXTURE_SWORDSMAN,	//���m
	TEXTURE_MAGICIAN,	//���p�t
	TEXTURE_ARCHER,		//�|��
	TEXTURE_SHIELDER,	//����
	TEXTURE_BACKGROUND,	//�퓬���w�i
	TEXTURE_FONT,		//�t�H���g
	TEXTURE_PLAIN_SQUARE,		//���n�w�i(�l�p)
	TEXTURE_PLAIN_CIRCLE,		//���n�w�i(��)
	TEXTURE_FIELD,		//�t�B�[���h
	TEXTURE_HP,			//�����uHP:�v
	TEXTURE_PP,			//�����uPP:�v
	TEXTURE_ATK,		//�����u�U�v
	TEXTURE_DEF,		//�����u�h�v
	TEXTURE_ATTACK,		//�����u�ʏ�U���v
	TEXTURE_SKILL,		//�����u���Z�v
	TEXTURE_ITEM,		//�����u�A�C�e���v
	TEXTURE_DEFENSE,	//�����u�h��v
	TEXTURE_REMAINDER,	//�����u�c��^�[���v
	TEXTURE_ARROW,		//�I��p���
	TEXTURE_STOCK,		//�X�g�b�N
	TEXTURE_MAX
};

#define WHITE_STOCK (10)	//���X�g�b�N�̕␳�l(10�{)
#define BLUE_STOCK (12)		//�X�g�b�N�̕␳�l(10�{)
#define GREEN_STOCK (15)	//�΃X�g�b�N�̕␳�l(10�{)



//---------------------------------------------------------------------------------------
// �v���g�^�C�v�錾
//---------------------------------------------------------------------------------------

#include"Class.h"

#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//�L�����N�^�[������^
int g_stage = 0;	//���݃X�e�[�W

int g_charcter_max[STAGE_MAX];	//�X�e�[�W�ʂ̓G�̍ő吔
int g_ally_charcter_max;	//�����L������

int g_charcter_job[STAGE_MAX][CHARCTER_MAX];	//�X�e�[�W�ʃL�����N�^�[�W���u

int g_turn;	//�o�߃^�[��
int g_next_skill[2];	//���̓G�̃X�L�������L�����̃W���u�ƌ��܂ł̃^�[��
int g_enemy_skill[5][2];	//�G�̃X�L������
//---�e�N�X�`��---//
LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];	//�e�N�X�`��


#else
extern CCharcter g_charcter[CHARCTER_MAX];
extern int g_stage;

extern int g_charcter_max[STAGE_MAX];
extern int g_ally_charcter_max;

extern int g_charcter_job[STAGE_MAX][CHARCTER_MAX];

extern int g_turn;	//�o�߃^�[��
extern int g_next_skill[2];	//���̓G�̃X�L�������L�����̃W���u�ƌ��܂ł̃^�[��
extern int g_enemy_skill[5][2];	//�G�̃X�L������

extern LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];

#endif

#include"Window.h"		//�^�C�g�������U���g

#include"Draw.h"	//�`��
#include"Battole.h"	//�o�g������

#include"Game.h"	//�Q�[������	

/*------------------------*/
/*----------�֐�----------*/
/*------------------------*/

//-----��ʑJ��-----//
void ScreenState();

//-----�X�e�[�^�X�̏�����-----//
void SetStatus();


//����
#ifdef DX
#define PUSH_A (Key.ReleaseKey(VK_RETURN, ENTER_KEY))
#define PUSH_UP (Key.ReleaseKey(VK_UP, UP_KEY))
#define PUSH_DOWN (Key.ReleaseKey(VK_DOWN, DOWN_KEY))
#define PUSH_RIGHT (Key.ReleaseKey(VK_RIGHT, RIGHT_KEY))
#define PUSH_LEFT (Key.ReleaseKey(VK_LEFT, LEFT_KEY))
#else
#define PUSH_A (kpads[0][0].hold &KPAD_BUTTON_A)
#define PUSH_UP (kpads[0][0].hold &KPAD_BUTTON_UP)
#define PUSH_DOWN (kpads[0][0].hold &KPAD_BUTTON_DOWN)
#define PUSH_RIGHT (kpads[0][0].hold &KPAD_BUTTON_RIGHT)
#define PUSH_LEFT (kpads[0][0].hold &KPAD_BUTTON_LEFT)
#endif