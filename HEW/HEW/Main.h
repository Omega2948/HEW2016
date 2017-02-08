#pragma once

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

/*----------------------------------*/
/*----------グローバル変数----------*/
/*----------------------------------*/
#ifdef MAIN
LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;

#else
extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

#endif

//---------------------------------------------------------------------------------------
// プロトタイプ宣言
//---------------------------------------------------------------------------------------

#include"Class.h"

#include"Window.h"		//タイトル＆リザルト

#include"Battole.h"	//バトル処理
#include"Draw.h"		//描画


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
	SHIELDER	//盾兵
};

//---アクションコマンド---//
enum eCommand{
	ATTACK,		//攻撃
	SKILL,		//特技
	ITEM,		//アイテム
	DEFENSE		//防御
};

#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//キャラクターを入れる型

int g_charcter_max;	//現在のステージの敵の最大数
#else
extern CCharcter g_charcter[CHARCTER_MAX];

extern int g_charcter_max;
#endif
