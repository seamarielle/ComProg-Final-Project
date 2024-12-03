#pragma once

#include "skillscreen.h"

string subOps[3] = { " [USE] ", " [DROP] ", " [CANCEL] " };

int itemSelect = 0;
int itemSubSelect = 0;

void UseHealthPot()
{
	currentHealth += 25;
	ClampData();
	system("cls");
	DrawLine(50, true);
	cout << "You gulp down the contents of a health potion." << endl << endl;
	cout << "25 HP restored!" << endl;
	DrawLine(50);
	Pause();
}

void UseStaminaPot()
{
	currentStamina += 25;
	ClampData();
	system("cls");
	DrawLine(50, true);
	cout << "You gulp down the contents of a stamina potion." << endl << endl;
	cout << "25 SP restored!" << endl;
	DrawLine(50);
	Pause();
}

bool ItemSubOptionEnter()
{
	if (itemSubSelect == 2)
	{
		return true;
	}
	else if(itemSubSelect == 0)
	{
		switch (inventory[itemSelect])
		{
		case 1: UseHealthPot(); break;

		case 2: UseStaminaPot(); break;
		}

		

	}

	inventory[itemSelect] = 0;
	SortInventory();
	return true;

}

bool ItemSubOptionSelect(int& value, int max)
{
	int input;

	input = InputVertical();

	if (input != 0)
	{
		value -= input;
		
	}
	else
	{
		return ItemSubOptionEnter();
	}
	Clamp(value, max);
	return false;
}


void DisplayItem()
{
	while (true)
	{
		system("cls");
		DrawLine(50, true);
		cout << items[inventory[itemSelect]].name << endl << endl << items[inventory[itemSelect]].desc << endl;
		DrawLine(50);

		for (int i = 0; i < 3; i++)
		{
			if (itemSubSelect == i)
			{
				cout << selector2;
			}
			else
			{
				cout << ' ';
			}

			cout << subOps[i];

			if (itemSubSelect == i)
			{
				cout << selector1;
			}
			else
			{
				cout << ' ';
			}

			cout << endl;
		}

		if (ItemSubOptionSelect(itemSubSelect, 2))
		{
			break;
		}

	}
}

void ItemOptionEnter()
{
	itemSubSelect = 0;

	if (itemSelect == 10)
	{
		screen = 1;
	}
	else if (inventory[itemSelect] != 0)
	{
		DisplayItem();
	}
}

void ItemOptionSelect(int& value, int max)
{
	int input;

	input = InputVertical();

	if (input != 0)
	{
		value -= input;
	}
	else
	{
		ItemOptionEnter();
	}
	Clamp(value, max);
}

void DisplayInventory()
{
	itemSelect = 0;

	while (screen == 5)
	{
		system("cls");
		DrawLine(50, true);
		Indent(23);  cout << "ITEMS" << endl;
		DrawLine(50);

		for (int i = 0; i < 10; i++)
		{
			if (itemSelect == i)
			{
				cout << selector2;
			}
			else
			{
				cout << ' ';
			}

			switch (inventory[i])
			{
			case 0: cout << " [Empty slot]"; break;

			default: cout << " [" << items[inventory[i]].name << "]"; break;
			}

			cout << endl;
		}

		DrawLine(50);

		if (itemSelect == 10)
		{
			cout << selector2 << " [EXIT] " << selector1;
		}
		else
		{
			cout << "  [EXIT]  ";
		}

		ItemOptionSelect(itemSelect, 10);
		
	}
}