//Garcia , Zamudio
#include <iostream>
#include<string>
#include<vector>
#include "die.h"
#include "player.h"
#include "table.h"
#include "/public/colors.h"
using namespace std;
void die() {
	cout << "Invalid Input!\n";
	exit(EXIT_FAILURE);
	//return;
}

int howManyOnes, howManyTwos, howManyThrees, howManyFours, howManyFives, howManySixes;

void resetCounters() {
	howManyOnes = 0, howManyTwos = 0, howManyThrees = 0, howManyFours = 0, howManyFives = 0, howManySixes = 0;
}


int getScore(int roll, vector<Die> hand) { //SCORING FUNCTION
	bool farkle = false;
	int onesCheck = 0, twosCheck = 0, threesCheck = 0, foursCheck = 0, fivesCheck = 0, sixesCheck = 0;
	for (int i = 0; i < hand.size(); i++) { ///Farkle check
		if (hand.at(i).get_roll() == 1)onesCheck++;
		else if (hand.at(i).get_roll() == 2)twosCheck++;
		else if (hand.at(i).get_roll() == 3)threesCheck++;
		else if (hand.at(i).get_roll() == 4)foursCheck++;
		else if (hand.at(i).get_roll() == 5)fivesCheck++;
		else if (hand.at(i).get_roll() == 6)sixesCheck++;

	}

	if (onesCheck == 0 && fivesCheck == 0 && twosCheck < 3 && threesCheck < 3 && foursCheck < 3 && sixesCheck < 3) {
		farkle = true;
		return -1;
	}

	int score = 0;
	if (roll == 1) {
		score = 100;
		howManyOnes++;
		if (farkle == true && howManyOnes < 3)return -1;
		else if (howManyOnes == 3) score = 800; //adds up to 1000
		else if (howManyOnes == 4) score = 1000; //adds up to 2000
		else if (howManyOnes == 5) score = 2000;}//adds up to 4000

	else if (roll == 5) {
		howManyFives++;
		score = 50;
		if (farkle == true && howManyFives < 3)return -1;
		else if (howManyFives == 3) score = 400; //100 +400 =500
		else if (howManyFives == 4) score = 500; //500+500=1000
		else if (howManyFives == 5) score = 1000;}//1000+1000=2000
	else if (roll == 2) {
		howManyTwos++;
		if (farkle == true && howManyTwos < 3)return -1;
		else if (howManyTwos == 3)score = 200; //200
		else if (howManyTwos == 4)score = 200; //400
		else if (howManyTwos == 5)score = 400;}//800
	else if (roll == 3) {
		howManyThrees++;
		if (farkle == true && howManyThrees < 3)return -1;
		else if (howManyThrees == 3)score = 300;
		else if (howManyThrees == 4)score = 300; //600
		else if (howManyThrees == 5)score = 600;}//1200

	else if (roll == 4) {
		howManyFours++;
		if (farkle == true && howManyFours < 3)return -1;
		else if (howManyFours == 3)score = 400;
		else if (howManyFours == 4)score = 400; //800
		else if (howManyFours == 5)score = 800;}//1600
	else if (roll == 6) {
		howManySixes++;
		if (farkle == true && howManySixes < 3)return -1;
		else if (howManySixes == 3)score = 600;
		else if (howManySixes == 4)score = 600; //1200
		else if (howManySixes == 5)score = 1200;}//2400

	return score;

}
void gameFunction(Table table, Player &currPlayer) {

	vector<int> iterator ;// made of vector so user cant add the same Dice multiple times to score more points
	bool choosen = false;
	int diceChoosen = 0;
	const int DICE_REMAINING = 6;
	int currScore = 0;
	bool playerTurnOver = false;	
	int hotDice=0;	
	bool hottDice=false;
	char diceType;
	bool cheater=true;
		
while(true){	
	cin>>diceType;
	
	if(diceType=='n' || diceType=='N'){//IF THEY WANT NORMAL DICE DO THIS
		table.loadTableHand(DICE_REMAINING);//load table dice
			cout << "Rolling Dice...  " << endl;
				table.setRoll();
					cheater=false;
						break;
	}
	
	else if(diceType=='y' || diceType=='Y'){//IF THEY WANT CHEATER DICE DO THIS
		table.loadCheater(DICE_REMAINING);//load table dice
			cout << "Rolling Dice...  " << endl;
				table.setCheatRoll();
					cheater=true;
						break;
	}
	
	else 
		cout<<"Y for yes, N for no.\nTry again\n";
			continue;
}
	if(!cheater){
	
		if (getScore(0, table.getTableHand()) == -1) {
			cout << RED << "YOU FARKLED\n" << RESET;
				playerTurnOver = true;
					table.setScore(-5);//IF THEY FARKLE THEY LOSE ALL CURRENT POINTS	
		}}
	else if(cheater){
	
		if (getScore(0, table.getCheater()) == -1) {
			cout << RED << "YOU FARKLED\n" << RESET;
				playerTurnOver = true;
				table.setScore(-5);//IF THEY FARKLE THEY LOSE ALL CURRENT POINTS
		}}


	while (!playerTurnOver) {

		cout << "Pick a dice: " << endl;
		char keep;
		cin >> keep;

		if (keep >= 48 && keep <= 53) {								//had to use a char for keep so user can type in both numbers or letters

			for (int i = 0; i < iterator.size(); i++) {
				if (iterator.at(i) == int(keep) - 48) { //dont load into player vector same dice 2x (same die not same die value)
					cout << int(keep) - 48 << " has already been selected\n";
						choosen = true;
				}
			}
			if (!choosen) {
				if(!cheater){
				if(int(keep-48) >= table.getTableHand().size()){//TO NOT SEGFAULT WHEN TRYING TO ACCESS DIE > VECTOR<DIE>
					cout<<"Invalid option, try again\n";
						continue;}
							cout << GREEN << "Dice chosen: " << table.getTableHand().at(int(keep - 48)).get_roll() << endl << RESET;

				iterator.push_back(int(keep) - 48); // what dice was chosen, make sure same dice isnt chosen again

				for (int i = 0; i < iterator.size(); i++)
					//	cout<<"iterator choices are: "<<iterator.at(i)<<endl;



				currPlayer.add(table.getTableHand().at(int(keep - 48)));
					diceChoosen++;  //KEEPING TRACK OF HOW MANY DICE HAVE BEEN SELECTED
						int value = (table.getTableHand().at(int(keep - 48)).get_roll());
							table.setScore(getScore((value), table.getTableHand()));// set the current score (using table class)
								cout << BLUE << "Current score is: " << table.getScore() << endl << RESET;
				//	cout<<"Player added: \n";
//				for (size_t i = 0; i < currPlayer.getHand().size(); i++)
					//		cout<< currPlayer.getHand().at(i).get_roll()<<endl;
					continue;
				}
				else if(cheater){
				
					if(int(keep-48) >= table.getCheater().size()){//TO NOT SEGFAULT WHEN TRYING TO ACCESS DIE > VECTOR<DIE>
						cout<<"Invalid option, try again\n";
							continue;}
								cout << GREEN << "Dice chosen: " << table.getCheater().at(int(keep - 48)).get_roll() << endl << RESET;

									iterator.push_back(int(keep) - 48); // what dice was chosen, make sure same dice isnt chosen again

				for (int i = 0; i < iterator.size(); i++)
					//	cout<<"iterator choices are: "<<iterator.at(i)<<endl;



				currPlayer.add(table.getCheater().at(int(keep - 48)));
					diceChoosen++;  //KEEPING TRACK OF HOW MANY DICE HAVE BEEN SELECTED
						int value = (table.getCheater().at(int(keep - 48)).get_roll());
							table.setScore(getScore((value), table.getCheater()));// set the current score (using table class)
								cout << BLUE << "Current score is: " << table.getScore() << endl << RESET;
				//	cout<<"Player added: \n";
//				for (size_t i = 0; i < currPlayer.getHand().size(); i++)
					//		cout<< currPlayer.getHand().at(i).get_roll()<<endl;
					continue;

					}
			}
			choosen = false; //reset boolean otherwise wont load any dice after 1st time they choose the same dice
			//}
	}
	else if (keep == 82 || keep == 114) { //IF THEY CHOOSE R(REROLL)
		
		if(iterator.size() <1) cout<<"You must choose at least 1 die to reroll\n";
		//	continue;
		else{
			resetCounters();//Reset the 3-of-a-kind, 4-of-a-kind counters
				cout << "Rerolling....\n# of dice chosen so far = " << diceChoosen << endl;
					table.clear();//new set of dice
						iterator.clear();// reset the vector that checks if they already chose a certain dice
							table.loadTableHand(DICE_REMAINING - diceChoosen);	//subtract # of dice chosen from new roll
								table.setRoll();
			if (getScore(0, table.getTableHand()) == -1) {
				cout << RED << "YOU FARKLED\n" << RESET;
					playerTurnOver = true;
						table.setScore(-5);//IF THEY FARKLE THEY LOSE ALL CURRENT POINTS RESET TABLE SCORE TO 0
			}
		}
		continue;
	}


	else if (keep == 80 || keep==112) { //if they want to finish and pass
		cout <<	currPlayer.getName()<< " BANKS POINTS.\n\n";
			playerTurnOver = true;
	}

	else
		;
}
if(diceChoosen==hotDice && !playerTurnOver){
	cout<<"Hot Dice!\n";
	hottDice=true;
}	
currPlayer.setScore(table.getScore());
	cout << BOLDGREEN << currPlayer.getName() << "'s Score is: " << currPlayer.getScore() << endl << RESET;
		resetCounters();//Reset the 3-of-a-kind, 4-of-a-kind counters
}
int main() {
	srand(time(0));
	int howManyOnes = 0, howManyTwos = 0, howManyThrees = 0, howManyFours = 0, howManyFives = 0, howManySixes = 0;
	Table t;
	Player PlyOne, PlyTwo;
	int pointLimit=0;
	int wager=0;
	cout << "Please enter how many points you will be playing to : " << endl;
		cin>>pointLimit;
			while(true){
				if(!cin) die();
					if (pointLimit < 0 || pointLimit > 100000){
						cout<<"Invalid input, try again\n";
							cin>>pointLimit;}

						else 
							break;
							}	

	cout << "Please enter Player 1's name " << endl;
		string player1Name = "";
			cin >> player1Name;
				PlyOne.setName(player1Name);
	
	cout << "Please enter Player 1's starting money (1-1000)" << endl;
		int player1StartMoney=0;
			cin >> player1StartMoney;
						while(true){
							if(!cin) die();
								if ( player1StartMoney < 0 || player1StartMoney > 1000){
									cout<<"Invalid input, try again\n";
										cin>>player1StartMoney;}

						else 
							break;
							}	
				PlyOne.setMoolah(player1StartMoney);



	cout << "Please enter Player 2's name " << endl;
		string player2Name = "";
			cin >> player2Name;
				PlyTwo.setName(player2Name);
	
	cout << "Please enter Player 2's starting money (1-1000)" << endl;
			int player2StartMoney;
					cin >> player2StartMoney;
						while(true){
							if(!cin) die();
								if ( player2StartMoney < 0 || player2StartMoney > 1000){
									cout<<"Invalid input, try again\n";
										cin>>player2StartMoney;}

						else 
							break;
							}	
								PlyTwo.setMoolah(player2StartMoney);
	cout<<"WAGER AMOUNT = \n";
		cin>> wager;
				while(true){
					if(!cin) die();
						if ( wager > PlyTwo.getMoolah() || wager > PlyOne.getMoolah()){
									cout<<"Can't bet more than the lowest player bank\nTry again.\n";
										cin>>wager;}

						else 
							break;
							}	
				t.setWagerUp(wager);

	
	while (PlyOne.getScore() <pointLimit || PlyTwo.getScore() < pointLimit) {
		
		cout <<"\n"<< MAGENTA << PlyOne.getName() << "'S TURN\n\n" << RESET;
		cout<<"Do you want to user cheater dice? (y or n)\n";
			gameFunction(t, PlyOne);
		
			if(PlyOne.getScore() >= pointLimit){
				cout<< PlyOne.getName() <<" Wins!"<<endl;
					PlyOne.setMoolah(PlyOne.getMoolah() + t.getWagerUp());
						PlyTwo.setMoolah(PlyTwo.getMoolah() - t.getWagerUp());
							cout<<PlyOne.getName()<<BOLDGREEN<< " has $ "<<PlyOne.getMoolah()<<endl<<RESET;
								cout<<PlyTwo.getName()<< BOLDGREEN<<" has $ "<<PlyTwo.getMoolah()<<endl<<RESET;
									break;}

		cout <<"\n"<< MAGENTA << PlyTwo.getName() << "'S TURN\n\n" << RESET;
		cout<<"Do you want to user cheater dice? (y or n)\n";
			gameFunction(t, PlyTwo);
		
			if(PlyTwo.getScore() >= pointLimit){
				cout<< PlyTwo.getName() <<" Wins!"<<endl;
					PlyTwo.setMoolah(PlyTwo.getMoolah() + t.getWagerUp());
						PlyOne.setMoolah(PlyOne.getMoolah() - t.getWagerUp());
							cout<<PlyOne.getName()<<BOLDGREEN<<" has $ "<<PlyOne.getMoolah()<<endl<<RESET;
								cout<<PlyTwo.getName()<<BOLDGREEN<<" has $ "<<PlyTwo.getMoolah()<<endl<<RESET;
									break;}

	}
}
