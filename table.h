#pragma once
#include<iostream>
#include<vector>
#include "die.h"
#include "player.h"

using namespace std;

class Table {
vector<Die> sixFair;
vector<Die> sixWeighted;
int currScore;
int wagerUp;
Player tableOne;
Player tableTwo;

public:
Table();
Table(Player, Player);
vector<Die> getTableHand();
vector<Die> getCheater();
void setScore(int newScore);
int getScore();
void setWagerUp(int newWager);
int getWagerUp();
void setTableDice(vector<Die> Dice);
void loadTableHand(int);
void loadCheater(int);
void setRoll();
void setCheatRoll();
void clear();
void update(int);
//void remove(int);
};
