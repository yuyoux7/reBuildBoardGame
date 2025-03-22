#pragma once
#include "ExampleH.h"
#include "Player.h"

typedef struct _tagl
{
	time_t Date{};
	string Text{};
	Player::PlayerData* player = nullptr;
	string LogPath{};
}Log_T;

class Log_t
{
public:
	Log_t();
	Log_t(Log_T *T);
	void LoadLog(Log_T *T, string LogT, bool off = false);
	void OWrite(Log_T* T);
	~Log_t();
private:
	void getLog(Log_T* T);
	time_t ttlf{};
};

