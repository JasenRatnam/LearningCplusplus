/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.1: Flights of an airline company.
 * Driver that contains the main function to test the class flight.
 * Prompt user to enter information about two flights.
 * Creates two objects of th e class flight with given information.
 * Test all member functions of the class.
 */

#include <iostream>
#include <cmath>
#include "flight.h"

using namespace std;

/*
 * Function that gets information about a flight from user.
 * And creates an flight object from the flight class constructor.
 * returns flight object.
 */
flight getFlight()
{
    // Initialize variables needed to create flight object.
    int number;
    string depTime;
    string depDate;
    string depCity;
    string desCity;
    
    // Ask and save the information about the flight.
    cout << "Enter information about flight:\n"
            "1. Enter flight number: (An integer number)";
    cin >>  number;
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> number;     // Save input.
    }
    
    cout << "2. Enter flight departure time: ";
    cin >>  depTime;
    
    cout << "3. Enter flight departure date: ";
    cin >>  depDate;
    
    cout << "4. Enter flight departure city: ";
    cin >>  depCity;
 
    cout << "5. Enter flight destination city: ";
    cin >>  desCity;
    
    // Create flight object
    flight flight(number, depTime, depDate, depCity, desCity);
    
    // Return flight
    return flight;
}

/*
 * Function that does the menu and choices fro commands.
 * Goes in a loop until user chooses to quit.
 */
void menuAction()
{
    // Create 2 flight object
    flight flight1 = getFlight();
    flight flight2 = getFlight();
    
    
    //boolean: user can choose options until it is false.
    bool playing = true;
    
    // Variable to save the choice chosen.
    int choice;
    
    // String to save new time.
    string time;
    
    // String to save new date.
    string date;
    
    // Give choices
    cout << "\nChoose one of the following options: (To test functions of class)\n"
            "1. Get the first flight number.\n"
            "2. Get the second flight number.\n"
            "3. Get the first flight departure time.\n"
            "4. Get the second flight departure time.\n"
            "5. Get the first flight departure date.\n"
            "6. Get the second flight departure date.\n"
            "7. Get the first flight departure city.\n"
            "8. Get the second flight departure city.\n"
            "9. Get the first flight destination city\n"
            "10. Get the second flight destination city.\n"
            "11. Modify the first flight departure time.\n"
            "12. Modify the second flight departure time.\n"
            "13. Modify the first flight departure date.\n"
            "14. Modify the second flight departure date.\n"
            "15. Exit.\n\n";

    // Save choice.
    cin >> choice;
    cout << "\n";
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> choice;     // Save input.
    }
    
    // Loop with the current choice.
    while(playing)
    {
        switch(choice)
        {
            case 1:
                {   
                    cout << "The number of flight 1 is: " << flight1.getNumber();
                    break;
                }
            case 2:
                {
                    cout << "The number of flight 2 is: " << flight2.getNumber();
                    break;
                }
            case 3:
                {
                    cout << "The departure time of flight 1 is: " << flight1.getDepartureTime();
                    break;
                }      
            case 4:
                {
                    cout << "The departure time of flight 2 is: " << flight2.getDepartureTime();
                    break;
                }
            case 5:
                {
                    cout << "The departure date of flight 1 is: " << flight1.getDepartureDate();
                    break;
                }
            case 6:
                {
                    cout << "The departure date of flight 2 is: " << flight2.getDepartureDate();
                    break;
                }
            case 7:
                {
                    cout << "The departure city of flight 1 is: " << flight1.getDepartureCity();
                    break;
                }
            case 8:
                {
                    cout << "The departure city of flight 2 is: " << flight2.getDepartureCity();
                    break;
                }
            case 9:
                {
                    cout << "The destination city of flight 1 is: " << flight1.getDestinationCity();
                    break;
                }
            case 10:
                {
                    cout << "The destination city of flight 2 is: " << flight2.getDestinationCity();
                    break;
                }
            case 11:
                {
                    cout << "Enter the new departure time: \n";
                    cin >> time;
                    flight1.setDepartureTime(time);
                    cout << "New departure time for the first flight: " << flight1.getDepartureTime();
                    break;
                }
            case 12:
                {
                    cout << "Enter the new departure time: \n";
                    cin >> time;
                    flight2.setDepartureTime(time);
                    cout << "New departure time for the second flight: " << flight2.getDepartureTime();
                    break;
                }
            case 13:
                {
                    cout << "Enter the new departure date: \n";
                    cin >> date;
                    flight1.setDepartureDate(date);
                    cout << "New departure date for the first flight: " << flight2.getDepartureDate();
                    break;
                }
            case 14:
                {      
                    cout << "Enter the new departure date: \n";
                    cin >> date;
                    flight2.setDepartureDate(date);
                    cout << "New departure date for the second flight: " << flight2.getDepartureDate();
                    break;
                }
            case 15:
                {
                    // Quit program:
                    playing = false;
                    break;
                }
            default: // else input is wrong, ask for new input.
                {
                    cout << "Invalid input. Please enter a correct choice\n";
                }
        }
    
        // Ask for new input. if boolean is true
        if(playing) 
        {
            cout << "\n\nPlease choose another option from the menu: ";
            
            // Save input
            cin >> choice;
            cout << "\n";
            
             // Check if input is not an integer.
            // Print error message if not an integer and get new input until an integer is inserted.
            // Save correct input in place of wrong input.
            // While loop until an integer is inserted.
            while(!cin)
            {
                cout << "ERROR: The input was not a number, Please enter a number:\n";
                cin.clear();          // Clear the input.
                cin.ignore();         // Ignore the current input and wait for new input.
                cin >> choice;     // Save input.
            }
        }
    }
}

int main() 
{
    // ask for flight info and choices.
    menuAction();
    
    return 0;
}

