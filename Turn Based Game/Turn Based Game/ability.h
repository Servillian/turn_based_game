
#pragma once
#include <iostream>
#include <list>
#include <string>
#include "team.h"
#include "monster.h"

class Ability
{
public:
	std::string attack_name;
	double d_multiplyer;
	int multiple; // Number of enemies to attack
	bool freeze; // True if freezes enemies for one turn
	int cooldown;


	Ability() : attack_name(""), d_multiplyer(0), multiple(0), freeze(false), cooldown(0) {}

	// Parameterized constructor
	Ability(const std::string& n, double d, int m, bool f, int c)
		: attack_name(n), d_multiplyer(d), multiple(m), freeze(f), cooldown(c) {}

	

};
extern std::map<std::string, std::pair<std::tuple<std::string, double, int, bool, int>, std::tuple<std::string, double, int, bool, int>>> characterAbilities;
