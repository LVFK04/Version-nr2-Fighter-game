#include "FighterGame.h"
FighterGame::FighterGame(int NOF) {
	fighterList = new Fighter* [NOF];
	for (int i = 0; i < NOF; i++) {
		fighterList[i] = new Fighter();
	}
	orgiginalNumOfFighters = numOfFighters = NOF;
}

FighterGame::~FighterGame() {
	for (int i = 0; i < orgiginalNumOfFighters; i++) {
		if (fighterList[i])
			delete fighterList[i];
	}
	delete fighterList;
}

bool FighterGame::killFighter(Fighter* fighter) {
	if (fighter) {
		for (int i = 0; i < numOfFighters; i++) 
			if (fighter = fighterList[i]) {
				delete fighter;
				numOfFighters--;
				if (numOfFighters != i) {
					fighterList[i] = fighterList[numOfFighters];
					fighterList[numOfFighters] = 0;
				}
				else
					fighterList[i] = nullptr;
				break;
				return true;
			}
		return false;
	}
	else
		return false;
}

void FighterGame::round() {
	for (int i = 0; i < numOfFighters; i++) {
		std::cout << "Now then " << fighterList[i]->getName() << ". It is the beginning of your turn. What do you want to do? Attack, defend or rest?" << std::endl;

		std::string action;
		bool incorrectInput = true;

		while (incorrectInput) {
			incorrectInput = false;
			std::cin >> action;
			switch (action.c_str()[0])
			{
			case 'a':
			case 'A': {
				std::cout << "Which fighter do you want to attack?" << std::endl;
				for (int j = 0; j < numOfFighters; j++) 
					std::cout << fighterList[j]->getName() <<  "	";
				std::cout << std::endl;
				while (true) {
					Fighter* ptr = getFighterByName(((std::cin >> action), action));
					if (ptr) {
						fighterList[i]->attack(ptr);
						break;
					}
					else
						std::cout << "Invalid input. Try again" << std::endl;
				}
				break;
			}

			case 'd':
			case 'D': {
				fighterList[i]->defend();
				break;
			}
			case 'r':
			case 'R': {
				fighterList[i]->rest();
				break;
			}

			case 's':
			case 'S': {
				fighterList[i]->shop();
				break;
			}
			default:
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid input. Try again" << std::endl;
				incorrectInput = true;
			}
		}
	}
}




Fighter* FighterGame::getFighterByName(std::string name) {
	for (int i = 0; i < numOfFighters; i++) {
		if (fighterList[i]->getName() == name)
			return fighterList[i];
	}
	return nullptr;
}

