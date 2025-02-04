#pragma once
#include "ExampleH.h"
class Player
{
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
		unsigned short *Type = nullptr;
		unsigned int *ID = nullptr;
	}PlayerCard;
	typedef struct _tag
	{
		PlayerValue Value{};
		PlayerCard Card{};
		unsigned short ID{};
		unsigned short Name[2]{};
		unsigned short Map{};
		unsigned short AttackType{};
	}PlayerData;
public:
	Player();
	void SetPlayerRace(PlayerData *player);
	~Player();
private:
	void CardUsing(PlayerData *player, int CardID = 0);
};

