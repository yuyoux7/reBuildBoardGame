#pragma once
#include "ExampleH.h"
#include "WinUIExport.h"
#include "log.h"
class WinUIClass : public WinUIExport
{
public:
	BOOL WinUICreat(unsigned int Width, unsigned int Height, unsigned int CmdShow = 0);
	void WinUITitleSet(const string title);
	void SetClass(string Class = "ButtonFont");
	void SetScenes(string Scenes);
	bool LoadIMG(string ID, double dp = 1, IMAGE* img = nullptr);
	void PutIMG(string ID);
	void PutIMG(int Width, int Height,IMAGE* img = nullptr);
	double GetWindowZoomRatio(void) const;
	void SetLog(Log_T *T);
	void MixLog(Log_T* T);
	void clear(void);
	bool WinUISave(void);
private:
	HWND WinUIhWnd{};
	double WindowZoomRatio{};	//simple with 1080p(FULL HDMI)
	string ClassType{};
	string ScenesT{};
	Log_T* WTL{};
	bool WINDOWUISTATE{};
	void LogWrite(string T);
	void WinUIUnRegister(void);
};

