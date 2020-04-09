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
	currScore= currScore + newScore;

}
int Table:: getScore(){return currScore;}

void Table:: setWagerUp( int newWager){
wagerUp=newWager;
}
int Table::getWagerUp(){return wagerUp;}

vector<Die> Table::getTableHand(){return sixFair;}

void Table:: setTableDice(vector<Die> Dice){
		for(size_t i=0; i< Dice.size();i++)
			sixFair.push_back(Dice.at(i));

}
void Table::loadTableHand(int howManyDice){
	for(int i=0; i< howManyDice;i++){
		Die curr;
		sixFair.push_back(curr);
	}
		/*
 Die One, Two, Three, Four, Five, Six;
    sixFair.push_back(One);
    sixFair.push_back(Two);
    sixFair.push_back(Three);
    sixFair.push_back(Four);
    sixFair.push_back(Five);
    sixFair.push_back(Six);
*/

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
}

void Table::update(int diceUsed){

	for(int i=0; i< diceUsed;i++){
		Die curr;
		sixFair.push_back(curr);}
}
//void Table::remove(int location){
//sixFair.erase(sixFair.begin()+ location); 
//}




