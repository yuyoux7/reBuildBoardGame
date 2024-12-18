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
};
class ButtonClass : ButtonData
{
public:
	void SetScenes(string Scenes);
	bool ButtonProcess(unsigned int width_local, unsigned int height_local, string ID);
};

