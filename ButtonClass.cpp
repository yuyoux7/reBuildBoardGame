#include "ButtonClass.h"

void ButtonClass::SetScenes(string Scenes)
{
    this->Scenes = Scenes;
}

void ButtonClass::SetWindowZoomRatio(int Width, int Height)
{
    this->ZoomRatio = ((double)((double)(Width / (int)1920) + (double)(Height / (int)1080)) / 2);
}

bool ButtonClass::ButtonProcess(string ID)
{
    AppDataProcess* FlashData = new AppDataProcess;
    WinUIExport* MSG = new WinUIExport;
    MSG->PeekMSG();
    FlashData->setClass();
    FlashData->setScenes(this->Scenes);
    if (MSG->DispatchMSG().x > FlashData->DisplayWidth(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio && MSG->DispatchMSG().x < FlashData->DisplayWidth(ID) + FlashData->GetImageWidth(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio)
    {
        if (MSG->DispatchMSG().y > FlashData->DisplayHeight(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio && MSG->DispatchMSG().y < FlashData->DisplayHeight(ID) + FlashData->GetImageHeight(ID) * FlashData->GetDisplayProportion(ID) * this->ZoomRatio)
        {
            delete MSG;
            delete FlashData;
            return true;
        }
    }
    delete MSG;
    delete FlashData;
    return false;
}