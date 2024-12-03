#pragma once
#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <fstream>
#include "stats.h"

int screen = 1;
int statSelect = 0;
int skillSelect = 0;

int combatOption[2];
int skillOption;
int exitSkillCast;
string action = "null";
vector<string> notif = { "", "", "", "", ""};
int numberOfNotifs = 1;
int notifIndex;
bool notifFinished;

const int regenTurns = 2;
int regen = 0;



void Clamp(int& input, int max, int min = 0)
{
	if (input < min)
	{
		input = min;
	}
	if (input > max)
	{
		input = max;
	}
}

void Regen()
{
	regen++;

	for (int i = 0; i < 4; i++)
	{
		cd[i]--;
		if (cd[i] < 0)
		{
			cd[i] = 0;
		}
	}

	if (regenTurns <= regen)
	{
		currentHealth += maxHealth / 80;
		currentStamina += maxStamina / 80;
		regen = 0;
	}
}



void CalculateStats()
{
	maxHealth = vit * 10;
	maxStamina = bru * 10;
	atk = (bru / 2) + level;
	def = (vit / 2) + level;
}

void ReturnToCombat()
{
	CalculateStats();
	screen = 1;
}

void Debug(string text, bool pause = false)
{
	cout << text << endl;
	system("pause");
}

int Random(int min = 0, int max = 100)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

bool Roll(int rate)
{
	if (Random() <= rate)
	{
		return true;
	}
	else
	{
		return false;
	}
}



int RollDamage(int baseAtk, int increase)
{
	return baseAtk + Random(0, increase);
}

int RollDamage(int baseAtk, int decrease, int increase)
{
	return baseAtk + Random(decrease, increase);
}

void Attack()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	int cost = Random(1, 3);
	if (currentStamina - cost >= 0)
	{
		currentStamina -= cost;
		dmg = RollDamage(atk, 3);
		enemy.dmg = RollDamage(enemy.atk, 3);

		action = "attack";
		notif[0] = "You attacked! The enemy lost " + to_string(dmg) + " HP.[[The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
	}
	else
	{
		dmg = 0;
		action = "attack";
		enemy.dmg = RollDamage(enemy.atk, 3);
		notif[0] = "Your stamina fails you...[[The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
	}

	
}

void Bite()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	if (learned[0])
	{
		if (currentStamina - 8 >= 0)
		{
			
			if (cd[0] <= 0)
			{
				currentStamina -= 8;
				dmg = RollDamage(bru, atk);
				enemy.dmg = RollDamage(enemy.atk, 3) - def;
				cd[0] = 4;
				Regen();

				action = "attack";
				notif[0] = "You sink your teeth in the enemy and tear away a chunk of flesh![You deal " + to_string(dmg) + " damage![The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
			}
			else
			{
				action = "huh";
				notif[0] = "Bite is in cooldown for " + to_string(cd[0]) + " turns.";
			}
		}
		else
		{
			dmg = 0;
			action = "attack";
			enemy.dmg = RollDamage(enemy.atk, 3);
			notif[0] = "Your stamina fails you...[[The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
		}
	}
	else
	{
		action = "huh";
		notif[0] = "Please learn the skill first.";
	}
}

void Heal()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	if (learned[2])
	{
		int heal = Random(vit * 2, vit * 3);

		if (currentStamina - heal >= 0)
		{
			
			if (cd[2] <= 0)
			{
				currentStamina -= heal;
				currentHealth += heal;
				Clamp(currentHealth, maxHealth);
				
				enemy.dmg = RollDamage(enemy.atk, 3) - def;
				cd[2] = 6;
				Regen();

				action = "defend";
				notif[0] = "You channel your energy and heal.[" + to_string(heal) + " HP restored![The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
			}
			else
			{
				action = "huh";
				notif[0] = "Heal is in cooldown for " + to_string(cd[2]) + " turns.";
			}
		}
		else
		{
			dmg = 0;
			action = "attack";
			enemy.dmg = RollDamage(enemy.atk, 3);
			notif[0] = "Your stamina fails you...[[The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
		}
	}
	else
	{
		action = "huh";
		notif[0] = "Please learn the skill first.";
	}
}

void Defend()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	enemy.dmg = RollDamage(enemy.atk, 3) - def;
	Clamp(enemy.dmg, 9999, 1);

	action = "defend";
	notif[0] = "You assume a defentive stance![[The enemy attacked! You lost " + to_string(enemy.dmg) + " HP!";
}

void OpenScreen(int index)
{
	screen = index;
}
void EnemyDeath()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	expGain = enemy.exp;

	action = "enemydeath";
	notif[0] = "The enemy was slain. You have gained " + to_string(expGain) + " EXP.";

	if (Roll(30))
	{
		numberOfNotifs = 2;

		if (Roll(50))
		{
			if (AddItem(1))
			{
				notif[1] = "The enemy dropped a Health Potion!";
			}
			else
			{
				notif[1] = "The enemy dropped a Health Potion![[...But your bag is full.";
			}
		}
		else
		{
			if (AddItem(2))
			{
				notif[1] = "The enemy dropped a Stamina Potion!";
			}
			else
			{
				notif[1] = "The enemy dropped a Stamina Potion![[...But your bag is full.";
			}
		}
	}

}

void ExpMaxed()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	action = "levelup";
	notif[0] = "You have leveled up! 3 Stat Points and 1 Skill Point awarded!";
}

