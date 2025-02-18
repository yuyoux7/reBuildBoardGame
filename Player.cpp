#include "Player.h"

Player::Player()
{
}

string Player::SetPlayerRace(PlayerData* player, unsigned short Race)
{
	unique_ptr<AppDataRegister> tool(new AppDataRegister);
	string rc{}, fcc{};
	if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue") != NULL)
	{
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Exist"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Exist"].is_number())
				player->Value.Exist = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Exist"];
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Exist\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Exist = 0;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Intellect"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Intellect"].is_number())
				player->Value.Intellect = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Intellect"];
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Intellect\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Intellect = 100;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Anchored"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Anchored"].is_number())
				player->Value.Anchored = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Anchored"];
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Anchored\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Anchored = 100;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Effect"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Effect"].is_number())
				player->Value.Effect = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Effect"]; 
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Effect\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Effect = 0;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Understand"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Understand"].is_number())
				player->Value.Understand = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Understand"];
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Understand\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Understand = 0;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue").contains("Observatuon"))
		{
			if (tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Observatuon"].is_number())
				player->Value.Observatuon = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue")["Observatuon"];
			else {
				string T;
				ifstream Login("./Log/ELF.err");
				if (Login.is_open())
				{
					char c{};
					while (!Login.eof())
					{
						Login.get(c);
					}
				}
				Login.close();
				T[T.size() - 1] = ' ';
				ofstream LogFile("./Log/ELF.err");
				if (LogFile.is_open())
				{
					LogFile << T << "No Found Player Basic Race Value: \"Observatuon\"\n" << "Using Define Value\n";
				}
				LogFile.close();
				player->Value.Observatuon = 0;
			}
		}
	}
	else
	{
		MessageBox(NULL, string("No Have Player Basic Value").c_str(), NULL, MB_OK | MB_ICONERROR);
		exit(-1);
	}
	switch (player->Race)
	{
	case Player::People:
		rc = "People";
		break;
	case Player::God:
		rc = "God";
		break;
	case Player::Mosnster:
		rc = "Monster";
		break;
	case Player::OutPeople:
		rc = "OutPeople";
		break;
	case Player::ThinkingPeople:
		rc = "ThinkingPeople";
		break;
	case Player::Elf:
		rc = "Elf";
		break;
	case Player::Bug:
		rc = "Bug";
		break;
	case Player::NoSaveMonster:
		rc = "NoSaveMonster";
		break;
	default:
		break;
	}
	switch (Race)
	{
	case Player::People:
		fcc = "Human";
		break;
	case Player::God:
		fcc = "God";
		break;
	case Player::Mosnster:
		fcc = "Monster";
		break;
	case Player::OutPeople:
		fcc = "OutPeople";
		break;
	case Player::ThinkingPeople:
		fcc = "ThinkingPeople";
		break;
	case Player::Elf:
		fcc = "Elf";
		break;
	case Player::Bug:
		fcc = "Bug";
		break;
	case Player::NoSaveMonster:
		fcc = "NoSaveMonster";
		break;
	default:
		break;
	}
	if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue").contains(fcc))
	{
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Exist"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Exist"] == "*0")
			{
				player->Value.Exist = 0;
			}
			else if(tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Exist"].is_number())
				player->Value.Exist += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Exist"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Exist\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Exist += 0;
				break;
			case Player::God:
				player->Value.Exist += 0;
				break;
			case Player::Mosnster:
				player->Value.Exist += 0;
				break;
			case Player::OutPeople:
				player->Value.Exist += 0;
				break;
			case Player::ThinkingPeople:
				player->Value.Exist += 0;
				break;
			case Player::Elf:
				player->Value.Exist += 5;
				break;
			case Player::Bug:
				player->Value.Exist += 5;
				break;
			case Player::NoSaveMonster:
				player->Value.Exist = 0;
				break;
			default:
				break;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Intellect"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Intellect"] == "=50")
			{
				player->Value.Intellect = 50;
			}
			else if(tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Intellect"].is_number())
				player->Value.Intellect += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Intellect"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Intellect\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Intellect += 0;
				break;
			case Player::God:
				player->Value.Intellect += 0;
				break;
			case Player::Mosnster:
				player->Value.Intellect += 0;
				break;
			case Player::OutPeople:
				player->Value.Intellect = 50;
				break;
			case Player::ThinkingPeople:
				player->Value.Intellect += 0;
				break;
			case Player::Elf:
				player->Value.Intellect += 0;
				break;
			case Player::Bug:
				player->Value.Intellect += 0;
				break;
			case Player::NoSaveMonster:
				player->Value.Intellect += 2;
				break;
			default:
				break;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Anchored"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Anchored"] == "=50")
			{
				player->Value.Anchored = 50;
			}
			else if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Anchored"] == "=75")
			{
				player->Value.Anchored = 75;
			}
			else if(tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Anchored"].is_number())
				player->Value.Anchored += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Anchored"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Anchored\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Anchored += 0;
				break;
			case Player::God:
				player->Value.Anchored += 0;
				break;
			case Player::Mosnster:
				player->Value.Anchored += 0;
				break;
			case Player::OutPeople:
				player->Value.Anchored += 0;
				break;
			case Player::ThinkingPeople:
				player->Value.Anchored = 50;
				break;
			case Player::Elf:
				player->Value.Anchored += 0;
				break;
			case Player::Bug:
				player->Value.Anchored = 75;
				break;
			case Player::NoSaveMonster:
				player->Value.Anchored += 2;
				break;
			default:
				break;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Effect"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Effect"].is_number())
				player->Value.Effect += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Effect"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Effect\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Effect += 0;
				break;
			case Player::God:
				player->Value.Effect += 0;
				break;
			case Player::Mosnster:
				player->Value.Effect += 5;
				break;
			case Player::OutPeople:
				break;
			case Player::ThinkingPeople:
				player->Value.Effect += 0;
				break;
			case Player::Elf:
				player->Value.Effect += 0;
				break;
			case Player::Bug:
				player->Value.Effect += 5;
				break;
			case Player::NoSaveMonster:
				player->Value.Effect += 2;
				break;
			default:
				break;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Understand"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Understand"].is_number())
				player->Value.Understand += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Understand"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Understand\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Understand += 0;
				break;
			case Player::God:
				player->Value.Understand += 5;
				break;
			case Player::Mosnster:
				player->Value.Understand += 0;
				break;
			case Player::OutPeople:
				player->Value.Understand += 0;
				break;
			case Player::ThinkingPeople:
				player->Value.Understand += 0;
				break;
			case Player::Elf:
				player->Value.Understand += 0;
				break;
			case Player::Bug:
				player->Value.Understand += 0;
				break;
			case Player::NoSaveMonster:
				player->Value.Understand += 2;
				break;
			default:
				break;
			}
		}
		if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc].contains("Observatuon"))
		{
			if (tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Observatuon"].is_number())
				player->Value.Observatuon += tool->AppDataSent(TYPE_DFT, "RaceBasicValue")[fcc]["Observatuon"];
		}
		else
		{
			string T;
			ifstream Login("./Log/ELF.err");
			if (Login.is_open())
			{
				char c{};
				while (!Login.eof())
				{
					Login.get(c);
				}
			}
			Login.close();
			T[T.size() - 1] = ' ';
			ofstream LogFile("./Log/ELF.err");
			if (LogFile.is_open())
			{
				LogFile << T << "No Found Player Basic Race Value: \"Observatuon\"\n" << "Using Define Value\n";
			}
			LogFile.close();
			switch (Race)
			{
			case Player::People:
				player->Value.Observatuon += 5;
				break;
			case Player::God:
				player->Value.Observatuon += 0;
				break;
			case Player::Mosnster:
				player->Value.Observatuon += 0;
				break;
			case Player::OutPeople:
				player->Value.Observatuon += 0;
				break;
			case Player::ThinkingPeople:
				player->Value.Observatuon += 0;
				break;
			case Player::Elf:
				player->Value.Observatuon += 0;
				break;
			case Player::Bug:
				player->Value.Observatuon += 0;
				break;
			case Player::NoSaveMonster:
				player->Value.Observatuon += 5;
				break;
			default:
				break;
			}
		}
		player->Race = Race;
	}
	else
	{
		MessageBox(NULL, string("No Have Race: " + rc).c_str(), NULL, MB_OK | MB_ICONERROR);
		exit(-1);
	}
	return string("Race_" + rc);
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

