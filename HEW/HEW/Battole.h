#pragma once

#define STOCK_CRRECTION ((float)g_charcter[_act_charcter_id].stock / 10.0f)	//�X�g�b�N�ɂ��␳

//---�R�}���hID---//
enum eCommandId{
	ATTACK = 0,		//�U��
	SKILL,		//���Z
	ITEM,		//�A�C�e��
	DEFENSE,	//�h��
	COMMAND_MAX
};

//---�R�}���h�␳�l---//
enum eCommandCorrection{	
	ATTACK_ACTION = 0,
	SKILL_ACTION = 4,
	ITEM_ACTION = 2,
	DEFENSE_ACTION = 2
};

class CEnemyAI{
	//�R�}���h

	//�^�Q

};

class CBattle{
	CBattleDraw bDraw;


	FILE* _fp;	//�GAI�ǂݎ��p
	/*
	�X�e�[�W�ʂ�AI�t�@�C������

	�Œ�AI������p�̔z���
	*/


	int _select_command;	//�s���I��p
	int _select_target;		//�ΏۑI��p

	int _select_order[CHARCTER_MAX],	//�s���I����(�L����ID)
	_charcter_action[CHARCTER_MAX][3],	//�I�������s��([�L����ID][0..�R�}���hID 1..�Ώ�(��������Ό��𑝂₷) 2...�R�}���h�␳�l])
	_action_oder[CHARCTER_MAX];		//�s����(�L����ID)
	
	int _count;	//swich�����[�v�p
	int _select;

	bool _select_flg;	//T...�s���I��
	bool _target_flg;	//T...�ΏۑI��

	//---�s���I��---//
	void SelectCommand(int _act_charcter);

	//---�Ώۂ̎n�_---//
	int TargetReset(int _act_charcter);

	//---�ʏ�U��---//
	void ActionAttack(int _act_charcter_id);

	//---���Z---//
	void ActionSkill(int _act_charcte_idr);

	//---�A�C�e��---//
	void ActionItem(int _act_charcter_id);

	//---�h��---//
	void ActionDefense(int _act_charcter_id);


public:
	//---�s���̑I��---//
	void SelectSort();
	void ActionSort();

	void BattleMain();

	CBattle(){
		_select_flg = false;
		_target_flg = false;
	}

	//---�`��---//
	void BattleDrawMain();

};

