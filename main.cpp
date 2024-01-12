#include<iostream>
#include<ctime>
#include<fstream> 

using namespace std;
class snakesandladdergame{
    private:
	int playerpositions[4];
	int diceroll;
	public:
	int num;
	int gameplayed=0;
	string names[4];
    void snakesandladdergames(int);
    int rollDice();
    void movePlayer(int playerId, int steps);
    void checkSnakeAndLadder(int playerId);
    bool isGameWon();
    void playgame();
	void wait();
	void printdice(int);
	void printladder();
	void instructions();
	void printsnake();
	void bonusmove();
	void displayGameRecords();
	void updatePlayerRecord(string playerName, int matchesPlayed);
	bool isNameValid(string playerName);
 };
 
 void snakesandladdergame::printsnake(){
	cout << "  _" << endl;
    cout << " / \\" << endl;
    cout << "|o o|" << endl;
    cout << "|   |" << endl;
    cout << "|   |" << endl;
    cout << "|   |" << endl;
    cout << " \\_/" << endl;
 }
 void snakesandladdergame::instructions() {
    cout << "----------------- INSTRUCTIONS FOR SNAKES AND LADDERS GAME -----------------" << endl;
    cout << "1. The game is played on a board numbered from 1 to 100." << endl;
    cout << "2. Players take turns to roll a six-sided die to determine their movement." << endl;
    cout << "3. Each player starts at position 1 and moves forward according to the dice roll." << endl;
    cout << "4. If a player lands on a ladder, they climb to a higher position on the board." << endl;
    cout << "5. If a player lands on a snake, they slide down to a lower position on the board." << endl;
    cout << "6. The first player to reach position 100 wins the game." << endl;
    cout << "7. Additional ladder and snake positions are specified in the game logic." << endl;
    cout << "8. Press Enter to continue after each player's turn." << endl;
    cout << "9. The game ends when a player reaches position 100." << endl;
    cout << "10. Have fun playing the Snakes and Ladders game!" << endl;
    cout << "---------------------------------**********------------------------------------" << endl;
}

 void snakesandladdergame::printladder(){
	cout << "|    |\n";
	cout << "|----|\n";
	cout << "|    |\n";
	cout << "|----|\n";
	cout << "|    |\n";
 }
 void snakesandladdergame::printdice(int diceroll){
	cout << "+-------+" <<endl;
	cout << "|       |" <<endl;
	cout << "|   " << diceroll << "   |" <<endl;
	cout << "|       |" <<endl;
	cout << "+-------+" <<endl;
 }
 void snakesandladdergame::wait(){
	cin.get();
 }

 void snakesandladdergame::snakesandladdergames(int num){
	gameplayed++;
    for (int i = 0; i < num; ++i) {
            playerpositions[i] = 1;
        }
 }
 int snakesandladdergame::rollDice() {
        return rand() % 6 + 1;
    }
void snakesandladdergame::movePlayer(int playerId, int steps) {
        playerpositions[playerId] += steps;
		if(playerpositions[playerId]>100){
			cout<<"YOU CANNOT MOVE!!";
			playerpositions[playerId]=playerpositions[playerId]-steps;
		}
    }
void snakesandladdergame::checkSnakeAndLadder(int playerId) {
        int playerposition = playerpositions[playerId];
		switch(playerposition){
			case 4:
				cout<<"\nyou landed on a ladder now climb from position 4 to 45\n\n";
				printladder();
				playerpositions[playerId]=45;
				break;
			case 6:
				cout<<"\nYou landed on a ladder now climb from position 6 to 25\n\n";
				printladder();
				playerpositions[playerId]=25;
				break;
			case 32:
				cout<<"\nYou landed on a snakes now move back to position 5\n\n";
				printsnake();
				playerpositions[playerId]=5;
				break;
			case 40:
				cout<<"\nYou landed on a ladder now climb from position 40 to 77\n\n";
				printladder();
				playerpositions[playerId]=77;
				break;
			case 43:
				cout<<"\nYou landed on a snake now move back to position 17\n\n";
				printsnake();
				playerpositions[playerId]=17;
				break;
			case 50:
				cout<<"\nYou landed on a ladder now climb from position 50 to 93\n\n";
				printladder();
				playerpositions[playerId]=93;
				break;
			case 52:
				cout<<"\nYou landed on a snake now move back to position 11\n\n";
				printsnake();
				playerpositions[playerId]=11;
				break;
			case 57:
				cout<<"\nYou landed on a snake now move back to position 24\n\n";
				printsnake();
				playerpositions[playerId]=24;
				break;
			case 62:
				cout<<"\nYou landed on a snake now move back to position 22\n\n";
				printsnake();
				playerpositions[playerId]=22;
				break;
			case 68:
				 cout<<"\nYou landed on a ladder now climb from position 68 to 87\n\n";
				 printladder();
				 playerpositions[playerId]=87;
				 break;
			case 91:
				cout<<"\nYou landed on a snake now move back to position 51\n\n";
				printsnake();
				playerpositions[playerId]=51;
				break;
			case 95:
				cout<<"\nYou landed on a snake now move back to position 76\n\n";
				printsnake();
				playerpositions[playerId]=76;
				break;
			case 99:
				cout<<"\nYou landed on a snake now move back to position 10\n\n";
				printsnake();
				playerpositions[playerId]=10;
				break;
			default:
				break;				 									
		}
	}
