/*
 * Author: Jasen Ratnam 40094237
 * Date: 09/18/2018
 * Assignment 1: Introduction to Programming with C++ 
 * Due: 09/28/2018
 * This program will covert the temperatures from 1 to 100 Celsius into Fahrenheit and display them.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Declare variables and initialize them.
    // One double variable to temporarily save the Fahrenheit equivalent of a Celsius degree.
    double fahrenheit;
    
    // Print title of both columns to start,
    // Formatted using setw(10) to set the width of each column to 10 and aligned to the left.
    cout << left << setw(10) << "Celsius" << setw(10) << "Fahrenheit\n";    
    
    // for loop that goes from 1 to 100.
    // Finds the equivalent Fahrenheit value of the current loop cycle value (Celsius value)
    // Print the Celsius value and the Fahrenheit equivalent in their column aligned to left with a width of 10.
    for(int i =1; i <= 100; i++)  
    {
        fahrenheit = ((i * (9.0/5.0)) + 32.0);      
        cout << left << setw(10) << i << setw(10) << fahrenheit << "\n"; 
    }
    
//    Un-formated version of code. (Hard-coded.)
//    cout << "Celsius  Fahrenheit\n";    // Write title bar
//    
//    double fahrenheit;
//    
//    for(int i =1; i <= 100; i++)  // Print data until 100
//    {
//        fahrenheit = ((i * (9.0/5.0)) + 32.0);          // Convert Celsius to Fahrenheit.
//        cout << i << "         " << fahrenheit << "\n"; // Print Celsius and Fahrenheit.
//    }
    return 0;
}
