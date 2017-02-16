#pragma once

//-----頂点情報-----//
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

//---スキル---//
class CSkill{
public:
	int cost;			//消費PP
	char target;		//スキルの対象
	char type;			//効果の種類
	float correction;	//スキルによる補正倍率
	char explanation;	//説明
};

//-----ステータス-----//
class CStatus{
public:
	int max_hp,	//HP最大値
		max_pp;	//PP最大値

	float hp,	//体力
		pp,	//PP
		atk,	//物攻
		def,	//物防
		Int,	//魔攻
		spd;	//素早さ

	float cor_atk,	//物攻補正値
		cor_def,	//物防補正値
		cor_Int;	//魔攻補正値

};

class CCharcter :public CStatus{
public:
	VERTEX_2D vx[4];

	CSkill Skill;

	int char_id;	//キャラクターID(0から昇順)

	char job;	//職

	char command;	//アクションコマンド
	char stock;	//ストック

	bool SG_flg;	//シールドガード
};