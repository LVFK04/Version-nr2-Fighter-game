#include <iostream>
#include <Windows.h>
#include "FighterGame.h"
using namespace std;
//void turn(Fighter* fighter, Fighter** fighterList);
int getIntInput(int lowBound, int upBound);
int main() {
	
	bool playAgain = true;

	while (playAgain) {
		cout << "How many players are you? Choose between 2 and 5?" << endl;
		FighterGame game(getIntInput(2, 5));
		while (game.getNumberOfFighters() > 1) { //Kollar att det finns fler än en spelare
			game.round();
		}
	}
	return 0;
}

//void turn(Fighter* fighter, Fighter** fighterList) {
//
//	cout << "Now then " << fighter->getName() << ". It is the beginning of your turn. What do you want to do? Attack, defend or rest?" << endl;
//
//	string action;
//	action = actionChecker();
//
//	if (action == "Attack" || action == "attack") {
//		cout << "You have chosen to attack..." << endl << "Who do you want to attack?" << endl;
//		string target;
//
//		cin >> target;
//
//		for (int j = 0; j < Fighter::numOfFighters; j++) {
//			if (target == fighterList[j]->getName()) {
//				fighter->attack(fighterList[j]);
//
//				if (fighterList[j]->getHealth() <= 0) {
//					cout << "This hit takes " << fighterList[j]->getName() << "!" << endl;
//					delete fighterList[j];
//					fighterList[j] = nullptr;
//					Fighter::numOfFighters--;
//				}
//			}
//		}
//		return;
//	}
//
//	if (action == "Rest" || action == "rest") {
//		cout << "You have chosen to rest. This restores 15 health, 20 stamina and 10 speed" << endl;
//		fighter->rest();
//		return;
//	}
//
//	if (action == "Defend" || action == "defend") {
//		cout << "You have chosen to defend yourself, this increases your defenses by 20 until your next round"
//			<< ", and decreases your stamina by 5" << endl;
//		fighter->defend();
//		return;
//	}
//}


int getIntInput() {
	int a;
	cin >> a;
	while (!cin.good()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid answer, try again" << endl;
		cin >> a;
	}
	return a;
}

int getIntInput(int lowBound, int upBound) {
	int a;
	cin >> a;
	while (!cin.good() || a < lowBound || a > upBound) {
		cin.clear();
		cin.ignore();
		cout << "Invalid answer, try again" << endl;
		cin >> a;
	}
	return a;
}


//string actionChecker() { 
//	string a;
//	cin >> a;
//	while (a != "Attack" && a != "attack" && a != "Rest" && a != "rest" && a != "defend" && a != "Defend"){
//		cin.clear();
//		cin.ignore();
//		cout << "Invalid answer, try again" << endl;
//		cin >> a;
//	}
//	return a;
//}
//
//unsigned short statChecker() { // Dålig namngivning av funktion och dåligt designad.
//	unsigned short a;
//	cin >> a;
//	while (!cin.good() || a > 100) {
//		cin.clear();
//		cin.ignore();
//		cout << "That answer is invalid, try again" << endl;
//		cin >> a;
//	}
//
//	if (a > 80 && a < 90) {
//		a *= 0.8;
//		cout << "In order to not make you too OP, we are lowering this score to " << a << endl;
//	}
//
//	if (a > 90 && a <= 100) {
//		a *= 0.6;
//		cout << "In order to not make you too OP, we are lowering this score to " << a << endl;
//	}
//
//	if (a < 50) {
//		a *= 2;
//		cout << "In order to not make you too weak, we'll increase this score to " << a << endl;
//	}
//	return a;	
//} 
//
//void excIncreaser() { // Varför finns denna
//	cout << "." << endl;
//	Sleep(1000);
//	cout << ".." << endl;
//	Sleep(1000);
//	cout << "..." << endl;
//	Sleep(1000);
//}
