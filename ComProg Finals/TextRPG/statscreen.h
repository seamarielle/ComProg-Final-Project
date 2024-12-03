#pragma once

#include "system.h"
#include "display.h"


int increment[4];
int totalIncrement;
string statName[7] = {"BRU", "DEX", "VIT", "TEN", "[SAVE]", "[CANCEL]", "[EXIT]"};
int stats[4];

class Unsaved
{
public:
	int bru, dex, vit, ten, statPoints;
};

Unsaved unsaved;

void ReturnStats()
{
	bru = stats[0];
	dex = stats[1];
	vit = stats[2];
	ten = stats[3];
}



void SaveStats()
{
	for (int i = 0; i < 4; i++)
	{
		stats[i] += increment[i];
		increment[i] = 0;
	}

	statPoints -= totalIncrement;
	totalIncrement = 0;

	ReturnStats();
}

void RemoveStats()
{
	for (int i = 0; i < 4; i++)
	{
		increment[i] = 0;
	}

	totalIncrement = 0;
}

void StatOptionEnter()
{
	switch (statSelect)
	{
	case 4: SaveStats(); break;
	case 5: RemoveStats(); break;
	case 6: ReturnToCombat(); break;
	}
}

auto ConditionalInputPair(int& firstValue, int& secondValue, int firstMax, int secondMax)
{
	auto select = NestedInput();

	if (select.first != 0)
	{
		if (!select.second)
		{
			firstValue -= select.first;
			Clamp(firstValue, secondMax);
		}
		else if(statSelect <= 3 && statSelect >= 0)
		{
			if (increment[statSelect] < unsaved.statPoints + increment[statSelect])
			{
				if (select.first > 0)
				{
					secondValue += select.first;
				}
			}

			if (select.first < 0)
			{
				secondValue += select.first;
			}

			

			Clamp(secondValue, firstMax);

		}
	}
	else
	{
		StatOptionEnter();
	}
}

void StatOptionSelect()
{
	ConditionalInputPair(statSelect, increment[statSelect], statPoints, 6);
}

void PassStats()
{
	stats[0] = bru;
	stats[1] = dex;
	stats[2] = vit;
	stats[3] = ten;
}

void DisplayStats()
{
	PassStats();



	while (screen == 3)
	{
		totalIncrement = 0;

		for (int i = 0; i < 4; i++)
		{
			totalIncrement += increment[i];
		}

		unsaved.statPoints = statPoints - totalIncrement;

		DrawLine(50, true);
		Indent(20);  cout << "PLAYER STATS" << endl;
		DrawLine(50);

		cout << "Unallocated Stat Points: " << statPoints << endl << endl;


		for (int i = 0; i < 4; i++)
		{
			if (i == statSelect)
			{
				cout << selector2 << " ";
			}
			else
			{
				cout << "  ";
			}

			cout << statName[i] << "	";
			
			if (increment[i] <= 0)
			{
				cout << "  ";
			}
			else
			{
				cout << "- ";
			}

			cout << stats[i];

			if (increment[i] >= unsaved.statPoints + increment[i])
			{
				cout << "  ";
			}
			else
			{
				cout << " +";
			}

			if (increment[i] > 0)
			{
				cout << "    (+" << increment[i] << ")";
			}

			cout << endl;
		}


		DrawLine(50, true);
		for (int i = 4; i < 7; i++)
		{
			if (i == statSelect)
			{
				cout << selector2 << " ";
			}
			else
			{
				cout << "  ";
			}

			cout << statName[i];

			if (i == statSelect)
			{
				cout << " " << selector1;
			}
			else
			{
				cout << "  ";
			}

			cout << endl;

		}

		StatOptionSelect();
		system("cls");
	}
}
