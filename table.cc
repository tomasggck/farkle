#include "table.h"
#include <iostream>
#include "/public/colors.h"

using namespace std;

Table::Table(){
vector<Die> sixFair{};
vector<Die> sixWeighted{};
currScore=0;
wagerUp=0;
Player tableOne{};
Player tableTwo {};

}

Table::Table( Player one, Player two){
Player tableOne= one;
Player tableTwo= two;
}


void Table::setScore(int newScore){
	if(newScore==-5) currScore=0;//IF FARKLE(USING -5 TO REPRESENT FARKLE) RESET TO 0 , OTHERWISE ADD TO PREVIOUS
	else
	currScore= currScore + newScore;

}
int Table:: getScore(){return currScore;}

void Table:: setWagerUp( int newWager){
wagerUp=newWager;
}
int Table::getWagerUp(){return wagerUp;}

vector<Die> Table::getTableHand(){return sixFair;}
vector<Die> Table::getCheater(){return sixWeighted;}

void Table::loadTableHand(int howManyDice){
	for(int i=0; i< howManyDice;i++){
		Die curr;
		sixFair.push_back(curr);}
}

void Table::loadCheater(int howManyDice){
	for(int i=0; i< howManyDice;i++){
		Die cheat(vector<double>{.4,.05,.1, .1, .3,.05}, 6);
		sixWeighted.push_back(cheat);
	}
}
void Table::setCheatRoll (){

		int count=0;
    for (Die &d: sixWeighted){
        d.roll();
            cout<<BOLDCYAN<<"Dice "<<count<<":  "<< d.get_roll()<<endl<<RESET;
			count++;}
}

void Table::setRoll (){

		int count=0;
    for (Die &d: sixFair){
        d.roll();
            cout<<BOLDCYAN<<"Dice "<<count<<":  "<< d.get_roll()<<endl<<RESET;
			count++;}
}
void Table::clear(){
sixFair.clear();
sixWeighted.clear();
}

void Table::update(int diceUsed){

	for(int i=0; i< diceUsed;i++){
		Die curr;
		sixFair.push_back(curr);}
}
//void Table::remove(int location){
//sixFair.erase(sixFair.begin()+ location); 
//}
		/*
 Die One, Two, Three, Four, Five, Six;
    sixFair.push_back(One);
    sixFair.push_back(Two);
    sixFair.push_back(Three);
    sixFair.push_back(Four);
    sixFair.push_back(Five);
    sixFair.push_back(Six);
*/

/*void Table:: setTableDice(vector<Die> Dice){
		for(size_t i=0; i< Dice.size();i++)
			sixFair.push_back(Dice.at(i));

}*/



