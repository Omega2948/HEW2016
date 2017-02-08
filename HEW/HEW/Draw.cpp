#include"Main.h"
//-----ï`âÊ-----//

void CDraw::SetTexture()
{
	//---åïém---//
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char000.png", &_texture[0]))){
		exit(1);
	}
	//---ñÇèpét---//
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char001.png", &_texture[1]))){
		exit(1);
	}
	//---ã|ï∫---///
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char002.png", &_texture[2]))){
		exit(1);
	}
	//---èÇï∫---//
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/char003.png", &_texture[3]))){
		exit(1);
	}

	//---îwåi---//
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/bg000.png", &_texture[4]))){
		exit(1);
	}

}
void CDraw::SetVertex()
{
	for (int i = 0; i < CHARCTER_MAX; i++){
		//_status_vx[i][0].x = _status_vx[i][3].x = 0.0f;
		//_status_vx[i][1].x = _status_vx[i][2].x = SCREEN_WIDTH;

		//_status_vx[i][0].y = _status_vx[i][1].y = 0.0f;
		//_status_vx[i][2].y = _status_vx[i][3].y = SCREEN_HEIGHT;

		_status_vx[i][0].tex_u = _status_vx[i][3].tex_u = 0.0f;
		_status_vx[i][1].tex_u = _status_vx[i][2].tex_u = 1.0f;

		_status_vx[i][0].tex_v = _status_vx[i][1].tex_v = 0.0f;
		_status_vx[i][2].tex_v = _status_vx[i][3].tex_v = 1.0f;

		for (int i = 0; i < 4; i++){
			_status_vx[i][i].z = 0.0f;

			_status_vx[i][i].rhw = 1.0f;
			_status_vx[i][i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		}

		//_stock_vx[i][0].x = _stock_vx[i][3].x = 0.0f;
		//_stock_vx[i][1].x = _stock_vx[i][2].x = SCREEN_WIDTH;

		//_stock_vx[i][0].y = _stock_vx[i][1].y = 0.0f;
		//_stock_vx[i][2].y = _stock_vx[i][3].y = SCREEN_HEIGHT;

		_stock_vx[i][0].tex_u = _stock_vx[i][3].tex_u = 0.0f;
		_stock_vx[i][1].tex_u = _stock_vx[i][2].tex_u = 1.0f;

		_stock_vx[i][0].tex_v = _stock_vx[i][1].tex_v = 0.0f;
		_stock_vx[i][2].tex_v = _stock_vx[i][3].tex_v = 1.0f;

		for (int i = 0; i < 4; i++){
			_stock_vx[i][i].z = 0.0f;

			_stock_vx[i][i].rhw = 1.0f;
			_stock_vx[i][i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		}
	}

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

		_bg_vx[i].rhw = 1.0f;
		_bg_vx[i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	}
}


//---ÉLÉÉÉâÇÃï`âÊ---//
void CDraw::DrawCharcter(int _char_no)
{
	g_pd3dDevice->SetTexture(0, _texture[_char_no]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_charcter[_char_no].vx, sizeof(VERTEX_2D));
}

//---îwåiÇÃï`âÊ---//
void CDraw::DrawBg()
{
	g_pd3dDevice->SetTexture(0, _texture[4]);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _bg_vx, sizeof(VERTEX_2D));
}

//---ÉXÉeÅ[É^ÉXÇÃï`âÊ---//
void CDraw::DrawStatus(int _char_no)
{
	
}

void CDraw::DrawMain()
{
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->SetFVF(FVF_VERTEX_2D);

	if (SUCCEEDED(g_pd3dDevice->BeginScene())){
		DrawBg();

		for (int i = 0; i < g_charcter_max; i++){
			DrawCharcter(i);

			DrawStatus(i);
		}
		g_pd3dDevice->EndScene();
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
