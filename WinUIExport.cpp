#include "WinUIExport.h"

bool WinUIExport::PeekMSG(void)
{
    return ::peekmessage(&msg, EX_KEY | EX_MOUSE);
}

ExMessage WinUIExport::DispatchMSG(void) const
{
    return msg;
}
