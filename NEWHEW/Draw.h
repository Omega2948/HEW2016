#pragma once

#define FIELD_SIZE (180.0f)	//�t�B�[���h�̃T�C�Y

#define FONT_U	(1/20)

//-----�`��-----//
class CDraw{
	void SetTexture();
	VERTEX_2D _status_vx[CHARCTER_MAX][14][4],	//�X�e�\���p�|���S��
		_bg_vx[4],	//�w�i�`��p�|���S��
		_charcter_vx[CHARCTER_MAX][4],	//�L�����N�^�[�p�|���S��
		_field_vx[2][4],	//�L�����N�^�[�z�u�p�}�X�|���S��
		_clock_vx[2][4],	//[0]..�w�i [1]&[2]����
		_command_vx[5][4],	//[0]..�w�i �c��..�e�R�}���h
		_danger_vx[4][4];	//[0]..�w�i [1]..�G�A�C�R�� [2]..���� [3]..�c��J�E���g

	//---�X�e�[�^�X�\���p�|���S���̃T�C�Y�ݒ�---//
	int VxSizeSet(int _j);
	void SetVertex();
	//---�L�����N�^�[�̕`��---//
	void DrawCharcter(int _char_no);
	//---�X�e�[�^�X�̕`��---//
	void DrawStatus(int _char_no);
	//---_status_vx�̍X�V---//
	void UpdateStatusvx();
	//---�w�i�̕`��---//
	void DrawBg();
	//---�t�B�[���h�̕`��---//
	void DrawField();
	//---�c��^�[��---//
	void DrawClock();
	//---�R�}���h---//
	void DrawCommand();
	//---�G�̃X�L���g�p---//
	void DrawDanger();
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