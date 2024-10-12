#include "MenuUIShow.h"
int main(void)
{
	bool GameRun = true;
	AppDataProcess* AppData = new AppDataProcess;
	int GameRound = AppData->GetGameRound();
	delete AppData;
	MenuUIShow* Display = new MenuUIShow;
	int PlayerTotal = Display->GetPlayerTotal();
	Display->ScenesPlayerDataLoad();
	for (auto i = 0; GameRun; i++)
	{
		Display->ScenesGameRotateDisplay();
		Display->ScenesCardFunctionUsing();
		Display->ScenesAttack();
		if (i == PlayerTotal - 1)
		{
			i = 0;
			GameRound--;
			if (GameRound == -1)
			{
				GameRun = false;
			}
		}
	}
	delete Display;
};