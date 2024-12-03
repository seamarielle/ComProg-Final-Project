#pragma once

#include <iostream>
#include <string>

string combatActions[3][3] = {	{"ATTACK", "DEFEND", "CAST"},
								{"STATS", "SKILLS", "ITEMS"},
								{"SAVE", "LOAD", "RESET"}};

string skillOptions[4] = { "[BITE]", "[FOCUS]", "[HEAL]", "[ENDURE]" };

char line1 = static_cast<char>(196);
char line2 = static_cast<char>(205);

char bar1 = static_cast<char>(176);
char bar2 = static_cast<char>(177);
char bar3 = static_cast<char>(178);

char selector1 = static_cast<char>(174);
char selector2 = static_cast<char>(175);

void Indent(int amount, bool isTab = false)
{
	if (isTab)
	{
		for (int i = 0; i < amount; i++)
		{
			cout << "\t";
		}
	}
	else
	{
		for (int i = 0; i < amount; i++)
		{
			cout << " ";
		}
	}
}

void DrawLine(int length = 8, bool end = false)
{
	for (int i = 0; i < length; i++)
	{
		if (end)
		{
			cout << line2;
		}
		else
		{
			cout << line1;
		}
	}
	cout << endl;
}

void DrawBars(int max, int current, int length = 25)
{
	max *= length; current *= length * length;

	for (int i = 0; i < length; i++)
	{
		if (i < current / max)
		{
			cout << bar3;
		}
		else
		{
			cout << bar2;
		}
	}

	cout << endl;
}

void DisplaySkillOptions(int spacing)
{
	DrawLine(50, true);
		int distance = 0;
		

		for (int j = 0; j < 4; j++)
		{
			if (skillOption == j && exitSkillCast == 0)
			{
				cout << selector2 << " " << skillOptions[j] << " " << selector1;
			}
			else
			{
				cout << "  " << skillOptions[j] << "  ";
			}

			int length = skillOptions[j].length() + 4;

			while (true)
			{
				cout << " ";
				distance++;

				if (distance + length >= spacing)
				{
					distance = 0;
					break;
				}

			}

		}

		cout << endl << endl;

		if (exitSkillCast == 0)
		{
			Indent(19);  cout << "  [CANCEL]  " << endl;
		}
		else
		{
			Indent(19);  cout << selector2 << " [CANCEL] " << selector1 << endl;

		}

	DrawLine(50, true);
}

void DisplayCombatOptions(int spacing)
{
	DrawLine(50, true);
	for (int i = 0; i < 3; i++)
	{
		int distance = 0;

		for (int j = 0; j < 3; j++)
		{
			if (combatOption[0] == i && combatOption[1] == j)
			{
				cout << selector2 << " " << combatActions[i][j] << " " << selector1;
			}
			else
			{
				cout << "  " << combatActions[i][j] << "  ";
			}

			int length = combatActions[i][j].length() + 4;

			while (true)
			{
				cout << " ";
				distance++;

				if (distance + length >= spacing)
				{
					distance = 0;
					break;
				}

			}

		}

		cout << endl;

	}
	DrawLine(50, true);
}

void Notifications(int lines, int characterLimit)
{
	DrawLine(50, true);

		int counter = 0, nextCounter = 0, lineCounter, length = notif[notifIndex].length();
		while (counter < length)
		{
			lineCounter = 0;

			while (true)
			{
				if ((lineCounter > characterLimit && notif[notifIndex][counter] == ' ') || counter >= length || notif[notifIndex][counter] == '[')
				{
					counter++;
					break;
				}
				else
				{
					cout << notif[notifIndex][counter];
				}

				counter++;
				lineCounter++;
			}

			cout << endl;
			nextCounter++;

		}

		while (nextCounter < lines)
		{
			nextCounter++;
			cout << endl;
		}

		DrawLine(50, true);

		if (notifIndex < numberOfNotifs - 1)
		{
			notifIndex++;
		}
		else
		{
			notifFinished = true;
		}

		Pause();
}

void Welcome()
{
	cout << endl << endl << endl;
	DrawLine(50, true);
	cout << "Welcome to TEXT RPG!" << endl;
	DrawLine(50);
	Pause();
}