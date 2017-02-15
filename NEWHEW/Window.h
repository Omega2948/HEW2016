#pragma once

class CWindow{
	//---ウィンドウサイズのポリゴン---//
	VERTEX_2D _window[4];
	//---テクスチャ [0]-タイトル [1]-リザルト---//
	LPDIRECT3DTEXTURE9 texture[2];

	//---頂点情報の初期化---//
	void SetupVx();
	//---テクスチャの初期化---//
	void SetupTextre();
public:
	//---タイトルの描画---//
	void DrawTitle();
	//---リザルト画面の描画---//
	void DrawResult();

	CWindow(){
		SetupVx();
		SetupTextre();
	};
};