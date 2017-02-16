#include"Main.h"
//-----�`��-----//

void CDraw::SetTexture()
{
	////---���m---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char000.tga", &g_texture[TEXTURE_SWORDSMAN]))){
	//	exit(1);
	//}
	////---���p�t---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char001.tga", &g_texture[TEXTURE_MAGICIAN]))){
	//	exit(1);
	//}
	////---�|��---///
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char002.tga", &g_texture[TEXTURE_ARCHER]))){
	//	exit(1);
	//}
	////---����---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char003.tga", &g_texture[TEXTURE_SHIELDER]))){
	//	exit(1);
	//}

	////---�w�i---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/bg001.tga", &g_texture[TEXTURE_BG_BATTLE]))){
	//	exit(1);
	//}

	////---�t�H���g---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/font.tga", &g_texture[TEXTURE_FONT]))){
	//	exit(1);
	//}

	////---���n�w�i(�l�p)---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/plain_bg000.tga", &g_texture[TEXTURE_PLAIN_SQUARE]))){
	//	exit(1);
	//}

	////---���n�w�i(��)---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/plain_bg001.tga", &g_texture[TEXTURE_PLAIN_CIRCLE]))){
	//	exit(1);
	//}

	////---�t�B�[���h---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/field.tga", &g_texture[TEXTURE_FIELD]))){
	//	exit(1);
	//}

	////---�����uHP:�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string000.tga", &g_texture[TEXTURE_HP]))){
	//	exit(1);
	//}
	////---�����uPP:�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string001.tga", &g_texture[TEXTURE_PP]))){
	//	exit(1);
	//}
	////---�����u�U�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string002.tga", &g_texture[TEXTURE_ATK]))){
	//	exit(1);
	//}
	////---�����u�h�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string003.tga", &g_texture[TEXTURE_DEF]))){
	//	exit(1);
	//}

	////---�����u�ʏ�U���v�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string004.tga", &g_texture[TEXTURE_ATTACK]))){
	//	exit(1);
	//}
	////---�����u���Z�v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string005.tga", &g_texture[TEXTURE_SKILL]))){
	//	exit(1);
	//}
	////---�����u�A�C�e���v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string006.tga", &g_texture[TEXTURE_ITEM]))){
	//	exit(1);
	//}
	////---�����u�h��v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string007.tga", &g_texture[TEXTURE_DEFENSE]))){
	//	exit(1);
	//}

	////---�����u�c��^�[���v---//
	//if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/string008.tga", &g_texture[TEXTURE_REMAINDER]))){
	//	exit(1);
	//}

}

//---�X�e�[�^�X�\���p�|���S���̃T�C�Y�ݒ�---//
int CDraw::VxSizeSet(int _j)
{
	if (_j == 2 || _j == 5){
		return 30;
	}
	else if (_j == 8 || _j == 11){
		return 20;
	}
	else{
		return 10;
	}
}

