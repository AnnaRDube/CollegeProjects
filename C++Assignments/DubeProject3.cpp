/* Anna Dube
   00091750
   adube@my.athens.edu
   April 2021
   CS 317
   Project 3

   This is a seat reservation program for a theater
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ROWS = 7;
const int SEATS = 8;
const string MOVIE1 = "Free Birds";
const string MOVIE2 = "Beethoven";
const string MOVIE1_TIME1 = "3:30 pm";
const string MOVIE1_TIME2 = "6:00 pm";
const string MOVIE2_TIME1 = "5:30 pm";
const string MOVIE2_TIME2 = "7:30 pm";
const double ADULT_TICKET = 6.0;
const double CHILD_TICKET = 4.0;
const double ADULT_TICKET_EVE = 8.0;
const double CHILD_TICKET_EVE = 6.0;
const int ADMIN = -99;
const int CHOICE1 = 1;
const int CHOICE2 = 2;
const int CHOICE3 = 3;
const int CHOICE4 = 4;
const int TOTAL_SEAT = 56;
char selection1[ROWS][SEATS];
char selection2[ROWS][SEATS];
char selection3[ROWS][SEATS];
char selection4[ROWS][SEATS];


void movieListings();
void admin(int, int, int, double, double, double, int&);
void seatingChart(int&, int&, int&, int&, int&, int&, double&, double&, double&, int, double&, char[][SEATS]);
void getAmount(int&, int&, int&);
void totalBill(int&, int&, int&, int&, int&, double&, double&, double&, int, double&);


int main()
{
	int choice = 0;
	double total = 0, totalChild = 0, totalAdult = 0, profit = 0;
	int aTicketAmount = 0, cTicketAmount = 0, ticketsPurchased = 0,
		cTicketsSold = 0, aTicketsSold = 0, totalSold = 0;
	int shutDown = 0;

	for (int rowCount = 0; rowCount < ROWS; rowCount++) {
		for (int colCount = 0; colCount < SEATS; colCount++) {
			selection1[rowCount][colCount] = '*';
			selection2[rowCount][colCount] = '*';
			selection3[rowCount][colCount] = '*';
			selection4[rowCount][colCount] = '*';
		}
	}

	cout << setprecision(2) << fixed << showpoint;
	do {

		movieListings(); // call function to show movie listings
		cin >> choice;
		cout << endl;


		if (choice == CHOICE1) {
			//first movie
			cout << MOVIE1 << ": " << MOVIE1_TIME1 << endl;
			seatingChart(ticketsPurchased, aTicketAmount, cTicketAmount, cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, total, choice, profit, selection1);
		}
		else if (choice == CHOICE2) {
			// second movie
			cout << MOVIE1 << ": " << MOVIE1_TIME2 << endl;
			seatingChart(ticketsPurchased, aTicketAmount, cTicketAmount, cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, total, choice, profit, selection2);
		}
		else if (choice == CHOICE3) {
			// third movie
			cout << MOVIE2 << ": " << MOVIE2_TIME1 << endl;
			seatingChart(ticketsPurchased, aTicketAmount, cTicketAmount, cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, total, choice, profit, selection3);
		}
		else if (choice == CHOICE4) {
			// fourth movie
			cout << MOVIE2 << ": " << MOVIE2_TIME2 << endl;
			seatingChart(ticketsPurchased, aTicketAmount, cTicketAmount, cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, total, choice, profit, selection4);
		}
		else if (choice == ADMIN) {
			// admin funcion call
			admin(cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, profit, shutDown); // call admin function
		}
		else
			cout << "A number 1-4 was not entered\n";

		cout << endl;
		total = 0;

	} while (shutDown == 0);
	system("pause");
	return 0;
}

// This function displays movie times and prices
void movieListings() {
	cout << setprecision(2) << fixed << showpoint;
	cout << "========================================================\n";
	cout << setw(39) << "Movie Times and Prices\n";
	cout << "--------------------------------------------------------\n";
	cout << setw(13) << "Movie Title" << setw(10) << "Time" << setw(18) << "Adult Price" << setw(16) << "Child Price\n"
		<< setw(13) << "-----------" << setw(12) << "-------" << setw(16) << "-----------" << setw(16) << "-----------\n"
		<< CHOICE1 << " " << MOVIE1 << setw(13) << MOVIE1_TIME1 << setw(9) 
		<< "$" << ADULT_TICKET << setw(11) << "$" << CHILD_TICKET << endl
		<< CHOICE2 << " " << MOVIE1 << setw(13) << MOVIE1_TIME2 << setw(9) 
		<< "$" << ADULT_TICKET_EVE << setw(11) << "$" << CHILD_TICKET_EVE << endl
		<< CHOICE3 << " " << MOVIE2 << setw(14) << MOVIE2_TIME1 << setw(9) 
		<< "$" << ADULT_TICKET << setw(11) << "$" << CHILD_TICKET << endl
		<< CHOICE4 << " " << MOVIE2 << setw(14) << MOVIE2_TIME2 << setw(9) 
		<< "$" << ADULT_TICKET_EVE << setw(11) << "$" << CHILD_TICKET_EVE << endl;
	cout << "========================================================\n";
}


// This function gets the ticket amounts.
void getAmount(int& aTicketAmount, int& cTicketAmount, int& ticketsPurchased) {
	cout << "How many adult tickets? ";
	cin >> aTicketAmount;
	while (aTicketAmount < 0) {
		cout << "How many adult tickets? ";
		cin >> aTicketAmount;
	}
	cout << "How many child tickets? ";
	cin >> cTicketAmount;
	while (cTicketAmount < 0) {
		cout << "How many adult tickets? ";
		cin >> aTicketAmount;
	}
	ticketsPurchased = cTicketAmount + aTicketAmount;
}

// This function calculates the total bill.
void totalBill(int& aTicketAmount, int& cTicketAmount, int& cTicketsSold, int& aTicketsSold, int& totalSold, double& totalChild, double& totalAdult, double& total, int select, double& profit) {
	cTicketsSold += cTicketAmount;
	aTicketsSold += aTicketAmount;
	totalSold = aTicketsSold + cTicketsSold;

	if (select == CHOICE1 || select == CHOICE3) {
		// regular price
		totalChild += cTicketAmount * CHILD_TICKET;
		totalAdult += aTicketAmount * ADULT_TICKET;
		total = (cTicketAmount * CHILD_TICKET) + (aTicketAmount * ADULT_TICKET);
	}
	else {
		// evening price
		totalChild += cTicketAmount * CHILD_TICKET_EVE;
		totalAdult += aTicketAmount * ADULT_TICKET_EVE;
		total = (cTicketAmount * CHILD_TICKET_EVE) + (aTicketAmount * ADULT_TICKET_EVE);
	}
	profit += total;
	cout << "\nTotal: $" << total << endl;
}



// This function displays the seating chart and allows the user to select their seats.
// The seating chart is then updated.
void seatingChart(int& ticketsPurchased, int& aTicketAmount, int& cTicketAmount, int& cTicketsSold, int& aTicketsSold, int& totalSold, double& totalChild, double& totalAdult, double& total, int choice, double& profit, char selection[][SEATS]) {
	int rowSelect, seatSelect;
	static int available = 0;
	char selectionz[ROWS][SEATS];

	cout << "\nSeats ";
	for (int counter = 0; counter < SEATS; counter++)
		cout << counter + 1 << " ";
	cout << endl;

	//show matrix
	for (int rowCount = 0; rowCount < ROWS; rowCount++) {
		cout << "Row " << rowCount + 1 << " ";
		for (int colCount = 0; colCount < SEATS; colCount++) {
			cout << selection[rowCount][colCount] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "* - available\n# - taken\nX - blocked\n\n";

	// check for available seats
	available = 0;
	for (int rowCount = 0; rowCount < ROWS; rowCount++) {
		for (int colCount = 0; colCount < SEATS; colCount++) {
			if (selection[rowCount][colCount] == '*') {
				available++;
			}
		}
	}
	// call getAmount to get the number of tickets the user wants to purchase
	getAmount(aTicketAmount, cTicketAmount, ticketsPurchased);
	cout << endl;

	if (ticketsPurchased <= available) {

		// do forever
		for (int countt = 0; countt < TOTAL_SEAT; countt++) {

			// blank out selectionZ
			for (int row = 0; row < ROWS; row++) {
				for (int col = 0; col < SEATS; col++) {
					selectionz[row][col] = '*';
				}
			}

			cout << "\nChoose your seats... " << endl;

			// get row and seat numbers from user
			for (int counter = 0; counter < ticketsPurchased; counter++) {
				cout << "Enter the row and seat for ticket " << counter + 1 << ": ";
				cin >> rowSelect >> seatSelect;

				// check seats
				if (rowSelect > SEATS || seatSelect > SEATS || rowSelect < 1 || seatSelect < 1) {
					cout << "\nChoose again\n" << endl;
					counter--;
					continue;
				}

				if (selectionz[rowSelect - 1][seatSelect - 1] == '#') {
					cout << "\n\nSeat taken. Choose again\n\n";
					counter--;
					continue;
				}
				selectionz[rowSelect - 1][seatSelect - 1] = '#';
			}

			bool wegottaproblem = false;
			// check row and seat numbers
			for (int rowCount = 0; rowCount < ROWS; rowCount++) {
				for (int colCount = 0; colCount < SEATS; colCount++) {
					if (selectionz[rowCount][colCount] == '#' && selection[rowCount][colCount] != '*') {
						wegottaproblem = true;
					}
				}
			}

			if (wegottaproblem) {
				cout << "\n\nSeats already taken or empty for social distance.\n" << endl;
				continue;
			}


			// assigning row and seat numbers
			for (int rowCount = 0; rowCount < ROWS; rowCount++) {
				for (int colCount = 0; colCount < SEATS; colCount++) {
					if (selectionz[rowCount][colCount] == '#') {
						selection[rowCount][colCount] = '#';
					}

				}
			}


			// place x on blocked seats
			for (int rowCount = 0; rowCount < ROWS; rowCount++) {
				for (int colCount = 0; colCount < SEATS; colCount++) {
					if (selection[rowCount][colCount] == '#') {
						// prior row
						bool gotsomething = false;
						for (int colCount = 0; colCount < SEATS; colCount++) {
							if (selectionz[rowCount - 1][colCount] == '#') {
								gotsomething = true;
							}
						}
						if (rowCount > 0 && gotsomething == false && selection[rowCount - 1][colCount] == '*') {
							selection[rowCount - 1][colCount] = 'X';
						}
						// current row
						if (colCount > 0 && selection[rowCount][colCount - 1] != '#' && selection[rowCount][colCount - 1] == '*') {
							selection[rowCount][colCount - 1] = 'X';
						}
						if (colCount < 7 && selection[rowCount][colCount + 1] != '#' && selection[rowCount][colCount + 1] == '*') {
							selection[rowCount][colCount + 1] = 'X';
						}
						// subsequent row
						gotsomething = false;
						for (int colCount = 0; colCount < SEATS; colCount++) {
							if (selectionz[rowCount + 1][colCount] == '#') {
								gotsomething = true;
							}
						}
						if (rowCount < ROWS - 1 && gotsomething == false && selection[rowCount + 1][colCount] == '*') {
							selection[rowCount + 1][colCount] = 'X';
						}
					}
				}
			}
			break;
		}

		cout << "\nSeats ";
		for (int counter = 0; counter < SEATS; counter++) {
			cout << counter + 1 << " ";
		}

		cout << endl;
		// display updated seating chart
		for (int rowCount = 0; rowCount < ROWS; rowCount++) {
			cout << "Row " << rowCount + 1 << " ";
			for (int colCount = 0; colCount < SEATS; colCount++) {
				cout << selection[rowCount][colCount] << " ";
			}
			cout << endl;
		}
		// get total bill amount
		totalBill(aTicketAmount, cTicketAmount, cTicketsSold, aTicketsSold, totalSold, totalChild, totalAdult, total, choice, profit);
	}
	else {
		cout << "There are not enough seats.\n";
	}
}






// This function gives administrators access to ticket data
void admin(int cTicketsSold, int aTicketsSold, int totalSold, double totalChild, double totalAdult, double profit, int &exiting) {
	int adminChoice = 0;
	int menuChoice = 0;
	do {
		cout << "\n*************************************\n";
		cout << "1. Tickets Sold\n"
			<< "2. Profits\n"
			<< "3. Return to movie listings\n"
			<< "4. Shut Down\n"
			<< "*************************************\n"
			<< "Enter your choice: ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice)
		{
		case 1:
			// allow user to select how they want tickets sold to be displayed
			cout << "\nSelect number of tickets sold to be displayed by:\n(1) ticket type\n(2) total\n";
			cin >> adminChoice;
			while (adminChoice != CHOICE1 && adminChoice != CHOICE2) {
				cout << "Select number of tickets sold to be displayed by:\n(1) ticket type\n(2) total\n";
				cin >> adminChoice;
			}
			if (adminChoice == CHOICE1) {
				cout << "Child Tickets: " << cTicketsSold << endl
					<< "Adult Tickets: " << aTicketsSold << endl;
			}
			else {
				cout << "Total tickets sold: " << totalSold << endl;
			}
			break;


		case 2:
			// allow user to select how they want profits to be displayed
			cout << "Select the profits to be displayed by:\n(1) tickets sold by ticket type\n(2) total\n";
			cin >> adminChoice;
			while (adminChoice != CHOICE1 && adminChoice != CHOICE2) {
				cout << "Select number of tickets sold to be displayed by:\n(1) tickets sold by ticket type\n(2) total\n";
				cin >> adminChoice;
			}
			if (adminChoice == CHOICE1) {
				cout << "Child Tickets: $" << totalChild << endl
					<< "Adult Tickets: $" << totalAdult << endl;
			}
			else {
				cout << "Total profits: $" << profit << endl;
			}

			break;

		case 3:
			// break out of switch statement and do while.
			// return to displaying movies
			break;

		case 4:
			//shut down
			cout << "Shutting down\n";
			exiting = 1;
			break;
		default: cout << "1-4 was not selected\n";
		}
	} while (menuChoice != CHOICE3 && menuChoice != CHOICE4);
}