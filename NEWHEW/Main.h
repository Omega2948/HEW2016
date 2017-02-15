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

#define CHARCTER_MAX (9)	//最大キャラ数

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
	TEXTURE_FONT,		//フォント
	TEXTURE_PLAIN_SQUARE,		//無地背景(四角)
	TEXTURE_PLAIN_CIRCLE,		//無地背景(丸)
	TEXTURE_FIELD,		//フィールド
	TEXTURE_HP,			//文字「HP:」
	TEXTURE_PP,			//文字「PP:」
	TEXTURE_ATK,		//文字「攻」
	TEXTURE_DEF,		//文字「防」
	TEXTURE_ATTACK,		//文字「通常攻撃」
	TEXTURE_SKILL,		//文字「特技」
	TEXTURE_ITEM,		//文字「アイテム」
	TEXTURE_DEFENSE,	//文字「防御」
	TEXTURE_REMAINDER,	//文字「残りターン」
	TEXTURE_ARROW,		//選択用矢印
	TEXTURE_STOCK,		//ストック
	TEXTURE_MAX
};

#define WHITE_STOCK (10)	//白ストックの補正値(10倍)
#define BLUE_STOCK (12)		//青ストックの補正値(10倍)
#define GREEN_STOCK (15)	//緑ストックの補正値(10倍)



//---------------------------------------------------------------------------------------
// プロトタイプ宣言
//---------------------------------------------------------------------------------------

#include"Class.h"

#ifdef MAIN
CCharcter g_charcter[CHARCTER_MAX];	//キャラクターを入れる型
int g_stage = 0;	//現在ステージ

int g_charcter_max[STAGE_MAX];	//ステージ別の敵の最大数
int g_ally_charcter_max;	//味方キャラ数

int g_charcter_job[STAGE_MAX][CHARCTER_MAX];	//ステージ別キャラクタージョブ

int g_turn;	//経過ターン
int g_next_skill[2];	//次の敵のスキルを撃つキャラのジョブと撃つまでのターン
int g_enemy_skill[5][2];	//敵のスキル入れ
//---テクスチャ---//
LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];	//テクスチャ


#else
extern CCharcter g_charcter[CHARCTER_MAX];
extern int g_stage;

extern int g_charcter_max[STAGE_MAX];
extern int g_ally_charcter_max;

extern int g_charcter_job[STAGE_MAX][CHARCTER_MAX];

extern int g_turn;	//経過ターン
extern int g_next_skill[2];	//次の敵のスキルを撃つキャラのジョブと撃つまでのターン
extern int g_enemy_skill[5][2];	//敵のスキル入れ

extern LPDIRECT3DTEXTURE9 g_texture[TEXTURE_MAX];

#endif

#include"Window.h"		//タイトル＆リザルト

#include"Draw.h"	//描画
#include"Battole.h"	//バトル処理

#include"Game.h"	//ゲーム処理	

/*------------------------*/
/*----------関数----------*/
/*------------------------*/

//-----画面遷移-----//
void ScreenState();

//-----ステータスの初期化-----//
void SetStatus();


//入力
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