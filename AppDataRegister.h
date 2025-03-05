#pragma once
#include "ExampleH.h"
class AppDataRegister
{
public:
	AppDataRegister();
	json AppDataSent(string type, string Class);	//type = TYPE_IMG || TYPE_CFG || TYPE_DET
	~AppDataRegister();
private:
	json ConfigData{};
	json ImageData{};
	json DefaultData{};
};

