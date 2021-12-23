#pragma once
#include <iostream>
#include<string>

using namespace std;

string actionChecker();
int numChecker();
void excIncreaser();
unsigned short statChecker();

class Fighter {
public:
	Fighter(){
		cout << "Name: ";
		cin >> name;

		cout << "Age: ";
		age = numChecker();

		cout << "Health: ";
		health = statChecker();

		cout << "Power: ";
		power = statChecker();

		cout << "Stamina: ";
		stamina = statChecker();

		cout << "Speed: ";
		speed = statChecker();
	}
	~Fighter();

private: 
	string name;
	unsigned short age;
	unsigned short health;
	unsigned short power;
	unsigned short stamina;
	unsigned short speed;
	unsigned short defencePower;

public:

	void startOfTurn() {
		defencePower = speed;
		cout << "Now then ";
		printName();
		cout << "It is the beginning of your turn. What do you want to do? Attack, defend yourself or rest?" << endl;
	}
	void attack(Fighter* tar){
		excIncreaser();
		if (speed > (tar->getDefece() - 10)) {
			cout << "You manage to hit ";
			tar->printName();
			cout << " with your attack!" << endl
				 << "They lose " << power / 5 << " health and " << power/10 << " stamina";

			loseStamina(5);
			tar->loseHealth(power / 5);
			tar->loseStamina(power / 10);
		}
	}
	void defend(){
		defencePower += 20;
		stamina -= 5;
	}
	void rest(){
		gainHealth(15);
		gainStamina(20);
		gainSpeed(10);
		cout << "Ok, your speed, stamina and health are increased. " << endl;
	}

	

	unsigned int getSpeed() { return speed; }
	unsigned int getDefece(){ return defencePower; }
	unsigned int getStamina() { return stamina; }
	unsigned int getHealth() { return health; }
	string getName() { return name; }

	void loseHealth(unsigned int x) { health -= x; }
	void gainHealth(unsigned int x) { health += x; }
	void loseStamina(unsigned int x) { stamina -= x; }
	void gainStamina(unsigned int x) { stamina += x; }
	void gainSpeed(unsigned int x) { speed += x; }

	void printName() { cout << name; }
	void printStam() { cout << stamina; }
	void printHealth() { cout << health; }
};