void Death()
{
	numberOfNotifs = 1;
	notifIndex = 0;

	action = "death";
	notif[0] = "Your HP has been depleted. May your soul fare well in the afterlife.";
}

void SpawnEnemy()
{
	enemy.exp = 33 + level * 2 + Random(-3, 5 + level);
	enemy.maxHealth = 18 + (level * 2) + Random(0, 2 + level * 3);
	enemy.currentHealth = enemy.maxHealth;
	enemy.atk = level + 2;
}

void Pause()
{
	_getch();
}

void Pause(string text)
{
	cout << text << endl;
	_getch();
}


char InputGuard()
{
	char input;

	while (true)
	{
		input = _getch();

		if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 13)
		{
			return input;
		}

	}

}

char InputGuardVertical()
{
	char input;

	while (true)
	{
		input = _getch();

		if (input == 'w'|| input == 's' || input == 13)
		{
			return input;
		}

	}
}



int InputHorizontal()
{
	switch (_getch())
	{
		case 'a': return -1; break;

		case 'd': return 1; break;

		default: return 0; break;
	}
}

int InputVertical()
{
	switch (InputGuardVertical())
	{
	case 'w': return 1; break;

	case 's': return -1; break;

	default: return 0; break;
	}
}



pair<int, bool> NestedInput()
{
	//FALSE IS VERTICAL
	//TRUE IS HORIZONTAL

	switch (InputGuard()
		)
	{
		case 'w': return make_pair(1, false); break;

		case 's': return make_pair(-1, false); break;

		case 'a': return make_pair(-1, true); break;

		case 'd': return make_pair(1, true); break;

		case 13: return make_pair(0, false); break;
	}
}

void CastOptionEnter()
{
	

	if (exitSkillCast == 1)
	{
		action = "null";
	}
	else
	{
		switch (skillOption)
		{
		case 0: action = "null"; Bite(); break;
		case 2: action = "null"; Heal(); break;


		}
	}
}

void Clear()
{
	Initialize();
	SpawnEnemy();

	numberOfNotifs = 1;
	notifIndex = 0;

	notif[0] = "Progress has been reset.";
	action = "save";

}

void Load()
{
	ifstream load("save.txt");
	if(load.is_open())
	{
		load >> level >> statPoints >> skillPoints >> maxExp >>
			currentExp >> maxHealth >> currentHealth >> maxStamina
			>> currentStamina >> bru >> dex >> vit >> ten >> enemy.maxHealth
			>> enemy.currentHealth >> enemy.exp;

		for (int i = 0; i < 10; i++)
		{
			load >> inventory[i];
		}

		for (int i = 0; i < 4; i++)
		{
			load >> learned[i] >> cd[i];
		}

		numberOfNotifs = 1;
		notifIndex = 0;

		notif[0] = "Game loaded.";
		action = "save";

	}
	else
	{
		numberOfNotifs = 1;
		notifIndex = 0;

		notif[0] = "Unable to load game.";
		action = "save";
	}
}

void Save()
{
	ofstream save("save.txt");
	if (save.is_open())
	{
		save
			<< level << " "
			<< statPoints << " "
			<< skillPoints << " "
			<< maxExp << " "
			<< currentExp << " "
			<< maxHealth << " "
			<< currentHealth << " "
			<< maxStamina << " "
			<< currentStamina << " "
			<< bru << " "
			<< dex << " "
			<< vit << " "
			<< ten << " "

			<< enemy.maxHealth << " "
			<< enemy.currentHealth << " "
			<< enemy.exp << " ";

		for (int i = 0; i < 10; i++)
		{
			save << inventory[i] << " ";
		}

		for (int i = 0; i < 4; i++)
		{
			save << learned[i] << " " << cd[i] << " ";
		}

		numberOfNotifs = 1;
		notifIndex = 0;

		notif[0] = "Game saved.";
		action = "save";

	}
	else
	{

	}
}

void MatrixOptionEnter()
{
	int index = combatOption[1] + (combatOption[0] * 3);

	switch (index)
	{
	case 0: Attack(); Regen(); break;
	case 2: action = "cast"; break;
	case 1: Defend(); Regen(); break;
	case 6: Save(); break;
	case 7: Load(); break;
	case 8: Clear();  break;
	default: OpenScreen(index); statSelect = 0; skillSelect = 0; break;
	}

	

}

auto InputPair(int& firstValue, int& secondValue, int firstMax, int secondMax)
{
	auto select = NestedInput();

	if (select.first != 0)
	{
		if (!select.second)
		{
			firstValue -= select.first;
			Clamp(firstValue, secondMax);
		}
		else
		{
			secondValue += select.first;
			Clamp(secondValue, firstMax);
		}
	}
	else
	{
		MatrixOptionEnter();
	}
}

auto CastInputPair(int& firstValue, int& secondValue, int firstMax, int secondMax)
{
	auto select = NestedInput();

	if (select.first != 0)
	{
		if (!select.second)
		{
			firstValue -= select.first;
			Clamp(firstValue, secondMax);
		}
		else
		{
			secondValue += select.first;
			Clamp(secondValue, firstMax);
		}
	}
	else
	{
		CastOptionEnter();
	}
}

void SkillCastSelect()
{
	CastInputPair(exitSkillCast, skillOption, 3, 1);
}

void MatrixOptionSelect()
{
	InputPair(combatOption[0], combatOption[1], 2, 2);
}


void ClampData()
{
	Clamp(currentHealth, maxHealth);
	Clamp(currentStamina, maxStamina);
}

