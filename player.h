#pragma once
#include<iostream>
#include "die.h"
using namespace std;

class Player {
	string name;
	int score;
	int moolah;	
	int wager;

	public:
	Player();
	void setName(string new_name);
	void setScore(int new_score);
	int getScore();
	std::string getName();
	void setMoolah(int cashOnly);
	int getMoolah(){
		return moolah;
	}
//void setRoll(vector<Die> &new_roll);	


};
