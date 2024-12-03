#pragma once
#include "statscreen.h"

string skillName[5] = { "BITE", "FOCUS", "HEAL", "ENDURE", "[EXIT]" };
string skillDesc[4] = { "Sink your teeth against enemy flesh and brutally tear it off", 
						"Enter a state of extreme flow and precision",
						"Reroute your energy to revitalize your body",
						"Harden your aura to brace yourself from incoming damage"};

string skillChoice[2] = { "[LEARN]", "[CANCEL]" };
int skillAction = 0;

int skillCost[4] = {8, 12, 0, 0};
int skillCooldown[4] = { 3, 5, 5, 3 };



bool showSkill = false;

void TryLearnSkill()
{
	if (skillPoints > 0)
	{
		learned[skillSelect] = true;
		skillPoints -= 1;
	}
	else
	{
		system("cls");
		DrawLine(50, true);
		cout << "You do not have enough skill points." << endl;
		DrawLine(50);
		Pause();
		system("cls");
		showSkill = false;
	}
}

void SkillOptionEnter(bool shownSkill)
{
	if (!shownSkill)
	{
		switch (skillSelect)
		{
		case 4: screen = 1; break;

		default: showSkill = true; break;
		}
	}
	else
	{
		switch (skillAction)
		{
		case 0: TryLearnSkill(); break;

		case 1: showSkill = false; skillAction = 0; break;
		}
	}
}

char EnterExit()
{
	while (true)
	{
		char input = _getch();

		if (input == '0' || input == 13)
		{
			return input;
		}
	}
}

void SkillOptionSelect(int& value, int max, bool shownSkill)
{
	int input;

	input = InputVertical();

	if (input != 0)
	{
		value -= input;
	}
	else
	{
		SkillOptionEnter(shownSkill);
	}
	Clamp(value, max);
}

void Descriptions(int characterLimit, string desc)
{
	DrawLine(50, true);

	int counter = 0, nextCounter = 0, lineCounter, length = desc.length();
	while (counter < length)
	{
		lineCounter = 0;

		while (true)
		{
			if ((lineCounter > characterLimit && desc[counter] == ' ') || counter >= length || desc[counter] == '[')
			{
				counter++;
				break;
			}
			else
			{
				cout << desc[counter];
			}

			counter++;
			lineCounter++;
		}

		cout << endl;
		nextCounter++;

	}
}

void DisplaySkills()
{
	while (screen == 4)
	{
		if(!showSkill)
		{
			DrawLine(50, true);
			Indent(19);  cout << "PLAYER SKILLS" << endl;
			DrawLine(50);

			cout << "Available Skill Points: " << skillPoints << endl << endl;

			for (int i = 0; i < 4; i++)
			{
				if (skillSelect == i)
				{
					cout << selector2 << " " << skillName[i] << " " << selector1 << endl;
				}
				else
				{
					cout << "  " << skillName[i] << "  " << endl;
				}


			}

			DrawLine(50, true);
			if (skillSelect == 4)
			{
				cout << selector2 << " " << skillName[4] << " " << selector1 << endl;
			}
			else
			{
				cout << "  " << skillName[4] << "  " << endl;
			}

			//add enter function, and then add the skills
			SkillOptionSelect(skillSelect, 4, false);
			system("cls");
		}
		else
		{
			DrawLine(50, true);
			Indent(20);  cout << skillName[skillSelect] << endl;
			DrawLine(50);

			Descriptions(42, skillDesc[skillSelect]); cout << endl << endl;
			cout << "SP Cost:	" << skillCost[skillSelect] << " SP" << endl;
			cout << "Cooldown:	" << skillCooldown[skillSelect] << " turns" << endl;
			DrawLine(50, true);

			if (!learned[skillSelect])
			{
				for (int i = 0; i < 2; i++)
				{
					if (i == skillAction)
					{
						cout << selector2 << " " << skillChoice[i] << " " << selector1 << endl;
					}
					else
					{
						cout << "  "<< skillChoice[i] << "  " << endl;
					}
				}

				SkillOptionSelect(skillAction, 1, true);

				if (learned[skillSelect])
				{
					system("cls");
					cout << endl << endl;
					DrawLine(50, true);
					cout << "You have successfully learned [" << skillName[skillSelect] << "]!" << endl;
					DrawLine(50);
					Pause("Press any key to continue");
				}
			}
			else
			{
				cout << "Skill already learned!" << endl;
				cout << selector2 << " [CANCEL] " << selector1;
				char userInput;
				do
				{
					userInput = _getch();
				} while (userInput != 13);

				showSkill = false;
			}

			system("cls");
		}

		

	}

}