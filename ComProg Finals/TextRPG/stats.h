#pragma once

#include <vector>
#include <string>

using namespace std;

bool isAlive = true;

struct Item
{
	string name;
	string desc;
};

vector<Item> items = { {"", ""}, {"Health Potion", "Restores 25 HP"}, {"Stamina Potion", "Restores 25 SP"}};

int inventory[10];
int cd[4];
bool learned[4];

int

level,
statPoints,
skillPoints,

expGain,
maxExp,
currentExp,
overGain,

maxHealth, 
currentHealth,

maxStamina,
currentStamina,

bru,
dex,
vit,
ten,

atk,
def,

dmg;


class Enemy
{
public:

	int exp;
	int maxHealth;
	int currentHealth;
	int atk;
	int dmg;
};

Enemy enemy;

void Initialize()
{
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = 0;

		/*if (i % 2 == 0)
		{
			inventory[i] = 1;
		}
		else
		{
			inventory[i] = 2;
		}*/
	}

	level = 1;
	statPoints = 0;
	skillPoints = 0;

	maxExp = 50 + level * 50;
	currentExp = 0;

	maxHealth = 100;
	currentHealth = maxHealth;

	maxStamina = 100;
	currentStamina = maxStamina;

	bru = 10;
	dex = 10;
	vit = 10;
	ten = 10;

	atk = 3;
	def = 3;

}

void SortInventory()
{
	bool firstTick = false, secondTick = false;

	do
	{
		firstTick = false;
		secondTick = false;

		for (int i = 0; i < 9; i++)
		{
			
			if (inventory[i] == 0)
			{
				if (!firstTick)
				{
					firstTick = true;
				}
			}
			else if (firstTick)
			{
				if (!secondTick)
				{
					secondTick = true;
				}
			}
		}

		for (int i = 0; i < 9; i++)
		{
			
				if (inventory[i] == 0)
				{
					inventory[i] = inventory[i + 1];
					inventory[i + 1] = 0;
				}
			
		}
	} while (secondTick);
}

bool AddItem(int id)
{
	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = id;
			return true;
		}
	}

	return false;

}

int Damage(int& health, int damage)
{
	health -= damage;
	return damage;
}