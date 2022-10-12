/*
Anna Dube
adube@my.athens.edu
00091750
April 2021
CS 317
Assignment 10 Problem 1
*/

/* This program reads in a file and finds:
   the highest number
   the lowest number
   the average and
   the sum
*/

#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

void getNumbers(int [], int&);
int lowest(int, int []);
int highest(int, int[]);
int sum(int [], int);
double average(int[], int);

const int SIZE = 100;

int main()
{
    int counter;
    int numbers[SIZE];
    int low = 0, high = 0, add = 0; 
    double mean = 0;

    // function calls
    getNumbers(numbers, counter);
    low = lowest(counter, numbers);
    high = highest(counter, numbers);
    add = sum(numbers, counter);
    mean = average(numbers, counter);

    // display results
    cout << setprecision(2) << fixed << showpoint;
    cout << "\nThe highest number is " << high << endl;
    cout << "The lowest number is " << low << endl;
    cout << "The sum of all the numbers is " << add << endl;
    cout << "The average of all the numbers is " << mean << endl << endl;
    system("pause");
    return 0;
}

// This function reads numbers from a file.
void getNumbers(int numbers[], int &counter) {
    ifstream ifile;
    string fileName;
    int num = 0;

    counter = 0;
    cout << "Enter the file name: ";
    cin >> fileName;
    ifile.open(fileName);

    if (ifile.fail()) {
        cout << "Error opening file\n";
    }
    else {
        while (ifile >> num && counter < SIZE) {
            numbers[counter] = num;
            counter++;
        }
    }
    ifile.close();
}

// This function finds and returns the lowest number in the array.
// It is passed the array and the number of elements in the array.
int lowest(int size, int numbers[]) {
    int low = 0;
    low = numbers[0];
    for (int num = 0; num < size; num++) {
        if (low > numbers[num]) {
            low = numbers[num];
        }
    }
    return low;
}

// This function finds and returns the highest number in the array.
// It is passed the array and the number of elements in the array.
int highest(int size, int numbers[]) {
    int high = 0;
    high = numbers[0];
    for (int num = 0; num < size; num++) {
        if (high < numbers[num]) {
            high = numbers[num];
        }
    }
    return high;
}

// This function calculates the sum of the numbers in the array.
// It is passed the array and the number of elements in the array.
int sum(int numbers[], int size) {
    int adding = 0;
    for (int num = 0; num < size; num++) {
        adding += numbers[num];
    }
    return adding;
}

// This function calculates the average of the numbers in the array.
// It is passed the array and the number of elements in the array.
double average(int numbers[], int size) {
    int adding = 0; 
    double mean = 0;
    for (int num = 0; num < size; num++) {
        adding += numbers[num];
    }
    mean = static_cast<double>(adding) / size;
    return mean;
}