/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/20/2018
 * Due: 11/25/2018
 * Assignment 5: User-Defined Classes/ Pointers
 * 5.1: Date class that creates a date with day, month and year
 * Define date object by the attributes:
 * day (int),
 * month (int),
 * year (int),
 * Contains the implementation of the member functions of the class.
 */
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;
/*
 * Test the new functions of the class Date by creating dynamically (i.e., using pointers) two objects of
 * the class Date and invoking the new member functions on both objects.
 */

Date getDate()
{
    
    // Initialize variables needed to create date object.
    int day;
    int month;
    int year;
    
    cout << "Enter information about the date: \n"
            "1. Enter the day: ";
    cin >>  day;

    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> day;            // Save input.
    }
    
    cout << "2. Enter the month: ";
    cin >>  month;

    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> month;            // Save input.
    }
    
    cout << "3. Enter the year: ";
    cin >>  year;

    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> year;            // Save input.
    }
    
    Date date(day,month,year);
    return date;
}

int main()
{
    Date *date1Ptr;
    
    date1Ptr = new Date;
    
    *date1Ptr = getDate();
    
    Date *date2Ptr;
    
    date2Ptr = new Date;
    
    *date2Ptr = getDate();
    
    cout << "The month of the first date in letter is " << (*date1Ptr).getMonth() << "\n";
    (*date1Ptr).newYear();
    
    cout << "The month of the second date in letter is " << (*date2Ptr).getMonth() << "\n";
    (*date2Ptr).newYear();
    
    if((*date1Ptr).compareDate(*date2Ptr) == true)
    {
        cout << "Both the dates are the same.";
    }
    
    else if((*date1Ptr).compareDate(*date2Ptr) == false)
    {
        cout << "Both the dates are not the same.";
    }
    
    return 0;
}

