#pragma once
#include "AppDataRegister.h"
class AppDataProcess : public AppDataRegister
{
public:
	typedef struct _token
	{
		int DisplayWidth{};
		int DisplayHeight{};
		int LinkSourceLocal{};
		string LinkSource{};
		string LinkSourceClass = "Box";
		string LinkID{};
		string LinkClass{};
	}Link;
	void setClass(string Class = "ButtonFont");
	void setScenes(string Scenes);
	int GetImageWidth(string ID);
	int GetImageHeight(string ID);
	int DisplayWidth(string ID, int ArrayLocal = 0);
	int DisplayHeight(string ID, int ArrayLocal = 0);
	string GetPath(string ID);
	int GetGameRound(void);
	double GetDisplayProportion(string ID, int ArrayLocal = 0);
	void LinkIMG(Link *ID);
private:
	string ClassType{};
	string ScenesT{};
	void ErrorLog(string ELT, string LV = ": warning");
	string ELPT;
	void exit(int i, string ET = "");
	bool ELS = false;
};

