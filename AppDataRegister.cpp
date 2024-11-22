#include "AppDataRegister.h"

AppDataRegister::AppDataRegister()
{
	ifstream* Data = new ifstream;
	Data->open("./Config.json");
	*Data >> ConfigData;
	Data->close();
	Data->open("./ImageConfig.json");
	*Data >> ImageData;
	Data->close();
	Data->open("./DefaultConfig.json");
	*Data >> DefaultData;
	Data->close();
	delete Data;
}

json AppDataRegister::AppDataSent(string type, string Class)
{
	if (type == TYPE_CFG)
	{
		if(ConfigData.contains(Class))
		return ConfigData[Class];
	}
	else if (type == TYPE_IMG)
	{
		if (ImageData.contains(Class))
		return ImageData[Class];
	}
	else if (type == TYPE_DFT)
	{
		if (DefaultData.contains(Class))
		return DefaultData[Class];
	}
	return NULL;
}

AppDataRegister::~AppDataRegister()
{
	ConfigData = NULL;
	ImageData = NULL;
	DefaultData = NULL;
}
