//Zach Gilmore
//3-29-2021
//CSC 140
//Program: Caesar's Cypher


#include <iostream>
#include <string> 
#include <locale>
#include <cctype>
using namespace std;

//Signatures will go here
string encodeMsg(char msg[99]); //Set large index value for user input
string decodeMsg(char decode[99]);


int main()
{
    //Var for user input
    int userInput;
    char encryption[99];

    //Greetings and instructions
    cout << "Welcome to Caesar's Cypher.\nIn this program you will input a message you wish to encode or decode.\nSelect your option below." << endl;

    //Menu of options
    cout << "1.\tEncode" << endl;
    cout << "2.\tDecode" << endl;
    cout << "3.\tExit" << endl;

    //User input
    cout << "Option selected: ";
    cin >> userInput;

    //If statements and function calls
    if (userInput == 1) {
        //Encode fx
        cout << "Enter a message you wish to encode: ";     //Instructions
        cin.ignore();                   //Continues to input
        cin.getline(encryption, 99);    //Grabs all input
        encodeMsg(encryption);          //Pass argument
        cout << "\nYou're encoded message is above. Semper Invictus." << endl;   //Outro
    }
    else if (userInput == 2) {
        //Decode fx
        cout << "Enter the message you wish to decode: ";   //Instructions
        cin.ignore();                   //Continues to input
        /*tolower(encryption, 99);*/
        cin.getline(encryption, 99);    //Grabs all input
        decodeMsg(encryption);          //Pass argument
        cout << "\nYou're decoded message is above. Veritas Odit Moras." << endl;    //Outro
    }
    else if (userInput == 3) {  
        cout << "Verba volant, scripta manent." << endl;    //Exit message
    }
    else {  
        cout << "Invalid input.\nYou made Caesar mad.\nTo the gallows with you." << endl;   //Error message
    }

    return 0;
}
//Encode fx
string encodeMsg(char msg[99]) {
    //Iterate through the char array
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == '\0') {   //Condition to stop the array at null character
            break;
        }
        else if (msg[i] == ' ') {   //Keeps the whitespace from printing out any weird ASCII characters
            cout << ' ';
            continue;
        }
        msg[i] = ((msg[i] - 65) % 26) + 65;     //Encoding key
        cout << msg[i];                        //Print encoded message
    }
   
    return msg;
}
//Decode fx
string decodeMsg(char decode[99]) {
    for (int i = 0; i < 25; i++) {  //Take in full string, print 25 times
        for (int j = 0; j < strlen(decode); j++) {  //Check each character
            if (decode[j] == '\0') {   //Break when null character is reached 
                break;
            }
            else if (decode[j] == ' ') { //Making sure spaces are printed out if present
                cout << ' ';
                continue;
            }
            char c = ((decode[j] + i) % 26) + 65; //Shift char values  
            cout << c;
        }
        cout << endl;
    }

    return decode;
 }