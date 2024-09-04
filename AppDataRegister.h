#pragma once
#include "ExampleH.h"
#define TYPE_IMG (string)"Image"
#define TYPE_CFG (string)"Config"
#define TYPE_DFT (string)"Default"
class AppDataRegister
{
public:
	void RegisterConfigData(string Path);
	void RegisterImageData(string Path);
	void RegisterDefaultData(string Path);
	json AppDataSent(string type, string Class);	//type = TYPE_IMG || TYPE_CFG || TYPE_DET
	void UnRegisterConfigData(void);
	void UnRegisterImageData(void);
	void UnRegisterDefaultData(void);
private:
	json ConfigData{};
	json ImageData{};
	json DefaultData{};
};

