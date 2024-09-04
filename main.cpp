#include "MenuUIShow.h"
int main(void)
{
	bool GameRun = true;
	AppDataProcess* AppData = new AppDataProcess;
	int GameRound = AppData->GetGameRound();
	delete AppData;
	MenuUIShow* Display = new MenuUIShow;
	Display->ScenesHome();
	int PlayerTotal = Display->GetPlayerTotal();
	Display->ScenesPlayerDataLoad();
	for (auto i = 0; GameRun; i++)
	{
		Display->ScenesGameRotateDisplay();
		Display->ScenesCardFunctionUsing();
		Display->ScenesAttack();
		if (i == PlayerTotal)
		{
			i = 0;
			GameRound--;
			if (GameRound == -1)
			{
				GameRun = false;
			}
		}
	}
};