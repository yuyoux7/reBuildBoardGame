#pragma once
#include "ExampleH.h"
#include "AppDataProcess.h"
class Player
{
public:
	typedef struct _tagv
	{
		short Exist{};
		short Intellect{};
		short Anchored{};
		short Effect{};
		short Understand{};
		short Observatuon{};
	}PlayerValue;
	typedef struct _tagc
	{
		unsigned short* Type = nullptr;
		unsigned int* ID = nullptr;
	}PlayerCard;
	typedef struct _tag
	{
		PlayerValue Value{};
		PlayerCard Card{};
		unsigned short ID{};
		unsigned short Name[2]{};
		unsigned short Map{};
		unsigned short AttackType{};
		unsigned short Race{};
	}PlayerData;
	enum RaceList : unsigned short
	{
		People,
		God,
		Mosnster,
		OutPeople,
		ThinkingPeople,
		Elf,
		Bug,
		NoSaveMonster
	};
	Player();
	void SetPlayerRace(PlayerData *player, unsigned short Race);
	~Player();
private:
	void CardUsing(PlayerData *player, int CardID = 0);
};

