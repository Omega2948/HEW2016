#pragma once

#include"Main.h"

class CWindow{
#ifdef DX
	//---�E�B���h�E�T�C�Y�̃|���S��---//
	VERTEX_2D _window[4];
	//---�e�N�X�`�� [0]-�^�C�g�� [1]-���U���g---//
	LPDIRECT3DTEXTURE9 texture[2];
#endif

	//---���_���̏�����---//
	void SetupVx();
	//---�e�N�X�`���̏�����---//
	void SetupTextre();
public:
	//---�^�C�g���̕`��---//
	void DrawTitle();
	//---���U���g��ʂ̕`��---//
	void DrawResult();

	CWindow(){
		SetupVx();
		SetupTextre();
	};
};