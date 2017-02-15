#pragma once

#define FIELD_SIZE (180.0f)	//フィールドのサイズ

#define FONT_U	(1/20)

//-----描画-----//
class CDraw{
	void SetTexture();
	VERTEX_2D _status_vx[CHARCTER_MAX][14][4],	//ステ表示用ポリゴン
		_bg_vx[4],	//背景描画用ポリゴン
		_charcter_vx[CHARCTER_MAX][4],	//キャラクター用ポリゴン
		_field_vx[2][4],	//キャラクター配置用マスポリゴン
		_clock_vx[2][4],	//[0]..背景 [1]&[2]数字
		_command_vx[5][4],	//[0]..背景 残り..各コマンド
		_danger_vx[4][4];	//[0]..背景 [1]..敵アイコン [2]..文字 [3]..残りカウント

	//---ステータス表示用ポリゴンのサイズ設定---//
	int VxSizeSet(int _j);
	void SetVertex();
	//---キャラクターの描画---//
	void DrawCharcter(int _char_no);
	//---ステータスの描画---//
	void DrawStatus(int _char_no);
	//---_status_vxの更新---//
	void UpdateStatusvx();
	//---背景の描画---//
	void DrawBg();
	//---フィールドの描画---//
	void DrawField();
	//---残りターン---//
	void DrawClock();
	//---コマンド---//
	void DrawCommand();
	//---敵のスキル使用---//
	void DrawDanger();
public:

	void DrawMain();
	CDraw(){
		SetTexture();
	}
};

//-----行動選択関係-----//
class CBattleDraw{
	VERTEX_2D _arrow_vx[4],		//選択矢印
	_stock_vx[CHARCTER_MAX][4];	//ストック

	void SetVx();
	void SexTexture();

	//---行動選択---//
	void DrawActionSelect();
	//---対象選択---//
	void DrawTargetSelect();
	//---ストック---//
	void DrawStock(int _charcter_id);
public:
	//---メイン---//
	void BattleDrawMain();

	CBattleDraw(){
		SetVx();
		SexTexture();
	};
};