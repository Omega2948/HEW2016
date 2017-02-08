#pragma once

enum KeyNo{
	A_KEY = 0,
	B_KEY,
	C_KEY,
	D_KEY,
	E_KEY,
	F_KEY,
	G_KEY,
	H_KEY,
	I_KEY,
	J_KEY,
	K_KEY,
	L_KEY,
	M_KEY,
	N_KEY,
	O_KEY,
	P_KEY,
	Q_KEY,
	R_KEY,
	S_KEY,
	T_KEY,
	U_KEY,
	V_KEY,
	W_KEY,
	X_KEY,
	Y_KEY,
	Z_KEY,
	UP_KEY,
	DOWN_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	ENTER_KEY,
	Last_KeyNo
};

class CKey{
	bool PushFlg[Last_KeyNo], OldPushFlg[Last_KeyNo];
	int HoldTime[Last_KeyNo];
public:
	CKey();
	bool InpKey(int VKey, int KeyNo);
	int HoleKey(int KeyNo);
	bool ReleaseKey(int VKey, int KeyNo);
	void SetUpKey();
};

#ifdef MAIN
CKey Key;
#else
extern CKey Key;
#endif // KEY

