#include "log.h"

void Log_t::LoadLog(Log_T* T, string LogT, bool off)
{
	if (ttlf != time(NULL))
	{
		getLog(T);
	}
	T->Text.pop_back();
	if (T->player == nullptr)
	{
		T->Text += TimeToString(time(NULL)) + ": " + LogT + "\n";
	}
	else
	{
		T->Text += TimeToString(time(NULL)) + ": " + LogT + " PlayerID: " + TimeToString(T->player->ID) + "\n";
	}
	if (ttlf != time(NULL) || off)
	{
		OWrite(T);
	}
}

void Log_t::OWrite(Log_T* T)
{
	ofstream LogFile(T->LogPath);
	if (LogFile.is_open())
	{
		LogFile << T->Text;
	}
	LogFile.close();
}

Log_t::~Log_t()
{
}

void Log_t::getLog(Log_T *T)
{
	ifstream Login(T->LogPath);
	if (Login.is_open())
	{
		char c{};
		T->Text.clear();
		while (!Login.eof())
		{
			Login.get(c);
			T->Text += c;
		}
	}
	Login.close();
}

Log_t::Log_t()
{
}

Log_t::Log_t(Log_T* T)
{
	T->Date = time(NULL);
	T->LogPath = ("./Log/" + (("Log") + TimeToString(T->Date) + ".log"));
	ofstream LogFile(T->LogPath);
	LogFile.close();
}
