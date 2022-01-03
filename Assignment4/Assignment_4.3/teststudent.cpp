/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.3: class that represent the students of a university.
 */

#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

/*
 * Function that gets information about a student from user.
 * And creates an student object from the student class constructor.
 * returns student object.
 */
student getStudent()
{
    // Initialize variables needed to create student object.
    int id;
    string firstName;
    string lastName;
    string dateOfBirth;
    string address;
    int areaCode;
    string phoneNumber;
    int birthYear;
    
    // Ask and save the information about the student.
    cout << "Enter information about student:\n"
            "1. Enter student id number: ";
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
        cin >> id;            // Save input.
    }
    
    cout << "2. Enter student first name: ";
    cin >>  firstName;
    
    cout << "3. Enter student last name: ";
    cin >>  lastName;
    
    cout << "4. Enter student date of birth: ";
    cin >>  dateOfBirth;
    
    cout << "5. Enter student birth year: ";
    cin >>  birthYear;
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> birthYear;     // Save input.
    }
    
    cout << "6. Enter student address: ";
    cin >>  address;
    
    cout << "7. Enter student telephone area code: ";
    cin >>  areaCode;
    
    // Check if input is not an integer.
    // Print error message if not an integer and get new input until an integer is inserted.
    // Save correct input in place of wrong input.
    // While loop until an integer is inserted.
    while(!cin)
    {
        cout << "ERROR: The input was not a number, Please enter a number:\n";
        cin.clear();          // Clear the input.
        cin.ignore();         // Ignore the current input and wait for new input.
        cin >> areaCode;     // Save input.
    }
    
    cout << "7. Enter student telephone 7-digit number: ";
    cin >>  phoneNumber;
    
    // Create student object
    student student(id, firstName, lastName, dateOfBirth, 
                    address, areaCode, phoneNumber,birthYear);
    
    // Return student
    return student;
}

/*
 * Function that does the menu and choices fro commands.
 * Goes in a loop until user chooses to quit.
 */
