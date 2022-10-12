// Anna Dube
// 00091750
// adube@my.athens.edu
// Phase 3
// 2 in 1 Numbers: High roll vs Low roll
// and Sudoku

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

const int ROW_COL = 4;

void mainMenu();
void highLowRoll();
void sudoku();
void playHighLow(int&, int&);
void checkHighLow(int, int);
void displaySudokuBoard(int[ROW_COL][ROW_COL]);
void setUpSudoku(int[ROW_COL][ROW_COL]);
void createGameBoard(int[ROW_COL][ROW_COL]);
void openFile(string);
void sudokuWinLose(int[ROW_COL][ROW_COL]);

int main()
{
	int mmChoice = 0;
	do {
		mainMenu();
		cin >> mmChoice;

		if (mmChoice == 1) {
			highLowRoll();
		}
		else if (mmChoice == 2) {
			sudoku();
		}
		else if (mmChoice == 3){ system("Pause"); }
		else {
			cout << "Invalid choice\n";
			system("Pause");
		}
		
	} while (mmChoice != 3);
	return 0;
}

//Main menu
void mainMenu() {
	system("CLS");
	cout << "-------------- 2 in 1 Numbers --------------\n"
		<< "********************************************\n"
		<< "1. High roll vs. Low roll\n"
		<< "2. Sudoku\n"
		<< "3. Exit\n"
		<< "********************************************\n"
		<< "Enter your choice 1-3: ";
}

// High roll vs. Low roll game menu
void highLowMenu() {
	system("CLS");
	cout << "---------- High roll vs. Low roll ----------\n"
		<< "============================================\n"
		<< "1. Play High Roll\n"
		<< "2. Play Low Roll\n"
		<< "3. Tutorial\n"
		<< "4. Exit\n"
		<< "============================================\n"
		<< "Enter your choice 1-4: ";
}
// Sudoku game menu
void sudokuMenu() {
	system("CLS");
	cout << "------------------ Sudoku ------------------\n"
		<< "============================================\n"
		<< "1. Play Sudoku\n"
		<< "2. Tutorial\n"
		<< "3. Return to Menu\n"
		<< "============================================\n"
		<< "Enter your choice 1-3: ";
}

// Playing High rol vs. Low roll
void highLowRoll() {
	int hlmChoice = 0;
	int userNum = 0;
	unsigned hlSeed = time(0);
	srand(hlSeed);
	int randNum = 0;

	do {
		highLowMenu();
		cin >> hlmChoice;
		cout << endl;

		if (hlmChoice == 1) {
			// High roll
			playHighLow(userNum, randNum);
			checkHighLow(userNum, randNum);
		}
		else if (hlmChoice == 2) {
			// Low roll
			playHighLow(userNum, randNum);
			checkHighLow(randNum, userNum);
		}
		else if (hlmChoice == 3) {
			// tutorial
			string fileName = "HighLowTutorial.txt";
			cout << "---- Tutorial ----\n";
			openFile(fileName);
		}
		else if (hlmChoice == 4) {
			cout << "Returning to the main menu\n";
		}
		else {
			cout << "Invalid choice\n";
		}
		cout << endl;
		system("Pause");
	} while (hlmChoice != 4);
}

// open file for tutorial
void openFile(string fileName) {
	string temp = "";
	ifstream ifile;
	ifile.open(fileName);
	if (ifile.fail()) {
		cout << "Error opening file\n";
	}
	else {
		while (getline(ifile, temp)) {
			cout << temp << endl;
		}
	}
	ifile.close();
}

