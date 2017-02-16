#pragma once

#define STOCK_CRRECTION ((float)g_charcter[_act_charcter_id].stock / 10.0f)	//ストックによる補正

//---コマンドID---//
enum eCommandId{
	ATTACK = 0,		//攻撃
	SKILL,		//特技
	ITEM,		//アイテム
	DEFENSE,	//防御
	COMMAND_MAX
};

//---コマンド補正値---//
enum eCommandCorrection{	
	ATTACK_ACTION = 0,
	SKILL_ACTION = 4,
	ITEM_ACTION = 2,
	DEFENSE_ACTION = 2
};

class CEnemyAI{
	//コマンド

	//タゲ

};

class CBattle{
	CBattleDraw bDraw;


	FILE* _fp;	//敵AI読み取り用
	/*
	ステージ別にAIファイル分け

	最長AIが入る用の配列を
	*/


	int _select_command;	//行動選択用
	int _select_target;		//対象選択用

	int _select_order[CHARCTER_MAX],	//行動選択順(キャラID)
	_charcter_action[CHARCTER_MAX][3],	//選択した行動([キャラID][0..コマンドID 1..対象(複数いれば桁を増やす) 2...コマンド補正値])
	_action_oder[CHARCTER_MAX];		//行動順(キャラID)
	
	int _count;	//swich内ループ用
	int _select;

	bool _select_flg;	//T...行動選択中
	bool _target_flg;	//T...対象選択中

	//---行動選択---//
	void SelectCommand(int _act_charcter);

	//---対象の始点---//
	int TargetReset(int _act_charcter);

	//---通常攻撃---//
	void ActionAttack(int _act_charcter_id);

	//---特技---//
	void ActionSkill(int _act_charcte_idr);

	//---アイテム---//
	void ActionItem(int _act_charcter_id);

	//---防御---//
	void ActionDefense(int _act_charcter_id);


public:
	//---行動の選択---//
	void SelectSort();
	void ActionSort();

	void BattleMain();

	CBattle(){
		_select_flg = false;
		_target_flg = false;
	}

	//---描画---//
	void BattleDrawMain();

};

