#include "WinUIClass.h"
#include "AppDataProcess.h"
BOOL WinUIClass::WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow)
{
		WinUIhWnd = ::initgraph(Width, Height, CmdShow);
		WindowZoomRatio = ((double)((double)(Width / (double)1920) + (double)(Height / (double)1080)) / 2);
		WINDOWUISTATE = true;
		return WINDOWUISTATE;
}

void WinUIClass::WinUIUnRegister(void)
{
	if (WINDOWUISTATE)
	{
		::closegraph();
		WINDOWUISTATE = false;
	}
}

void WinUIClass::WinUITitleSet(const string title) const
{
	if (WINDOWUISTATE)
	::SetWindowText(WinUIhWnd, title.c_str());
}

void WinUIClass::SetClass(string Class)
{
	this->ClassType = Class;
}

void WinUIClass::SetScenes(string Scenes)
{
	this->ScenesT = Scenes;
}

bool WinUIClass::LoadIMG(string ID, double dp, IMAGE* img) const
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
			::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
			delete FlashData;
			delete AppDataImage;
			return WINDOWUISTATE;
		}
		::loadimage(img, AppDataImage->GetPath(ID).c_str(), ImageWidth * dp, ImageHeight * dp, true);
		delete AppDataImage;
	}
	return WINDOWUISTATE;
}

bool WinUIClass::PutIMG(string ID) const
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
		::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
		delete FlashData;
		delete AppDataImage;
	}
	return WINDOWUISTATE;
}

bool WinUIClass::PutIMG(int Width, int Height, IMAGE* img) const
{
	if (WINDOWUISTATE)
	{
		if (img == nullptr)
		{
			return false;
		}
		::putimage(Width * WindowZoomRatio, Height * WindowZoomRatio, img);
	}
	return WINDOWUISTATE;
}

double WinUIClass::GetWindowZoomRatio(void) const
{
	return WindowZoomRatio;
}
