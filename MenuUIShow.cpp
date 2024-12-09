#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataRegister* AppData = new AppDataRegister;

MenuUIShow::MenuUIShow()
{
	this->WindowSet = AppData->AppDataSent(TYPE_CFG, "WindowSize");
	UI->WinUICreat(this->WindowSet["Width"], this->WindowSet["Height"], this->WindowSet["CmdShow"]);
	UI->WinUITitleSet("BoardGame");
	UI->SetClass("BackGround");
	UI->SetScenes("Home");
	UI->PutIMG("HomeBG");
	this->PlayrTotal = 10;
}

void MenuUIShow::ScenesPlayerDataLoad(void)
{
}

void MenuUIShow::ScenesGameRotateDisplay(void)
{
}

void MenuUIShow::ScenesCardFunctionUsing(void)
{
}

void MenuUIShow::ScenesAttack(void)
{
}

int MenuUIShow::GetPlayerTotal(void) const
{
	return this->PlayrTotal;
}

MenuUIShow::~MenuUIShow()
{
	UI->WinUIUnRegister();
	delete AppData;
	delete UI;
}
