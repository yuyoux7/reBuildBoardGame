#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataRegister* AppData = new AppDataRegister;
AppDataProcess* tool = new AppDataProcess;
ButtonClass* Button = new ButtonClass;
Player* player = nullptr;
Log_T TL;

MenuUIShow::MenuUIShow()
{
	UI->SetLog(&TL);
	bool NextScenes = false;
	IMAGE imgg;
	this->PlayrTotal = AppData->AppDataSent(TYPE_DFT, "MinPlayer");
	this->WindowSet = AppData->AppDataSent(TYPE_CFG, "WindowSize");
	string Number_t;
	UI->WinUICreat(this->WindowSet["Width"], this->WindowSet["Height"], this->WindowSet["CmdShow"]);
	UI->MixLog(&TL);
	UI->WinUITitleSet("BoardGame");
	UI->MixLog(&TL);
	TL.Text += (TimeToString(time(NULL)) + ": " + "WindowCraetSuccess\n");
	Button->SetWindowZoomRatio(this->WindowSet["Width"], this->WindowSet["Height"]);
	UI->SetScenes("Home");
	UI->MixLog(&TL);
	Button->SetScenes("Home");
	UI->SetClass("BackGround");
	UI->MixLog(&TL);
	UI->PutIMG("HomeBG");
	UI->MixLog(&TL);
	UI->SetClass("Box");
	UI->MixLog(&TL);
	UI->PutIMG("PlayerTotalBox");
	UI->MixLog(&TL);
	UI->SetClass();
	UI->MixLog(&TL);
	UI->PutIMG("AddPlayerCount");
	UI->MixLog(&TL);
	UI->PutIMG("ReducePlayerCount");
	UI->MixLog(&TL);
	UI->PutIMG("Start");
	UI->MixLog(&TL);
	UI->SetClass("Number");
	UI->MixLog(&TL);
	if (this->PlayrTotal >= 10)
	{
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
		UI->LoadIMG(Number_t, 1, &imgg);
		UI->MixLog(&TL);
		UI->PutIMG(952, 643, &imgg);
		UI->MixLog(&TL);
		TL.Text += (TimeToString(time(NULL)) + ": " + "Default Player Count: " + (char)((this->PlayrTotal / 10) ^ 48));
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
		UI->LoadIMG(Number_t, 1, &imgg);
		UI->MixLog(&TL);
		tool->setClass("Number");
		tool->setScenes("Home");
		UI->PutIMG(955 + (int)((double)tool->GetImageWidth(Number_t) * (double)tool->GetDisplayProportion(Number_t) * (double)UI->GetWindowZoomRatio()), 643, &imgg);
		UI->MixLog(&TL);
		TL.Text += ((char)((this->PlayrTotal % 10) ^ 48) + (string)"\n");
	}
	else
	{
		Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
		UI->LoadIMG(Number_t, 1, &imgg);
		UI->MixLog(&TL);
		UI->PutIMG(952, 643, &imgg);
		UI->MixLog(&TL);
		TL.Text += (TimeToString(time(NULL)) + ": " + "Default Player Count: " + (char)((this->PlayrTotal) ^ 48) + (string)"\n");
	}
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
					UI->MixLog(&TL);
					UI->PutIMG("PlayerTotalBox");
					UI->MixLog(&TL);
					UI->SetClass("Number");
					UI->MixLog(&TL);
					if ((this->PlayrTotal) < 10)
					{
						Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						tool->setClass("Number");
						UI->MixLog(&TL);
						tool->setScenes("Home");
						UI->MixLog(&TL);
						UI->PutIMG(955 + (int)((double)tool->GetImageWidth(Number_t) * (double)tool->GetDisplayProportion(Number_t) * (double)UI->GetWindowZoomRatio()), 643, &imgg);
					}
					TL.Text += (TimeToString(time(NULL)) + ": " + "PlayerCountLow" + (string)"\n");
					while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				}
			}
			if (Button->ButtonProcess("AddPlayerCount"))
			{
				if (this->PlayrTotal < AppData->AppDataSent(TYPE_DFT, "MaxPlayer"))
				{
					this->PlayrTotal++;
					UI->SetClass("Box");
					UI->MixLog(&TL);
					UI->PutIMG("PlayerTotalBox");
					UI->MixLog(&TL);
					UI->SetClass("Number");
					UI->MixLog(&TL);
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
						UI->MixLog(&TL);
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, 1, &imgg);
						UI->MixLog(&TL);
						tool->setClass("Number");
						tool->setScenes("Home");
						UI->PutIMG(955 + (int)((double)tool->GetImageWidth(Number_t) * (double)tool->GetDisplayProportion(Number_t) * (double)UI->GetWindowZoomRatio()), 643, &imgg);
						UI->MixLog(&TL);
					}
					TL.Text += (TimeToString(time(NULL)) + ": " + "PlayerCountUp" + (string)"\n");
					while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				}
			}
			if (Button->ButtonProcess("Start"))
			{
				UI->SetClass();
				UI->MixLog(&TL);
				UI->PutIMG("Block_Mask");
				UI->MixLog(&TL);
				UI->PutIMG("Start_Put");
				UI->MixLog(&TL);
				TL.Text += (TimeToString(time(NULL)) + ": " + "HomeStartButtonPush" + (string)"\n");
				while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				Button->ButtonInput(UI->DispatchMSG());
				if (Button->ButtonProcess("Start"))
				{
					NextScenes = !NextScenes;
					TL.Text += (TimeToString(time(NULL)) + ": " + "GamePlayerTotle: " + TimeToString(this->PlayrTotal) + (string)"\n");
					player = (Player*)malloc(sizeof(Player) * this->PlayrTotal);
					break;
				}
				TL.Text += (TimeToString(time(NULL)) + ": " + "HomeStartButtonBack" + (string)"\n");
				UI->PutIMG("Start");
				UI->MixLog(&TL);
			}
		}
		Sleep(1);
	}
}

void MenuUIShow::ScenesPlayerDataLoad(void)
{
	UI->SetLog(&TL);
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
	while (1);
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

void MenuUIShow::LogMix(Log_T *T)
{
	T->Text += TL.Text;
	TL.Text = T->Text;
	TL.LogPath = T->LogPath;
}

MenuUIShow::~MenuUIShow()
{
	UI->WinUIUnRegister();
	free(player);
	delete AppData;
	delete UI;
	delete Button;
	delete tool;
}
