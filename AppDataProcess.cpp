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
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes")) 
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayWidth"))
					return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"]);
			}
		}
	}
	return NULL;
}

int AppDataProcess::DisplayHeight(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	delete FlashData;
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes"))
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayHeight"))
					return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"]);
			}
		}
	}
	return NULL;
}

string AppDataProcess::GetPath(string ID)
{
	AppDataRegister FlashData;
	if (FlashData.AppDataSent(TYPE_IMG, this->ClassType).contains(ID))
	{
		if(FlashData.AppDataSent(TYPE_IMG, this->ClassType)[ID].contains("Path"))
			return ((string)FlashData.AppDataSent(TYPE_IMG, this->ClassType)[ID]["Path"]);
	}
	ifstream Login("./Log/errorLog");
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
	T[T.size() - 1] = '\0';
	Login.close();
	ofstream errLog(("./Log/errorLog" + TimeToString(time(NULL)) + ".log"));
	if (errLog.is_open())
	{
		errLog << TimeToString(time(NULL)) << ": Can't find \"" << ID << "\" Path";
	}
	errLog.close();
	errLog.open("./Log/errorLog");
	errLog << T << TimeToString(time(NULL)) << ": Can't find \"" << ID << "\" Path\n";
	errLog.close();
	exit(-1);
}

int AppDataProcess::GetGameRound()
{
	AppDataRegister* FlashData = new AppDataRegister;
	int game = FlashData->AppDataSent(TYPE_DFT, "GameRound");
	delete FlashData;
	return game;
}

double AppDataProcess::GetDisplayProportion(string ID)
{
	AppDataRegister* FlashData = new AppDataRegister;
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	delete FlashData;
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes"))
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayProportion"))
					return (double)(Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"]);
			}
		}
	}
	return NULL;
}
