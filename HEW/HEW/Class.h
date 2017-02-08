#pragma once

//-----���_���-----//
class VERTEX_2D{
public:
	float x;
	float y;
	float z;

	float rhw;

	D3DCOLOR diffuse;

	float tex_u;
	float tex_v;
};

//---�X�L��---//
class CSkill{
public:
	int id;			//ID
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

	int hp,	//�̗�
		pp,	//PP
		atk,	//���U
		def,	//���h
		Int,	//���U
		spd;	//�f����

	int cor_atk,	//���U�␳�l
		cor_def,	//���h�␳�l
		cor_Int;	//���U�␳�l

};

class CCharcter :public CStatus{
public:
	VERTEX_2D vx[4];

	CSkill Skill;

	int char_id;	//�L�����N�^�[ID(1���珸��)

	char job;	//�E

	char command;	//�A�N�V�����R�}���h
	char stock;	//�X�g�b�N
};