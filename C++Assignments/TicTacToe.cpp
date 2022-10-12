#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROW = 3, COL = 3;

void ticTacToe(char[][COL]);
void userTurn(char[][COL], char);
bool gameOver(char[][COL], char, bool&);
bool winLose(char[][COL], char);
bool stillWin(char[][COL], char);
void display(char);

//Tic Tac Toe

int main()
{
	char board[ROW][COL];
	char winnerrr = '*';
	bool winner = false;
	bool canWin1 = false;
	bool canWin2 = false;
	char player1 = 'X';
	char player2 = 'O';
	int winner1 = 0, winner2 = 0;

	//initialize the board
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			board[row][col] = '*';
		}
	}

	cout << "Tic Tac Toe\n";
	ticTacToe(board);

	do {
		// player 1 turn
		if (stillWin(board, player1) || (stillWin(board, player2))) {
			cout << "\nIt is player 1's turn (X)";
			userTurn(board, player1);
			if (gameOver(board, player1, winner)) { // check if game can still be played
				if (winner == true) {
					winnerrr = player1;
				}
				break;
			}
			ticTacToe(board);
		}
		else {
			break;
		}
		// player 2 turn
		if (stillWin(board, player1) || (stillWin(board, player2))) {
			cout << "\nIt is player 2's turn (O)";
			userTurn(board, player2);
			if (gameOver(board, player2, winner)) { // check if game can still be played
				if (winner == true) {
					winnerrr = player2;
				}
				break;
			}
			ticTacToe(board);
		}
		else {
			break;
		}

	} while (1 == 1);

	cout << "\nGame over\n" << endl;
	ticTacToe(board);
	display(winnerrr);

	system("pause");
	return 0;
}


//This function displays the game board.
// It is passed the array that holds tic tac toe board.
void ticTacToe(char board[][COL]) {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}


// This function allows the user to take a turn.
// It is passed the array that holds tic tac toe board and the player's symbol.
void userTurn(char board[][COL], char player) {
	int rowSelect = 0, colSelect = 0;
	bool taken = false;

	cout << "\nEnter the row and column numbers: ";
	cin >> rowSelect >> colSelect;
	// check input
	while (rowSelect - 1 < 0 || rowSelect - 1 >= ROW || colSelect - 1 < 0 || colSelect - 1 >= COL) {
		cout << "Enter the row and column numbers: ";
		cin >> rowSelect >> colSelect;
	}

	if (board[rowSelect - 1][colSelect - 1] != 'O' && board[rowSelect - 1][colSelect - 1] != 'X') {}
	else {
		while (1 == 1) {
			cout << "Enter the row and column numbers: ";
			cin >> rowSelect >> colSelect;
			if (board[rowSelect - 1][colSelect - 1] != 'X' && board[rowSelect - 1][colSelect - 1] != 'O') {
				break;
			}
		}
	}

	board[rowSelect - 1][colSelect - 1] = player;

}


/* 
   This function determines if the game is over.
   It is passed the array that holds tic tac toe board, 
   the player's symbol and the variable that holds the 
   result of the winLose function.
*/
bool gameOver(char board[][COL], char player, bool& winner) {
	bool over = false;

	winner = winLose(board, player); // check to see if a player has won

	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (board[row][col] == '*') {
				over = false;
				break;
			}
			else {
				over = true;
			}
		}
		if (over == false) {
			break;
		}
	}

	if (winner) {
		over = true;
	}

	return over;
}

// This function determines who wins the game.
// It is passed the array that holds tic tac toe board and the player symbol.
bool winLose(char board[][COL], char player) {
	bool win = false;

	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		win = true;
	}
	else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		win = true;
	}
	else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		win = true;
	}
	else if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		win = true;
	}
	else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		win = true;
	}
	else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		win = true;
	}
	else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		win = true;
	}
	else if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
		win = true;
	}

	return win;
}

// This function determines if a player can still win.
// It is passed the array that holds tic tac toe board and the player symbol.
bool stillWin(char board[][COL], char player) {
	bool canWin = false;
	char boardz[ROW][COL];

	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (board[row][col] == '*') {
				boardz[row][col] = player;
			}
			else {
				boardz[row][col] = board[row][col];
			}
		}
	}
	canWin = winLose(boardz, player);
	return canWin;
}


// This function display who wins.
// It is passed the player who has won.
void display(char winner) {
	if (winner == 'X') {
		cout << "\nPlayer 1 (X) wins\n";
	}
	else if (winner == 'O') {
		cout << "\nPlayer 2 (O) wins\n";
	}
	else {
		cout << "\nIt's a tie\n";
	}
	cout << endl;
}