#pragma once

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

struct Player_Character
{
	string name,
		race,
		char_class;
	int strength,
		dexterity,
		constitution,
		intelligence,
		wisdom,
		charisma;
};

void create_Player_Char();
void edit_Player_Char();

int choose_New_Trait_i(string name, string traitName);
string choose_New_Trait_s(string name, string traitName);
Player_Character choose_Hero();

void print_Player_Char(const Player_Character & playerChar);
void print_All_Player_Chars();
void print_Player_Char_Trait_List(const Player_Character & playerChar);
