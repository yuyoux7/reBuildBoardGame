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
		std::vector<unsigned short> Type{};
		std::vector<unsigned int> ID{};
	}PlayerCard;
	typedef struct _tag
	{
		PlayerValue Value{};
		unsigned short Name[2]{};
		PlayerCard Card{};
		unsigned short ID{};
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
	string SetPlayerRace(PlayerData *player, unsigned short Race);
	~Player();
private:
	void CardUsing(PlayerData *player, int CardID = 0);
	unsigned short GetCardType(int CardID = 0);
};

