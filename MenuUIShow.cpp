#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataProcess* AppData = new AppDataProcess;
ButtonClass* Button = new ButtonClass;
Player::PlayerData* player = new Player::PlayerData;
Player* PlayCtrlTool = new Player;
Log_T TL;
AppDataProcess::Link LinkToken;
int rd = static_cast<int>(time(NULL));

MenuUIShow::MenuUIShow()
{
	srand(rd);
	UI->SetLog(&TL);
	IMAGE imgg;
	if (AppData->AppDataSent(TYPE_DFT, "MinPlayer") > AppData->AppDataSent(TYPE_DFT, "MaxPlayer"))
	{
		exit(-2, "Player Count Break");
	}
	this->PlayrTotal = AppData->AppDataSent(TYPE_DFT, "MinPlayer");
	this->WindowSet = AppData->AppDataSent(TYPE_CFG, "WindowSize");
	string Number_t;
	UI->WinUICreat(this->WindowSet["Width"], this->WindowSet["Height"], this->WindowSet["CmdShow"]);
	UI->MixLog(&TL);
	UI->WinUITitleSet("BoardGame");
	UI->MixLog(&TL);
	BeginBatchDraw();
	TL.Text += " " + (TimeToString(time(NULL)) + ": " + "WindowCraetSuccess\n");
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
	AppData->setClass("Number");
	AppData->setScenes("Home");
	LinkToken.LinkID = "NumberLink";
	LinkToken.LinkSourceLocal = 0;
	AppData->LinkIMG(&LinkToken);
	if (this->PlayrTotal >= 10)
	{
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
		UI->MixLog(&TL);
		TL.Text += " " + (TimeToString(time(NULL)) + ": " + "Default Player Count: " + (char)((this->PlayrTotal / 10) ^ 48));
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		UI->PutIMG((LinkToken.DisplayWidth + AppData->GetImageWidth(Number_t)), LinkToken.DisplayHeight, &imgg);
		UI->MixLog(&TL);
		TL.Text += ((char)((this->PlayrTotal % 10) ^ 48) + (string)"\n");
	}
	else
	{
		Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
		UI->MixLog(&TL);
		TL.Text += " " + (TimeToString(time(NULL)) + ": " + "Default Player Count: " + (char)((this->PlayrTotal) ^ 48) + (string)"\n");
	}
	FlushBatchDraw();
	while (true)
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
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
						UI->MixLog(&TL);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG((LinkToken.DisplayWidth + AppData->GetImageWidth(Number_t)), LinkToken.DisplayHeight, &imgg);
						UI->MixLog(&TL);
					}
					TL.Text += " " + (TimeToString(time(NULL)) + ": " + "PlayerCountLow" + (string)"\n");
					FlushBatchDraw();
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
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG((LinkToken.DisplayWidth + AppData->GetImageWidth(Number_t)), LinkToken.DisplayHeight, &imgg);
						UI->MixLog(&TL);
					}
					TL.Text += " " + (TimeToString(time(NULL)) + ": " + "PlayerCountUp" + (string)"\n");
					FlushBatchDraw();
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
				TL.Text += " " + (TimeToString(time(NULL)) + ": " + "HomeStartButtonPush" + (string)"\n");
				FlushBatchDraw();
				while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
				Button->ButtonInput(UI->DispatchMSG());
				if (Button->ButtonProcess("Start"))
				{
					TL.Text += " " + (TimeToString(time(NULL)) + ": " + "GamePlayerTotle: " + TimeToString(this->PlayrTotal) + (string)"\n");
					break;
				}
				TL.Text += " " + (TimeToString(time(NULL)) + ": " + "HomeStartButtonBack" + (string)"\n");
				UI->PutIMG("Start");
				UI->MixLog(&TL);
			}
		}
		Sleep(1);
		FlushBatchDraw();
	}
	EndBatchDraw();
}

