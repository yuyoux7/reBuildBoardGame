#pragma once
#include "AppDataRegister.h"
class AppDataProcess : public AppDataRegister
{
public:
	void setClass(string Class = "ButtonFont");
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
	void ErrorLog(string ELT, string LV = ": warning");
	bool ELS = false;
	string ELPT;
	void exit(int i, string ET = "");
};

