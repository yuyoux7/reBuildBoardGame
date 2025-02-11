#pragma once
#include "AppDataRegister.h"
#include "AppDataProcess.h"
#include "WinUIClass.h"
#include "ButtonClass.h"
#include "Player.h"
#include "log.h"
class MenuUIShow
{
public:
	MenuUIShow();
	Player::PlayerData ScenesPlayerDataLoad(void);
	void ScenesGameRotateDisplay(void);
	void ScenesCardFunctionUsing(void);
	void ScenesAttack(void);
	int GetPlayerTotal(void) const;
	void LogMix(Log_T *T);
	~MenuUIShow();
private:
	int PlayrTotal{};
	json WindowSet{};
	void exit(int i, string ET);
};

