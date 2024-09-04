#pragma once
#include "AppDataRegister.h"
#include "AppDataProcess.h"
class MenuUIShow
{
public:
	MenuUIShow();
	void ScenesPlayerDataLoad(void);
	void ScenesGameRotateDisplay(void);
	void ScenesCardFunctionUsing(void);
	void ScenesAttack(void);
	int GetPlayerTotal(void);
private:
	int PlayrTotal{};
};