void CDraw::SetVertex()
{
	for (int i = 0; i < CHARCTER_MAX; i++){
		//�X�e�[�^�X�\���p�|���S��
		for (int j = 0; j < 14; j++){
			if (j == 0){
				_status_vx[i][j][0].x = _status_vx[i][j][3].x = 430.0f;
				_status_vx[i][j][1].x = _status_vx[i][j][2].x = _status_vx[i][j][0].x + 190;
			}
			else{
				if (j == 1){
					_status_vx[i][j][0].x = _status_vx[i][j][3].x = 430.0f;
				}
				else{
					_status_vx[i][j][0].x = _status_vx[i][j][3].x = _status_vx[i][j - 1][1].x;
				}
				_status_vx[i][j][1].x = _status_vx[i][j][2].x = _status_vx[i][j][0].x + VxSizeSet(j);
			}
			_status_vx[i][j][0].y = _status_vx[i][j][1].y = 10.0f + 20 * i;
			_status_vx[i][j][2].y = _status_vx[i][j][3].y = _status_vx[i][j][0].y + 20;

			_status_vx[i][j][0].tex_u = _status_vx[i][j][3].tex_u = 0.0f;
			_status_vx[i][j][1].tex_u = _status_vx[i][j][2].tex_u = 1.0f;

			_status_vx[i][j][0].tex_v = _status_vx[i][j][1].tex_v = 0.0f;
			_status_vx[i][j][2].tex_v = _status_vx[i][j][3].tex_v = 1.0f;

			for (int k = 0; k < 4; k++){
				_status_vx[i][j][k].z = 0.0f;
#ifdef DX
				_status_vx[i][j][k].rhw = 1.0f;
				_status_vx[i][j][k].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
			}
		}

		//�L�����N�^�[�p�|���S��
		_charcter_vx[i][0].tex_u = _charcter_vx[i][3].tex_u = 0.0f;
		_charcter_vx[i][1].tex_u = _charcter_vx[i][2].tex_u = 1.0f;

		_charcter_vx[i][0].tex_v = _charcter_vx[i][1].tex_v = 0.0f;
		_charcter_vx[i][2].tex_v = _charcter_vx[i][3].tex_v = 1.0f;

		for (int i = 0; i < 4; i++){
			_charcter_vx[i][i].z = 0.0f;
#ifdef DX
			_charcter_vx[i][i].rhw = 1.0f;
			_charcter_vx[i][i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
		}
	}

	//�w�i�`��p�|���S��
	_bg_vx[0].x = _bg_vx[3].x = 0.0f;
	_bg_vx[1].x = _bg_vx[2].x = SCREEN_WIDTH;

	_bg_vx[0].y = _bg_vx[1].y = 0.0f;
	_bg_vx[2].y = _bg_vx[3].y = SCREEN_HEIGHT;

	_bg_vx[0].tex_u = _bg_vx[3].tex_u = 0.0f;
	_bg_vx[1].tex_u = _bg_vx[2].tex_u = 1.0f;

	_bg_vx[0].tex_v = _bg_vx[1].tex_v = 0.0f;
	_bg_vx[2].tex_v = _bg_vx[3].tex_v = 1.0f;

	for (int i = 0; i < 4; i++){
		_bg_vx[i].z = 0.0f;
#ifdef DX
		_bg_vx[i].rhw = 1.0f;
		_bg_vx[i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
	}
	//�L�����N�^�[�z�u�p�}�X�|���S��
	_field_vx[0][0].x = 120.0f;
	_field_vx[0][1].x = _field_vx[0][0].x + FIELD_SIZE;
	_field_vx[0][3].x = 40.0f;
	_field_vx[0][2].x = _field_vx[0][3].x + FIELD_SIZE;

	_field_vx[1][0].x = 330.0f;
	_field_vx[1][1].x = _field_vx[1][0].x + FIELD_SIZE;
	_field_vx[1][3].x = 410.0f;
	_field_vx[1][2].x = _field_vx[1][3].x + FIELD_SIZE;

	for (int i = 0; i < 2; i++){
		_field_vx[i][0].y = _field_vx[i][1].y = 260.0f;
		_field_vx[i][2].y = _field_vx[i][3].y = _field_vx[i][0].y + FIELD_SIZE / 2;

		_field_vx[i][0].tex_u = _field_vx[i][3].tex_u = 0.0f;
		_field_vx[i][1].tex_u = _field_vx[i][2].tex_u = 1.0f;

		_field_vx[i][0].tex_v = _field_vx[i][1].tex_v = 0.0f;
		_field_vx[i][2].tex_v = _field_vx[i][3].tex_v = 1.0f;

		for (int j = 0; j < 4; j++){
			_field_vx[i][j].z = 0.0f;

#ifdef DX
			_field_vx[i][j].rhw = 1.0f;

			if (i == 0){
				_field_vx[i][j].diffuse = D3DCOLOR_RGBA(0, 0, 255, 255);
			}
			else{
				_field_vx[i][j].diffuse = D3DCOLOR_RGBA(255, 0, 0, 255);
			}
#endif
		}
	}

	//�c��^�[��
	for (int i = 0; i < 2; i++){
		if (i == 0){
			_clock_vx[i][0].x = _clock_vx[i][3].x = 270.0f;
			_clock_vx[i][1].x = _clock_vx[i][2].x = _clock_vx[i][0].x + 100.0f;

			_clock_vx[i][0].y = _clock_vx[i][1].y = 10.0f;
			_clock_vx[i][2].y = _clock_vx[i][3].y = _clock_vx[i][0].y + 100.0f;
		}
		else{
			_clock_vx[i][0].x = _clock_vx[i][3].x = 300.0f;
			_clock_vx[i][1].x = _clock_vx[i][2].x = _clock_vx[i][0].x + 40.0f;

			_clock_vx[i][0].y = _clock_vx[i][1].y = 20.0f;
			_clock_vx[i][2].y = _clock_vx[i][3].y = _clock_vx[i][0].y + 80.0f;
		}
		_clock_vx[i][0].tex_u = _clock_vx[i][3].tex_u = 0.0f;
		_clock_vx[i][1].tex_u = _clock_vx[i][2].tex_u = 1.0f;

		_clock_vx[i][0].tex_v = _clock_vx[i][1].tex_v = 0.0f;
		_clock_vx[i][2].tex_v = _clock_vx[i][3].tex_v = 1.0f;

		for (int j = 0; j < 4;){
			_clock_vx[i][j].z = 0.0f;
#ifdef DX
			_clock_vx[i][j].rhw = 1.0f;
			_clock_vx[i][j].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
		}
	}

	//�R�}���h
	for (int i = 0; i < 5; i++){
		if (i == 0){
			_command_vx[i][0].x = _command_vx[i][3].x = 20.0f;
			_command_vx[i][1].x = _command_vx[i][2].x = _command_vx[i][0].x + 140.0f;

			_command_vx[i][0].y = _command_vx[i][1].y = 30.0f;
			_command_vx[i][2].y = _command_vx[i][3].y = _command_vx[i][0].y + 120.0f;
		}
		else{
			_command_vx[i][0].x = _command_vx[i][3].x = 40.0f;
			_command_vx[i][1].x = _command_vx[i][2].x = _command_vx[i][0].x + 120.0f;

			_command_vx[i][0].y = _command_vx[i][1].y = 30.0f + (i - 1) * 30;
			_command_vx[i][2].y = _command_vx[i][3].y = _command_vx[i][0].y + 30.0f;
		}

		_command_vx[i][0].tex_u = _command_vx[i][3].tex_u = 0.0f;
		_command_vx[i][1].tex_u = _command_vx[i][2].tex_u = 1.0f;

		_command_vx[i][0].tex_v = _command_vx[i][1].tex_v = 0.0f;
		_command_vx[i][2].tex_v = _command_vx[i][3].tex_v = 1.0f;
		for (int j = 0; j < 4;){
			_command_vx[i][j].z = 0.0f;
#ifdef DX
			_command_vx[i][j].rhw = 1.0f;
			_command_vx[i][j].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
		}
	}

	//�G�̃X�L���g�p
	for (int i = 0; i < 4; i++){
		switch (i){
		case 0:
			_danger_vx[i][0].x = _danger_vx[i][3].x = 250.0f;
			_danger_vx[i][1].x = _danger_vx[i][2].x = _danger_vx[i][0].x + 140.0f;
			break;
		case 1:
			_danger_vx[i][0].x = _danger_vx[i][3].x = 250.0f;
			_danger_vx[i][1].x = _danger_vx[i][2].x = _danger_vx[i][0].x + 140.0f;
			break;
		case 2:
			_danger_vx[i][0].x = _danger_vx[i][3].x = 290.0f;
			_danger_vx[i][1].x = _danger_vx[i][2].x = _danger_vx[i][0].x + 70.0f;
			break;
		case 3:
			_danger_vx[i][0].x = _danger_vx[i][3].x = 370.0f;
			_danger_vx[i][1].x = _danger_vx[i][2].x = _danger_vx[i][0].x + 20.0f;
			break;
		}

		_danger_vx[i][0].y = _danger_vx[i][1].y = 130.0f;
		_danger_vx[i][2].y = _danger_vx[i][3].y = _danger_vx[i][0].y + 40.0f;

		_danger_vx[i][0].tex_u = _danger_vx[i][3].tex_u = 0.0f;
		_danger_vx[i][1].tex_u = _danger_vx[i][2].tex_u = 1.0f;

		_danger_vx[i][0].tex_v = _danger_vx[i][1].tex_v = 0.0f;
		_danger_vx[i][2].tex_v = _danger_vx[i][3].tex_v = 1.0f;
		for (int j = 0; j < 4;){
			_danger_vx[i][j].z = 0.0f;
#ifdef DX
			_danger_vx[i][j].rhw = 1.0f;
			_danger_vx[i][j].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
#endif
		}
	}

}


//---�L�����̕`��---//
void CDraw::DrawCharcter(int _char_no)
{
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[g_charcter[_char_no].job]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_charcter[_char_no].vx, sizeof(VERTEX_2D));
#endif
}

//---�w�i�̕`��---//
void CDraw::DrawBg()
{
<<<<<<< HEAD
=======
#ifdef DX
>>>>>>> f7e79cff34aaf307bc02e14d9bea415760d70ea2
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_BG_BATTLE]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _bg_vx, sizeof(VERTEX_2D));
#endif
}

