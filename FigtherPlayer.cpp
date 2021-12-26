#include "FighterPlayer.h"
Fighter::Fighter() {
	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Age: ";
	age = numChecker();

	std::cout << "Health: ";
	health = statChecker();

	std::cout << "Power: ";
	power = statChecker();

	std::cout << "Stamina: ";
	stamina = statChecker();

	std::cout << "Speed: ";
	speed = statChecker();
}


void Fighter::startOfTurn() {
	defencePower = speed;
	std::cout << "Now then " << name << "It is the beginning of your turn. What do you want to do? Attack, defend yourself or rest?" << std::endl;
}
void Fighter::attack(Fighter* tar) {
	excIncreaser();
	if (speed > (tar->getDefece() - 10)) {
		std::cout << "You manage to hit ";
		tar->printName();
		std::cout << " with your attack!" << std::endl
			<< "They lose " << power / 5 << " health and " << power / 10 << " stamina";

		loseStamina(5);
		tar->loseHealth(power / 5);
		tar->loseStamina(power / 10);
	}
}
void Fighter::defend() {
	defencePower += 20;
	stamina -= 5;
}
void Fighter::rest() {
	gainHealth(15);
	gainStamina(20);
	gainSpeed(10);
	std::cout << "Ok, your speed, stamina and health are increased. " << std::endl;
}