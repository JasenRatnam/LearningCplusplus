/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.2: Cars which represents cars of a car rental company.
 * Prompts the user to enter information about two cars.
 * Create two objects of the class car with given information.
 * Test all the member functions of the class.
 * Contains main function.
 */

#include <iostream>
#include <cmath>
#include "car.h"

using namespace std;

/*
 * Function that gets information about a car from user.
 * And creates an car object from the car class constructor.
 * returns car object.
 */
car getCar()
{
    // Initialize variables needed to create car object.
    int id;
    string brand;
    string type;
    
    // Ask and save the information about the car.
    cout << "Enter information about car:\n"
            "1. Enter car id number: ";
    cin >>  id;
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> id;     // Save input.
    }
    
    cout << "2. Enter car brand: ";
    cin >>  brand;
    
    cout << "3. Enter car type: ";
    cin >>  type;
   
    // Create car object
    car car(id, brand, type);
    
    // Return car
    return car;
}

/*
 * Function that does the menu and choices fro commands.
 * Goes in a loop until user chooses to quit.
 */
void menuAction()
{
    // Create 2 car object.
    car car1 = getCar();
    car car2 = getCar();
   
    //boolean: user can choose options until it is false.
    bool playing = true;
    
    // Variable to save the choice chosen.
    int choice;
    
    // Give choices
    cout << "\nChoose one of the following options: (To test functions of class)\n"
            "1. Get the first car id number.\n"
            "2. Get the second car id number.\n"
            "3. Get the first car brand.\n"
            "4. Get the second car brand.\n"
            "5. Get the first car type.\n"
            "6. Get the second car type.\n"
            "7. Exit.\n\n";

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
    
    // Loop with the current number.
    while(playing)
    {
        switch(choice)
        {
            case 1:
                {   
                    cout << "The id number of car 1 is: " << car1.getId();
                    break;
                }
            case 2:
                {
                    cout << "The id number of car 2 is: " << car2.getId();
                    break;
                }
            case 3:
                {
                    cout << "The brand of car 1 is: " << car1.getBrand();
                    break;
                }      
            case 4:
                {
                    cout << "The brand of car 2 is: " << car2.getBrand();
                    break;
                }
            case 5:
                {
                    cout << "The type of car 1 is: " << car1.getType();
                    break;
                }
            case 6:
                {
                    cout << "The type of car 2 is: " << car2.getType();
                    break;
                }
            case 7:
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
    // ask for course info and choices.
    menuAction();
    
    return 0;
}


