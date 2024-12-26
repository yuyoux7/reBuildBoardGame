#include "ButtonClass.h"

void ButtonClass::SetScenes(string Scenes)
{
    this->Scenes = Scenes;
}

void ButtonClass::SetWindowZoomRatio(int Width, int Height)
{
    this->ZoomRatio = ((double)((double)(Width / (double)1920) + (double)(Height / (double)1080)) / 2);
}

bool ButtonClass::ButtonProcess(string ID)
{
    AppDataProcess* FlashData = new AppDataProcess;
    FlashData->setClass();
    FlashData->setScenes(this->Scenes);
    if (Message.x > (FlashData->DisplayWidth(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio) && Message.x < ((FlashData->DisplayWidth(ID) + FlashData->GetImageWidth(ID)) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio))
    {
        if (Message.y > (FlashData->DisplayHeight(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio) && Message.y < ((FlashData->DisplayHeight(ID) + FlashData->GetImageHeight(ID)) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio))
        {
            delete FlashData;
            return true;
        }
    }
    delete FlashData;
    return false;
}

void ButtonClass::ButtonInput(ExMessage Msg)
{
    this->Message = Msg;
}
