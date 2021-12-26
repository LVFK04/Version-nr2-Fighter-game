#pragma once
#include <iostream>
#include<string>

std::string actionChecker();
int numChecker();
void excIncreaser();
unsigned short statChecker();

class Fighter {
public:
	Fighter();
	~Fighter();

private: 
	std::string name;
	unsigned short age;
	unsigned short health;
	unsigned short power;
	unsigned short stamina;
	unsigned short speed;
	unsigned short defencePower;

public:

	void startOfTurn();
	void attack(Fighter* tar);
	void defend();
	void rest();

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

	void printName() { std::cout << name; }
	void printStam() { std::cout << stamina; }
	void printHealth() { std::cout << health; }
};
