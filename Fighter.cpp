#pragma once
#include "Fighter.h"

Fighter::Fighter() {
	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Age: ";
	age = 20; 

	std::cout << "Health: ";
	health = 20;

	std::cout << "Power: ";
	power = 20;

	std::cout << "Stamina: ";
	stamina = 20;

	std::cout << "Speed: ";
	speed = 20;

	defencePower = 0;
}

void Fighter::startOfTurn() {
	defencePower = speed;
	std::cout << "Now then " << name << "It is the beginning of your turn. What do you want to do? Attack, defend yourself or rest?" << std::endl;
	return;
}

void Fighter::attack(Fighter* tar) {
	//excIncreaser();
	if (speed > (tar->getDefece() - 10)) {
		std::cout << "You manage to hit " << tar->getName() << " with your attack!" << std::endl
			<< "They lose " << power / 5 << " health and " << power / 10 << " stamina";

		loseStamina(5);
		tar->loseHealth(power / 5);
		tar->loseStamina(power / 10);
	}
	return;
}
void Fighter::defend() {
	defencePower += 20;
	stamina -= 5;
	return;
}
void Fighter::rest() {
	gainHealth(15);
	gainStamina(20);
	gainSpeed(10);
	std::cout << "Ok, your speed, stamina and health are increased. " << std::endl;
	return;
}
void Fighter::shop() {
	return;
}