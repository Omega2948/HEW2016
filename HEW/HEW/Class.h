#pragma once

//-----���_���-----//
class VERTEX_2D{
public:
	float x;
	float y;
	float z;

#ifdef DX
	float rhw;
	D3DCOLOR diffuse;
#endif

	float tex_u;
	float tex_v;
};

//---�X�L��---//
class CSkill{
public:
	int cost;			//����PP
	char target;		//�X�L���̑Ώ�
	char type;			//���ʂ̎��
	float correction;	//�X�L���ɂ��␳�{��
	char explanation;	//����
};

//-----�X�e�[�^�X-----//
class CStatus{
public:
	int max_hp,	//HP�ő�l
		max_pp;	//PP�ő�l

	float hp,	//�̗�
		pp,	//PP
		atk,	//���U
		def,	//���h
		Int,	//���U
		spd;	//�f����

	float cor_atk,	//���U�␳�l
		cor_def,	//���h�␳�l
		cor_Int;	//���U�␳�l

};

class CCharcter :public CStatus{
public:
	VERTEX_2D vx[4];

	CSkill Skill;

	int char_id;	//�L�����N�^�[ID(0���珸��)

	char job;	//�E

	char command;	//�A�N�V�����R�}���h
	char stock;	//�X�g�b�N

	bool SG_flg;	//�V�[���h�K�[�h
};