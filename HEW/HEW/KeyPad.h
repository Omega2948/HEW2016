#pragma once

#include "Main.h"

//=======================================================================================
//
//  [ KeyPad ] Wii sample program
//  Wii コントローラーサンプルプログラム
//
//=======================================================================================

#ifdef WII

//C:\RVL_SDK\include\revolution
#include <revolution/kpad.h>     // KPAD library

#endif //WII

//-------------------------------------------------------------
//  To show KPAD callback status(Wiiのみ)
//-------------------------------------------------------------
#ifdef WII

typedef struct MyCallbackStatus {
	u32 count;
	s32 reason;
} MyCallbackStatus;

#define MY_CALLBACK_MAX         2
#define MY_START_COUNTS_MAX     4
#define MY_START_COUNT_DEFAULT  400

extern s32              MyCallbackLatestIdx[MY_CALLBACK_MAX];
extern MyCallbackStatus MyCallbackStatusBuf[MY_CALLBACK_MAX][MY_START_COUNTS_MAX];

extern vu32 MySamplingCount;


#define KPAD_BUF_SIZE   16

extern  KPADStatus kpads[WPAD_MAX_CONTROLLERS][KPAD_BUF_SIZE * 2];              // キーデータバッファ
extern  s32        kpad_reads[WPAD_MAX_CONTROLLERS];                              // キーデータ数

#endif //WII

//-------------------------------------------------------------
//  関数宣言(Wii・DirectX両用)
//-------------------------------------------------------------
extern  void init_KPAD(void);


extern void	init_controller(void);
extern void	work_controller(void);

#ifdef WII

extern  void dpd_callback(s32 chan, s32 reason);
extern  void mpls_callback(s32 chan, s32 reason);
extern  void sampling_callback(s32 chan);


void* alloc32(u32);	// キーパッドデータの取得用メモリー確保
u8 free32(void *);	// キーパッドデータの取得用メモリー解放

#endif // WII