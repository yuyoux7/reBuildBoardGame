#pragma once
#include "ExampleH.h"
#include "WinUIExport.h"
class WinUIClass : public WinUIExport
{
public:
	BOOL WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow = 0);
	void WinUIUnRegister(void);
	void WinUITitleSet(const string title) const;
	void SetClass(string Class = "ButtonFont");
	void SetScenes(string Scenes);
	bool LoadIMG(string ID, double dp = 1, IMAGE* img = nullptr) const;
	bool PutIMG(string ID) const;
	bool PutIMG(int Width, int Height,IMAGE* img = nullptr) const;
private:
	HWND WinUIhWnd{};
	bool WINDOWUISTATE{};
	double WindowZoomRatio{};	//simple with 1080p(FULL HDMI)
	string ClassType{};
	string ScenesT{};
};

