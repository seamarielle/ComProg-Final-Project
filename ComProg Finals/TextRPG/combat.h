#pragma once

#include "itemscreen.h"


void PlayerAttack()
{

		enemy.currentHealth -= dmg;
		Clamp(enemy.currentHealth, enemy.maxHealth);



}

void EnemyAttack()
{
	currentHealth -= enemy.dmg;
	Clamp(currentHealth, maxHealth);
}

void ExpGain()
{

	if (currentExp + expGain > maxExp)
	{
		overGain = currentExp + expGain - maxExp;
		expGain -= overGain;
	}
	currentExp += expGain;
}

void LevelUp()
{
	level++;
	currentHealth = maxHealth;
	currentStamina = maxStamina;
	statPoints += 3;
	skillPoints++;
	currentExp = 0;
	maxExp = 50 + level * 50;

	if (overGain > 0)
	{
		currentExp += overGain;
		overGain = 0;
	}

}

void Die()
{
	isAlive = false;
}

void Action()
{
	if (action == "attack")
	{
		PlayerAttack();
		EnemyAttack();
	}
	if (action == "defend")
	{
		EnemyAttack();
	}
	if (action == "enemydeath")
	{
		ExpGain();
	}
	if (action == "levelup")
	{
		LevelUp();
	}
	if (action == "death")
	{
		Die();
	}

	action = "null";

}

void CheckForEvents()
{
	if (enemy.currentHealth <= 0)
	{
		EnemyDeath();
	}
	if (currentExp >= maxExp)
	{
		ExpMaxed();
	}
	if (currentHealth <= 0)
	{
		Death();
	}
}

void DisplayCombat()
{
	while (isAlive && screen == 1)
	{
		system("cls");

		if (notifFinished)
		{
			Action();
			notifFinished = false;
		}

		CheckForEvents();

		Indent(60);		DrawLine(20, true);
		Indent(60);		cout << "Enemy" << endl;
		Indent(60);		cout << "HP: " << enemy.currentHealth << "/" << enemy.maxHealth << endl;
		Indent(60);		DrawBars(enemy.maxHealth, enemy.currentHealth, 15);
		Indent(60);		DrawLine(20, true);


		DrawLine(50, true);
		cout << "LEVEL " << level << "		   " << "EXP: " << currentExp << "/" << maxExp << "    ";
		
		DrawBars(maxExp, currentExp, 15);
		cout << endl << endl;

		cout << "HP: " << currentHealth << "/" << maxHealth << endl;
		DrawBars(maxHealth, currentHealth);
		cout << endl << endl;

		cout << "SP: " << currentStamina << "/" << maxStamina << endl;
		DrawBars(maxStamina, currentStamina);



		if (action == "null")
		{
			DisplayCombatOptions(20);
			MatrixOptionSelect();
		}
		else if (action == "cast")
		{
			DisplaySkillOptions(13);
			SkillCastSelect();
		}
		else
		{
			Notifications(3, 42);
			if (enemy.currentHealth <= 0)
			{
				SpawnEnemy();
			}
		}







		system("cls");
	}



}



/*		THIS CODE IS FOR 2D INPUT TABLES
		for (int i = 0; i < 3; i++)
		{
			if (option == i)
			{
				cout << ">	" << num[i] << endl;
			}
			else
			{
				cout << "	" << num[i] << endl;
			}
		}

		InputPair(num[option], option);
		*/