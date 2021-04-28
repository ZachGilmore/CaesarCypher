//Zach Gilmore
//CSC-140
//Feb 11, 2021
//Program: Book Club

//My only issue with this is when the discount is applied the number goes past the hundreths place, ie "$64.775" and I'm
//not sure how to round it up to just 2 decimal places.

#include <iostream>
using namespace std;

int main()
{
    double book1 = 7.95;
    double book2 = 12.95;
    int totalNumBooks = 0;
    double totalCost = 0.00;
    double discount;
    string userInput;


    //Program instructions and user input

    cout << "Greetings fellow bookworm! This program will allow you to purchase as many books as you would like." << endl;
    cout << "Granted, there are only two (2) books to choose from (yikes!), but you can purchase as many of those\nas you'd like!" << endl;
    cout << "'Dune' costs $7.95, 'Misery' costs $12.95." << endl;

    cout << "Do you wish to purchase any books today? (Press any key to confirm. Type 'Exit' to exit to purchase screen.)" << endl;
    cin >> userInput;

    //Loops
    while (!(userInput == "Exit" || userInput == "exit")) {

        cout << "Would you like to purchase 'Dune' ($7.95) or 'Misery' ($12.95)? (Enter 'Exit' to proceed to purchase)" << endl;
        cin >> userInput;

        if (userInput == "Dune" || userInput == "dune") {
            totalNumBooks = totalNumBooks + 1;
            totalCost = totalCost + book1;
            cout << "You purchased 'Dune' for $7.95." << endl;
            //Prints out current number of books and current total.
            cout << "Current books purchased: " << totalNumBooks << ". Current total: " << totalCost << "." << endl;
            continue;
        }
        else if (userInput == "Misery" || userInput == "misery") {
            totalNumBooks = totalNumBooks + 1;
            totalCost = totalCost + book2;
            cout << "You purchesed 'Misery' for $12.95." << endl;
            //Prints out current number of books and current total.
            cout << "Current books purchased: " << totalNumBooks << ". Current total: " << totalCost << "." << endl;
            continue;
        }
        else if (userInput == "exit" || userInput == "Exit") {
            break;
        }
        else {
            cout << "Invalid input. Check spelling and try again." << endl;
        }

    }

    //Discount

    if (totalNumBooks > 4) {
        discount = totalCost * .10;
        totalCost = totalCost - discount;
        cout << "You got a 10% discount for your purchase of 5 or more books!" << endl;
    }

    //Final output

    cout << "You have bought a total of " << totalNumBooks << " books. You're total cost comes to: $" << totalCost << "." << endl;
    cout << "Thank you for shopping at your local book store!" << endl;

    return 0;


}

//Create a program where a person can purchase as many books as they want. X
//
//They will be presented with a menu of books to choose from. X
//
//Book 1 will cost $7.95 X
//
//Books 2 will cost $12.95 X
//
//
//
//* Keep a running total of the number of books purchased X
//
//* Keep a running total of the cost of the books purchased X
//
//* if more than 4 books were purchased, the customer should get 10 % off the total price. X
//
//Display the number of books, and the total price at the end X