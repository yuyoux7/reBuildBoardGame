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
			if (player->Card.Type[0] == player->Card.ID[0])
			{
				size_t t = player->Card.ID[0];
				unsigned short* FlashT;
				unsigned int* FlashI;
				FlashI = (unsigned int*)realloc(player->Card.ID, (sizeof(unsigned int*) * (t + 1)));
				if (FlashI != nullptr)
				{
					player->Card.ID = FlashI;
					player->Card.ID[0] = t + 1;
					player->Card.ID[t - 1] = CardID;
				}
				t = sizeof(player->Card.Type);
				FlashT = (unsigned short*)realloc(player->Card.Type, (sizeof(unsigned short*) * (t + 1)));
				if (FlashT != nullptr)
				{
					player->Card.Type = FlashT;
					player->Card.Type[0] = t + 1;
					player->Card.Type[t - 1] = 0;
				}
			}
		}
		else
		{
			player->Card.ID = (unsigned int*)malloc(sizeof(unsigned int*) * 2);
			if(player->Card.ID != nullptr)
			{
				player->Card.ID[0] = 1;
				player->Card.ID[1] = CardID;
			}
			player->Card.Type = (unsigned short*)malloc(sizeof(unsigned short*) * 2);
			if (player->Card.Type != nullptr)
			{
				player->Card.Type[0] = 1;
				player->Card.Type[1] = 0;
			}
		}
	}
}

