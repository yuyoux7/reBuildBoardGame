#pragma once
#include "ExampleH.h"
#include "AppDataRegister.h"
struct ButtonData
{
	unsigned int Width{};
	unsigned int Height{};
	unsigned int wlocal{};	//to simple left
	unsigned int hlocal{};	//to simple top
	string ID{};
};
class ButtonClass : ButtonData
{
public:
	bool GetRegisterData(void) const;
	bool UnRegisterData(void) const;
	bool ButtonState(string ID) const;
};

