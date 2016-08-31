#include "PlayerCharacterFunctions.h"

vector<Player_Character> heroList;

void create_Player_Char()
{
	Player_Character newPlayer;

	printf("Enter your character's name, race, and class.");
	cin >> newPlayer.name >> newPlayer.race >> newPlayer.char_class;

	printf("What is your Strength? ");
	scanf_s("%d", &newPlayer.strength);

	printf("What is your Dexterity? ");
	scanf_s("%d", &newPlayer.dexterity);

	printf("What is your Constitution? ");
	scanf_s("%d", &newPlayer.constitution);

	printf("What is your Intelligence? ");
	scanf_s("%d", &newPlayer.intelligence);

	printf("What is your Wisdom? ");
	scanf_s("%d", &newPlayer.wisdom);

	printf("What is your Charisma? ");
	scanf_s("%d", &newPlayer.charisma);

	heroList.push_back(newPlayer);
}

void edit_Player_Char()
{
	printf("Choose the hero to edit!\n");
	Player_Character chosenHero = choose_Hero();

	int choice = -1;
	// Choose a trait to change
	printf("Choose a trait to change:\n");
	while (true)
	{
		print_Player_Char_Trait_List(chosenHero);
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
			chosenHero.name = choose_New_Trait_s(chosenHero.name, "name");
			break;
		case 1:
			chosenHero.race = choose_New_Trait_s(chosenHero.name, "race");
			break;
		case 2:
			chosenHero.char_class = choose_New_Trait_s(chosenHero.name, "class");
			break;
		case 3:
			chosenHero.strength = choose_New_Trait_i(chosenHero.name, "strength");
			break;
		case 4:
			chosenHero.dexterity = choose_New_Trait_i(chosenHero.name, "dexterity");
			break;
		case 5:
			chosenHero.constitution = choose_New_Trait_i(chosenHero.name, "constitution");
			break;
		case 6:
			chosenHero.intelligence = choose_New_Trait_i(chosenHero.name, "intelligence");
			break;
		case 7:
			chosenHero.wisdom = choose_New_Trait_i(chosenHero.name, "wisdom");
			break;
		case 8:
			chosenHero.charisma = choose_New_Trait_i(chosenHero.name, "charisma");
			break;
		case 9:
			printf("\n");
			return; // exit the editor
			break;
		default:
			continue; // choose something else
			break;
		}
	}
}

int choose_New_Trait_i(string name, string traitName)
{
	int newTrait;
	printf("Choose %s's new %s score: ", name.c_str(), traitName.c_str());
	scanf_s("%d", &newTrait);
	return newTrait;
}

string choose_New_Trait_s(string name, string traitName)
{
	string newTrait;
	printf("Choose %s's new %s: ", name.c_str(), traitName.c_str());
	cin >> newTrait;
	return newTrait;
}

Player_Character choose_Hero()
{
	int choice = -1;

	printf("Choose a hero:\n");
	print_All_Player_Chars();
	if (heroList.size() > 1)
	{
		while (choice < 0 && choice >(heroList.size() - 1))
		{
			scanf_s("%d\n", &choice);
		}
	}
	else
	{
		choice = 0;
	}

	return heroList[choice];
}

void print_Player_Char(const Player_Character & playerChar)
{
	printf("This mighty hero is a %s %s, named %s!\n", playerChar.race.c_str(),
		playerChar.char_class.c_str(),
		playerChar.name.c_str());

	printf("This hero is indeed mighty, for they have %d strength!\n", playerChar.strength);
	printf("%d dexterity!\n", playerChar.dexterity);
	printf("%d constitution!\n", playerChar.constitution);
	printf("%d intelligence!\n", playerChar.intelligence);
	printf("%d wisdom!\n", playerChar.wisdom);
	printf("And a whopping %d charisma!\n", playerChar.charisma);
}

void print_All_Player_Chars()
{
	for (int ii = 0; ii < heroList.size(); ++ii)
	{
		printf("%d) %s the %s %s!\n", ii,
			heroList[ii].name.c_str(),
			heroList[ii].race.c_str(),
			heroList[ii].char_class.c_str());

	}
}

void print_Player_Char_Trait_List(const Player_Character & playerChar)
{
	printf("0) Name: %s \n1) Race: %s \n2) Class: %s\n", playerChar.name.c_str(),
		playerChar.race.c_str(),
		playerChar.char_class.c_str());

	printf("3) Strength:     %d\n", playerChar.strength);
	printf("4) Dexterity:    %d\n", playerChar.dexterity);
	printf("5) Constitution: %d\n", playerChar.constitution);
	printf("6) Intelligence: %d\n", playerChar.intelligence);
	printf("7) Wisdom:       %d\n", playerChar.wisdom);
	printf("8) Charisma:     %d\n", playerChar.charisma);
}