// Playing Sudoku
void sudoku() {
	int sChoice = 0;
	int userNum = 0;
	int x, y;
	bool over = false;
	unsigned sSeed = time(0);
	srand(sSeed);
	int sudokuArr[ROW_COL][ROW_COL];

	do {
		sudokuMenu();
		cin >> sChoice;
		cout << endl;

		if (sChoice == 1) {
			over = true;
			// initialize sudoku array
			setUpSudoku(sudokuArr);
			// create game board with numbers missing
			createGameBoard(sudokuArr);
			do {
				system("CLS");
				displaySudokuBoard(sudokuArr);

				cout << "Enter coordinates(R C): ";
				cin >> x >> y;
				while ((x > 4 || x < 0) || (y > 4 || y < 0) || sudokuArr[x - 1][y - 1] != 0) {
					cout << "Enter coordinates(R C): ";
					cin >> x >> y;
				}
				x--;
				y--;
				cout << "Enter a number 1-4: ";
				cin >> userNum;
				while (userNum > 4 || userNum < 0) {
					cout << "Enter a number 1-4: ";
					cin >> userNum;
				}
				sudokuArr[x][y] = userNum;
				// check to see if the game is over
				for (int countX = 0; countX < ROW_COL; countX++) {
					for (int countY = 0; countY < ROW_COL; countY++) {
						if (sudokuArr[countX][countY] == 0) {
							over = false;
							break;
						}
						else {
							over = true;
						}
					}
					if (over == false) { break; }
				}
			} while (over == false);
			system("CLS");
			displaySudokuBoard(sudokuArr);
			sudokuWinLose(sudokuArr);
		}
		else if (sChoice == 2) {
			string fileName = "sudokuTutorial.txt";
			cout << "---- Tutorial ----\n";
			openFile(fileName);
		}
		else if (sChoice == 3) {
			cout << "Returning to the main menu\n";
		}
		else {
			cout << "Invalid choice\n";
		}
		cout << endl;
		system("Pause");
	} while (sChoice != 3);
}

// Display the Sudoku board
void displaySudokuBoard(int gameBoard[ROW_COL][ROW_COL]) {
	cout << "\n C 1 2 3 4\n";
	cout << "R  -------\n";
	for (int countX = 0; countX < ROW_COL; countX++) {
		cout << countX + 1 << "| ";
		for (int countY = 0; countY < ROW_COL; countY++) {
			cout << gameBoard[countX][countY] << " ";
		}
		cout << endl;
	}
}

// check to see if user wins
void sudokuWinLose(int gameBoard[ROW_COL][ROW_COL]) {
	int totalR = 0, totalC = 0, totalS = 0;
	int r = 0, c = 0, s = 0;
	for (int countX = 0; countX < ROW_COL; countX++) {
		totalR = 0;
		totalC = 0;
		for (int countY = 0; countY < ROW_COL; countY++) {
			// check rows and columns
			totalR += gameBoard[countX][countY];
			totalC += gameBoard[countY][countX];
			// check diagonals
			if (countX % 2 == 0 && countY % 2 == 0) {
				for (int x = countX; x < countX + 2; x++) {
					for (int y = countY; y < countY + 2; y++) {
						totalS += gameBoard[x][y];
						if (totalS == 10) { s++; }
					}
				}
				totalS = 0;
			}
		}
		if (totalR == 10) { r++; }
		if (totalC == 10) { c++; }
	}
	if (s == 4 && r == 4 && c == 4)
	{
		cout << "\nYou win!\n";
	}
	else { cout << "\nYou lose.\n"; }
}

// create a valid sudoku array
void setUpSudoku(int sudokuArr[ROW_COL][ROW_COL]) {
	const int S_MIN = 1;
	int randNum = 0;
	int countX, countY;
	bool good = true;
	bool problem = 0;
	char trackProblems[5] = { ' ', ' ', ' ', ' ', ' ' };

	//initialize array
	for (countX = 0; countX < ROW_COL; countX++) {
		for (countY = 0; countY < ROW_COL; countY++) {
			sudokuArr[countX][countY] = 0;
		}
	}

	for (countX = 0; countX < ROW_COL; countX++) {
		for (countY = 0; countY < ROW_COL; countY++) {
			problem = false;
			for (int x = 0; x < 5; x++) {
				trackProblems[x] = ' ';
			}
			do {
				good = true;
				randNum = (rand() % (ROW_COL - S_MIN + 1)) + S_MIN;
				trackProblems[randNum] = '*';

				//check rows and columns
				for (int checkY = 0; checkY < ROW_COL; checkY++) {
					if (sudokuArr[countX][checkY] == randNum) {
						good = false;
					}
				}
				for (int checkX = 0; checkX < ROW_COL; checkX++) {
					if (sudokuArr[checkX][countY] == randNum) {
						good = false;
					}
				}
				// check diagonals
				if (countX % 2 != 0) {
					if (countY % 2 == 0) {
						if (sudokuArr[countX - 1][countY + 1] == randNum) {
							good = false;
						}
					}
					else {
						if (sudokuArr[countX - 1][countY - 1] == randNum) {
							good = false;
						}
					}
				}
				// check to see if every number 1-4 has been checked
				// for a specific spot in the array
				for (int x = 1; x < 5; x++) {
					if (trackProblems[x] != ' ') {
						problem = true;
					}
					else {
						problem = false;
						break;
					}
				}
				if (problem && !good) {	break; }
			} while (!good);
			if (good) {
				sudokuArr[countX][countY] = randNum;
			}
			if (problem && !good) { break; }
		}
		if (problem && !good) { break; }
	}
	if (problem && !good) { setUpSudoku(sudokuArr); }
}

