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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	float NewFrame, OldFrame;
	int Seane = TITLE;


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
	while (1)
	{

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

				//---画面遷移---//
				ScreenState();
				//---キー情報の更新---//
				Key.SetUpKey();
			}
		}
	}
	timeEndPeriod(1);

	//DirectX終了処理関数
	DestroyD3D();

	return (int)msg.wParam;

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
		if (Key.ReleaseKey(VK_RETURN, ENTER_KEY)){
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
		if (Key.ReleaseKey(VK_RETURN, ENTER_KEY)){
			seane = TITLE;
		}
		break;
	}


}

//-----ステータスの初期化-----//
void SetStatus()
{

}
//=======================================================================================
//    End of File
//=======================================================================================