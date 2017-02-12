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

#include"Cross.h"
#include"Key.h"

#define SCREEN_WIDTH (640.0f)
#define SCREEN_HEIGHT (480.0f)

#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FPS 60

#define CHARCTER_MAX (10)	//�ő�L������

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
//---------------------------------------------------------------------------------------
// �v���g�^�C�v�錾
//---------------------------------------------------------------------------------------

#include"Class.h"

#include"Window.h"		//�^�C�g�������U���g

#include"Battole.h"	//�o�g������
#include"Draw.h"	//�`��

#include"Game.h"	//�Q�[������	

/*------------------------*/
/*----------�֐�----------*/
/*------------------------*/

//-----��ʑJ��-----//
void ScreenState();

//-----�X�e�[�^�X�̏�����-----//
void SetStatus();

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
	TEXTURE_FONT,

	TEXTURE_ARROW,		//�I��p���
	TEXTURE_MAX
};

#define WHITE_STOCK (10)	
#define BLUE_STOCK (12)	
#define GREEN_STOCK (15)	


#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//�L�����N�^�[������^
int g_stage = 0;	//���݃X�e�[�W

int g_charcter_max[STAGE_MAX];	//�X�e�[�W�ʂ̓G�̍ő吔
int g_ally_charcter_max;	//�����L������

int g_charcter_job[STAGE_MAX][CHARCTER_MAX];	//�X�e�[�W�ʃL�����N�^�[�W���u

LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];	//�e�N�X�`��

//---�e�N�X�`��---//

#else
extern CCharcter g_charcter[CHARCTER_MAX];
extern int g_stage;

extern int g_charcter_max;
extern int g_ally_charcter_max;

extern int g_charcter_job[STAGE_MAX][CHARCTER_MAX];

extern LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];

#endif