bool snakesandladdergame::isGameWon() {
        for (int i = 0; i < num; i++) {
            if (playerpositions[i] == 100) {
                cout << "\nPlayer " <<names[i]<< " won!" << endl;
                return true;
            }
        }
        return false;
    }
 void snakesandladdergame::playgame() {
        srand(time(0));
    cout << "Enter the number of players (2 to 4): ";
    cin >> num;

    if (num < 2 || num > 4) {//valiations for checking number of players
        cout << "Invalid number of players. Please enter a number between 2 and 4." << endl;
        return;
    }

    for (int i = 0; i < num; i++) {
        string playerName;
        bool validName = false;

        do {
            cout << "Enter name for player " << i + 1 << ": ";
            cin >> playerName;

            if (isNameValid(playerName)) {//Player Name Validation{Ensure that each player enters a unique name}
                names[i] = playerName;
                validName = true;
            } else {
                cout << "Name already exists. Please enter a unique name." << endl;
            }
        } while (!validName);
    }

    snakesandladdergames(num);
        while (true) {
			if(num<=4 && num>=2){
            for (int i = 0; i < num; i++) {
				cout<<"it's "<<names[i]<<"'s turn press enter to continue\n";
				cin.ignore();
				cin.get();
                diceroll = rollDice();
				cout<<"dice rolled is:"<<diceroll<<endl;
				printdice(diceroll);
                movePlayer(i, diceroll);
                checkSnakeAndLadder(i);
				cout<<"\nThe current position of "<<names[i]<<" is "<<playerpositions[i]<<endl;
				while(diceroll==6){
					cout<<"YOU GOT A BONUS MOVE!!!!";
					diceroll = rollDice();
					cout<<"\nYour bonus move is:"<<diceroll;
					movePlayer(i, diceroll);
					cout<<"\nThe current position of "<<names[i]<<" is "<<playerpositions[i]<<endl;
				}
				if (isGameWon()) {					
                return;
            }
            }
             }
			else{
				cout<<"wrong input";
				break;
				
			}
    }
	}
void snakesandladdergame::updatePlayerRecord(string playerName, int matchesPlayed) {
    ifstream inFile("game_records.txt");
    ofstream outFile("temp.txt");

    bool playerFound = false;
    string name;
    int played;

    while (inFile >> name >> played) {
        if (name == playerName) {
            playerFound = true;
            played ++;
        }
        outFile << name << "\t" << played << endl;
    }

    inFile.close();
    outFile.close();

    remove("game_records.txt");
    rename("temp.txt", "game_records.txt");

    if (!playerFound) {
        ofstream newPlayer("game_records.txt", ios::app);
		matchesPlayed=1;
        newPlayer << playerName << "\t" << matchesPlayed << endl;
        newPlayer.close();
    }
}
void snakesandladdergame::displayGameRecords() {
        ifstream inFile("game_records.txt");

        if (!inFile.is_open()) {//Game Records File Existence Check{validation}
            cout << "Unable to open file or no records found!" << endl;
            return;
        }

        cout << "----------------- Game Records -----------------" << endl;
        cout << "Player Name" <<"\t"<<"Matches Played" << endl;
        cout << "-----------------------------------------------" << endl;

        string playerName;
        int matchesPlayed;

        while (inFile >> playerName >> matchesPlayed) {
            cout<<"    "<< playerName<<"\t\t\t"<< matchesPlayed << endl;
        }

        inFile.close();
    }
	bool snakesandladdergame::isNameValid(string playerName) {
    for (int i = 0; i < num; ++i) {
        if (playerName == names[i]) {
            return false; 
        }
    }
    return true;
}
 int main(){
    snakesandladdergame game;
    int choice;
	cout<<"************************************************************\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                  SNAKE AND LADDER GAME                   *\n";                                             
    cout<<"*         *************************************            *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                      DEVELOPED BY :-                     *\n";
    cout<<"*                      Prerna Sharma                       *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"*                                                          *\n";
    cout<<"************************************************************\n\n";

    do{
		cout<<"\nPress 1 to Start the Game\nPress 2 to Display Previous Matches\nPress 3 to View Instructions\nPress 4 to Quit\n\nEnter Your Choice:";
		cin>>choice;
		switch(choice)
		{
		case 1: 
			game.playgame();
			for(int i=0;i<game.num;i++)
			game.updatePlayerRecord(game.names[i],game.gameplayed);
		break;
		case 2:
			game.displayGameRecords();
			break;
		case 3: 
			game.instructions();
			break;
		case 4:	
			cout<<"***************EXITED FROM THE GAME***************";
			exit(0);
		default:
			cout<<"incorrect input";//Menu Choice Validation
			break;    
		}
	}while(choice!=4);
 }