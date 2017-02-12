#pragma once

//-----描画-----//
class CDraw{
	void SetTexture();
	VERTEX_2D _status_vx[CHARCTER_MAX][4];	//HP、PP表示用ポリゴン
	VERTEX_2D _bg_vx[4];	//背景描画用ポリゴン
	VERTEX_2D _stock_vx[CHARCTER_MAX][4];	//背景描画用ポリゴン
	void SetVertex();
	//---キャラクターの描画---//
	void DrawCharcter(int _char_no);
	//---HP、PPの描画---//
	void DrawStatus(int _char_no);
	//---_status_vxの更新---//
	void UpdateStatusvx();
	//---背景の描画---//
	void DrawBg();


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