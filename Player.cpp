#include "Player.h"

Player::Player()
{
}

void Player::SetPlayerRace(PlayerData* player)
{
}

Player::~Player()
{
}

void Player::CardUsing(PlayerData* player, int CardID)
{
	if (CardID != NULL)
	{
		if (player->Card.Type != nullptr && player->Card.ID != nullptr)
		{
			size_t t = sizeof(player->Card.ID);
			unsigned short* FlashT;
			unsigned int* FlashI;
			FlashI = (unsigned int*)malloc(sizeof(unsigned int));
			FlashI = (unsigned int*)realloc(player->Card.ID, (sizeof(unsigned int) * t) + 1);
			if (FlashI != nullptr)
			{
				player->Card.ID = FlashI;
				t = sizeof(player->Card.ID);
				player->Card.ID[t - 1] = CardID;
			}
			t = sizeof(player->Card.Type);
			FlashT = (unsigned short*)malloc(sizeof(unsigned short));
			FlashT = (unsigned short*)realloc(player->Card.Type, (sizeof(unsigned short) * t) + 1);
			if (FlashT != nullptr)
			{
				player->Card.Type = FlashT;
				t = sizeof(player->Card.Type);
				player->Card.Type[t - 1] = 0;
			}
			free(FlashT);
			free(FlashI);
		}
		else
		{
			player->Card.ID = (unsigned int*)malloc(sizeof(unsigned int) * 2);
			if(player->Card.ID != nullptr)
			{
				player->Card.ID[1] = CardID;
			}
			player->Card.Type = (unsigned short*)malloc(sizeof(unsigned short) * 2);
			if (player->Card.Type != nullptr)
			{
				player->Card.Type[1] = 0;
			}
		}
	}
}

