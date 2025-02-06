#include "WinUIClass.h"
#include "AppDataProcess.h"

Log_t Log_O;

BOOL WinUIClass::WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow)
{
		WinUIhWnd = ::initgraph(Width, Height, CmdShow);
		WindowZoomRatio = ((double)((double)(Width / (double)1920) + (double)(Height / (double)1080)) / 2);
		//LogWrite("WindowZoomRatio:" + TimeToString(this->WindowZoomRatio) + (string)"." + TimeToString((this->WindowZoomRatio * 10000)));
		WINDOWUISTATE = true;
		return WINDOWUISTATE;
}

void WinUIClass::WinUIUnRegister(void)
{
	if (WINDOWUISTATE)
	{
		::closegraph();
		WINDOWUISTATE = false;
		LogWrite("WindowClose");
	}
}

void WinUIClass::WinUITitleSet(const string title)
{
	if (WINDOWUISTATE)
	::SetWindowText(WinUIhWnd, title.c_str());
	LogWrite("Title Set: " + title);
}

void WinUIClass::SetClass(string Class)
{
	this->ClassType = Class;
	LogWrite("Set Image Class: " + Class);
}

void WinUIClass::SetScenes(string Scenes)
{
	this->ScenesT = Scenes;
	LogWrite("Set Image Scenes: " + Scenes);
}

bool WinUIClass::LoadIMG(string ID, double dp, IMAGE* img)
{
	if (WINDOWUISTATE)
	{
		AppDataProcess *AppDataImage = new AppDataProcess;
		AppDataImage->setClass(this->ClassType);
		AppDataImage->setScenes(this->ScenesT);
		int ImageWidth = AppDataImage->GetImageWidth(ID) * WindowZoomRatio;
		int ImageHeight = AppDataImage->GetImageHeight(ID) * WindowZoomRatio;
		if (img == nullptr)
		{
			int ImageShowLocalWidth = AppDataImage->DisplayWidth(ID) * WindowZoomRatio;
			int ImageShowLocalHeight = AppDataImage->DisplayHeight(ID) * WindowZoomRatio;
			IMAGE *FlashData = new IMAGE;
			::loadimage(FlashData, AppDataImage->GetPath(ID).c_str(), ImageWidth * dp, ImageHeight * dp, true);
			LogWrite("Success Load Image: " + ID);
			::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
			LogWrite("Success Put Image: " + ID);
			delete FlashData;
			delete AppDataImage;
			return WINDOWUISTATE;
		}
		::loadimage(img, AppDataImage->GetPath(ID).c_str(), ImageWidth * dp, ImageHeight * dp, true);
		LogWrite("Success Load Image: " + ID);
		delete AppDataImage;
	}
	return WINDOWUISTATE;
}

bool WinUIClass::PutIMG(string ID)
{
	if (WINDOWUISTATE)
	{
		AppDataProcess* AppDataImage = new AppDataProcess;
		AppDataImage->setClass(this->ClassType);
		AppDataImage->setScenes(this->ScenesT);
		int ImageWidth = AppDataImage->GetImageWidth(ID);
		int ImageHeight = AppDataImage->GetImageHeight(ID);
		int ImageShowLocalWidth = AppDataImage->DisplayWidth(ID) * WindowZoomRatio;
		int ImageShowLocalHeight = AppDataImage->DisplayHeight(ID) * WindowZoomRatio;
		double dp = AppDataImage->GetDisplayProportion(ID) * WindowZoomRatio;
		IMAGE* FlashData = new IMAGE;
		::loadimage(FlashData, AppDataImage->GetPath(ID).c_str(), ImageWidth * dp, ImageHeight * dp, true);
		LogWrite("Success Load Image: " + ID);
		::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
		LogWrite("Success Put Image: " + ID);
		delete FlashData;
		delete AppDataImage;
	}
	return WINDOWUISTATE;
}

bool WinUIClass::PutIMG(int Width, int Height, IMAGE* img)
{
	if (WINDOWUISTATE)
	{
		if (img == nullptr)
		{
			return false;
		}
		::putimage(Width * WindowZoomRatio, Height * WindowZoomRatio, img);
		LogWrite("Success Put Image");
	}
	return WINDOWUISTATE;
}

double WinUIClass::GetWindowZoomRatio(void) const
{
	return WindowZoomRatio;
}

void WinUIClass::SetLog(Log_T* T)
{
	WTL = T;
}


void WinUIClass::MixLog(Log_T* T)
{
	if (WTL->Text != T->Text)
	{
		T->Text += WTL->Text;
		WTL->Text = T->Text;
	}
}

void WinUIClass::LogWrite(string T)
{
	if (WTL->LogPath != "")
	{
		Log_O.LoadLog(WTL, T);
	}
	else
	{
		WTL->Text += TimeToString(time(NULL)) + ": " + T + "\n";
	}
}
