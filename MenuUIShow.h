#pragma once
#include "AppDataRegister.h"
#include "AppDataProcess.h"
#include "WinUIClass.h"
class MenuUIShow
{
public:
	MenuUIShow();
	void ScenesPlayerDataLoad(void);
	void ScenesGameRotateDisplay(void);
	void ScenesCardFunctionUsing(void);
	void ScenesAttack(void);
	int GetPlayerTotal(void) const;
	~MenuUIShow();
private:
	int PlayrTotal{};
	json WindowSet{};
};

