#include "AppDataRegister.h"

AppDataRegister::AppDataRegister()
{
	unique_ptr<ifstream> Data = make_unique<ifstream>();
	Data->open("./Config.json");
	if (Data->is_open())
	{
		*Data >> ConfigData;
		Data->close();
	}
	Data->open("./ImageConfig.json");
	if (Data->is_open())
	{
		*Data >> ImageData;
		Data->close();
	}
	Data->open("./DefaultConfig.json");
	if (Data->is_open())
	{
		*Data >> DefaultData;
		Data->close();
	}
}

json AppDataRegister::AppDataSent(string type, string Class)
{
	if (type == TYPE_CFG)
	{
		if (ConfigData.contains(Class))
			return ConfigData[Class];
		else
			MessageBox(NULL, "Data Config Lost", NULL, MB_OK | MB_ICONERROR);
	}
	else if (type == TYPE_IMG)
	{
		if (ImageData.contains(Class))
			return ImageData[Class];
		else
			MessageBox(NULL, "Data ImageConfig Lost", NULL, MB_OK | MB_ICONERROR);
	}
	else if (type == TYPE_DFT)
	{
		if (DefaultData.contains(Class))
			return DefaultData[Class];
		else
			MessageBox(NULL, "Data DefaultConfig Lost", NULL, MB_OK | MB_ICONERROR);
	}
	return NULL;
}

AppDataRegister::~AppDataRegister()
{
	ConfigData = NULL;
	ImageData = NULL;
	DefaultData = NULL;
}
