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
	IMAGE* FlashIMG = new IMAGE;
	::loadimage(FlashIMG, GetPath(ID).c_str());
	int width = FlashIMG->getwidth();
	delete FlashIMG;
	return width;
}

int AppDataProcess::GetImageHeight(string ID)
{
	IMAGE* FlashIMG = new IMAGE;
	::loadimage(FlashIMG, GetPath(ID).c_str());
	int height = FlashIMG->getheight();
	delete FlashIMG;
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
				ErrorLog(string(ID + "\" " + "DisplayWidth"));
				return NULL;
			}
			ErrorLog(string(ID + "\" " + ScenesT));
			return NULL;
		}
		ErrorLog(string(ID + "\" Scenes"));
		return NULL;
	}
	ErrorLog(string(ID + "\""), ": error");
	exit(-1, string(ID + " Lost"));
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
				ErrorLog(string(ID + "\" " + ScenesT));
				return NULL;
			}
			ErrorLog(string(ID + "\" " + "DisplayHeight"));
			return NULL;
		}
		ErrorLog(string(ID + "\" Scenes"));
		return NULL;
	}
	ErrorLog(string(ID + "\""), ": error");
	exit(-1, string(ID + " Lost"));
}

string AppDataProcess::GetPath(string ID)
{
	AppDataRegister FlashData;
	if (FlashData.AppDataSent(TYPE_IMG, this->ClassType).contains(ID))
	{
		if (FlashData.AppDataSent(TYPE_IMG, this->ClassType)[ID].contains("Path"))
		{
			return ((string)FlashData.AppDataSent(TYPE_IMG, this->ClassType)[ID]["Path"]);
		}
		ErrorLog(string(ID + "\" Path"));
		exit(-1, string(ID + " Path Lost"));
	}
	ErrorLog(string(ID + "\""), ": error");
	exit(-1, string(ID + " Lost"));
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
				ErrorLog(string(ID + "\" " + "DisplayProportion"));
				return 1.0;
			}
			ErrorLog(string(ID + "\" " + ScenesT));
			return 1.0;
		}
		ErrorLog(string(ID + "\" Scenes"));
		return 1.0;
	}
	ErrorLog(string(ID + "\""), ": error");
	exit(-1, string(ID + " Lost"));
}

void AppDataProcess::ErrorLog(string ELT, string LV)
{
	ifstream Login("./Log/ELF.err");
	string T{}, ZT{};
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
	if (!ELS) {
		ELPT = TimeToString(time(NULL));
		ELS = true;
	}
	ELT += "\n";
	Login.open(("./Log/ELF" + ELPT + ".log"));
	if (Login.is_open())
	{
		char c{};
		while (!Login.eof())
		{
			Login.get(c);
			ZT += c;
		}
	}
	ZT[ZT.size() - 1] = ' ';
	Login.close();
	ofstream errLog(("./Log/ELF" + ELPT + ".log"));
	if (errLog.is_open())
	{
		errLog << ZT << TimeToString(time(NULL)) << LV << ": Can't find \"" << ELT;
	}
	errLog.close();
	errLog.open("./Log/ELF.err");
	errLog << T << TimeToString(time(NULL)) << LV << ": Can't find \"" << ELT;
	errLog.close();
}

void AppDataProcess::exit(int i, string ET)
{
	MessageBoxA(NULL, ET.c_str(), NULL, MB_OK | MB_ICONERROR);
	::exit(i);
}

