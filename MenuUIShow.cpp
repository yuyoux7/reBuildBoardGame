#include "MenuUIShow.h"

WinUIClass* UI = new WinUIClass;
AppDataProcess* AppData = new AppDataProcess;
ButtonClass* Button = new ButtonClass;
Player::PlayerData* player = new Player::PlayerData;
Player* PlayCtrlTool = new Player;
Log_T TL;
AppDataProcess::Link LinkToken;
int rd = time(NULL);

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
	if (this->PlayrTotal >= 10)
	{
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
		LinkToken.LinkID = "NumberLink";
		LinkToken.LinkSourceLocal = 0;
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		AppData->LinkIMG(&LinkToken);
		UI->PutIMG(LinkToken.DisplayHeight, LinkToken.DisplayWidth, &imgg);
		UI->MixLog(&TL);
		TL.Text += " " + (TimeToString(time(NULL)) + ": " + "Default Player Count: " + (char)((this->PlayrTotal / 10) ^ 48));
		Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		UI->PutIMG((LinkToken.DisplayHeight + AppData->GetImageWidth(Number_t)), LinkToken.DisplayWidth, &imgg);
		UI->MixLog(&TL);
		TL.Text += ((char)((this->PlayrTotal % 10) ^ 48) + (string)"\n");
	}
	else
	{
		Number_t = ((std::string)"Number" + (char)(this->PlayrTotal ^ 48));
		UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
		UI->MixLog(&TL);
		UI->PutIMG(952, 643, &imgg);
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
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(955 + AppData->GetImageWidth(Number_t), 643, &imgg);
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
						UI->PutIMG(952, 643, &imgg);
					}
					else
					{
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal / 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(952, 643, &imgg);
						UI->MixLog(&TL);
						Number_t = ((std::string)"Number" + (char)((this->PlayrTotal % 10) ^ 48));
						UI->LoadIMG(Number_t, (double)AppData->GetDisplayProportion(Number_t), &imgg);
						UI->MixLog(&TL);
						UI->PutIMG(955 + AppData->GetImageWidth(Number_t), 643, &imgg);
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
	FlushBatchDraw();
	while (1) 
	{
		if (UI->DispatchMSG().message == 0x00000201)
		{
			Button->ButtonInput(UI->DispatchMSG());
			if (Button->ButtonProcess("Race_People"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::People);
			}
			if (Button->ButtonProcess("Race_God"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::God);
			}
			if (Button->ButtonProcess("Race_Monster"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Mosnster);
			}
			if (Button->ButtonProcess("Race_OutPeople"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::OutPeople);
			}
			if (Button->ButtonProcess("Race_ThinkingPeople"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::ThinkingPeople);
			}
			if (Button->ButtonProcess("Race_Elf"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Elf);
			}
			if (Button->ButtonProcess("Race_Bug"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::Bug);
			}
			if (Button->ButtonProcess("Race_NoSaveMonster"))
			{
				PlayCtrlTool->SetPlayerRace(&FlashPlayerData, Player::NoSaveMonster);
			}
			if (Button->ButtonProcess("Rand"))
			{
				FlashPlayerData.Name[0] = (rand() % 41);
			}
		}
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