Player::PlayerData MenuUIShow::ScenesPlayerDataLoad(void)
{
	Player::PlayerData FlashPlayerData;
	BeginBatchDraw();
	UI->SetLog(&TL); 
	{
		UI->SetScenes("PlayerDataLoad");
		UI->SetClass("BackGround");
		UI->PutIMG("OtherBG");
		UI->SetClass("Box");
		Button->SetScenes("PlayerDataLoad");
		UI->PutIMG("SetNameBox");
		UI->PutIMG("ExistValueBox");
		UI->PutIMG("IntellectValueBox");
		UI->PutIMG("AnchoredValueBox");
		UI->PutIMG("EffectValueBox");
		UI->PutIMG("UnderstandValueBox");
		UI->PutIMG("ObservatuonValueBox");
		UI->PutIMG("FourDiceValueBox");
		UI->PutIMG("SixDiceValueBox");
		UI->SetClass();
		UI->PutIMG("Race_People");
		UI->PutIMG("Race_God");
		UI->PutIMG("Race_Monster");
		UI->PutIMG("Race_OutPeople");
		UI->PutIMG("Race_ThinkingPeople");
		UI->PutIMG("Race_Elf");
		UI->PutIMG("Race_Bug");
		UI->PutIMG("Race_NoSaveMonster");
		UI->PutIMG("Rand");
	}
	FlashPlayerData.Name[0] = ((rand() % 40) + 1);
	FlashPlayerData.Name[1] = ((rand() % 40) + 1);
	UI->SetClass("Name");
	AppData->setClass("Name");
	AppData->setScenes("PlayerDataLoad");
	LinkToken.LinkID = "NameLink";
	LinkToken.LinkSourceLocal = 0;
	AppData->LinkIMG(&LinkToken);
	IMAGE FlashIMG{};
	string Name_t{};
	string Adj_t{};
	if (FlashPlayerData.Name[0] < 10)
	{
		Adj_t = string("Adj0" + TimeToString(FlashPlayerData.Name[0]));
	}
	else
	{
		Adj_t = string("Adj" + TimeToString(FlashPlayerData.Name[0]));
	}
	if (FlashPlayerData.Name[1] < 10)
	{
		Name_t = string("Name0" + TimeToString(FlashPlayerData.Name[1]));
	}
	else
	{
		Name_t = string("Name" + TimeToString(FlashPlayerData.Name[1]));
	}
	UI->LoadIMG(Adj_t, AppData->GetDisplayProportion(Adj_t), &FlashIMG);
	UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &FlashIMG);
	LinkToken.LinkSourceLocal = 1;
	AppData->LinkIMG(&LinkToken);
	UI->LoadIMG(Name_t, AppData->GetDisplayProportion(Name_t), &FlashIMG);
	UI->PutIMG((LinkToken.DisplayWidth + AppData->GetImageWidth(Adj_t)), LinkToken.DisplayHeight, &FlashIMG);
	FlushBatchDraw();
	UI->SetClass();
	while (1) 
	{
		if (UI->DispatchMSG().message == 0x00000201)
		{
			UI->SetClass();
			while (UI->DispatchMSG().message != 0x00000202) { Sleep(1); };
			Button->ButtonInput(UI->DispatchMSG());
			if (Button->ButtonProcess("Race_People"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::People));
				UI->PutIMG("Race_People_Put");
			}
			if (Button->ButtonProcess("Race_God"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::God));
				UI->PutIMG("Race_God_Put");
			}
			if (Button->ButtonProcess("Race_Monster"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Mosnster));
				UI->PutIMG("Race_Monster_Put");
			}
			if (Button->ButtonProcess("Race_OutPeople"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::OutPeople));
				UI->PutIMG("Race_OutPeople_Put");
			}
			if (Button->ButtonProcess("Race_ThinkingPeople"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::ThinkingPeople));
				UI->PutIMG("Race_ThinkingPeople_Put");
			}
			if (Button->ButtonProcess("Race_Elf"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Elf));
				UI->PutIMG("Race_Elf_Put");
			}
			if (Button->ButtonProcess("Race_Bug"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Bug));
				UI->PutIMG("Race_Bug_Put");
			}
			if (Button->ButtonProcess("Race_NoSaveMonster"))
			{
				UI->PutIMG(PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::NoSaveMonster));
				UI->PutIMG("Race_NoSaveMonster_Put");
			}
			if (Button->ButtonProcess("Rand"))
			{
				UI->SetClass("Name");
				FlashPlayerData.Name[0] = ((rand() % 40) + 1);
				FlashPlayerData.Name[1] = ((rand() % 40) + 1);
				LinkToken.LinkSourceLocal = 0;
				AppData->LinkIMG(&LinkToken);
				if (FlashPlayerData.Name[0] < 10)
				{
					Adj_t = string("Adj0" + TimeToString(FlashPlayerData.Name[0]));
				}
				else
				{
					Adj_t = string("Adj" + TimeToString(FlashPlayerData.Name[0]));
				}
				if (FlashPlayerData.Name[1] < 10)
				{
					Name_t = string("Name0" + TimeToString(FlashPlayerData.Name[1]));
				}
				else
				{
					Name_t = string("Name" + TimeToString(FlashPlayerData.Name[1]));
				}
				UI->LoadIMG(Adj_t, AppData->GetDisplayProportion(Adj_t), &FlashIMG);
				UI->PutIMG(LinkToken.DisplayWidth, LinkToken.DisplayHeight, &FlashIMG);
				LinkToken.LinkSourceLocal = 1;
				AppData->LinkIMG(&LinkToken);
				UI->LoadIMG(Name_t, AppData->GetDisplayProportion(Name_t), &FlashIMG);
				UI->PutIMG((LinkToken.DisplayWidth + AppData->GetImageWidth(Adj_t)), LinkToken.DisplayHeight, &FlashIMG);
			}
		}
		FlushBatchDraw();
		Sleep(1);
	};
	EndBatchDraw();
	return FlashPlayerData;
}

void MenuUIShow::ScenesGameRotateDisplay(void)
{
	BeginBatchDraw();
	UI->SetScenes("GameRotateDisplay");
	UI->SetClass("BackGround");
	UI->PutIMG("OtherBG");
	UI->SetClass("Text");
	UI->PutIMG("NextPlayer");
	UI->PutIMG("PlayerOrder");
	UI->SetClass("Box");
	UI->PutIMG("NowRoundBox");
	FlushBatchDraw();
	while (1) { Sleep(1); };
	EndBatchDraw();
}

void MenuUIShow::ScenesCardFunctionUsing(void)
{
	BeginBatchDraw();
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
	FlushBatchDraw();
	while (1) { Sleep(1); };
	EndBatchDraw();
}

void MenuUIShow::ScenesAttack(void)
{
	BeginBatchDraw();
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
	FlushBatchDraw();
	while (1) { Sleep(1); };
	EndBatchDraw();
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
}

void MenuUIShow::exit(int i, string ET)
{
	ifstream Login("./Log/ELF.err");
	string T{};
	if (Login.is_open())
	{
		char c{};
		while (!Login.eof())
		{
			Login.get(c);
			T += c;
		}
	}
	T[T.size() - 1] = ' ';
	Login.close();
	ofstream errLog;
	errLog.open("./Log/ELF.err");
	errLog << T << TimeToString(time(NULL)) << " " << ET << "\n";
	errLog.close();
	MessageBoxA(NULL, ET.c_str(), NULL, MB_OK | MB_ICONERROR);
	::exit(i);
}
