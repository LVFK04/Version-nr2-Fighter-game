#pragma once
#include <string>
#include "Fighter.h"
class FighterGame {
public:
	FighterGame(int NOF);
	~FighterGame();
private:
	Fighter** fighterList;
	int numOfFighters;
	int orgiginalNumOfFighters;
public:
	Fighter* getFighterByName(std::string name);
	bool killFighter(Fighter* fighter);
	int getNumberOfFighters() { return numOfFighters; }
	void round();
};