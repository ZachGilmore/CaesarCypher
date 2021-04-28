#include <iostream>
#include <fstream>
using namespace std;


//fx signatures go here
void enterGrades(string name, int grade[], int arrySize);
void viewGrades(string name, int grade[], int arrySize);
void gradeAvg(string name, int grade[], int arrySize);

int main()
{
    int menuOption;
    string stdName;
    int stdGrade[5];

    //Greetings and prompt
    cout << "\nWelcome to your gradebook.\nWhat you would like to do today?\n(Press any key to exit)\n";
    cout << endl;
    //Menu
    cout << "1.\tEnter Grades" << endl;
    cout << "2.\tView Grades" << endl;
    cout << "3.\tView Final Grades" << endl;
    cout << "\nSelected option: ";
    cin >> menuOption;

    if (menuOption == 1) {
        //enter grades fx call
        enterGrades(stdName, stdGrade, 5);
    }
    else if (menuOption == 2) {
        //view grades fx call
        viewGrades(stdName, stdGrade, 5);
    }
    else if (menuOption == 3) {
        //view final grades fx call
        gradeAvg(stdName, stdGrade, 5);
    }
    else {
        cout << "\nThank you for using gradebook. Goodbye!" << endl;
    }

    return 0;

}

//enter grades fx
void enterGrades(string name, int grade[], int arrySize)        //Input student name and grades here
{
    ofstream fileOut; //out of file stream
    char select;

    //Instructions
    cout << "\nYou can record grades here.\nEnter a students last name, and 5 of their grades" << endl;
    cout << "\nWould you like to enter grades today? (Y/N)" << endl;

    //User Input
    cin >> select;
   
    while (select == 'y' || select == 'Y') {
        fileOut.open("studentFile.txt", ios::app);              //creating and appending data file
        cout << "\nPlease enter the last name of your student: ";
        cin >> name;
        cout << "\nEnter the last 5 grades for this student: \n";

        for (int i = 0; i < arrySize; i++) {                    //Loop through array to input grades
            cin >> grade[i];
        }

        fileOut << name << " ";                               //Input name and grades into file
        for (int i = 0; i < arrySize; i++) {                  //Loop through array to input grades
            fileOut << grade[i] << " ";
        }
        fileOut << endl;

        fileOut.close();

        cout << name << "\n ";                                //Output name and grades in file
        for (int i = 0; i < arrySize; i++) {
            cout << grade[i] << " ";
        }
        cout << endl;

        cout << "Would you like to enter another student today?" << endl;
        cin >> select;
        if (select == 'n' || select == 'N') {
            break;
        }

    }

    main();

}

//view grades fx
void viewGrades(string name, int grade[], int arrySize)         //View student roster here
{
    ifstream fileIn;
    
    cout << "\nStudent Roster:\n";

    fileIn.open("studentFile.txt");     //Open the text file
    
    fileIn >> name;                     
    for (int i = 0; i < arrySize; i++) {    //Get data from the text file
        fileIn >> grade[i];
    }

    while (!fileIn.eof()) {                    //While there is data in the file
        cout << name << " ";                  // output what the above code went in and grabbed
        for (int i = 0; i < arrySize; i++) {
            cout << grade[i] << " ";
        }
        cout << endl;

        fileIn >> name;                  //and go back in for more.
        for (int i = 0; i < arrySize; i++) {    //Grab the next students grades
            fileIn >> grade[i];
        }
    }                                 //Until eof is reached.

    main();

}

//view final grades fx
void gradeAvg(string name, int grade[], int arrySize)            //Average of grades calculated and displayed here
{
    ifstream fileIn;
    int avgInt = 0;

    fileIn.open("studentFile.txt");                     //So far this is doing the same as the viewGrades function

    fileIn >> name;
    for (int i = 0; i < arrySize; i++) {
        fileIn >> grade[i];
    }

    while (!fileIn.eof()) {                             //While there is data in the file
        //cout << name << " ";
        for (int i = 0; i < arrySize; i++) {            //Loop throught the grade
            if (i == 4) {                               //if the index is 4
                avgInt = (grade[0] + grade[1] + grade[2] + grade[3] + grade[4]) / 5;        //Average out the grade and store it into the the variable
            }
            //cout << i << " ";
            //cout << grade[i] << " ";
        }
        cout << endl;
        cout << name << "'s average grade is: " << avgInt << endl;          //Display name of student and their average

        fileIn >> name;                                                     //Go back in for more
        for (int i = 0; i < arrySize; i++) {
            fileIn >> grade[i];                                             //Grab the next students grades
        }
    }

    main();

}
