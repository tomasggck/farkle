#pragma once
#include<iostream>

using namespace std;

class player {
	string name;
	int score;


public:
player();
void setName(string new_name);
void setScore(int new_score);
int getScore();
std::string getName();




};
