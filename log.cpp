#include "log.h"

void Log_t::LoadLog(Log_T* T, string LogT)
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
	T->Text[T->Text.size() - 1] = ' ';
	ofstream LogFile(T->LogPath);
	if (LogFile.is_open())
	{
		if (T->player == nullptr)
		{
			T->Text += TimeToString(time(NULL)) + ": " + LogT + "\n";
			LogFile << T->Text;		
		}
		else
		{
			T->Text += TimeToString(time(NULL)) + ": " + LogT + " PlayerID: " + TimeToString(T->player->ID) + "\n";
			LogFile << T->Text;
		}
	}
	LogFile.close();
}

Log_t::~Log_t()
{
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
