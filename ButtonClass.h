#pragma once
#include "ExampleH.h"
#include "AppDataProcess.h"
#include "WinUIExport.h"
class ButtonClass
{
public:
	void SetScenes(string Scenes);
	void SetWindowZoomRatio(int Width, int Height);
	bool ButtonProcess(string ID) const;
	void ButtonInput(ExMessage Msg);
private:
	double ZoomRatio{};
	string Scenes{};
	ExMessage Message{};
};

