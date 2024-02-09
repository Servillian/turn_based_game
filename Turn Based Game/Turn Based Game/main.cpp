
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include <random>
#include "monster.h"
#include "team.h"
#include <numeric>

std::random_device rd;
std::mt19937 gen(rd());

int validate_input(std::string prompt, std::list<int> options)
{
	int player_choice;

	while (true)
	{
		std::cout << prompt;
		std::cin >> player_choice;
		bool found = (std::find(options.begin(), options.end(), player_choice) != options.end());
		if (found)
		{
			break;
		}
		else
		{
			std::cout << "\nInvalid input. Please enter a number between 1-" << options.back() << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	}
	system("cls");
	return player_choice;
}

void main()
{
	bool game_end = false;
	Team player_team;
	std::string characters[5] = { "Geralt", "Yennefer", "Triss", "Ciri", "Regis" };
	std::string elements[5] = { "Water", "Fire", "Wind", "Light", "Dark" };
	
	Monster dummy_mon("Dummy", 10, 100, "Dark");


	while (game_end == false)
	{
		std::list<int> main_menu_options = { 1, 2, 3 };
		int main_menu_choice = validate_input("\n==============================\n1. Summon a character\n2. Modify team\nEnter: ",main_menu_options);
		system("cls");

		if (main_menu_choice == 1)
		{
			int RandIndex = std::uniform_int_distribution<int>(0, 4)(gen);
			int RandElem = std::uniform_int_distribution<int>(0, 4)(gen); 
			
			int character_attack = std::uniform_int_distribution<int>(10, 20)(gen); 
			int character_health = std::uniform_int_distribution<int>(90, 120)(gen);

			std::string character_name = characters[RandIndex];
			std::string character_elem = elements[RandElem];

			Monster new_character(character_name, character_attack, character_health, character_elem);
			std::cout << "Summoned " << new_character.name << std::endl;
			std::cout << "Health: " << new_character.health << std::endl;
			std::cout << "Attack: " << new_character.attack << std::endl;
			std::cout << "Element: " << new_character.element << std::endl;

			player_team.add_to_team(new_character);
		}
		else if (main_menu_choice == 2)
		{
			while (true)
			{
				std::list<int> team_menu_options = { 1, 2, 3, 4 };
				int team_menu_choice = validate_input("\n==============================\n1. View Team\n2. View collection\n3. Swap character\n4. Return to main menu\nEnter: ",team_menu_options);

				system("cls");

				if (team_menu_choice == 1)
				{
					player_team.display_team(true);
				}
				else if (team_menu_choice == 2)
				{
					player_team.display_team(false);
				}
				else if (team_menu_choice == 3)
				{
					player_team.display_team(true);
					std::list<int> swap_teammate_options = { 1, 2, 3, 4, 5 };
					int swap_teammate_choice = validate_input("\nSelect character to remove (1-5)\nEnter: ", swap_teammate_options);

					std::list<int> collection_numbers(player_team.all_monsters.size());
					std::iota(collection_numbers.begin(), collection_numbers.end(), 1);

					player_team.display_team(false);


					std::ostringstream oss;
					oss << "\nSelect character to add in (1-" << player_team.all_monsters.size() << ")\nEnter: ";

					std::string formatted_string = oss.str();

					int add_monster_choice = validate_input(formatted_string, collection_numbers);
					player_team.swap_team(swap_teammate_choice, add_monster_choice);
				}	

				else if (team_menu_choice == 4)
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}
		}

		else if (main_menu_choice == 3)
		{
			
			Monster& current_mon = player_team.team_members.front();

			std::cout << "Current mon element: " << current_mon.element << std::endl;
			std::cout << "Current mon attack: " << current_mon.attack << std::endl;


			current_mon.Attack(current_mon,dummy_mon);
			
			current_mon.Attack(current_mon, dummy_mon);
		}


	}
};