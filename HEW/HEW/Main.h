#pragma once

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

/*----------------------------------*/
/*----------�O���[�o���ϐ�----------*/
/*----------------------------------*/
#ifdef MAIN
LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;

#else
extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

#endif

//---------------------------------------------------------------------------------------
// �v���g�^�C�v�錾
//---------------------------------------------------------------------------------------

#include"Class.h"

#include"Window.h"		//�^�C�g�������U���g

#include"Battole.h"	//�o�g������
#include"Draw.h"		//�`��


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
	SHIELDER	//����
};

//---�A�N�V�����R�}���h---//
enum eCommand{
	ATTACK,		//�U��
	SKILL,		//���Z
	ITEM,		//�A�C�e��
	DEFENSE		//�h��
};

#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//�L�����N�^�[������^

int g_charcter_max;	//���݂̃X�e�[�W�̓G�̍ő吔
#else
extern CCharcter g_charcter[CHARCTER_MAX];

extern int g_charcter_max;
#endif
