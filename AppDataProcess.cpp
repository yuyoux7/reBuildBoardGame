#include "AppDataProcess.h"

unique_ptr<AppDataRegister> FlashData = make_unique<AppDataRegister>();

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

int AppDataProcess::DisplayWidth(string ID, int ArrayLocal)
{
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes")) 
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayWidth"))
				{
					if (Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"].is_number())
					{
						return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"]);
					}
					else if (Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"].is_array()) 
					{
						if (Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"][ArrayLocal].is_number() && (Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"]).size() >= ArrayLocal)
						{
							return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"][ArrayLocal]);
						}
						else if(Data[ID]["Scenes"][this->ScenesT]["DisplayWidth"][ArrayLocal].is_number())
						{
							ErrorLog(string(ID + "\" " + "DisplayWidth Array Lost: " + TimeToString(ArrayLocal)));
							return NULL;
						}
						else
						{
							ErrorLog(string(ID + "\" " + "TypeError"));
							exit(-1, string(ID + " TypeError"));
						}
					}
					else 
					{
						ErrorLog(string(ID + "\" " + "TypeError"));
						exit(-1, string(ID + " TypeError"));
					}
				}
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

int AppDataProcess::DisplayHeight(string ID, int ArrayLocal)
{
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes"))
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayHeight")) 
				{
					if (Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"].is_number())
					{
						return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"]);
					}
					else if (Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"].is_array())
					{
						if (Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"][ArrayLocal].is_number() && (Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"]).size() >= ArrayLocal)
						{
							return (int)(Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"][ArrayLocal]);
						}
						else if (Data[ID]["Scenes"][this->ScenesT]["DisplayHeight"][ArrayLocal].is_number())
						{
							ErrorLog(string(ID + "\" " + "DisplayHeight Array Lost: " + TimeToString(ArrayLocal)));
							return NULL;
						}
						else
						{
							ErrorLog(string(ID + "\" " + "TypeError"));
							exit(-1, string(ID + " TypeError"));
						}
					}
					else
					{
						ErrorLog(string(ID + "\" " + "TypeError"));
						exit(-1, string(ID + " TypeError"));
					}
				}
				ErrorLog(string(ID + "\" " + "DisplayHeight"));
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

string AppDataProcess::GetPath(string ID)
{
	if (FlashData->AppDataSent(TYPE_IMG, this->ClassType).contains(ID))
	{
		if (FlashData->AppDataSent(TYPE_IMG, this->ClassType)[ID].contains("Path"))
		{
			return ((string)FlashData->AppDataSent(TYPE_IMG, this->ClassType)[ID]["Path"]);
		}
		ErrorLog(string(ID + "\" Path"));
		exit(-1, string(ID + " Path Lost"));
	}
	ErrorLog(string(ID + "\""), ": error");
	exit(-1, string(ID + " Lost"));
}

int AppDataProcess::GetGameRound()
{
	return FlashData->AppDataSent(TYPE_DFT, "GameRound");
}

double AppDataProcess::GetDisplayProportion(string ID, int ArrayLocal)
{
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	if (Data.contains(ID))
	{
		if (Data[ID].contains("Scenes"))
		{
			if (Data[ID]["Scenes"].contains(this->ScenesT))
			{
				if (Data[ID]["Scenes"][this->ScenesT].contains("DisplayProportion"))
					if (Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"].is_number())
						return (double)(Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"]);
					else if (Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"].is_array())
						return (double)(Data[ID]["Scenes"][this->ScenesT]["DisplayProportion"][ArrayLocal]);
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

void AppDataProcess::LinkIMG(Link* ID)
{
	json Data = FlashData->AppDataSent(TYPE_IMG, this->ClassType);
	if (Data.contains(ID->LinkID))
	{
		if (Data[ID->LinkID].contains("Scenes"))
		{
			if (Data[ID->LinkID]["Scenes"].contains(this->ScenesT))
			{
				ID->LinkClass = this->ClassType;
				setClass(ID->LinkSourceClass);
				if (Data[ID->LinkID]["Scenes"][this->ScenesT].contains("BoxName"))
				{
					if (ID->LinkSourceLocal == 0 && !Data[ID->LinkID]["Scenes"][this->ScenesT]["BoxName"].is_array())
						ID->LinkSource = Data[ID->LinkID]["Scenes"][this->ScenesT]["BoxName"];
					else if (Data[ID->LinkID]["Scenes"][this->ScenesT]["BoxName"].is_array()) {
						if ((Data[ID->LinkID]["Scenes"][this->ScenesT]["BoxName"]).size() >= ID->LinkSourceLocal)
							ID->LinkSource = Data[ID->LinkID]["Scenes"][this->ScenesT]["BoxName"][ID->LinkSourceLocal];
						else
						{
							MessageBox(NULL, string("Fail Link Source Link to: " + ID->LinkID + " ID: " + TimeToString(ID->LinkSourceLocal)).c_str(), NULL, MB_OK | MB_ICONERROR);
							ErrorLog(string("Fail Link Source Link to: " + ID->LinkID + " ID: " + TimeToString(ID->LinkSourceLocal)));
						}
					}
					else
					{
						MessageBox(NULL, string("Fail Link Source Link to: " + ID->LinkID + " ID: " + TimeToString(ID->LinkSourceLocal)).c_str(), NULL, MB_OK | MB_ICONERROR);
						ErrorLog(string("Fail Link Source Link to: " + ID->LinkID + " ID: " + TimeToString(ID->LinkSourceLocal)));
					}
					double fdp = GetDisplayProportion(ID->LinkSource);
					ID->DisplayWidth = static_cast<int>(DisplayWidth(ID->LinkSource) * fdp);
					ID->DisplayHeight = static_cast<int>(DisplayHeight(ID->LinkSource) * fdp);
					setClass(ID->LinkClass);
					ID->DisplayWidth += static_cast<int>(DisplayWidth(ID->LinkID, ID->LinkSourceLocal) * fdp);
					ID->DisplayHeight += static_cast<int>(DisplayHeight(ID->LinkID, ID->LinkSourceLocal) * fdp);
				}
				else
					ErrorLog(string(ID->LinkID) + "\" BoxName");
			}
			else
				ErrorLog(string(ID->LinkID + "\" " + ScenesT));
		}
		else
			ErrorLog(string(ID->LinkID + "\" Scenes"));
	}
	else {
		ErrorLog(string(ID->LinkID + "\""), ": error");
		exit(-1, string(ID->LinkID + " Lost"));
	}
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
	if (T.size() == 0)
		T[0] = ' ';
	else
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
	if(ZT.size() != 0)
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