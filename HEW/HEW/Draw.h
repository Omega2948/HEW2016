#pragma once

//-----`æ-----//
class CDraw{
	LPDIRECT3DTEXTURE9 _texture[5];	//eNX`
	void SetTexture();
	VERTEX_2D _status_vx[CHARCTER_MAX][4];	//HPAPP\¦p|S
	VERTEX_2D _bg_vx[4];	//wi`æp|S
	VERTEX_2D _stock_vx[CHARCTER_MAX][4];	//wi`æp|S
	void SetVertex();
	//---LN^[Ì`æ---//
	void DrawCharcter(int _char_no);
	//---HPAPPÌ`æ---//
	void DrawStatus(int _char_no);
	//---_status_vxÌXV---//
	void UpdateStatusvx();
	//---wiÌ`æ---//
	void DrawBg();
public:
	void DrawMain();
	CDraw(){
		SetTexture();
	}
};