//---�X�e�[�^�X�̕`��---//
void CDraw::DrawStatus(int _char_no)
{
	int wari = 10;
	int ans;

	int copy;

	//---�w�i---//
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_PLAIN_SQUARE]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][0], sizeof(VERTEX_2D));
#endif

	//---�L����ID---//
	_status_vx[_char_no][1][0].tex_u =
		_status_vx[_char_no][1][3].tex_u = _char_no * 2 * FONT_U;
	_status_vx[_char_no][1][1].tex_u =
		_status_vx[_char_no][1][2].tex_u = (_char_no * 2 + 1) * FONT_U;
		
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][1], sizeof(VERTEX_2D));
#endif

	//---HP---//
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_HP]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][2], sizeof(VERTEX_2D));
#endif

	copy = g_charcter[_char_no].hp;
	for (int i = 0; i < 2; i++){
		ans = copy / wari;

		_status_vx[_char_no][3 + i][0].tex_u =
			_status_vx[_char_no][3 + i][3].tex_u = ans * 2 * FONT_U;
		_status_vx[_char_no][3 + i][1].tex_u =
			_status_vx[_char_no][3 + i][2].tex_u = (ans * 2 + 1) * FONT_U;

#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][3 + i], sizeof(VERTEX_2D));
<<<<<<< HEAD
		copy -= ans * wari;
=======
#endif
>>>>>>> f7e79cff34aaf307bc02e14d9bea415760d70ea2
		wari /= 10;
	}

	//---PP---//
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_PP]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][5], sizeof(VERTEX_2D));
#endif

	copy = g_charcter[_char_no].pp;
	wari = 10;
	for (int i = 0; i < 2; i++){
		ans = copy / wari;

		_status_vx[_char_no][6 + i][0].tex_u =
			_status_vx[_char_no][6 + i][3].tex_u = ans * 2 * FONT_U;
		_status_vx[_char_no][6 + i][1].tex_u =
			_status_vx[_char_no][6 + i][2].tex_u = (ans * 2 + 1) * FONT_U;

#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][6 + i], sizeof(VERTEX_2D));
<<<<<<< HEAD
		copy -= ans * wari;
=======
#endif
>>>>>>> f7e79cff34aaf307bc02e14d9bea415760d70ea2
		wari /= 10;
	}

	//---�U---//
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_ATK]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][8], sizeof(VERTEX_2D));
#endif

	copy = g_charcter[_char_no].pp;
	wari = 10;
	for (int i = 0; i < 2; i++){
		ans = copy / wari;

		_status_vx[_char_no][9 + i][0].tex_u =
			_status_vx[_char_no][9 + i][3].tex_u = ans * 2 * FONT_U;
		_status_vx[_char_no][9 + i][1].tex_u =
			_status_vx[_char_no][9 + i][2].tex_u = (ans * 2 + 1) * FONT_U;

#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][9 + i], sizeof(VERTEX_2D));
#endif

		copy -= ans * wari;
		wari /= 10;
	}

	//---�h---//
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_DEF]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][11], sizeof(VERTEX_2D));
#endif

	copy = g_charcter[_char_no].pp;
	wari = 10;
	for (int i = 0; i < 2; i++){
		ans = copy / wari;

		_status_vx[_char_no][12 + i][0].tex_u =
			_status_vx[_char_no][12 + i][3].tex_u = ans * 2 * FONT_U;
		_status_vx[_char_no][12 + i][1].tex_u =
			_status_vx[_char_no][12 + i][2].tex_u = (ans * 2 + 1) * FONT_U;

#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _status_vx[_char_no][12 + i], sizeof(VERTEX_2D));
#endif

		copy -= ans * wari;
		wari /= 10;
	}
}

