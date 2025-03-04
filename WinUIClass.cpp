#include "WinUIClass.h"
#include "AppDataProcess.h"

Log_t Log_O;

BOOL WinUIClass::WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow)
{
		WinUIhWnd = ::initgraph(Width, Height, CmdShow);
		WindowZoomRatio = ((double)((double)(Width / (double)1920) + (double)(Height / (double)1080)) / 2);
		LogWrite("WindowZoomRatio: " + TimeToString(static_cast<time_t>(this->WindowZoomRatio)) + (string)"." + TimeToString(static_cast<time_t>(this->WindowZoomRatio * 10000)));
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
		unique_ptr<AppDataProcess> AppDataImage = make_unique<AppDataProcess>();
		AppDataImage->setClass(this->ClassType);
		AppDataImage->setScenes(this->ScenesT);
		int ImageWidth = static_cast<int>(AppDataImage->GetImageWidth(ID) * WindowZoomRatio);
		int ImageHeight = static_cast<int>(AppDataImage->GetImageHeight(ID) * WindowZoomRatio);
		if (img == nullptr)
		{
			int ImageShowLocalWidth = static_cast<int>(AppDataImage->DisplayWidth(ID) * WindowZoomRatio);
			int ImageShowLocalHeight = static_cast<int>(AppDataImage->DisplayHeight(ID) * WindowZoomRatio);
			IMAGE *FlashData = new IMAGE;
			::loadimage(FlashData, AppDataImage->GetPath(ID).c_str(), static_cast<int>(ImageWidth * dp), static_cast<int>(ImageHeight * dp), true);
			LogWrite("Load Image: " + ID);
			::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
			LogWrite("Put Image: " + ID + (string)" [" + TimeToString(ImageShowLocalWidth) + (string)", " + TimeToString(ImageShowLocalHeight) + (string)"] ");
			delete FlashData;
			return WINDOWUISTATE;
		}
		::loadimage(img, AppDataImage->GetPath(ID).c_str(), static_cast<int>(ImageWidth * dp), static_cast<int>(ImageHeight * dp), true);
		LogWrite("Load Image: " + ID);
	}
	return WINDOWUISTATE;
}

void WinUIClass::PutIMG(string ID)
{
	if (WINDOWUISTATE)
	{
		unique_ptr<AppDataProcess> AppDataImage = make_unique<AppDataProcess>();
		//AppDataProcess* AppDataImage = new AppDataProcess();
		AppDataImage->setClass(this->ClassType);
		AppDataImage->setScenes(this->ScenesT);
		int ImageWidth = AppDataImage->GetImageWidth(ID);
		int ImageHeight = AppDataImage->GetImageHeight(ID);
		int ImageShowLocalWidth = static_cast<int>(AppDataImage->DisplayWidth(ID) * WindowZoomRatio);
		int ImageShowLocalHeight = static_cast<int>(AppDataImage->DisplayHeight(ID) * WindowZoomRatio);
		double dp = AppDataImage->GetDisplayProportion(ID) * WindowZoomRatio;
		IMAGE* FlashData = new IMAGE;
		::loadimage(FlashData, AppDataImage->GetPath(ID).c_str(), static_cast<int>(ImageWidth * dp), static_cast<int>(ImageHeight * dp), true);
		LogWrite("Load Image: " + ID);
		::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
		LogWrite("Put Image: " + ID + (string)" [" + TimeToString(ImageShowLocalWidth) + (string)", " + TimeToString(ImageShowLocalHeight) + (string)"] ");
		delete FlashData;
		//delete AppDataImage;
	}
}

void WinUIClass::PutIMG(int Width, int Height, IMAGE* img)
{
	if (WINDOWUISTATE)
	{
		if (img != nullptr)
		{
			::putimage(static_cast<int>(Width * WindowZoomRatio), static_cast<int>(Height * WindowZoomRatio), img);
			LogWrite("Put Image" + (string)" [" + TimeToString(static_cast<time_t>(Width * WindowZoomRatio)) + (string)", " + TimeToString(static_cast<time_t>(Height * WindowZoomRatio)) + (string)"] ");
		}
	}
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
		WTL->Text += " " + TimeToString(time(NULL)) + ": " + T + "\n";
	}
}
