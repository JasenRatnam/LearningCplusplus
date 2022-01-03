/*
 * Author: Jasen Ratnam 40094237
 * Date: 09/18/2018
 * Assignment 1: Introduction to Programming with C++ 
 * Due: 09/28/2018
 * This program will print the square, square root, the factorial of a 
 *  user inputed integer value, it will also show if it is a prime number or not.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() 
{
    // Declare variables and initialize them.
    // One to store user input.
    // One to store the square of the users input.
    // One to store the square root of the user input.
    // One to store the factorial of the user input.
    // One to know if input is prime.
    // And one line string to be used to separate different steps
    int userInput;        
    int square;           
    double square_root;   
    int factorial = 1;       
    string prime = "Yes"; 
    
    string line = "*****************************************"; 
    
    // Print line and go to the next line.
    cout << line << "\n";
    
    // Ask for integer from user, (To be used for calculation) and save input:
    cout << "This program will give the square, square root and the factorial of any given integer value, it will also show if its is prime:\n"
            "Please enter a Integer number: \n";
    cin >> userInput;  
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a integer, Please enter an integer: \n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> userInput;     // Save input.
    }
    
// Doesn't work. Not going into the loop.
//    while(cin.fail())
//    {
//        cout << "ERROR: Please only enter a integer.\n";
//        cin.clear();
//        cin.exceptions();  // Should find exceptions?
//        cin >> userInput;
//    }
//    
    // Do calculations:
    // Uses the pow function to find the square of the user input.
    // Uses the sqrt function to find the square-root.
    square = pow(userInput, 2);     
    square_root = sqrt(userInput);  // pow(userInput, 0.5); 

    // Factorial calculations:
    // For loop that multiplies factorial variable from 1 to user input.
    // Multiply the previous number to the next number until the user input.
    for(int i=1; i <= userInput; i++)
    {
            factorial = factorial*i;    
    }

    // Prime calculations:   
    // For loop that verifies if the user input can be perfectly divided by any number from 2 to input-1:
    //      If it can then it is not prime. (Breaks loop)
    //      If it can't then it is prime.
    for(int i = 2; i < userInput; i++)
    {
            if(userInput % i == 0)   
            {
                prime = "No";
                break;              
            }
    }
    
    // Print the results to the user: (Formated version)
    // setw(15): sets the width of both columns to 15.
    // left: aligns everything to the left side of the columns.
    // Starts and ends with a line.
    cout << "\n" << line << "\n";                    
    cout << "The results are:\n\n";
    cout << left
         << setw(15) << "Square:" 
         << setw(15) << square << "\n"
         << setw(15) << "Square root:" 
         << setw(15) << square_root << "\n"
         << setw(15) << "Factorial:" 
         << setw(15) << factorial << "\n"
         << setw(15) << "Prime:" 
         << setw(15) << prime << "\n"
         << line;  //Ending line.
    
// Hard coded formating:
//    cout << "\n" << line << "\n";                    
//    cout << "The results are:\n\n";
//    cout << "Square:      " << square << "\n";
//    cout << "Square root: " << square_root << "\n";
//    cout << "Factorial:   " << factorial << "\n";
//    cout << "Prime:       " << prime << "\n";
//    cout << line;  //Ending line.
   
    return 0;
}