void menuAction()
{
    // Create 2 student object
    student student1 = getStudent();
    student student2 = getStudent();
   
   //boolean: user can choose options until it is false.
    bool playing = true;
    
    // Variable to save the choice chosen.
    int choice;
    
    // Give choices
    cout << "\nChoose one of the following options: (To test functions of class)\n"
            "1. Get the first student id number.\n"
            "2. Get the second student id number.\n"
            "3. Get the first student first name.\n"
            "4. Get the second student first name.\n"
            "5. Modify the first student first name.\n"
            "6. Modify the second student first name.\n"
            "7. Get the first student last name.\n"
            "8. Get the second student last name.\n"
            "9. Modify the first student last name.\n"
            "10. Modify the second student last name.\n"
            "11. Get the first student full name.\n"
            "12. Get the second student full name.\n"
            "13. Get the first student date of birth.\n"
            "14. Get the second student date of birth.\n"
            "15. Modify the first student date of birth.\n"
            "16. Modify the second student date of birth.\n"
            "17. Get the first student age.\n"
            "18. Get the second student age.\n"
            "19. Get the first student address.\n"
            "20. Get the second student address.\n"
            "21. Modify the first student address.\n"
            "22. Modify the second student address.\n"
            "23. Get the first telephone number.\n"
            "24. Get the second telephone number.\n"
            "25. Modify the first telephone number.\n"
            "26. Modify the second telephone number.\n"
            "27. Do both students have the same last name?\n"
            "28. Are both students roommates?\n"
            "29. Exit.\n\n";

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
                    cout << "The id number of student 1 is: " << student1.getId();
                    break;
                }
            case 2:
                {
                    cout << "The id number of student 2 is: " << student2.getId();
                    break;
                }
            case 3:
                {
                    cout << "The first name of student 1 is: " << student1.getFName();
                    break;
                }      
            case 4:
                {   cout << "The first name of student 2 is: " << student2.getFName();
                    break;
                }
            case 5:
                {
                    string fName;
                    cout << "Enter the new first name for student 1: \n";
                    cin >> fName;
                    student1.setFName(fName);
                    cout << "New first name for the first student: " << student1.getFName();
                    break;
                }
            case 6:
                {
                    string fName;
                    cout << "Enter the new first name for student 2: \n";
                    cin >> fName;
                    student2.setFName(fName);
                    cout << "New first name for the second student: " << student2.getFName();
                    break;
                }
            case 7:
                {
                    cout << "The last name of student 1 is: " << student1.getLName();
                    break;
                }
            case 8:
                {   
                    cout << "The last name of student 2 is: " << student2.getLName();
                    break;
                }
            case 9:
                {
                    string lName;
                    cout << "Enter the new last name for student 1: \n";
                    cin >> lName;
                    student1.setLName(lName);
                    cout << "New last name for the first student: " << student1.getLName();
                    break;
                }
            case 10:
                {
                    string lName;
                    cout << "Enter the new last name for student 2: \n";
                    cin >> lName;
                    student2.setLName(lName);
                    cout << "New last name for the second student: " << student2.getLName();
                    break;
                }      
            case 11:
                {
                    cout << "The full name of student 1 is: " << student1.getFullName();
                    break;
                }
            case 12:
                {
                    cout << "The full name of student 2 is: " << student2.getFullName();
                    break;
                }
            case 13:
                {
                    cout << "The date of birth of student 1 is: " << student1.getDateBirth();
                    break;
                }
            case 14:
                {
                    cout << "The date of birth of student 2 is: " << student2.getDateBirth();
                    break;
                }
            case 15:
                {   
                    string dateBirth;
                    cout << "Enter the new date of birth for student 1: \n";
                    cin >> dateBirth;
                    student1.setDateBirth(dateBirth);
                    cout << "New date of birth for the first student: " << student1.getDateBirth();
                    break;
                }
            case 16:
                {
                    
                    string dateBirth;
                    cout << "Enter the new date of birth for student 2: \n";
                    cin >> dateBirth;
                    student2.setDateBirth(dateBirth);
                    cout << "New date of birth for the second student: " << student2.getDateBirth();
                    break;
                }
            case 17:
                {
                    cout << "The age of student 1 is: " << student1.getAge();
                    break;
                }      
            case 18:
                {
                    cout << "The age of student 2 is: " << student2.getAge();
                    break;
                }
            case 19:
                {
                    cout << "The address of student 1 is: " << student1.getAddress();
                    break;
                }
            case 20:
                {
                    cout << "The address of student 2 is: " << student2.getAddress();
                    break;
                }
            case 21:
                {
                    string address;
                    cout << "Enter the address for student 1: \n";
                    cin >> address;
                    student1.setAddress(address);
                    cout << "New address for the first student: " << student1.getAddress();
                    break;
                }
            case 22:
                {   
                    string address;
                    cout << "Enter the address for student 2: \n";
                    cin >> address;
                    student2.setAddress(address);
                    cout << "New address for the second student: " << student2.getAddress();
                    break;
                }
            case 23:
                {
                    cout << "The telephone number of student 1 is: (" << student1.getAreaCode() << ") " << student1.getPhoneNumber();
                    break;
                }
            case 24:
                {
                     cout << "The telephone number of student 2 is: (" << student2.getAreaCode() << ") " << student2.getPhoneNumber();
                    break;
                }      
            case 25:
                {
                    string phoneNumber;
                    cout << "Enter the new 7-digit telephone number for student 1: \n";
                    cin >> phoneNumber;
                    student1.setPhoneNumber(phoneNumber);
                    cout << "New telephone number of student 1 is: (" << student1.getAreaCode() << ") " << student1.getPhoneNumber();
                    break;
                }
            case 26:
                {
                    string phoneNumber;
                    cout << "Enter the new 7-digit telephone number for student 2: \n";
                    cin >> phoneNumber;
                    student2.setPhoneNumber(phoneNumber);
                    cout << "New telephone number of student 2 is: (" << student2.getAreaCode() << ") " << student2.getPhoneNumber();
                    break;
                }
            case 27:
                {
                    bool sameLN = student1.sameLName(student2);
                    
                    if(sameLN == true)
                    {
                        cout << "The two students have the same last name."; 
                    }
                    
                    else
                    {
                        cout << "The two students do not have the same last name."; 
                    }
                    break;
                }
            case 28:
                {
                    bool sameAdd = student1.sameLName(student2);
                    
                    if(sameAdd == true)
                    {
                        cout << "The two students are roommates."; 
                    }
                    
                    else
                    {
                        cout << "The two students are not roommates."; 
                    }
                    break;
                }
            case 29:
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
    
        // Ask for new input.
        if(playing) 
        {
            cout << "\n\nPlease choose another option from the menu: ";

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