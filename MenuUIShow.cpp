#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataRegister* AppData = new AppDataRegister;
AppDataProcess* tool = new AppDataProcess;
ButtonClass* Button = new ButtonClass;

MenuUIShow::MenuUIShow()
{
	bool NextScenes = false;
	IMAGE imgg;
	this->PlayrTotal = AppData->AppDataSent(TYPE_DFT, "MinPlayer");
	this->WindowSet = AppData->AppDataSent(TYPE_CFG, "WindowSize");
	std::string Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
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
	UI->SetClass("Number");
	UI->LoadIMG(Number_t, 1, &imgg);
	UI->PutIMG(952, 643, &imgg);
	while (!NextScenes)
	{
		if (UI->DispatchMSG().message == 0x00000201)
		{
			Button->ButtonInput(UI->DispatchMSG());
			if (Button->ButtonProcess("ReducePlayerCount"))
			{
				if (this->PlayrTotal > AppData->AppDataSent(TYPE_DFT, "MinPlayer"))
				{
					this->PlayrTotal--;
					UI->SetClass("Box");
					UI->PutIMG("PlayerTotalBox");
					UI->SetClass("Number");
					Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
					UI->LoadIMG(Number_t, 1, &imgg);
					UI->PutIMG(952, 643, &imgg);
				}
				while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
			}
			if (Button->ButtonProcess("AddPlayerCount"))
			{
				if (this->PlayrTotal < AppData->AppDataSent(TYPE_DFT, "MaxPlayer"))
				{
					this->PlayrTotal++;
					UI->SetClass("Box");
					UI->PutIMG("PlayerTotalBox");
					UI->SetClass("Number");
					if ((this->PlayrTotal) < 10)
					{
						Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						UI->PutIMG(952, 643, &imgg);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						UI->PutIMG(952, 643, &imgg);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						tool->setClass("Number");
						tool->setScenes("Home");
						UI->PutIMG(955 + (int)((double)tool->GetImageWidth(Number_t) * (double)tool->GetDisplayProportion(Number_t) * (double)UI->GetWindowZoomRatio()), 643, &imgg);
					}
					while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				}
			}
			if (Button->ButtonProcess("Start"))
			{
				UI->SetClass();
				UI->PutIMG("Block_Mask");
				UI->PutIMG("Start_Put");
				while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				Button->ButtonInput(UI->DispatchMSG());
				if (Button->ButtonProcess("Start"))
				{
					NextScenes = !NextScenes;
					break;
				}
				UI->PutIMG("Start");
			}
			std::cout << this->PlayrTotal << std::endl;
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
