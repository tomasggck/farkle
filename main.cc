//Garcia , Zamudio
#include <iostream>
#include<vector>
#include "die.h"
#include "player.h"


using namespace std;


int main() {
	srand(time(0));
	vector<Die> playingDice;
	vector<int> userKeep;
	player One;

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


while (true){
int keep=0;
cout<<"Select a die to keep. Choose it again to unselect it.\n";
cin>>keep;
userKeep.push_back(playingDice.at(keep).get_roll());
if(keep==1)
break;

}
cout<<userKeep.at(0)<<endl;;
}
