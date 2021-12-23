#include <iostream>
#include <Windows.h>
#include "FighterPlayer.h"
using namespace std;

string actionChecker();
int numChecker();
void excIncreaser();
unsigned short statChecker();

int main() {
	unsigned short numFighters; //Antal spelare
	bool playAgain = true;
	while (playAgain) {

		Fighter* fighter[] = { nullptr, nullptr, nullptr, nullptr, nullptr };//Skapar fem Fighter objekt & gör dem till nullptr
		cout << "How many players are you?" << endl;
		cin >> numFighters; //Man får slå in hur många man är 
		for (int k = 0; k < numFighters; k++) {
			fighter[k] = new Fighter;//Det skapas en ny Fighter för varje spelare
			if (k != numFighters - 1)
				cout << "Time to create the next player" << endl;
		}

		while (numFighters > 1) { //Kollar att det finns mer än en spelare
			for (int k = 0; k <= numFighters; k++) {
				cout << "Now then ";
				fighter[k]->printName();
				cout << "It is the beginning of your turn. What do you want to do? Attack or rest?" << endl;

				string* action;
				action = new string;
				*action = actionChecker();

				if (*action == "Attack" || *action == "attack") {
					cout << "You have chosen to attack..." << endl;
					cout << "Who do you want to attack?" << endl;
					string* target;
					target = new string;
					cin >> *target;

					for (int a = 0; a <= numFighters; a++) {
						if (*target == fighter[a]->getName()) {
							fighter[k]->attack(fighter[a]);
					
							if (fighter[a]->getHealth() <= 0) {
								cout << "This hit takes ";
								fighter[a]->printName();
								cout << "!" << endl;
								fighter[a] = nullptr;
								numFighters--;
							}
						}
					}
					
				}

				if (*action == "Rest" || *action == "rest") {
					cout << "You have chosen to rest. This restores 15 health, 20 stamina and 10 speed" << endl;
					fighter[k]->rest();
				}

				if (*action == "Defend" || *action == "defend") {
					cout << "You have chosen to defend yourself, this increases your defenses by 20 until your next round"
						<<", and decreases your stamina by 5" << endl;
					fighter[k]->defend();
				}

				action = nullptr;
				delete action;
			}

		}

	}
}

int numChecker() {
	int x;
	cin >> x;
	while (!cin.good()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid answer, try again" << endl;
		cin >> x;
	}
	return x;
}

string actionChecker() {
	string a;
	cin >> a;
	while (a != "Attack" && a != "attack" && a != "Rest" && a != "rest" && a != "defend" && a != "Defend"){
		cin.clear();
		cin.ignore();
		cout << "Invalid answer, try again" << endl;
		cin >> a;
	}
	return a;
}

unsigned short statChecker() {
	unsigned short a;
	cin >> a;
	while (!cin.good() || a > 100) {
		cin.clear();
		cin.ignore();
		cout << "That answer is invalid, try again" << endl;
		cin >> a;
	}

	if (a > 80 && a < 90) {
		a *= 0.8;
		cout << "In order to not make you to OP, we are lowering this score to " << a << endl;
	}

	if (a > 90 && a <= 100) {
		a *= 0.6;
		cout << "In order to not make you to OP, we are lowering this score to " << a << endl;
	}

	if (a < 50) {
		a *= 2;
		cout << "In order to not make you to weak, we'll increase this score to " << a << endl;
	}
	return a;	
}

void excIncreaser() {
	cout << "." << endl;
	Sleep(3000);
	cout << ".." << endl;
	Sleep(3000);
	cout << "..." << endl;
	Sleep(3000);

	}