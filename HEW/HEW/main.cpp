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

<<<<<<< HEAD

=======
//-----main�֐�-----//
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

//-----�e�평����-----//
#ifdef DX
	//----DirectX----//
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

				//---��ʑJ��---//
				ScreenState();
				//---�L�[���̍X�V---//
#ifdef DX
				//----DirectX----//
				Key.SetUpKey();
			}
		}
	}
	
	timeEndPeriod(1);

	//DirectX�I�������֐�
	DestroyD3D();
	
	return (int)msg.wParam;
#else
		//----Wii----//
		work_controller();
	}
	OSHalt("End of sample");	// �Q�[���I��
#endif
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
		if (PUSH_A){
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
		if (PUSH_A){
			seane = TITLE;
		}
		break;
	}
}

//-----�X�e�[�^�X�̏�����-----//
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
//Wii�p����������
//-----------------------------------------------------------------------------------------------------------------
#ifdef WII
void InitGX(){

	// �e�N�X�`���p���b�g(TPL)�t�@�C���̓ǂݍ��݁i�J���p�g���������[�Ƀ��[�h�j
	TPLGetPaletteDevMEM(&texPal, "Texture.tpl");	// TPL�t�@�C�����J���@�g���������[�ɓǂݍ���
	
	for(int i = 0; i<TEXTURE_MAX;i++){
		// �e�N�X�`���p���b�g�i�s�o�k�j����e�N�X�`���I�u�W�F�N�g�̎擾
		TPLGetGXTexObjFromPalette(texPal, &texObj[TEXTURE_MAX], 0);
	}

	void       *axBuffer;			//�T�E���h�p�������擪�A�h���X


	hExpHeap = MEMCreateExpHeap((void *)(0x92000000), 0x2000000);	// MEM2�̌�딼�����g�p�iMEM2�𑼂̗p�r�ɂ��g���ꍇ�͒��ӁI�j
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
	/* �v���W�F�N�V�����s��̐ݒ� */
	Mtx44 projMatrix; // �v���W�F�N�V�����s��

	MTXOrtho(projMatrix, 0, SCREEN_HEIGHT, 0, SCREEN_WIDTH, 0.0f, 1.0f);// ���ˉe�s��̍쐬

	GXSetProjection(projMatrix, GX_ORTHOGRAPHIC);						// ���ˉe�s����v���W�F�N�V�����s��Ƃ��Đݒ�

	GXSetCopyClear(BG_COLOR, GX_MAX_Z24);								// ��ʂ̃N���A

	/* ���_�����̐ݒ� */
	GXClearVtxDesc();													// ���_���������N���A
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);								// ���W�̓_�C���N�g�Q��
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);								// �J���[�̓_�C���N�g�Q��
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);								// �e�N�X�`�����W�̓_�C���N�g�Q��
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);		// ���_���W�����t�H�[�}�b�g�̐ݒ�
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGB, GX_RGB8, 0);	// ���_�J���[�����t�H�[�}�b�g�̐ݒ�
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);	// �e�N�X�`�����W�����t�H�[�}�b�g�̐ݒ�
	GXSetNumTevStages(1);		// �g�p����TEV�X�e�[�W���̐ݒ�

	GXSetNumChans(1);			// �J���[�`�����l�����̐ݒ�

	GXSetNumTexGens(1);			// ���p�\�ɂ���e�N�X�`�����W���̐ݒ�

	// TEV�Ŏg�p����e�N�X�`���[�J���[�ƃ��X�^���C�Y�J���[�̐ݒ�
	GXSetTevOrder(GX_TEVSTAGE0,	// TEV�X�e�[�W0�̐ݒ�
		GX_TEXCOORD0,	// �e�N�X�`�����W0�Ԃ��g�p
		GX_TEXMAP0,		// �e�N�X�`���}�b�v0�Ԃ��g�p
		GX_COLOR0A0);	// �J���[�`�����l��0�E�A���t�@�`�����l��0���g�p

	// TEV�̊ȈՃJ���[�����ݒ�
	GXSetTevOp(GX_TEVSTAGE0,	// TEV�X�e�[�W0�̐ݒ� 
		GX_MODULATE);	// �e�N�X�`���J���[�ƃe�N�X�`���A���t�@���o��

	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
}
#endif
//=======================================================================================
//    End of File
//=======================================================================================