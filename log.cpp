#include "log.h"

void Log_t::LoadLog(Log_T* T, string LogT)
{
	T->Text += TimeToString(time(NULL)) + ": " + LogT + "\n";
	ofstream LogFile(T->LogPath);
	if (LogFile.is_open())
	{
		if (T->player == nullptr)
{
			LogFile << T->Text;		
		}
	}
	LogFile.close();
}

Log_t::~Log_t()
{
}

string Log_t::TimeToString(time_t t)
{
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
}

Log_t::Log_t(Log_T* T)
{
	T->Date = time(NULL);
	T->LogPath = ("./Log/" + (("Log") + TimeToString(T->Date) + ".log"));
	ofstream LogFile(T->LogPath);
	LogFile.close();
}
