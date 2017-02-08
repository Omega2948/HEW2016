#define MAIN
#include"Main.h"

//=======================================================================================
//  �v���O�����{��
//=======================================================================================
//---------------------------------------------------------------------------------------
//  �G���g���|�C���g
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


	//-----wc�̏������֐�-----//
	wcSet(&wc, hInstance);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "�E�B���h�E�N���X�̍\���̂̏������G���[", "", MB_OK);
	}

	hWnd = CreateWindow(wc.lpszClassName,
		"DirectX9 �X�P���g���v���O����",
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

				//---��ʑJ��---//
				ScreenState();
				//---�L�[���̍X�V---//
				Key.SetUpKey();
			}
		}
	}
	timeEndPeriod(1);

	//DirectX�I�������֐�
	DestroyD3D();

	return (int)msg.wParam;

}

//-----��ʑJ��-----//
void ScreenState()
{
	static CWindow Window;
	static int seane = TITLE;

	switch (seane)
	{
		//�^�C�g�����
	case TITLE:
		//---�^�C�g����ʂ̕`��---//
		Window.DrawTitle();
		if (Key.ReleaseKey(VK_RETURN, ENTER_KEY)){
			seane = GAME;
		}
		break;
		//�Q�[�����
	case GAME:
		seane = RESULT;
		break;
		//���U���g���
	case RESULT:
		//---���U���g��ʂ̕`��---//
		Window.DrawResult();
		if (Key.ReleaseKey(VK_RETURN, ENTER_KEY)){
			seane = TITLE;
		}
		break;
	}


}

//-----�X�e�[�^�X�̏�����-----//
void SetStatus()
{

}
//=======================================================================================
//    End of File
//=======================================================================================