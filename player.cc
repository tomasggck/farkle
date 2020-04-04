#include "player.h"
#include <iostream>

using namespace std;

Player::Player (){
	name="";
	score=-1;
}
void Player:: setName(string new_name){
	name=new_name;
}
void Player:: setScore(int new_score){
	score= new_score;
}
string Player::getName(){
	return name;

}


