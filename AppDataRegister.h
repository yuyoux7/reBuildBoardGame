#pragma once
#include "ExampleH.h"
#define TYPE_IMG (string)"Image"
#define TYPE_CFG (string)"Config"
#define TYPE_DFT (string)"Default"
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

