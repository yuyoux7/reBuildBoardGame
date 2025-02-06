#pragma once
#include "ExampleH.h"
#include "WinUIExport.h"
#include "log.h"
class WinUIClass : public WinUIExport
{
public:
	BOOL WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow = 0);
	void WinUIUnRegister(void);
	void WinUITitleSet(const string title);
	void SetClass(string Class = "ButtonFont");
	void SetScenes(string Scenes);
	bool LoadIMG(string ID, double dp = 1, IMAGE* img = nullptr);
	bool PutIMG(string ID);
	bool PutIMG(int Width, int Height,IMAGE* img = nullptr);
	double GetWindowZoomRatio(void) const;
	void SetLog(Log_T *T);
	void MixLog(Log_T* T);
private:
	HWND WinUIhWnd{};
	bool WINDOWUISTATE{};
	double WindowZoomRatio{};	//simple with 1080p(FULL HDMI)
	string ClassType{};
	string ScenesT{};
	Log_T* WTL{};
	void LogWrite(string T);
};

