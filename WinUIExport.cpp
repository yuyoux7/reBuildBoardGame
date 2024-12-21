#include "WinUIExport.h"

bool WinUIExport::PeekMSG(void)
{
	return ::peekmessage(&this->msg, EX_KEY | EX_MOUSE);
}

ExMessage WinUIExport::DispatchMSG(void)
{
	PeekMSG();
	return this->msg;
}

string WinUIExport::DispatchString(void)
{
	PeekMSG();
	if (this->msg.message == 0x00000100)
	{
		if (this->msg.vkcode == 0x0000000D)
		{
			return "enter";
		}
		if (this->msg.vkcode == 0x00000008)
		{
			return "back";
		}
		string FlashString{};
		if (this->msg.vkcode - '0' < 10)
		{
			FlashString += this->msg.vkcode;
		}
		else if (this->msg.vkcode - '0' > 47)
		{
			FlashString += (this->msg.vkcode - 48);
		}
		else
		{
			FlashString += (this->msg.vkcode + 32);
		}
		return FlashString;
	}
	return "";
}