//---�t�B�[���h�̕`��---//
void CDraw::DrawField()
{
	for (int i = 0; i < 2; i++){
#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FIELD]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _field_vx[i], sizeof(VERTEX_2D));
#endif
	}
}

//---�c��^�[��---//
void CDraw::DrawClock()
{
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_PLAIN_CIRCLE]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _clock_vx[0], sizeof(VERTEX_2D));
#endif
	
	_clock_vx[1][0].tex_u =
		_clock_vx[1][3].tex_u = g_turn * 2 * FONT_U;
	_clock_vx[1][1].tex_u =
		_clock_vx[1][2].tex_u = (g_turn * 2 + 1) * FONT_U;

#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_FONT]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _clock_vx[1], sizeof(VERTEX_2D));
#endif
}

//---�R�}���h---//
void CDraw::DrawCommand()
{
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_PLAIN_SQUARE]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _command_vx[0], sizeof(VERTEX_2D));
#endif
	for (int i = 0; i < 4; i++){
#ifdef DX
		g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_ATTACK + i]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _command_vx[i + 1], sizeof(VERTEX_2D));
#endif
	}
}
//---�G�̃X�L���g�p---//
void CDraw::DrawDanger()
{
#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_PLAIN_SQUARE]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _danger_vx[0], sizeof(VERTEX_2D));

	g_pd3dDevice->SetTexture(0, g_texture[g_next_skill[0]]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _danger_vx[1], sizeof(VERTEX_2D));

	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_REMAINDER]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _danger_vx[0], sizeof(VERTEX_2D));
