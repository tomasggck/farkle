//Write your last name and your partner's name here
//Garcia , Zamudio
#include <iostream>
#include<vector>
#include "die.h"
using namespace std;


int main() {
	srand(time(0));
	cout << "Hello World!\n";
	vector<Die> playingDice;
	Die d1;
	Die d2;
	Die d3;
	Die d4;
	Die d5;
	Die d6;
	playingDice.push_back(d1);
	playingDice.push_back(d2);
	playingDice.push_back(d3);
	playingDice.push_back(d4);
	playingDice.push_back(d5);
	playingDice.push_back(d6);

	
	
	for(int i=0; i< playingDice.size();i++){
		playingDice.at(i).roll();
		cout<<"Die: "<< i <<" "<<playingDice.at(i).get_roll()<<endl;
		}

}
