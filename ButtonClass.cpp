#include "ButtonClass.h"

bool ButtonClass::GetRegisterData(void)
{
    AppDataRegister* File = new AppDataRegister;
    this->Data = File->AppDataSent(TYPE_IMG, "Button");
    delete File;
    if (this->Data)
    {
        return true;
    }
    return false;
}

bool ButtonClass::UnRegisterData(void) const
{
    if (this->Data)
    {
        NULL >> this->Data;
        return true;
    }
    return false;
}

void ButtonClass::SetScenes(string Scenes)
{
    this->Scenes = Scenes;
}

void ButtonClass::ButtonProcess(int width_local /*key in*/, int height_local /*key in*/, string ID)
{
    AppDataProcess* FlashData = new AppDataProcess;
    this->ID = this->Data[ID];
    this->hlocal = FlashData->DisplayHeight(this->ID);
    this->wlocal = FlashData->DisplayWidth(this->ID);
    delete FlashData;
}

bool ButtonClass::ButtonState(string ID) const
{
    if (this->ID == ID)
    {
        return this->stat;
    }
    return NULL;
}
