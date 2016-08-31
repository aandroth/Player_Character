
#include <iostream>
#include "PlayerCharacterFunctions.h"


int main()
{

	int choice = 0;
	// Main Loop
	while (true)
	{
		printf("Choose what to do with this mighty hero generator:\n");
		printf("0) Create a hero\n");
		printf("1) Edit a hero\n");
		printf("2) Print hero ability scores\n");
		printf("3) See hero list\n");
		printf("4) Quit\n");

		scanf_s("%d", &choice);

		// Switch statement to fulfill choice
		switch (choice)
		{
		case 0:
			create_Player_Char();
			break;
		case 1:
			edit_Player_Char();
			break;
		case 2:
			print_Player_Char(choose_Hero());
			break;
		case 3:
			print_All_Player_Chars();
			break;
		case 4:
			return 0;
			break;
		default:
			printf("\n");
			continue;
			break;
		}
	}

	return 0;
}