#endif

	_danger_vx[1][0].tex_u =
		_danger_vx[1][3].tex_u = g_next_skill[1] * 2 * FONT_U;
	_danger_vx[1][1].tex_u =
		_danger_vx[1][2].tex_u = (g_next_skill[1] * 2 + 1) * FONT_U;

#ifdef DX
	g_pd3dDevice->SetTexture(0, g_texture[TEXTURE_REMAINDER]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _danger_vx[0], sizeof(VERTEX_2D));
#endif
}

void CDraw::DrawMain()
{
#ifdef DX
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->SetFVF(FVF_VERTEX_2D);
#endif

	//---------------------�`��J�n---------------------
#ifdef DX
	if (SUCCEEDED(g_pd3dDevice->BeginScene())){
#endif
		DrawBg();

		//�w�i
		DrawBg();
		//�t�B�[���h
		DrawField();
		for (int i = 0; i < g_charcter_max[g_stage]; i++){
			//�L����
			DrawCharcter(i);
			//�X�e�[�^�X
			DrawStatus(i);
		}

		//�c��^�[��
		DrawClock();
		//�R�}���h
		DrawCommand();
		//�G�̃X�L���g�p
		DrawDanger();
		 
		//---------------------�`��I��---------------------
#ifdef DX
		g_pd3dDevice->EndScene();
	}
#endif

	// �o�b�N�o�b�t�@����v���C�}���o�b�t�@�ɓ]��
#ifdef DX
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
#endif
}

//-----�s���I���֌W-----//
void CBattleDraw::SetVx()
{

}
void CBattleDraw::SexTexture()
{

}

//---�s���I��---//
void CBattleDraw::DrawActionSelect()
{

}
//---�ΏۑI��---//
void CBattleDraw::DrawTargetSelect()
{

}
//---�X�g�b�N---//
void CBattleDraw::DrawStock(int _charcter_id)
{
	if (_charcter_id < g_ally_charcter_max[g_stage]){
		switch (g_charcter[_charcter_id].stock){
		case WHITE_STOCK:

			break;
		case BLUE_STOCK:

			break;
		case GREEN_STOCK:

			break;
		}
	}
}
