#pragma once

//-----�`��-----//
class CDraw{
	LPDIRECT3DTEXTURE9 _texture[5];	//�e�N�X�`��
	void SetTexture();
	VERTEX_2D _status_vx[CHARCTER_MAX][4];	//HP�APP�\���p�|���S��
	VERTEX_2D _bg_vx[4];	//�w�i�`��p�|���S��
	VERTEX_2D _stock_vx[CHARCTER_MAX][4];	//�w�i�`��p�|���S��
	void SetVertex();
	//---�L�����N�^�[�̕`��---//
	void DrawCharcter(int _char_no);
	//---HP�APP�̕`��---//
	void DrawStatus(int _char_no);
	//---_status_vx�̍X�V---//
	void UpdateStatusvx();
	//---�w�i�̕`��---//
	void DrawBg();
public:
	void DrawMain();
	CDraw(){
		SetTexture();
	}
};