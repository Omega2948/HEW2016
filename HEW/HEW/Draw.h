#pragma once

//-----�`��-----//
class CDraw{
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

//-----�s���I���֌W-----//
class CBattleDraw{
	VERTEX_2D _arrow_vx[4],		//�I����
	_stock_vx[CHARCTER_MAX][4];	//�X�g�b�N

	void SetVx();
	void SexTexture();

	//---�s���I��---//
	void DrawActionSelect();
	//---�ΏۑI��---//
	void DrawTargetSelect();
	//---�X�g�b�N---//
	void DrawStock(int _charcter_id);
public:
	//---���C��---//
	void BattleDrawMain();

	CBattleDraw(){
		SetVx();
		SexTexture();
	};
};