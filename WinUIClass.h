#pragma once
#include "ExampleH.h"
class WinUIClass
{
public:
	BOOL WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow = 0);
	void WinUIUnRegister(void);
	void WinUITitleSet(const string title) const;
	bool LoadIMG(string ID, double dp = 1, IMAGE* img = nullptr) const;
	bool PutIMG(string ID) const;
private:
	HWND WinUIhWnd{};
	bool WINDOWUISTATE{};
	double WindowZoomRatio{};	//simple with 1080p(FULL HDMI)
};

