#include "ExampleH.h"

string TimeToString(time_t t)
{
	if (t == 0)
	{
		return "0";
	}
	string ft, rt;
	for (; t > 0; t /= 10)
	{
		ft += ((t % 10) ^ 48);
	}
	for (auto i = ft.size() - 1; i > 0; i--)
	{
		rt += ft[i];
	}
	rt += ft[0];
	return rt;
};