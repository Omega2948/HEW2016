#include"Main.h"

//------------------------//
//----------“ü—Í----------//
//------------------------//


CKey::CKey()
{
	for (int i = 0; i < Last_KeyNo; i++){
		PushFlg[i] = false;
		OldPushFlg[i] = false;
		HoldTime[i] = 0;
	}
}

bool CKey::InpKey(int VKey, int KeyNo)
{
	if (GetAsyncKeyState(VKey)){
		PushFlg[KeyNo] = true;
		if (OldPushFlg[KeyNo] == true){
			HoldTime[KeyNo] += 1;
		}
	}
	return PushFlg[KeyNo];
}

int CKey::HoleKey(int KeyNo)
{
	return HoldTime[KeyNo];
}

bool CKey::ReleaseKey(int VKey, int KeyNo)
{
	if (!InpKey(VKey, KeyNo)){
		if (OldPushFlg[KeyNo] == true && PushFlg[KeyNo] == false){
			return true;
		}
	}
	return false;
}


void CKey::SetUpKey()
{
	for (int i = 0; i < Last_KeyNo; i++){
		if (OldPushFlg[i] == true && PushFlg[i] == false){
			HoldTime[i] = 0;
		}
		OldPushFlg[i] = PushFlg[i];
		PushFlg[i] = false;
	}
}