// set up the Sudoku game board
void createGameBoard(int gameBoard[ROW_COL][ROW_COL]) {
	unsigned sSeed = time(0);
	srand(sSeed);
	int countZ;

	for (countZ = 0; countZ < 50; countZ++) {
		int rowxx = (rand() % (ROW_COL - 1 + 1));
		int colyy = (rand() % (ROW_COL - 1 + 1));
		int a = 0;
		for (int m = 0; m < 4; m++) {
			if (gameBoard[rowxx][m] != 0) {
				a++;
			}
		}
		int b = 0;
		for (int m = 0; m < 4; m++) {
			if (gameBoard[m][colyy] != 0) {
				b++;
			}
		}
		if (a > 1 && b > 1) {
			gameBoard[rowxx][colyy] = 0;
		}
		// should we exit loop
		int aa[4] = { 0, 0, 0, 0 };
		int bb[4] = { 0, 0, 0, 0 };

		for (int countA = 0; countA < 4; countA++) {
			for (int m = 0; m < 4; m++) {
				if (gameBoard[countA][m] != 0) {
					aa[countA]++;
				}
			}
			for (int m = 0; m < 4; m++) {
				if (gameBoard[m][countA] != 0) {
					bb[countA]++;
				}
			}
		}
		if (aa[0] > 1 && aa[0] < 4 && aa[1] > 1 && aa[1] < 4
			&& aa[2] > 1 && aa[2] < 4 && aa[3] > 1 && aa[3] < 4) {
			if (bb[0] > 1 && bb[0] < 4 && bb[1] > 1 && bb[1] < 4
				&& bb[2] > 1 && bb[2] < 4 && bb[3] > 1 && bb[3] < 4) {
				break;
			}
		}
	}
}

// Playing high or low roll
void playHighLow(int& userNum, int& randNum) {
	const int HL_MIN = 1;
	const int HL_MAX = 8;
	const int DIMENSIONS = 5;
	char hlArray[DIMENSIONS][DIMENSIONS];
	randNum = (rand() % (HL_MAX - HL_MIN + 1)) + HL_MIN;

	// set up die
	for (int countX = 0; countX < DIMENSIONS; countX++) {
		for (int countY = 0; countY < DIMENSIONS; countY++) {
			hlArray[countX][countY] = ' ';
		}
	}
	int holdRand = randNum;
	for (int countX = 0; countX < DIMENSIONS; countX++) {
		for (int countY = 0; countY < DIMENSIONS; countY++) {
			if (countX == 0 || countX == DIMENSIONS - 1) {
				hlArray[countX][countY] = '-';
				continue;
			}
			if (countY == 0 || countY == DIMENSIONS - 1) {
				hlArray[countX][countY] = '|';
				continue;
			}
			if (holdRand > 0) {
				hlArray[countX][countY] = '*';
				--holdRand;
			}
		}
	}
	hlArray[0][DIMENSIONS - 1] = ' ';
	hlArray[DIMENSIONS - 1][0] = ' ';
	hlArray[DIMENSIONS - 1][DIMENSIONS - 1] = ' ';
	hlArray[0][0] = ' ';

	cout << "Enter a number 1-8: ";
	cin >> userNum;
	while (userNum < HL_MIN || userNum > HL_MAX) {
		cout << "Enter a number 1-8: ";
		cin >> userNum;
	}
	system("Pause");
	for (int countX = 0; countX < DIMENSIONS; countX++) {
		for (int countY = 0; countY < DIMENSIONS; countY++) {
			cout << hlArray[countX][countY];
		}
		cout << endl;
	}
	cout << "Die: " << randNum << endl;
	cout << "Your Number: " << userNum << endl;
}

// Determine if user has won high or low roll
void checkHighLow(int num1, int num2) {
	if (num1 > num2) {
		cout << "You lose.\n";
	}
	else if (num1 < num2) {
		cout << "You win!\n";
	}
	else {
		cout << "It's a tie.\n";
	}
}
