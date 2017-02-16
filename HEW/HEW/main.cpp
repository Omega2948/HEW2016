#define MAIN

#include"Main.h"

//=======================================================================================
//  プログラム本編
//=======================================================================================
//---------------------------------------------------------------------------------------
//  エントリポイント
//---------------------------------------------------------------------------------------

enum eSeane{
	TITLE,
	GAME,
	RESULT
};

<<<<<<< HEAD

=======
//-----main関数-----//
#ifdef DX
//----DirectX----//
>>>>>>> f7e79cff34aaf307bc02e14d9bea415760d70ea2
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;
	
#else
//----Wii----//
int main(void){

#endif

	float NewFrame, OldFrame;
	int Seane = TITLE;

//-----各種初期化-----//
#ifdef DX
	//----DirectX----//
	//-----wcの初期化関数-----//
	wcSet(&wc, hInstance);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "ウィンドウクラスの構造体の初期化エラー", "", MB_OK);
	}

	hWnd = CreateWindow(wc.lpszClassName,
		"DirectX9 スケルトンプログラム",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (FAILED(InitD3D(hWnd))){
		return -1;
	}
	

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


	timeBeginPeriod(1);
	OldFrame = timeGetTime();
	
#else
	//----Wii----//
	InitGX();
#endif
	
	while (1)
	{
	
#ifdef DX
		//----DirectX----//
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0) == 0)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			NewFrame = timeGetTime();
			if (NewFrame - OldFrame >= 1000.0f / FPS){
				OldFrame = NewFrame;
#else
		//----Wii----//
		
#endif

				//---画面遷移---//
				ScreenState();
				//---キー情報の更新---//
#ifdef DX
				//----DirectX----//
				Key.SetUpKey();
			}
		}
	}
	
	timeEndPeriod(1);

	//DirectX終了処理関数
	DestroyD3D();
	
	return (int)msg.wParam;
#else
		//----Wii----//
		work_controller();
	}
	OSHalt("End of sample");	// ゲーム終了
#endif
}

//-----画面遷移-----//
void ScreenState()
{
	static CWindow Window;
	static int seane = TITLE;

	switch (seane)
	{
		//タイトル画面
	case TITLE:
		//---タイトル画面の描画---//
		Window.DrawTitle();
		if (PUSH_A){
			seane = GAME;
		}
		break;
		//ゲーム画面
	case GAME:
		seane = RESULT;
		break;
		//リザルト画面
	case RESULT:
		//---リザルト画面の描画---//
		Window.DrawResult();
		if (PUSH_A){
			seane = TITLE;
		}
		break;
	}
}

//-----ステータスの初期化-----//
void SetStatus()
{
	for (int i = 0; i < g_charcter_max[g_stage]; i++){
		g_charcter[i].char_id = i;
		g_charcter[i].job = g_charcter_job[g_stage][i];

		switch (g_charcter[i].job){
			case SWORDSMAN:
				g_charcter[i].max_hp = g_charcter[i].hp = 1;
				g_charcter[i].max_pp = g_charcter[i].pp = 1;
				g_charcter[i].atk = 1;
				g_charcter[i].def = 1;
				g_charcter[i].Int = 1;
				g_charcter[i].spd = 1;

				break;
			case MAGICIAN:
				g_charcter[i].max_hp = g_charcter[i].hp = 1;
				g_charcter[i].max_pp = g_charcter[i].pp = 1;
				g_charcter[i].atk = 1;
				g_charcter[i].def = 1;
				g_charcter[i].Int = 1;
				g_charcter[i].spd = 1;

				break;
			case ARCHER:
				g_charcter[i].max_hp = g_charcter[i].hp = 1;
				g_charcter[i].max_pp = g_charcter[i].pp = 1;
				g_charcter[i].atk = 1;
				g_charcter[i].def = 1;
				g_charcter[i].Int = 1;
				g_charcter[i].spd = 1;

				break;
			case SHIELDER:
				g_charcter[i].max_hp = g_charcter[i].hp = 1;
				g_charcter[i].max_pp = g_charcter[i].pp = 1;
				g_charcter[i].atk = 1;
				g_charcter[i].def = 1;
				g_charcter[i].Int = 1;
				g_charcter[i].spd = 1;

				break;
		}

		g_charcter[i].cor_atk =
			g_charcter[i].cor_def =
			g_charcter[i].cor_Int = 0;

		g_charcter[i].stock = WHITE_STOCK;
	}
}

