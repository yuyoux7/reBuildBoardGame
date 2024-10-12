#include "WinUIClass.h"
#include "AppDataProcess.h"
BOOL WinUIClass::WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow)
{
		WinUIhWnd = ::initgraph(Width, Height, CmdShow);
		WindowZoomRatio = ((double)((double)(Width / (int)1920) + (double)(Height / (int)1080)) / 2);
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

bool WinUIClass::LoadIMG(string ID, double dp, IMAGE* img) const
{
	if (WINDOWUISTATE)
	{
		AppDataProcess *AppDataImage = new AppDataProcess;
		int ImageWidth = AppDataImage->GetImageWidth(ID);
		int ImageHeight = AppDataImage->GetImageHeight(ID);
		int ImageShowLocalWidth = AppDataImage->DisplayWidth(ID);
		int ImageShowLocalHeight = AppDataImage->DisplayHeight(ID);
		if (img == nullptr)
		{
			IMAGE *FlashData = new IMAGE;
			::loadimage(FlashData, AppDataImage->GetPath(ID).c_str(), ImageWidth * WindowZoomRatio * dp, ImageHeight * WindowZoomRatio * dp, true);
			::putimage(ImageShowLocalWidth, ImageShowLocalHeight, FlashData);
			delete FlashData;
			delete AppDataImage;
			return WINDOWUISTATE;
		}
		::loadimage(img, AppDataImage->GetPath(ID).c_str(), ImageWidth * WindowZoomRatio * dp, ImageHeight * WindowZoomRatio * dp, true);
		delete AppDataImage;
		return WINDOWUISTATE;
	}
	return WINDOWUISTATE;
}

bool WinUIClass::PutIMG(string ID) const
{
	if (WINDOWUISTATE)
	{
		AppDataProcess* AppDataImage = new AppDataProcess;
		int ImageShowLocalWidth = AppDataImage->DisplayWidth(ID);
		int ImageShowLocalHeight = AppDataImage->DisplayHeight(ID);
		//::putimage(ImageShowLocalWidth, ImageShowLocalHeight, );
		delete AppDataImage;
		return WINDOWUISTATE;
	}
	return WINDOWUISTATE;
}
