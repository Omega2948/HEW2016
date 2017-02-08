#pragma once

class CBattle{
	int _select_order[10],	//行動選択順
	_action_oder[10];		//行動順
	
	//---通常攻撃---//
	void SelectAttack();
	void ActionAttack();

	//---特技---//
	void SelectSkill();
	void ActionSkill();

	//---アイテム---//
	void SelectItem();
	void ActionItem();

	//---防御---//
	void SelectDefense();
	void ActionDefense();

public:
	//---行動の選択---//
	void Select();
	void Action();

};