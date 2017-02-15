#include"Main.h"


/*

�X�g�b�N�͖����̂�

�A���ŕ��ׂΊm��A�b�v


*/


//---�s���I��---//
void CBattle::SelectCommand(int _act_charcter)
{
	//---�R�}���h�̑I��---//
	if (!_select_flg){
		if (Key.ReleaseKey(VK_RETURN, ENTER_KEY)){
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

			_select_flg = true;
			_select_command = 0;

			_select_target = TargetReset(_act_charcter);
		}
		//---����---//
		if (PUSH_UP){
			_select_command++;
			if (_select_command > DEFENSE){
				_select_command = ATTACK;
			}
		}
		//---�����---//
		if (PUSH_DOWN){
			_select_command--;
			if (_select_command < ATTACK){
				_select_command = DEFENSE;
			}
		}
	}
	//---�Ώۂ̑I��---//
	else{
		switch (_select_command){
		case ATTACK:
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
			_charcter_action[_select_order[_act_charcter]][1] =
				g_charcter[_select_order[_act_charcter]].char_id;
			break;
		}
	}

}

//---�Ώۂ̎n�_---//
int CBattle::TargetReset(int _act_charcter)
{
	switch (_select_command){
	case ATTACK:
		switch (g_charcter[_select_order[_act_charcter]].job)
		{
		case SWORDSMAN:
			if (_field[1][0] > 0 ||
				_field[1][3] > 0 ||
				_field[1][6] > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count] > 0){
						return _count;
					}
				}
			}
			else if (_field[1][1] > 0 ||
				_field[1][4] > 0 ||
				_field[1][7] > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count + 1] > 0){
						return _count + 1;
					}
				}
			}
			else{
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count + 2] > 0){
						return _count + 2;
					}
				}
			}
			break;
		case MAGICIAN:
			for (_count = 0; _count < 9; _count++){
				if (_field[1][_count] > 0){
					return _count;
				}
			}
			break;
		case ARCHER:
			for (_count = 0; _count < 9; _count++){
				if (_field[1][_count] > 0){
					return _count;
				}
			}
			break;
		case SHIELDER:
			if (_field[1][0] > 0 ||
				_field[1][3] > 0 ||
				_field[1][6] > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count] > 0){
						return _count;
					}
				}
			}
			else if (_field[1][1] > 0 ||
				_field[1][4] > 0 ||
				_field[1][7] > 0){
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count + 1] > 0){
						return _count + 1;
					}
				}
			}
			else{
				for (_count = 0; _count < 9; _count += 3){
					if (_field[1][_count + 2] > 0){
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
			if (_field[0][_count] == _select_order[_act_charcter]){
				return _count;
			}
		}
		break;
	}

}


//---�ʏ�U��---//
void CBattle::ActionAttack(int _act_charcter_id)
{
	float _damage = ((g_charcter[_act_charcter_id].atk +
		g_charcter[_act_charcter_id].cor_atk) * STOCK_CRRECTION) -
		(g_charcter[_charcter_action[_act_charcter_id][1]].def +
		g_charcter[_charcter_action[_act_charcter_id][1]].cor_def);

	if (_damage < 1){
		_damage = 1;
	}

	g_charcter[_charcter_action[_act_charcter_id][1]].hp -= _damage;
}

//---���Z---//
void CBattle::ActionSkill(int _act_charcter_id)
{

}

//---�A�C�e��---//
void CBattle::ActionItem(int _act_charcter_id)
{

}

//---�h��---//
void CBattle::ActionDefense(int _act_charcter_id)
{
	g_charcter[_act_charcter_id].cor_def =
		g_charcter[_act_charcter_id].def *
		STOCK_CRRECTION;
}

//---�s���̑I��---//
void CBattle::SelectSort()
{
	int j = 0;
	//---SPD�ɂ��\�[�g---//
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
	//---SPD+�␳�l�ɂ��\�[�g---//
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
	//---�s���̑I��---//
	SelectCommand(_select);
}

//---���C��---//
void CBattle::BattleDrawMain()
{
	if (_select_flg){

	}
	else if (_target_flg){

	}
}
