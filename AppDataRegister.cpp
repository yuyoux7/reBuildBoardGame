#include "AppDataRegister.h"

void AppDataRegister::RegisterConfigData(string Path)
{
	ifstream *Data = new ifstream;
	Data->open(Path);
	*Data >> ConfigData;
	Data->close();
	delete Data;
}

void AppDataRegister::RegisterImageData(string Path)
{
	ifstream* Data = new ifstream;
	Data->open(Path);
	*Data >> ImageData;
	Data->close();
	delete Data;
}

void AppDataRegister::RegisterDefaultData(string Path)
{
	ifstream* Data = new ifstream;
	Data->open(Path);
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

void AppDataRegister::UnRegisterConfigData(void)
{
	ifstream* Data = new ifstream;
	*Data >> ConfigData;
	delete Data;
}

void AppDataRegister::UnRegisterImageData(void)
{
	ifstream* Data = new ifstream;
	*Data >> ImageData;
	delete Data;
}

void AppDataRegister::UnRegisterDefaultData(void)
{
	ifstream* Data = new ifstream;
	*Data >> DefaultData;
	delete Data;
}
