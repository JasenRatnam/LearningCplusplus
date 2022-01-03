/*
 * Author: Jasen Ratnam 40094237
 * Date: 09/18/2018
 * Assignment 1: Introduction to Programming with C++ 
 * Due: 09/28/2018
 * This program will create a given shape using user given one-digit integer number
 */

#include <iostream>
using namespace std;

int main() 
{
    // Declare variables and initialize them.
    // One to save the user input once inputed.
    // One to save the number of rows in the shape (Defaulted to 10).
    // One boolean variable to know if the inputed data is in the correct format (One digit integer).
    int userInput = 0;    
    int NmbOfRow = 10; 
    bool correctInput = false;
    
    // Ask for one digit integer from user and save input.
    cout << "This program will create a shape with any given one-digit integer:\n"
            "Please enter a one digit Integer: (Decimals will be ignored.)\n";
    cin >> userInput;
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> userInput;     // Save input.
    }
    
    // While loop until boolean correctInput is true. (Input is a one digit integer)
    // If the input divided by 10 is greater or equal to 1.
    //      Then the input is not correct. ( boolean stays false.)
    //      check if decimal point can be used, use it if yes.
    //      Print error message if not an integer and get new input until an integer is inserted.
    //      Save correct input in place of wrong input.
    // If the input divided by 10 is smaller or equal to 1.
    //      Then the input is correct. ( boolean becomes true and loops ends)
    while(correctInput == false)
    {
        if(userInput / 10 >= 1)
        {
            correctInput = false;
            cout << "ERROR: The input has more then one digit, Please enter a single digit integer: (Decimal points will be first be checked if entered)\n";
            cin.clear();
            cin.ignore();
            cin >> userInput;
        }
        else
        {
            correctInput = true;
        }
    }
    
    // Add an empty line. 
    cout << "\n";   
    
    // Print first shape (upside down triangle):
    // Double for Loop to continue printing the userInput in the shape wanted. (Upside down triangle.
    // First for loop counts the number of rows printed:
    //      Prints a skip line after every loop cycle to get to the next row and removes 1 to NmbOfRow.
    //      Loops until NmbOfRow is reached.
    // Second for loop prints the user input for the numbers of columns wanted:
    //      Prints user input until the current row number is reached. Number also goes down every loop cycle.   
    for(int row = NmbOfRow; row >= 1; --row)    
    {
        for(int col = row; col >= 1; --col)    
        {
            cout << userInput;                 
        }
        
        cout << "\n";                  
    }
    
    // Add an empty line between the two shapes. 
    cout << "\n";                               
    
    // Print second shape (right side up triangle):
    // Same thing as first shape 
    //      but loop stars at 1 and ends at NmbOfRow by adding one after every loop cycle.
    for(int row = 1; row <= NmbOfRow; ++row)   
    {
        for(int col = 1; col <= row; ++col)     
        {
            cout << userInput;                 
        }
        
        cout << "\n";                           
    }
    
    return 0;
}