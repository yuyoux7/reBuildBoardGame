#include "ButtonClass.h"

void ButtonClass::SetScenes(string Scenes)
{
    this->Scenes = Scenes;
}

bool ButtonClass::ButtonProcess(unsigned int width_local /*key in*/, unsigned int height_local /*key in*/, string ID)
{
    AppDataProcess* FlashData = new AppDataProcess;
    FlashData->setClass();
    FlashData->setScenes(this->Scenes);
    this->hlocal = FlashData->DisplayHeight(ID);
    this->wlocal = FlashData->DisplayWidth(ID);
    this->Height = FlashData->GetImageHeight(ID);
    this->Width = FlashData->GetImageWidth(ID);
    delete FlashData;
    if (width_local > this->hlocal && width_local < this->hlocal + this->Height)
    {
        if (height_local > this->hlocal && height_local < this->hlocal + this->Height)
        {
            return true;
        }
    }
    return false;
}