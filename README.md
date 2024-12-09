
https://github.com/user-attachments/assets/ff66032b-03c3-4ad4-9513-21e1475407b7

# 🎯 TEXT ROLE PLAY GAME

## ![image](https://github.com/user-attachments/assets/ee8d5262-1d0e-49f1-aba8-d0dcba408925)

##### 👩‍💻 Welcome to the Text-Based RPG Project! 
##### 🎮 This project is a role-playing game developed in C++ that leverages the principles of CRUD (Create, Read, Update, Delete) operations to manage game elements dynamically. 
##### ⚔️ With the use of these operations, players can interact with the game world by creating characters, tracking progress, and modifying stats, skills, and inventory. 
##### 🛡️ The game presents an engaging text-based interface where each action influences the game’s outcome, making it a fun way to experience strategic decision-making. 
##### 💡 Get ready to dive into a world of adventure, quests, and character development! 🚀

-----------

## ![image](https://github.com/user-attachments/assets/1cd6da02-279b-4865-9a56-d59f5c8312fe)

##### 👩‍💻 The Text-Based RPG Project is a comprehensive role-playing game developed in C++ that immerses players in a text-based adventure filled with character development, quests, and item management. 
##### 🎮 The game leverages CRUD (Create, Read, Update, Delete) operations to facilitate the management of various game elements, allowing players to interact with a rich and dynamic environment. 
##### ⚔️ Players can create unique characters, each with distinct attributes and abilities, and embark on quests that challenge their skills and decision-making. 
##### 🛡️ The project not only serves as an engaging gaming experience but also acts as a practical demonstration of C++ programming concepts, particularly in data management and object-oriented programming. 
##### 💻 Overall, this project aims to provide both entertainment and educational value, showcasing the potential of C++ in game development. 🎓

----------------

