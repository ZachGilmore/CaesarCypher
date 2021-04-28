//Zach Gilmore
//March 22, 2021
//CSC-140
//Program: Guess My Number

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

//Function Signatures
bool duplicateCheck(vector<int>passedVal, int i);

int main()
{
    const int GUESSES = 10;
    vector<int>userNums(GUESSES);
    //vector<int>guessAttempts;
    srand(time(0));     //seed generator
    int random_number = (rand() % 100) + 1; //Switch back to 100 before submission
                                          //If I forget to switch, the 5 is for debugging purposes
    //cout << random_number;

    //Welcome message and instructions
    cout << "Welcome to 'Guess My Number!'" << endl;
    cout << "In this game, you will have 10 guess to guess the correct number between 1 and 100." << endl;
    cout << "If you guess correctly within 10 guesses, you win!" << endl;
    cout << "If you cannot guess within 10 guesses, you will lose the game." << endl;
    
    //Start of game
    cout << "Guess a number between 1 and 100." << endl;
    
    for (int i = 0; i < userNums.size(); ++i) { //initialize for loop with number of guesses
        bool isDup = true;  //Boolean conditional
        while (isDup) {
            cin >> userNums.at(i);
            isDup = duplicateCheck(userNums, i);    //Check if value has already been input
        }
        if (userNums.at(i) == random_number) {  //If value input matches randomly generated number
            int amount = i;
            cout << "Yippee! You win!" << endl;
            cout << "You guessed it in " << i + 1 << " guesses!" << endl;
            break;
        }
        if (i == GUESSES - 1) { //-1 matches const to index range; if condition met player loses
            cout << "Bummer. You lose :(" << endl;
        }
        else if (userNums.at(i) != random_number) { //if input does not match, you get another go
            cout << "Your number did not match. Guess again." << endl;
        }
    }

    return 0;
}

//Checks for duplicate input
bool duplicateCheck(vector<int>passedVal, int i) {
    for (int j = 0; j < i; ++j) {
        if (passedVal.at(i) == passedVal.at(j)) {   //Compare new input with input already in vector
            cout << "Duplicate value detected. Please reenter a number." << endl; //If duplicate input is detected...
            return true;    //return true, go back through while loop in main method and do not append to vector
        }
    }
    return false;   //else return false and move append value to vector
}
