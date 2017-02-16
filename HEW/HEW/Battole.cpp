#include"Main.h"


/*

ストックは味方のみ

連続で並べば確定アップ


*/


//---行動選択---//
void CBattle::SelectCommand(int _act_charcter)
{
	//---コマンドの選択---//
	if (!_select_flg){
		if (PUSH_A){
			_charcter_action[_act_charcter][0] = _select_command;
			
			switch (_select_command){
			case ATTACK:
				_charcter_action[_act_charcter][2] = ATTACK_ACTION;
				break;
			case SKILL:
				if (g_charcter[_act_charcter].job != SHIELDER){
					_charcter_action[_act_charcter][2] = SKILL_ACTION;
				}
				else{
					_charcter_action[_act_charcter][2] = 100;
				}
				break;
			case ITEM:
				_charcter_action[_act_charcter][2] = ITEM_ACTION;
				break;
			case DEFENSE:
				_charcter_action[_act_charcter][2] = DEFENSE_ACTION;
				break;
			}

			
			_select_flg = false;
			_select_command = 0;

			_select_target = TargetReset(_act_charcter);
			_target_flg = true;
		}
		//---一つ上に---//
		if (PUSH_UP){
			_select_command++;
			if (_select_command > DEFENSE){
				_select_command = ATTACK;
			}
		}
		//---一つ下に---//
		if (PUSH_DOWN){
			_select_command--;
			if (_select_command < ATTACK){
				_select_command = DEFENSE;
			}
		}
	}
	//---対象の選択---//
	else{
		switch (_select_command){
		case ATTACK:
			switch (g_charcter[_select_order[_act_charcter]].job)
			{
			case SWORDSMAN:
				if (PUSH_A){
					_charcter_action[_act_charcter][1] = _select_target;
					_select_flg = false;
				}
				if (PUSH_UP){
					for (_count = -3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count -= 3){
						if (_select_target + _count < 0){
							_count += 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_DOWN){
					for (_count = 3; g_field[1][_select_target + _count] > 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count += 3){
						if (_select_target + _count < 0){
							_count -= 9;
						}
					}
					_select_target += _count;
				}
				break;
			case MAGICIAN:
				if (PUSH_A){
					_charcter_action[_act_charcter][1] = _select_target;
					_select_flg = false;
				}
				if (PUSH_UP){
					for (_count = -3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count -= 3){
						if (_select_target + _count < 0){
							_count += 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_DOWN){
					for (_count = 3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count += 3){
						if (_select_target + _count < 0){
							_count -= 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_RIGHT){
					for (_count = 1; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count++){
						if ((_select_target + _count) / 3 != (_select_target + _count - 1) / 3){
							_count -= 3;
						}
					}
					_select_target += _count;
				}
				if (PUSH_LEFT){
					for (_count = -1; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count--){
						if ((_select_target + _count) / 3 != (_select_target + _count + 1) / 3){
							_count += 3;
						}
					}
					_select_target += _count;
				}
				break;
			case ARCHER:
				if (PUSH_A){
					_charcter_action[_act_charcter][1] = _select_target;
					_select_flg = false;
				}
				if (PUSH_UP){
					for (_count = -3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count -= 3){
						if (_select_target + _count < 0){
							_count += 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_DOWN){
					for (_count = 3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count += 3){
						if (_select_target + _count < 0){
							_count -= 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_RIGHT){
					for (_count = 1; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count++){
						if ((_select_target + _count) / 3 != (_select_target + _count - 1) / 3){
							_count -= 3;
						}
					}
					_select_target += _count;
				}
				if (PUSH_LEFT){
					for (_count = -1; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count--){
						if ((_select_target + _count) / 3 != (_select_target + _count + 1) / 3){
							_count += 3;
						}
					}
					_select_target += _count;
				}
				break;
			case SHIELDER:
				if (PUSH_A){
					_charcter_action[_act_charcter][1] = _select_target;
					_select_flg = false;
				}
				if (PUSH_UP){
					for (_count = -3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count -= 3){
						if (_select_target + _count < 0){
							_count += 9;
						}
					}
					_select_target += _count;
				}
				if (PUSH_DOWN){
					for (_count = 3; g_field[1][_select_target + _count] < 0 && g_charcter[g_field[1][_select_target + _count]].hp > 0; _count += 3){
						if (_select_target + _count < 0){
							_count -= 9;
						}
					}
					_select_target += _count;
				}
				break;
			}
			break;
		case SKILL:
			switch (g_charcter[_select_order[_act_charcter]].job)
			{
			case SWORDSMAN:

				break;
			case MAGICIAN:

				break;
			case ARCHER:
				if (PUSH_A){
					_select_flg = false;
				}
				break;
			case SHIELDER:
				if (PUSH_A){
					_select_flg = false;
				}
				break;
			}
			break;
		case ITEM:

			break;
		case DEFENSE:
			_charcter_action[_select_order[_act_charcter]][1] =
				g_charcter[_select_order[_act_charcter]].char_id;
			break;
		}
	}

}

//---対象の始点---//
int CBattle::TargetReset(int _act_charcter)
{
	switch (_select_command){
	case ATTACK:
		switch (g_charcter[_select_order[_act_charcter]].job)
		{
		case SWORDSMAN:
			if (g_field[1][0] > 0 && g_charcter[g_field[1][0]].hp > 0 ||
				g_field[1][3] > 0 && g_charcter[g_field[1][3]].hp > 0 ||
				g_field[1][6] > 0 && g_charcter[g_field[1][6]].hp > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count] < 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count;
					}
				}
			}
			else if (g_field[1][1] > 0 && g_charcter[g_field[1][1]].hp > 0 ||
				g_field[1][4] > 0 && g_charcter[g_field[1][4]].hp > 0 ||
				g_field[1][7] > 0 && g_charcter[g_field[1][7]].hp > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count + 1] > 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count + 1;
					}
				}
			}
			else{
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count + 2] > 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count + 2;
					}
				}
			}
			break;
		case MAGICIAN:
			for (_count = 0; _count < 9; _count++){
				if (g_field[1][_count] > 0 && g_charcter[g_field[1][_count]].hp > 0){
					return _count;
				}
			}
			break;
		case ARCHER:
			for (_count = 0; _count < 9; _count++){
				if (g_field[1][_count] > 0 && g_charcter[g_field[1][_count]].hp > 0){
					return _count;
				}
			}
			break;
		case SHIELDER:
			if (g_field[1][0] > 0 && g_charcter[g_field[1][0]].hp > 0 ||
				g_field[1][3] > 0 && g_charcter[g_field[1][3]].hp > 0 ||
				g_field[1][6] > 0 && g_charcter[g_field[1][6]].hp > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count] < 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count;
					}
				}
			}
			else if (g_field[1][1] > 0 && g_charcter[g_field[1][1]].hp > 0 ||
				g_field[1][4] > 0 && g_charcter[g_field[1][4]].hp > 0 ||
				g_field[1][7] > 0 && g_charcter[g_field[1][7]].hp > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count + 1] > 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count + 1;
					}
				}
			}
			else{
				for (_count = 0; _count < 9; _count += 3){
					if (g_field[1][_count + 2] > 0 && g_charcter[g_field[1][_count]].hp > 0){
						return _count + 2;
					}
				}
			}
			break;
		}
		break;
	case SKILL:
		switch (g_charcter[_select_order[_act_charcter]].job)
		{
		case SWORDSMAN:

			break;
		case MAGICIAN:

			break;
		case ARCHER:

			break;
		case SHIELDER:

			break;
		}
		break;
	case ITEM:

		break;
	case DEFENSE:
		for (_count = 0; _count < 9; _count++){
			if (g_field[0][_count] == _select_order[_act_charcter]){
				return _count;
			}
		}
		break;
	}

}


