#pragma once
#include "ExampleH.h"
class WinUIExport
{
public:
	bool PeekMSG(void);
	ExMessage DispatchMSG(void) const; 
private:
	ExMessage msg;
};

