#pragma once
#include "AppDataRegister.h"
class AppDataProcess : AppDataRegister
{
public:
	int GetImageWidth(string ID);
	int GetImageHeight(string ID);
	int DisplayWidth(string ID);
	int DisplayHeight(string ID);
	string GetPath(string ID);
	int GetGameRound(void);
	double GetDisplayProportion();
};

