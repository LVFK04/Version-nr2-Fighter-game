#pragma once
#include<string>
#include <iostream>

//std::string actionChecker();
//int numChecker();
//void excIncreaser();
//unsigned short statChecker();

class Fighter {
public:
	Fighter();
	void startOfTurn();

	void attack(Fighter* tar);
	void defend();
	void rest();
	void shop();

private: 
	std::string name;
	unsigned short age;
	unsigned short health;
	unsigned short power;
	unsigned short stamina;
	unsigned short speed;
	unsigned short defencePower;

public:

	static int numOfFighters;

	unsigned int getSpeed() { return speed; }
	unsigned int getDefece(){ return defencePower; }
	unsigned int getStamina() { return stamina; }
	unsigned int getHealth() { return health; }
	std::string getName() { return name; }

	void loseHealth(unsigned int x) { health -= x; }
	void gainHealth(unsigned int x) { health += x; }
	void loseStamina(unsigned int x) { stamina -= x; }
	void gainStamina(unsigned int x) { stamina += x; }
	void gainSpeed(unsigned int x) { speed += x; }

};