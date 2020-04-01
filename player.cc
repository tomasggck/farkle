#include "player.h"
#include <iostream>

using namespace std;

player::player (){
name="";
score=-1;
}
void player:: setName(string new_name){
	name=new_name;
}
void player:: setScore(int new_score){
	score= new_score;
}




