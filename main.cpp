#include "MenuUIShow.h"
int main(void)
{
	Log_T *LT = new Log_T;
	Log_t L(LT);
	bool GameRun = true;
	AppDataProcess* AppData = new AppDataProcess;
	L.LoadLog(LT, "DataReadSuccess");
	int GameRound = AppData->GetGameRound();
	delete AppData;
	MenuUIShow* Display = new MenuUIShow;
	Display->LogMix(LT);
	ofstream f(LT->LogPath);
	if (f.is_open())
	{
		f << LT->Text;
	}
	f.close();
	L.LoadLog(LT, "TurnNextScenes");
	int PlayerTotal = Display->GetPlayerTotal();
	Player::PlayerData* Player_Data = (Player::PlayerData*)malloc(sizeof(Player::PlayerData*) * (static_cast<unsigned long long>(PlayerTotal) + 3));
	if (Player_Data != nullptr)
	{
		for (auto i = 1; i <= PlayerTotal; i++)
		{
			Player_Data[i] = Display->ScenesPlayerDataLoad();
			Player_Data[i].ID = i;
		}
	}
	L.LoadLog(LT, "TurnNextScenes");
	for (auto i = 0; GameRun; i++)
	{
		Display->ScenesGameRotateDisplay();
		L.LoadLog(LT, "TurnNextScenes");
		Display->ScenesCardFunctionUsing();
		L.LoadLog(LT, "TurnNextScenes");
		Display->ScenesAttack();
		if (i == PlayerTotal)
		{
			i = 0;
			GameRound--;
			if (GameRound == -1)
			{
				GameRun = false;
			}
			else
			{
				L.LoadLog(LT, "NextRound");
			}
		}
		Sleep(1);
	}
	delete LT;
	delete Display;
};