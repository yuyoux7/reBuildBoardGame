#pragma once
#include "ExampleH.h"
class WinUIExport
{
public:
	bool PeekMSG(void);
	ExMessage DispatchMSG(void); 
	string DispatchString(void);
private:
	ExMessage msg;
};

