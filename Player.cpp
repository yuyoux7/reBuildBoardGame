#include "Player.h"

Player::Player()
{
}

string Player::SetPlayerRace(PlayerData* player, unsigned short Race)
{
	unique_ptr<AppDataRegister> tool = make_unique<AppDataRegister>();
	string rc{}, fcc{};
	json fjson = tool->AppDataSent(TYPE_DFT, "PlayerBasicValue");
	if (fjson != NULL)
	{
		if (fjson.contains("Exist"))
		{
			if (fjson["Exist"].is_number())
				player->Value.Exist = fjson["Exist"];
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
		if (fjson.contains("Intellect"))
		{
			if (fjson["Intellect"].is_number())
				player->Value.Intellect = fjson["Intellect"];
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
		if (fjson.contains("Anchored"))
		{
			if (fjson["Anchored"].is_number())
				player->Value.Anchored = fjson["Anchored"];
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
		if (fjson.contains("Effect"))
		{
			if (fjson["Effect"].is_number())
				player->Value.Effect = fjson["Effect"]; 
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
		if (fjson.contains("Understand"))
		{
			if (fjson["Understand"].is_number())
				player->Value.Understand = fjson["Understand"];
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
		if (fjson.contains("Observatuon"))
		{
			if (fjson["Observatuon"].is_number())
				player->Value.Observatuon = fjson["Observatuon"];
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
	player->Race = Race;
	fjson = tool->AppDataSent(TYPE_DFT, "RaceBasicValue");
	if (fjson.contains(fcc) != NULL)
	{
		if (fjson[fcc].contains("Exist"))
		{
			if (fjson[fcc]["Exist"].is_number())
				player->Value.Exist += fjson[fcc]["Exist"];
			else if (fjson[fcc]["Exist"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Exist"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Exist"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Exist"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Exist"])[0])
				{
				case '*':
					player->Value.Exist *= fint;
					break;
				case '/':
					player->Value.Exist /= fint;
					break;
				case '+':
					player->Value.Exist += fint;
					break;
				case '-':
					player->Value.Exist -= fint;
					break;
				case '=':
					player->Value.Exist = fint;
					break;
				default:
					break;
				}
			}
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
		if (fjson[fcc].contains("Intellect"))
		{
			if (fjson[fcc]["Intellect"].is_number())
				player->Value.Intellect += fjson[fcc]["Intellect"];
			else if (fjson[fcc]["Intellect"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Intellect"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Intellect"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Intellect"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Intellect"])[0])
				{
				case '*':
					player->Value.Intellect *= fint;
					break;
				case '/':
					player->Value.Intellect /= fint;
					break;
				case '+':
					player->Value.Intellect += fint;
					break;
				case '-':
					player->Value.Intellect -= fint;
					break;
				case '=':
					player->Value.Intellect = fint;
					break;
				default:
					break;
				}
			}
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
		if (fjson[fcc].contains("Anchored"))
		{
			if (fjson[fcc]["Anchored"].is_number())
				player->Value.Anchored += fjson[fcc]["Anchored"];
			else if (fjson[fcc]["Anchor"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Anchored"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Anchored"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Anchored"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Anchored"])[0])
				{
				case '*':
					player->Value.Anchored *= fint;
					break;
				case '/':
					player->Value.Anchored /= fint;
					break;
				case '+':
					player->Value.Anchored += fint;
					break;
				case '-':
					player->Value.Anchored -= fint;
					break;
				case '=':
					player->Value.Anchored = fint;
					break;
				default:
					break;
				}
			}
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
		if (fjson[fcc].contains("Effect"))
		{
			if (fjson[fcc]["Effect"].is_number())
				player->Value.Effect += fjson[fcc]["Effect"];
			else if (fjson[fcc]["Effect"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Effect"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Effect"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Effect"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Effect"])[0])
				{
				case '*':
					player->Value.Effect *= fint;
					break;
				case '/':
					player->Value.Effect /= fint;
					break;
				case '+':
					player->Value.Effect += fint;
					break;
				case '-':
					player->Value.Effect -= fint;
					break;
				case '=':
					player->Value.Effect = fint;
					break;
				default:
					break;
				}
			}
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
		if (fjson[fcc].contains("Understand"))
		{
			if (fjson[fcc]["Understand"].is_number())
				player->Value.Understand += fjson[fcc]["Understand"];
			else if (fjson[fcc]["Understand"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Understand"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Understand"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Understand"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Understand"])[0])
				{
				case '*':
					player->Value.Understand *= fint;
					break;
				case '/':
					player->Value.Understand /= fint;
					break;
				case '+':
					player->Value.Understand += fint;
					break;
				case '-':
					player->Value.Understand -= fint;
					break;
				case '=':
					player->Value.Understand = fint;
					break;
				default:
					break;
				}
			}
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
		if (fjson[fcc].contains("Observatuon"))
		{
			if (fjson[fcc]["Observatuon"].is_number())
				player->Value.Observatuon += fjson[fcc]["Observatuon"];
			else if (fjson[fcc]["Observatuon"].is_string())
			{
				int fint = 0;
				for (size_t i = 1; i < string(fjson[fcc]["Observatuon"]).size(); i++)
				{
					fint += static_cast<int>((string(fjson[fcc]["Observatuon"])[i]) ^ 48) * static_cast<int>(pow(10, string(fjson[fcc]["Observatuon"]).size() - i - 1));
				}
				switch (string(fjson[fcc]["Observatuon"])[0])
				{
				case '*':
					player->Value.Observatuon *= fint;
					break;
				case '/':
					player->Value.Observatuon /= fint;
					break;
				case '+':
					player->Value.Observatuon += fint;
					break;
				case '-':
					player->Value.Observatuon -= fint;
					break;
				case '=':
					player->Value.Observatuon = fint;
					break;
				default:
					break;
				}
			}
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
		unique_ptr<AppDataRegister> AppData = make_unique<AppDataRegister>();
		if (AppData->AppDataSent(TYPE_DFT, "CardValue").contains(TimeToString(CardID)))
		{
			player->Card.ID.push_back(CardID);
			player->Card.Type.push_back(GetCardType(CardID));
		}
	}
}

unsigned short Player::GetCardType(int CardID)
{
	unique_ptr<AppDataRegister> AppData = make_unique<AppDataRegister>();
	if (AppData->AppDataSent(TYPE_DFT, "CardValue")[TimeToString(CardID)].is_array())
	{
		return AppData->AppDataSent(TYPE_DFT, "CardValue")[TimeToString(CardID)][0];
	};
	return 0;
}

