#include "AppDataProcess.h"

void AppDataProcess::setClass(string Class)
{
	this->ClassType = Class;
}

void AppDataProcess::setScenes(string Scenes)
{
	this->ScenesT = Scenes;
}

int AppDataProcess::GetImageWidth(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	IMAGE* FlashIMG = new IMAGE;
	::loadimage(FlashIMG, GetPath(ID).c_str());
	int width = FlashIMG->getwidth();
	delete FlashIMG;
	delete FlashData;
	return width;
}

int AppDataProcess::GetImageHeight(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	IMAGE* FlashIMG = new IMAGE;
	::loadimage(FlashIMG, GetPath(ID).c_str());
	int height = FlashIMG->getheight();
	delete FlashIMG;
	delete FlashData;
	return height;
}

int AppDataProcess::DisplayWidth(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	delete FlashData;
	return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"]);
}

int AppDataProcess::DisplayHeight(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	delete FlashData;
	return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"]);
}

string AppDataProcess::GetPath(string ID)
{
	AppDataRegister FlashData;
	return ((string)FlashData.AppDataSent(TYPE_IMG, this->ClassType)[ID]["Path"]);
}

int AppDataProcess::GetGameRound()
{
	AppDataRegister* FlashData = new AppDataRegister;
	int game = FlashData->AppDataSent(TYPE_DFT, "GameRound");
	return game;
}

double AppDataProcess::GetDisplayProportion(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	delete FlashData;
	return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"]);
}
