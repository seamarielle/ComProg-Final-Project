#include "combat.h"

int main()
{
	Welcome();
	Initialize();
	SpawnEnemy();

	while (isAlive)
	{
		
		DisplayCombat();
		DisplayStats();
		DisplaySkills();
		DisplayInventory();
	}

	
	DrawLine(50, true);
	cout << "Thank you for playing TEXT RPG!" << endl;
	DrawLine(50);
	Pause();

}