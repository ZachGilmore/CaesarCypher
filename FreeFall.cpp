/* Author: Zach Gilmore
* Class: CSC-140
* Assignment: Homework Problems 2
* Date: Feb 2, 2021
* */

#include <iostream>
using namespace std;

int main()
{
	int timeSecs;		//should use float or double just in case a decimal does happen to show up
	int distance;

	// Greeting and time input

	cout << "This program will determine the distance (in feet) an object travels in freefall." << endl;
	cout << "Please enter time in seconds: ";
	cin >> timeSecs;
	cout << endl;

	// Distance Formula

	distance = 32 * (timeSecs * timeSecs) / 2;

	// Final output

	cout << "The object fell at a rate of " << distance << " feet for " << timeSecs << " seconds." << endl;


	return 0;







}