//-----------------------------------------------------------------------------------------------------------------
//Wii用初期化処理
//-----------------------------------------------------------------------------------------------------------------
#ifdef WII
void InitGX(){

	// テクスチャパレット(TPL)ファイルの読み込み（開発用拡張メモリーにロード）
	TPLGetPaletteDevMEM(&texPal, "Texture.tpl");	// TPLファイルを開発機拡張メモリーに読み込む
	
	for(int i = 0; i<TEXTURE_MAX;i++){
		// テクスチャパレット（ＴＰＬ）からテクスチャオブジェクトの取得
		TPLGetGXTexObjFromPalette(texPal, &texObj[TEXTURE_MAX], 0);
	}

	void       *axBuffer;			//サウンド用メモリ先頭アドレス


	hExpHeap = MEMCreateExpHeap((void *)(0x92000000), 0x2000000);	// MEM2の後ろ半分を使用（MEM2を他の用途にも使う場合は注意！）
	axBuffer = MEMAllocFromExpHeapEx(hExpHeap, AXGetMemorySize(AX_MAX_VOICES), 32);

	AIInit(NULL);
	AXInitSpecifyMem(AX_MAX_VOICES, axBuffer);
	LoadSamples();
	AXRegisterCallback(&AudioFrameCallback);
	for (int i = 0; i<AX_MAX_VOICES; i++){
		Voices[i].state = VOICE_STATE_STOP;
	}
}

void InitGXroop(){
	/* プロジェクション行列の設定 */
	Mtx44 projMatrix; // プロジェクション行列

	MTXOrtho(projMatrix, 0, SCREEN_HEIGHT, 0, SCREEN_WIDTH, 0.0f, 1.0f);// 正射影行列の作成

	GXSetProjection(projMatrix, GX_ORTHOGRAPHIC);						// 正射影行列をプロジェクション行列として設定

	GXSetCopyClear(BG_COLOR, GX_MAX_Z24);								// 画面のクリア

	/* 頂点属性の設定 */
	GXClearVtxDesc();													// 頂点属性情報をクリア
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);								// 座標はダイレクト参照
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);								// カラーはダイレクト参照
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);								// テクスチャ座標はダイレクト参照
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);		// 頂点座標属性フォーマットの設定
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGB, GX_RGB8, 0);	// 頂点カラー属性フォーマットの設定
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);	// テクスチャ座標属性フォーマットの設定
	GXSetNumTevStages(1);		// 使用するTEVステージ数の設定

	GXSetNumChans(1);			// カラーチャンネル数の設定

	GXSetNumTexGens(1);			// 利用可能にするテクスチャ座標数の設定

	// TEVで使用するテクスチャーカラーとラスタライズカラーの設定
	GXSetTevOrder(GX_TEVSTAGE0,	// TEVステージ0の設定
		GX_TEXCOORD0,	// テクスチャ座標0番を使用
		GX_TEXMAP0,		// テクスチャマップ0番を使用
		GX_COLOR0A0);	// カラーチャンネル0・アルファチャンネル0を使用

	// TEVの簡易カラー合成設定
	GXSetTevOp(GX_TEVSTAGE0,	// TEVステージ0の設定 
		GX_MODULATE);	// テクスチャカラーとテクスチャアルファを出力

	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
}
#endif
//=======================================================================================
//    End of File
//=======================================================================================