//---通常攻撃---//
void CBattle::ActionAttack(int _act_charcter_id)
{
	float _damage = ((g_charcter[_act_charcter_id].atk +
		g_charcter[_act_charcter_id].cor_atk) * STOCK_CRRECTION) -
		(g_charcter[_charcter_action[_act_charcter_id][1]].def +
		g_charcter[_charcter_action[_act_charcter_id][1]].cor_def);

	if (_damage < 1){
		_damage = 1;
	}

	if (g_charcter[_charcter_action[_act_charcter_id][1]].SG_flg){
		_damage /= 2;
	}
	g_charcter[_charcter_action[_act_charcter_id][1]].hp -= (int)_damage;
}

//---特技---//
void CBattle::ActionSkill(int _act_charcter_id)
{
	float _damage;
	int wari, ans;
	switch (g_charcter[_act_charcter_id].job)
	{
	case SWORDSMAN:
		wari = 100;
		for (_count = 0; _count < 3; _count++){
			ans = _charcter_action[_act_charcter_id][1] / wari;
			if (ans > 0){
				_damage = ((g_charcter[_act_charcter_id].atk +
					g_charcter[_act_charcter_id].cor_atk) * STOCK_CRRECTION) -
					(g_charcter[_charcter_action[_act_charcter_id][1]].def +
					g_charcter[_charcter_action[_act_charcter_id][1]].cor_def);

				if (_damage < 1){
					_damage = 1;
				}

				if (g_charcter[_charcter_action[_act_charcter_id][1]].SG_flg){
					_damage /= 2;
				}
				g_charcter[_charcter_action[_act_charcter_id][1]].hp -= (int)_damage;
			}
			_charcter_action[_act_charcter_id][1] -= ans * wari;
			wari /= 10;
		}
		break;
	case MAGICIAN:
		wari = 10000;
		for (_count = 0; _count < 3; _count++){
			ans = _charcter_action[_act_charcter_id][1] / wari;
			if (ans > 0){
				_damage = ((g_charcter[_act_charcter_id].atk +
					g_charcter[_act_charcter_id].cor_atk) * STOCK_CRRECTION) -
					(g_charcter[_charcter_action[_act_charcter_id][1]].def +
					g_charcter[_charcter_action[_act_charcter_id][1]].cor_def);

				if (_damage < 1){
					_damage = 1;
				}

				if (g_charcter[_charcter_action[_act_charcter_id][1]].SG_flg){
					_damage /= 2;
				}
				g_charcter[_charcter_action[_act_charcter_id][1]].hp -= (int)_damage;
			}
			_charcter_action[_act_charcter_id][1] -= ans * wari;
			wari /= 10;
		}
		break;
	case ARCHER:
		for (_count = g_ally_charcter_max[g_stage]; _count < g_charcter_max[g_stage]; _count++){
			if (g_charcter[_count].hp > 0){
				_damage = ((g_charcter[_act_charcter_id].atk +
					g_charcter[_act_charcter_id].cor_atk) * STOCK_CRRECTION) -
					(g_charcter[_count].def + g_charcter[_count].cor_def);
			
				if (_damage < 1){
					_damage = 1;
				}

				if (g_charcter[_count].SG_flg){
					_damage /= 2;
				}
				g_charcter[_count].hp -= (int)_damage;
			}
		}
		break;
	case SHIELDER:
		for (_count = 0; _count < g_ally_charcter_max[g_stage]; _count++){
			if (g_charcter[_count].hp > 0){
				g_charcter[_count].SG_flg = true;
			}
		}
		break;
	}
}

