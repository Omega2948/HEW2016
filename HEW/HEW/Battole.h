#pragma once

class CBattle{
	int _select_order[10],	//�s���I����
	_action_oder[10];		//�s����
	
	//---�ʏ�U��---//
	void SelectAttack();
	void ActionAttack();

	//---���Z---//
	void SelectSkill();
	void ActionSkill();

	//---�A�C�e��---//
	void SelectItem();
	void ActionItem();

	//---�h��---//
	void SelectDefense();
	void ActionDefense();

public:
	//---�s���̑I��---//
	void Select();
	void Action();

};