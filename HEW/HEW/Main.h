#pragma once

//------------------------------------//
//----------プラットフォーム----------//
//------------------------------------//
#define DX

//#define WII
//--------------------------------------------------------------------------------------- 
// インクルードファイル
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

#define CHARCTER_MAX (10)	//最大キャラ数

#define STAGE_MAX (5)	//ステージ数

/*----------------------------------*/
/*----------グローバル変数----------*/
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
// プロトタイプ宣言
//---------------------------------------------------------------------------------------

#include"Class.h"

#include"Window.h"		//タイトル＆リザルト

#include"Battole.h"	//バトル処理
#include"Draw.h"	//描画

#include"Game.h"	//ゲーム処理	

/*------------------------*/
/*----------関数----------*/
/*------------------------*/

//-----画面遷移-----//
void ScreenState();

//-----ステータスの初期化-----//
void SetStatus();

/*------------------------*/
/*----------定数----------*/
/*------------------------*/
//---職---//
enum eJob{
	SWORDSMAN,	//剣士
	MAGICIAN,	//魔術師
	ARCHER,		//弓兵
	SHIELDER,	//盾兵
	JOB_MAX
};

//---テクスチャ---//
enum eTexture{
	TEXTURE_SWORDSMAN,	//剣士
	TEXTURE_MAGICIAN,	//魔術師
	TEXTURE_ARCHER,		//弓兵
	TEXTURE_SHIELDER,	//盾兵
	TEXTURE_BACKGROUND,	//戦闘中背景
	TEXTURE_FONT,

	TEXTURE_ARROW,		//選択用矢印
	TEXTURE_MAX
};

#define WHITE_STOCK (10)	
#define BLUE_STOCK (12)	
#define GREEN_STOCK (15)	


#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//キャラクターを入れる型
int g_stage = 0;	//現在ステージ

int g_charcter_max[STAGE_MAX];	//ステージ別の敵の最大数
int g_ally_charcter_max;	//味方キャラ数

int g_charcter_job[STAGE_MAX][CHARCTER_MAX];	//ステージ別キャラクタージョブ

LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];	//テクスチャ

//---テクスチャ---//

#else
extern CCharcter g_charcter[CHARCTER_MAX];
extern int g_stage;

extern int g_charcter_max;
extern int g_ally_charcter_max;

extern int g_charcter_job[STAGE_MAX][CHARCTER_MAX];

extern LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];

#endif
