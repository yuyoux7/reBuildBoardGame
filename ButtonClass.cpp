#include "ButtonClass.h"

void ButtonClass::SetScenes(string Scenes)
{
    this->Scenes = Scenes;
}

void ButtonClass::SetWindowZoomRatio(int Width, int Height)
{
    this->ZoomRatio = ((double)((double)(Width / (double)1920) + (double)(Height / (double)1080)) / 2);
}

bool ButtonClass::ButtonProcess(string ID) const
{
    unique_ptr<AppDataProcess> FlashData = make_unique<AppDataProcess>();
    FlashData->setClass();
    FlashData->setScenes(this->Scenes);
    if (Message.x > (FlashData->DisplayWidth(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio) && Message.x < ((FlashData->DisplayWidth(ID) + FlashData->GetImageWidth(ID)) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio))
    {
        if (Message.y > (FlashData->DisplayHeight(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio) && Message.y < ((FlashData->DisplayHeight(ID) + FlashData->GetImageHeight(ID)) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio))
        {
            return true;
        }
    }
    return false;
}

void ButtonClass::ButtonInput(ExMessage Msg)
{
    this->Message = Msg;
}