## 📽️ Console Program Design
![image](https://github.com/user-attachments/assets/7bd078fe-0486-4367-8faf-9fbb6c347144)

----------------

## ![image](https://github.com/user-attachments/assets/c08cd099-6b3d-4543-b969-4bc1537ed5e8)

👩‍💻 The Text-Based RPG Project incorporates a variety of features that enhance gameplay and provide players with a rich interactive experience. The game is structured around several key functionalities, each of which utilizes CRUD (Create, Read, Update, Delete) operations to manage game elements effectively. Below is a detailed explanation of how these features work, including the specific CRUD operations associated with them.

## ⚙ Key Features
### 🛠️ Create Character:  
Players can create a new character by entering a name and selecting a class, such as warrior, mage, or rogue. ⚔️ This process involves defining initial attributes like health points, attack power, defense, and special abilities. 🌟 The character creation feature allows players to customize their gaming experience from the outset, setting the stage for their journey. 🏰

### 🎒 Manage Inventory:  
The inventory management system allows players to create and manage items they acquire throughout the game. 🛠️ Players can create new items by specifying their type (e.g., weapon, armor, potion), effects, and rarity. ⚔️ This feature is crucial for character development, as players can equip items that enhance their abilities or provide strategic advantages in battles.  

### ⚔️ Combat Mechanics:  
The game includes combat features such as Attack, Defend, and Cast spells. 🔥 During combat, players can choose to attack enemies, defend against incoming attacks, or cast spells that can heal or deal damage. 🧙‍♂️ Each of these actions can be influenced by the character's stats and skills, making strategic decision-making essential for success. 🏆

### 📊 Skills and Stats:  
Players can view and manage their character's skills and stats. 📊 This feature allows players to read their current abilities, such as strength, agility, and intelligence, and understand how these attributes affect gameplay. 🏋️‍♂️ Players can also update their skills as they level up, enhancing their character's effectiveness in combat and exploration. 🏞️

### 📜 Quest Management:  
Players can create, read, update, and delete quests. ✨ They can create new quests by defining objectives and rewards, read about available quests to choose which to undertake, update quest progress as they complete objectives, and delete quests that they no longer wish to pursue. 🌟 This dynamic quest management system keeps the gameplay engaging and allows for a personalized experience.  

### 💾 Save and Load Game:  
The game includes functionality to save and load progress. 💾 Players can create a save file that captures their current character state, inventory, and quest progress. 📂 This feature allows players to return to the game at a later time without losing their achievements. ⏳ The load function enables players to read their saved data and restore their previous game state.  

### 🔄 Reset Game:  
If players wish to start anew, they can reset the game, which deletes all current characters, items, and quests. 🔄 This feature allows players to create a fresh character and experience the game from the beginning, making it ideal for those who want to explore different character builds or strategies. 🎮

------------- 
## 🔎 Key Objectives: CRUD Operations

| No. | Objective |
|-----|-----------|
| 1   | Create new characters, items, and quests. |
| 2   | Read information about existing game elements |
| 3   | Update attributes of characters, items, and quests. |
| 4   | Delete or save progress |

### 📝 How CRUD Operations Work  

### ✨ Create:  
The Create operations are utilized when players create characters, items, quests, and save files. 🛠️ For example, when a player creates a character, the game generates a new entry in the character database with all specified attributes. 🌟 Similarly, new items and quests are added to their respective lists, allowing players to expand their gameplay options. 📦

### 👁️‍🗨️ Read:  
The Read operations allow players to view existing characters, items, quests, and stats. 📊 Players can access detailed information about their character's current state, including health, experience points, and equipped items. 💪 The inventory system enables players to read descriptions of items, while quest management allows them to read about available quests and their objectives. 📜

### 🔄 Update:  
Update operations are crucial for character progression and inventory management. 💥 As players complete quests or defeat enemies, they can update their character's stats, such as increasing health or attack power. 🏋️‍♂️ Items can also be updated, allowing players to enhance their effectiveness or change their attributes. 🛡️ Additionally, quest progress can be updated as players complete objectives, ensuring that the game reflects their current achievements. 🏆

### 🗑️ Delete:  
The Delete operations provide players with the ability to remove characters, items, quests, and save files that are no longer needed. 🚮 For instance, if a player decides to abandon a quest, they can delete it from their quest log. 📝 Similarly, players can delete items from their inventory that they no longer wish to keep, helping to streamline their gameplay experience. 🔄 The reset feature allows players to delete all current game data, providing a clean slate for new adventures. 🌍

By integrating these features and CRUD operations, the Text-Based RPG Project offers a comprehensive and engaging gaming experience. 🎮 Players can immerse themselves in a world of adventure, strategy, and character development, all while utilizing fundamental programming concepts in C++. 💻

------------

## File Structure of Project: TextRPG

**TextRPG Directory** This is the root directory of the TextRPG project, which contains all the necessary files and folders for the development and execution of the game.

### .vs Directory
The .vs directory is created by Visual Studio and contains various files related to the development environment and debugging processes.

#### Debug Folder: This folder contains files generated during the debugging and build processes.
##### TextRPG.tlog: This is a text log file that likely stores debugging information, including messages and errors encountered during the build process. It helps developers track issues and understand the build history.
##### main.obj: This object file is generated during the compilation process and contains the compiled code for the "main" source file. It is an intermediate file that will eventually be linked to create the final executable.
##### TextRPG.Build.CppClean.log: This log file records the cleaning of the project's build process, detailing which files were removed or cleaned up to ensure a fresh build environment.
##### TextRPG.exe.recipe: This file contains the recipe or configuration settings for building the executable file "TextRPG.exe." It outlines the steps and parameters used during the build process.
##### TextRPG.ilk: This is an incremental link file that helps speed up the linking process during subsequent builds. It stores information about previously linked files to optimize the build time.
##### TextRPG.log: This log file contains detailed information about the build process, including warnings, errors, and other messages that can help developers diagnose issues.
##### TextRPG.vcxproj.FileListAbsolute.txt: This file contains a list of absolute file paths used by the project, which helps Visual Studio manage and reference the various source files and resources.
##### vc142.idb: This is a database file used by the Visual Studio build system to store information about the project, including debugging symbols and other metadata that aids in the debugging process.
##### vc142.pdb: This program database file is used for debugging and contains symbol information that allows developers to debug their code more effectively by mapping machine code back to the original source code.

### Output Directory
The **output** directory contains the final compiled executable and any related output files generated during the build process.

#### main.exe: This is the main executable file for the TextRPG project. It is the result of the compilation and linking processes and is the file that users will run to play the game.

### Header Files
Header files contain declarations of functions, classes, and variables that are used throughout the project. They help organize code and promote reusability.

#### combat.h: This header file defines functions and data structures related to the combat mechanics of the game. It likely includes declarations for player and enemy actions, health management, and experience points.
#### CppProperties.json: This JSON file defines settings for the project, including configuration information for the C++ compiler and IntelliSense. It specifies include paths, IntelliSense modes, and other environment settings that facilitate code editing and compilation.
#### display.h: This header file defines functions and data structures related to displaying game information to the player. It may include functions for rendering graphics, updating the user interface, and displaying messages or notifications.
#### itemscreen.h: This header file defines functions and data structures related to the screen that displays items in the game. It likely includes functionality for managing inventory, equipping items, and displaying item details.
#### skillscreen.h: This header file defines functions and data structures related to the screen that displays character skills. It may include functionality for managing skill points, skill descriptions, and skill usage during gameplay.
#### stats.h: This header file defines functions and data structures related to character statistics, such as health, strength, agility, and other attributes that affect gameplay.
#### statscreen.h: This header file defines functions and data structures related to the screen that displays character statistics. It likely includes functionality for updating and displaying the player's current stats and any changes that occur during gameplay.
#### system.h: This header file likely contains system-level functions and definitions that support the overall functionality of the game, such as initialization routines, game state management, and other core features.

### Source Files
Source files contain the actual implementation of the functions and logic defined in the header files.

#### main.cpp: This is the main source code file for the TextRPG project. It likely contains the entry point of the program (the main function) and orchestrates the overall flow of the game, including initializing the game environment, handling user input, and managing game states.

### Other Files
These files serve various purposes within the project.

#### save.txt: This text file is potentially used for saving game progress. It may store player data, game state, and other relevant information that allows players to resume their game at
------------------
## ![image](https://github.com/user-attachments/assets/3354ddef-1eb9-4a39-a86e-a31660808a9a)

Welcome to the Text-Based RPG! This guide will help you navigate the game, utilize its features, and make the most of your adventure. Follow these instructions to get started and enjoy your journey! 🌟

#### Game Controls
Movement:

##### W: Move Up
##### A: Move Left
##### S: Move Down
##### D: Move Right

#### Getting Started 🚀

1. Clone the Repository: To begin, you need to clone the project repository from GitHub. Open your terminal or command prompt and run the following command:

`git clone https://github.com/seamarielle/ComProg-Final-Project.git`

2. Navigate to the Project Directory: Once the repository is cloned, navigate into the project directory using:

`cd ComProg-Final-Project`

3. Compile and Run the Project: To compile and run the game, you will need a C++ compiler. Use the following command to compile the project:

`g++ -o TextRPG Main.cpp`

After compilation, run the game with:

`./TextRPG`

-------------
## ![image](https://github.com/user-attachments/assets/8f565173-f683-4f65-9e40-761bb9f84497)

Upon launching the game, you will be presented with a main menu that offers several options. Here’s a breakdown of each feature and how to use them:

### 1. Create Character ✨:

Select the option to create a new character.
Enter your desired character name and choose a class (e.g., Warrior, Mage, Rogue).
Customize your character’s initial attributes, such as health points, attack power, and special abilities.
Confirm your choices to finalize character creation.

### 2. Manage Inventory 📦:

Access your inventory to view items you have collected.
You can Create new items by specifying their type (e.g., weapon, armor, potion) and attributes.
Use the Read function to see descriptions and effects of items in your inventory.
Update items by equipping them or modifying their attributes as you progress.
Delete items you no longer need to keep your inventory organized.

### 3. Combat Mechanics ⚔️:

During battles, you will have several options:
Attack: Choose this option to engage an enemy. Your attack power will determine the damage dealt.
Defend: Select this option to reduce incoming damage from enemy attacks.
Cast: If your character has magical abilities, you can choose to cast spells that may heal or deal damage.
Make strategic decisions based on your character’s stats and the situation in combat.

### 4. Skills and Stats 📊:

Access the skills and stats menu to view your character’s current abilities.
You can Read your character’s stats, including health, experience points, and skill levels.
As you gain experience, you can Update your skills to enhance your character’s effectiveness in combat and exploration.

### 5. Quest Management 🗺️:

View available quests and select which ones to undertake.
You can Create new quests by defining objectives and rewards.
Read about the quests you have accepted to track your progress.
As you complete objectives, you can Update quest status to reflect your achievements.
If you wish to abandon a quest, you can Delete it from your quest log.

### 6. Save and Load Game 💾:

To save your progress, select the save option from the main menu. This will create a save file that captures your current character state, inventory, and quest progress.
To continue your adventure later, use the load option to read your saved data and restore your previous game state.

### 7. Reset Game 🔄:

If you want to start over, select the reset option. This will delete all current characters, items, and quests, allowing you to create a new character and experience the game from the beginning.

### 8. Exit Game ❌:

When you are ready to conclude your session, select the exit option to save your progress and exit the game safely. This ensures that all your achievements and changes are retained for future play sessions.

## Tips for Enjoying the Game 🌈
Explore: Take your time to explore different quests and character builds. Each choice can lead to unique experiences.
Strategize: Use the combat mechanics wisely. Assess your character’s strengths and weaknesses to make informed decisions during battles.
Manage Your Inventory: Keep your inventory organized by regularly deleting items you no longer need. This will help you focus on the items that enhance your gameplay.
Save Often: Make use of the save feature to ensure you don’t lose progress, especially before challenging quests or battles.
By following these instructions and utilizing the features of the Text -Based RPG, you will be well-equipped to embark on your adventure. Enjoy your journey, and may you conquer every challenge that comes your way! 🌟

--------

## 💻 Technologies Used

### Programming Language
- **C++**

### Version Control
- **Git** - for version tracking and collaborative development

### Development Environment
- `Visual Studio Code`  - recommended IDEs for C++ development

## 🎞 Project Conclusion

This project provides a comprehensive exercise in managing game elements using CRUD operations. It enhances understanding of data management, and dynamic user interaction in a C++ environment. The Text-Based RPG Project not only offers a fun and engaging gameplay experience but also serves as a practical application of C++ programming skills.

## 🤍 Acknowledgements

- **Instructor:** Mr. Jayson Abratique

## ⌨️ Authors

| Name | GitHub | SR Code |
|------|--------|----------|
| 👨‍🎓 Marielle S. Landicho | [Seamarielle](https://github.com/seamarielle) | 22-04500 |