//---アイテム---//
void CBattle::ActionItem(int _act_charcter_id)
{

}

//---防御---//
void CBattle::ActionDefense(int _act_charcter_id)
{
	g_charcter[_act_charcter_id].cor_def =
		g_charcter[_act_charcter_id].def *
		STOCK_CRRECTION;
}

//---行動の選択---//
void CBattle::SelectSort()
{
	int j = 0;
	//---SPDによるソート---//
	for (int i = 0; i < g_charcter_max[g_stage]; i++){
		for (j = 0; j < i; j++){
			if (g_charcter[_select_order[j]].spd >=
				g_charcter[i].spd){
				break;
			}
		}
		_select_order[j] = g_charcter[i].char_id;
	}

}

void CBattle::ActionSort()
{
	int j = 0;
	//---SPD+補正値によるソート---//
	for (int i = 0; i < g_charcter_max[g_stage]; i++){
		for (j = 0; j < i; j++){
			if (g_charcter[_select_order[j]].spd + _charcter_action[j][2] >
				g_charcter[i].spd + _charcter_action[i][2]){
				break;
			}
		}
		_select_order[j] = g_charcter[i].char_id;
	}

}

void CBattle::BattleMain()
{
	//---行動の選択---//
	SelectCommand(_select);
}

//---メイン---//
void CBattle::BattleDrawMain()
{
	if (_select_flg){

	}
	else if (_target_flg){

	}
}
