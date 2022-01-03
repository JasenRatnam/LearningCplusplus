/*
 * Author: Jasen Ratnam 40094237
 * Date: 09/18/2018
 * Assignment 1: Introduction to Programming with C++ 
 * Due: 09/28/2018
 * This program will give the letter grade of the final grade of a student in percentage.
 * Uses this marking scheme:
 * A+ grade >= 90
 * A  80 <= grade < 90
 * B  70 <= grade < 80
 * C  60 <= grade < 70
 * F  grade < 60
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare variables and initialize them.
    // One double variable to save the grade of the student in percentage.
    // One String variable to save the grade of the student in letter system.
    // One boolean variable to know if the inputed data is in the correct interval (1 to 100).
    double gradePercent;
    string gradeLetter;
    bool correctInput = false;
    
    // Ask for integer from user. To be used for calculation:
    cout << "This program will give the letter grade of a student from a grade in percentage:\n"
            "Please enter the student's final grade in percentage. \n";
    cin >> gradePercent;  // Save Input

    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number between 0 and 100: \n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> gradePercent;  // Save input.
    }
    
    // While loop until boolean correctInput is true. (Input is between 1 and 100)
    // If the input is greater then 100 or smaller than 0.
    //      Then the input is not correct. ( boolean stays false.)
    //      Print error message if not in interval get new input until in interval is inserted.
    //      Save correct input in place of wrong input.
    // Else
    //      Then the input is correct. ( boolean becomes true and loops ends)
    while(correctInput == false)
    {
        if(gradePercent > 100 || gradePercent < 0)
        {
            correctInput = false;
            cout << "ERROR: The input is out of the interval, Please enter a number between 0 to 100:\n";
            cin.clear();
            cin.ignore();
            cin >> gradePercent;
        }
        else
        {
            correctInput = true;
        }
    }
    
    // Bunch of if-else statements to get the corresponding letter grade of a given percentage grade.
    // If greater or equal than 90 = A+
    // If else greater or equal then 80 and smaller than 90 = A
    // If else greater or equal then 70 and smaller than 80 = B
    // If else greater or equal then 60 and smaller than 70 = C
    // Else smaller than 60 = F
    if(gradePercent >= 90.0)
    {
        gradeLetter = "A+";
    }
    else if(80.0 <= gradePercent && gradePercent < 90.0)
    {
        gradeLetter = "A";
    }
    else if(70.0 <= gradePercent && gradePercent < 80.0)
    {
        gradeLetter = "B";
    }
    else if(60.0 <= gradePercent && gradePercent < 70.0)
    {
        gradeLetter = "C";
    }
    else
    {
        gradeLetter = "F";
    }
   
    // Print final grade of student in letter.
    cout << "The student has a final grade of: " << gradeLetter;
    
    return 0;
}

