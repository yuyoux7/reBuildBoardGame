#pragma once
#include "AppDataRegister.h"
class AppDataProcess : AppDataRegister
{
public:
	void setClass(string Class = "Button");
	void setScenes(string Scenes);
	int GetImageWidth(string ID);
	int GetImageHeight(string ID);
	int DisplayWidth(string ID);
	int DisplayHeight(string ID);
	string GetPath(string ID);
	int GetGameRound(void);
	double GetDisplayProportion(string ID);
private:
	string ClassType{};
	string ScenesT{};
};

