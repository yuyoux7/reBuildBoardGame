#pragma once
#include "ExampleH.h"
#include "AppDataProcess.h"
struct ButtonData
{
	unsigned int Width{};
	unsigned int Height{};
	unsigned int wlocal{};	//to simple left
	unsigned int hlocal{};	//to simple top
	string Scenes{};
	string ID{};
	json Data{};
	bool stat;
};
class ButtonClass : ButtonData
{
public:
	bool GetRegisterData(void);
	bool UnRegisterData(void);
	void SetScenes(string Scenes);
	void ButtonProcess(int width_local,int height_local, string ID);
	bool ButtonState(string ID) const;
};

