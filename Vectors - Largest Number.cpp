//Zach Gilmore
//March 22, 2021
//CSC-140
//Program: Largest Number

#include <iostream>
#include <vector>
using namespace std;

//function signature
int printLargestNum(vector<int> number);

//Global const
const int INDEX = 5;

int main()
{
    
    vector<int> numberThing(INDEX); //initialize index with 5


    //Welcome message and instructions
    cout << "Greetings user! In this program you will input 5 numbers and the computer will output the largest one." << endl;
    cout << "Please input your numbers: " << endl;

    printLargestNum(numberThing);   //function call

    //Outro
    cout << "Thank you for using this program.";


    return 0;
}

int printLargestNum(vector<int> number) {
    int largestNum = -99999;    //Initialize with lowest number possible
    
    //user input loop
    for (int i = 0; i < number.size(); ++i) {
        cin >> number.at(i);
    }


    for (int i = 0; i < number.size(); ++i) {
        /*cout << number.at(i) << ", ";*/ //this was just to make sure its running correctly
        if (number.at(i) > largestNum) {    //Check if user number is larger than var
            largestNum = number.at(i);      //if yes, assign to var
        }
    }
    cout << "You're largest number entered was: " << largestNum << "." << endl; //Display largest number
    return largestNum;
}

