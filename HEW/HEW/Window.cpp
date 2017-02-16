#include"Window.h"

//---頂点情報の初期化---//
void CWindow::SetupVx()
{
#ifdef DX
	_window[0].x = _window[3].x = 0.0f;
	_window[1].x = _window[2].x = SCREEN_WIDTH;

	_window[0].y = _window[1].y = 0.0f;
	_window[2].y = _window[3].y = SCREEN_HEIGHT;

	_window[0].tex_u = _window[3].tex_u = 0.0f;
	_window[1].tex_u = _window[2].tex_u = 1.0f;

	_window[0].tex_v = _window[1].tex_v = 0.0f;
	_window[2].tex_v = _window[3].tex_v = 1.0f;

	for (int i = 0; i < 4; i++){
		_window[i].z = 0.0f;

		_window[i].rhw = 1.0f;
		_window[i].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	}
#endif
}

//---テクスチャの初期化---//
void CWindow::SetupTextre()
{
#ifdef DX
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/title000.png", &texture[0]))){
		exit(1);
	}

	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "data/result000.png", &texture[1]))){
		exit(1);
	}
#endif
}

//---タイトルの描画---//
void CWindow::DrawTitle()
{
#ifdef DX
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->SetFVF(FVF_VERTEX_2D);

	if (SUCCEEDED(g_pd3dDevice->BeginScene())){
		g_pd3dDevice->SetTexture(0, texture[0]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _window, sizeof(VERTEX_2D));

		g_pd3dDevice->EndScene();
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
#endif
}
//---リザルト画面の描画---//
void CWindow::DrawResult()
{
#ifdef DX
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->SetFVF(FVF_VERTEX_2D);

	if (SUCCEEDED(g_pd3dDevice->BeginScene())){
		g_pd3dDevice->SetTexture(0, texture[1]);
		g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _window, sizeof(VERTEX_2D));

		g_pd3dDevice->EndScene();
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
#endif
}