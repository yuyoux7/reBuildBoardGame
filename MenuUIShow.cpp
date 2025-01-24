#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataRegister* AppData = new AppDataRegister;
ButtonClass* Button = new ButtonClass;

MenuUIShow::MenuUIShow()
{
	bool NextScenes = false;
	this->PlayrTotal = AppData->AppDataSent(TYPE_DFT, "MinPlayer");
	this->WindowSet = AppData->AppDataSent(TYPE_CFG, "WindowSize");
	UI->WinUICreat(this->WindowSet["Width"], this->WindowSet["Height"], this->WindowSet["CmdShow"]);
	UI->WinUITitleSet("BoardGame");
	Button->SetWindowZoomRatio(this->WindowSet["Width"], this->WindowSet["Height"]);
	UI->SetScenes("Home");
	Button->SetScenes("Home");
	UI->SetClass("BackGround");
	UI->PutIMG("HomeBG");
	UI->SetClass("Box");
	UI->PutIMG("PlayerTotalBox");
	UI->SetClass();
	UI->PutIMG("AddPlayerCount");
	UI->PutIMG("ReducePlayerCount");
	UI->PutIMG("Start");
	while (!NextScenes)
	{
		if (UI->DispatchMSG().message == 0x00000201)
		{
			if (Button->ButtonProcess("ReducePlayerCount"))
			{
				if (this->PlayrTotal > AppData->AppDataSent(TYPE_DFT, "MinPlayer"))
				{
					this->PlayrTotal--;
				}
			}
			if (Button->ButtonProcess("AddPlayerCount"))
			{
				if (this->PlayrTotal < AppData->AppDataSent(TYPE_DFT, "MaxPlayer"))
				{
					this->PlayrTotal++;
				}
			}
			if (Button->ButtonProcess("Start"))
			{
				UI->PutIMG("Block_Mask");
				UI->PutIMG("Start_Put");
				while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				if (Button->ButtonProcess("Start"))
				{
					NextScenes = !NextScenes;
					break;
				}
				UI->PutIMG("Start");
			}
		}
		Sleep(1);
	}
}

void MenuUIShow::ScenesPlayerDataLoad(void)
{
	UI->SetScenes("PlayerDataLoad");
	UI->SetClass("BackGround");
	UI->PutIMG("OtherBG");
	UI->SetClass("Box");
	UI->PutIMG("SetNameBox");
	UI->PutIMG("ExistValueBox");
	UI->PutIMG("IntellectValueBox");
	UI->PutIMG("AnchoredValueBox");
	UI->PutIMG("EffectValueBox");
	UI->PutIMG("UnderstandValueBox");
	UI->PutIMG("ObservatuonValueBox");
	UI->PutIMG("FourDiceValueBox");
	UI->PutIMG("SixDiceValueBox");
}

void MenuUIShow::ScenesGameRotateDisplay(void)
{
	UI->SetScenes("GameRotateDisplay");
	UI->SetClass("BackGround");
	UI->PutIMG("OtherBG");
	UI->SetClass("Text");
	UI->PutIMG("NextPlayer");
	UI->PutIMG("PlayerOrder");
	UI->SetClass("Box");
	UI->PutIMG("NowRoundBox");
}

void MenuUIShow::ScenesCardFunctionUsing(void)
{
	UI->SetScenes("CardFunctionUsing");
	UI->SetClass("BackGround");
	UI->PutIMG("OtherBG");
	UI->SetClass("Box");
	UI->PutIMG("NameBox");
	UI->PutIMG("ExistValueBox");
	UI->PutIMG("IntellectValueBox");
	UI->PutIMG("AnchoredValueBox");
	UI->PutIMG("EffectValueBox");
	UI->PutIMG("UnderstandValueBox");
	UI->PutIMG("ObservatuonValueBox");
	UI->PutIMG("HaveEffectBox");
	UI->PutIMG("NowRoundBox");
}

void MenuUIShow::ScenesAttack(void)
{
	UI->SetScenes("Attack");
	UI->SetClass("BackGround");
	UI->PutIMG("OtherBG");
	UI->SetClass("Box");
	UI->PutIMG("NameBox");
	UI->PutIMG("ExistValueBox");
	UI->PutIMG("IntellectValueBox");
	UI->PutIMG("AnchoredValueBox");
	UI->PutIMG("EffectValueBox");
	UI->PutIMG("UnderstandValueBox");
	UI->PutIMG("ObservatuonValueBox");
	UI->PutIMG("TagEffectBox");
	UI->PutIMG("AttackEffectBox");
	UI->PutIMG("NowRoundBox");
	UI->SetClass("Text");
	UI->PutIMG("PlayerAttack");
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
	delete Button;
}
