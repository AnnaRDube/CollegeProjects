/* Anna Dube
00091750
adube@my.athens.edu
March 23, 2021
Project 2

This program runs the game Blackjack. 
We were not allowed to use functions or
arrays since they were not covered in class
at the point of this project */

#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int PLAY = 1;
const int HISTORY = 2;
const int QUIT = 3;
const int MIN_BET = 10;
const int MAX_BET = 150;
const int BUST = 21;
const int DEALER_HIT_LIMIT = 17;
const int MINUS_ACE = 10;
const int FIRST_FOUR = 4;
const int USER_THREE = 3;
const int DEALER_TWO = 2;

int main()
{
	int choice = 0;
	char answer;
	double credit = 0;
	double bet = 0;
	int randomCardNum = 0;
	char dealAgain;
	string dealerc1 = " ", dealerc2 = " ", dealerc3 = " ",
		dealerc4 = " ";
	int person = 0;
	int dealer = 0;
	string personc1 = " ", personc2 = " ", personc3 = " ",
		personc4 = " ", personc5 = " ";
	int holdCard = 0;
	string holdStringCard = " ";
	char winLose = ' ';
	int handCounter = 0;
	double moneyMade = 0;
	string linedata;
	int personAce11 = 0, holdAce11 = 0,
		dealerAce11 = 0;
	int blackJack = 0;
	ofstream outFile;
	ifstream inFile;

	do {
		cout << "\n******************************************" << endl;
		cout << "1. Play BlackJack" << endl
			<< "2. View Game History" << endl
			<< "3. Quit Game" << endl;
		cout << "******************************************" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case PLAY:
			// Play BlakJack
			//Get credit from user
			cout << "How much do you have credit for?" << endl;
			cin >> credit;
			// input validation
			while (credit < MIN_BET) {
				cout << "The amount entered is too low." << endl;
				cout << "How much do you have credit for?" << endl;
				cin >> credit;
			}

			// open DubeHistory file
			outFile.open("DubeHistory.txt");
			outFile << "Hand Card1 Card2 Card3 Card4 Card5 Bet Dealer W/L Balance\n";

			handCounter = 1;
			// do while loop runs through each hand until user wants to quit
			do {
				cout << "\n***************** Hand " << handCounter << " *****************\n";
				// clear cards from previous hand
				dealerc1 = dealerc2 = dealerc3 = dealerc4 = " ";
				personc1 = personc2 = personc3 = personc4 = personc5 = " ";
				// Get bet amount from user
				cout << "How much do you want to bet?" << endl;
				cin >> bet;

				while (bet < MIN_BET || bet > MAX_BET || bet > credit) {
					cout << "The amount entered was either to low or to high." << endl;
					cout << "How much do you want to bet?" << endl;
					cin >> bet;
				}

				srand(time(0));
				// re-initalizing variables for each hand
				person = 0;
				dealer = 0;
				personAce11 = 0;
				dealerAce11 = 0;
				for (int counter = 1; counter <= FIRST_FOUR; counter++) {
					// Deal first and second cards
					holdCard = 0;
					holdAce11 = 0;
					randomCardNum = rand() % 13 + 1;
					randomCardNum++;
					// determine card type and value
					if (randomCardNum == 11 || randomCardNum == 12 || randomCardNum == 13) {
						holdCard = 10;
						if (randomCardNum == 11) {
							holdStringCard = "J";
						}
						else if (randomCardNum == 12) {
							holdStringCard = "Q";
						}
						else if (randomCardNum == 13) {
							holdStringCard = "K";
						}
					}
					else {
						if (randomCardNum < 11 && randomCardNum > 1) {
							holdCard = randomCardNum;
							if (holdCard == 2) {
								holdStringCard = "2";
							}
							else if (holdCard == 3) {
								holdStringCard = "3";
							}
							else if (holdCard == 4) {
								holdStringCard = "4";
							}
							else if (holdCard == 5) {
								holdStringCard = "5";
							}
							else if (holdCard == 6) {
								holdStringCard = "6";
							}
							else if (holdCard == 7) {
								holdStringCard = "7";
							}
							else if (holdCard == 8) {
								holdStringCard = "8";
							}
							else if (holdCard == 9) {
								holdStringCard = "9";
							}
							else if (holdCard == 10) {
								holdStringCard = "10";
							}
						}
						else if (randomCardNum == 14) {
							holdStringCard = "A";
							if (counter == 3 && person > 10 || counter == 4 && dealer > 10) {
								holdCard = 1;
							}
							else {
								holdCard = 11;
								holdAce11++;
							}
						}
					}
					// add points to the user and dealer and assign card types
					if (counter == 1) {
						person += holdCard;
						personc1 = holdStringCard;
						personAce11 += holdAce11;
					}
					else if (counter == 2) {
						dealer += holdCard;
						dealerc1 = holdStringCard;
						dealerAce11 += holdAce11;
					}
					else if (counter == 3) {
						person += holdCard;
						personc2 = holdStringCard;
						personAce11 += holdAce11;
					}
					else if (counter == 4) {
						dealer += holdCard;
						dealerc2 = holdStringCard;
						dealerAce11 += holdAce11;
					}
				}

				//display user's first two cards
				cout << "User card: " << personc1 << " " << personc2 << endl;
				cout << "User points: " << person << endl;
				cout << "\nDealer's 2nd card: " << dealerc2 << endl;


				//BlackJack
				if (person == BUST) {
					cout << "\n*************BlackJack*************\n";
					system("pause");
					cout << "\nDealer cards: " << dealerc1 << " " << dealerc2;
					cout << "\nDealer points: " << dealer << endl;
					blackJack = 1;
					if (person > dealer) {
						credit += bet;
						moneyMade = bet + bet;
						cout << "\nYou won $" << moneyMade << " which includes your bet." << endl;
						cout << "Your credit is now at $" << credit << endl;
						winLose = 'W';
					}
					else {
						//push
						cout << "\nIt is a push" << endl;
						cout << "Your credit is $" << credit << endl;
						winLose = '-';
					}
				}



				if (person < BUST) {
					cout << "\nDo you want to hit or stay (h/s)?" << endl;
					cin >> dealAgain;
					while (dealAgain != 'h' && dealAgain != 's' && dealAgain != 'H' && dealAgain != 'S') {
						cout << "s or h was not entered\n";
						cout << "Do you want to hit or stay (h/s)?" << endl;
						cin >> dealAgain;
					}
					if (dealAgain == 'h' || dealAgain == 'H') {
						srand(time(0));
						for (int counter = 1; counter <= USER_THREE; counter++) {
							// Deal up to three cards to the user
							holdCard = 0;
							holdAce11 = 0;
							randomCardNum = rand() % 13 + 1;
							randomCardNum++;
							if (randomCardNum == 11 || randomCardNum == 12 || randomCardNum == 13) {
								holdCard = 10;
								if (randomCardNum == 11) {
									holdStringCard = "J";
								}
								if (randomCardNum == 12) {
									holdStringCard = "Q";
								}
								if (randomCardNum == 13) {
									holdStringCard = "K";
								}
							}
							else {
								if (randomCardNum < 11 && randomCardNum > 1) {
									holdCard = randomCardNum;
									if (holdCard == 2) {
										holdStringCard = "2";
									}
									if (holdCard == 3) {
										holdStringCard = "3";
									}
									if (holdCard == 4) {
										holdStringCard = "4";
									}
									if (holdCard == 5) {
										holdStringCard = "5";
									}
									if (holdCard == 6) {
										holdStringCard = "6";
									}
									if (holdCard == 7) {
										holdStringCard = "7";
									}
									if (holdCard == 8) {
										holdStringCard = "8";
									}
									if (holdCard == 9) {
										holdStringCard = "9";
									}
									if (holdCard == 10) {
										holdStringCard = "10";
									}
								}
								else if (randomCardNum == 14) {
									holdStringCard = "A";
									if (person > 10) {
										holdCard = 1;
									}
									else {
										if (person <= 10)
										{
											holdCard = 11;
											holdAce11++;
										}
									}
								}
							}
							// assigning points to the user and card types
							if (counter == 1) {
								person += holdCard;
								personc3 = holdStringCard;
								personAce11 += holdAce11;
							}
							if (counter == 2) {
								person += holdCard;
								personc4 = holdStringCard;
								personAce11 += holdAce11;
							}
							if (counter == 3) {
								person += holdCard;
								personc5 = holdStringCard;
								personAce11 += holdAce11;
							}
							// display cards
							cout << "\nUser card: " << personc1 << " " << personc2 << " "
								<< personc3 << " " << personc4 << " " << personc5 << endl;

							// check user points and ace to see if ace needs to change
							if (person > BUST && personAce11 > 0) {
								personAce11--;
								person -= MINUS_ACE;
								cout << "Ace value was changed from 11 to 1." << endl;
							}

							// display points
							cout << "User points: " << person << endl;

							if (person >= BUST) {
								break;
							}
							if (counter < 3) {
								cout << "\nDo you want to hit or stay (h/s)?" << endl;
								cin >> dealAgain;
								while (dealAgain != 'h' && dealAgain != 's' && dealAgain != 'H' && dealAgain != 'S') {
									cout << "s or h was not entered\n";
									cout << "Do you want to hit or stay (h/s)?" << endl;
									cin >> dealAgain;
								}
								if (dealAgain == 's' || dealAgain == 'S') {
									break;
								}
							}
						}
					}
				}




				if (person > BUST) {
					// user has busted. the hand ends
					cout << "\n************* BUST *************\n";
					cout << "Dealer card: " << dealerc1 << " " << dealerc2 << endl;
					cout << "Dealer points: " << dealer << endl;
					credit -= bet;
					cout << "You lost $" << bet << endl;
					cout << "Your credit is now at $" << credit << endl;
					winLose = 'L';
				}




				if (person <= BUST && blackJack == 0) {
					// user is done drawing and has not busted
					cout << "\nDealer card: " << dealerc1 << " " << dealerc2 << endl;
					cout << "Dealer points: " << dealer << endl << endl;
					cout << "Now it is the dealer's turn." << endl;
					system("pause");
					srand(time(0));
					for (int counter = 1; counter <= DEALER_TWO; counter++) {
						if (counter == 1 && dealer >= DEALER_HIT_LIMIT) {
							// check for Ace on card 1 and 2.
							// changes ace value from 11 to 1 if dealer is not higher than user
							if (dealer < person && dealer >= DEALER_HIT_LIMIT && dealerAce11 > 0) {
								dealerAce11--;
								dealer -= MINUS_ACE;
							}
							if (dealer >= DEALER_HIT_LIMIT) {
								break;
							}
						}
						// Dealer draws cards until their total points are greater than or equal to 17
						holdCard = 0;
						holdAce11 = 0;
						randomCardNum = rand() % 13 + 1;
						randomCardNum++;
						// assigning random number to a card with points
						if (randomCardNum == 11 || randomCardNum == 12 || randomCardNum == 13) {
							holdCard = 10;
							if (randomCardNum == 11) {
								holdStringCard = "J";
							}
							if (randomCardNum == 12) {
								holdStringCard = "Q";
							}
							if (randomCardNum == 13) {
								holdStringCard = "K";
							}
						}
						else {
							if (randomCardNum < 11 && randomCardNum > 1) {
								holdCard = randomCardNum;
								if (holdCard == 2) {
									holdStringCard = "2";
								}
								if (holdCard == 3) {
									holdStringCard = "3";
								}
								if (holdCard == 4) {
									holdStringCard = "4";
								}
								if (holdCard == 5) {
									holdStringCard = "5";
								}
								if (holdCard == 6) {
									holdStringCard = "6";
								}
								if (holdCard == 7) {
									holdStringCard = "7";
								}
								if (holdCard == 8) {
									holdStringCard = "8";
								}
								if (holdCard == 9) {
									holdStringCard = "9";
								}
								if (holdCard == 10) {
									holdStringCard = "10";
								}
							}
							else if (randomCardNum == 14) {
								holdStringCard = "A";
								if (dealer > 10) {
									holdCard = 1;
								}
								else {
									if (dealer <= 10)
									{
										holdCard = 11;
										holdAce11++;
									}
								}
							}
						}
						// assign points and card types to dealer
						if (counter == 1) {
							dealer += holdCard;
							dealerc3 = holdStringCard;
							dealerAce11 += holdAce11;
						}
						else if (counter == 2) {
							dealer += holdCard;
							dealerc4 = holdStringCard;
							dealerAce11 += holdAce11;
						}


						// changes ace value from 11 to 1 if dealer busts or is not higher than user
						if (dealer < person && dealer >= DEALER_HIT_LIMIT && dealerAce11 > 0) {
							dealerAce11--;
							dealer -= MINUS_ACE;
						}
						if (dealer > BUST && dealerAce11 > 0) {
							dealerAce11--;
							dealer -= MINUS_ACE;
						}
						if (dealer >= DEALER_HIT_LIMIT) {
							break;
						}

					}



					//display cards and points 
					cout << "\nUser card: " << personc1 << " " << personc2 << " "
						<< personc3 << " " << personc4 << " " << personc5 << endl;
					cout << "User points: " << person << endl;
					cout << "\nDealer card: " << dealerc1 << " " << dealerc2 << " "
						<< dealerc3 << " " << dealerc4 << " " << endl;
					cout << "Dealer points: " << dealer << endl << endl;


					if (dealer > BUST) {
						// dealer has busted
						cout << "The dealer has busted. You win." << endl;
						credit += bet;
						moneyMade = bet + bet;
						cout << "You won $" << moneyMade << " which includes your bet." << endl;
						cout << "Your credit is now at $" << credit << endl;
						winLose = 'W';
					}
					else if (person > dealer) {
						// user wins
						cout << "You win" << endl;
						credit += bet;
						moneyMade = bet + bet;
						cout << "You won $" << moneyMade << " which includes your bet." << endl;
						cout << "Your credit is now at $" << credit << endl;
						winLose = 'W';
					}
					else if (dealer > person) {
						//dealer wins
						cout << "The house wins" << endl;
						credit -= bet;
						cout << "You lost $" << bet << endl;
						cout << "Your credit is now at $" << credit << endl;
						winLose = 'L';
					}
					else {
						//push
						cout << "It is a push" << endl;
						cout << "Your credit is $" << credit << endl;
						winLose = '-';
					}
				}


				//write game information to the file
				outFile << setw(3) << handCounter << setw(5) << personc1 << setw(6) << personc2
					<< setw(6) << personc3 << setw(6) << personc4 << setw(6) << personc5
					<< setw(6) << bet << setw(6) << dealer
					<< setw(4) << winLose << setw(7) << credit << endl;

				blackJack = 0;
				handCounter++;
				// check user credit
				if (credit >= 10) {
					cout << "\nDo you want to play again (Y/N)?" << endl;
					cin >> answer;
					while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
						cout << "\nDo you want to play again (Y/N)?" << endl;
						cin >> answer;
					}
				}
				else {
					cout << "You do not have enough credit.\n";
					system("pause");
					break;
				}
			} while (answer == 'Y' || answer == 'y');
			outFile.close();
			break;



		case HISTORY:
			//open file and display contents
			cout << endl;
			inFile.open("DubeHistory.txt");
			if (inFile.fail()) {
				cout << "There is no history to display." << endl;
			}
			else {
				while (getline(inFile, linedata)) {
					cout << linedata << endl;
				}
			}
			inFile.close();
			cout << endl;
			system("pause");
			break;



		case QUIT:
			// quit option
			cout << "\nThank you for playing" << endl
				<< "Balance: $" << credit << endl;
			break;


		default: cout << "1, 2, or 3 was not entered." << endl;
		}

	} while (choice != 3);
	system("pause");
	return 0;
}