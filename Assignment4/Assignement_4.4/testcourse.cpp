
/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.4: create a class course, represents the course offered with students enrolled.
 * testCourse: this contains the main function to test the class course.
 * Prompts user to enter information about one course and four students, tests all
 * function of class course. 
 */

#include <iostream>
#include <iomanip>
#include "course.h"
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
    
    // Ask and save the information about the student.
    cout << "Enter information about student: \n"
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

    cout << "5. Enter student address: ";
    cin >>  address;

    cout << "6. Enter student telephone area code: ";
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
        cin >> areaCode;            // Save input.
    }
    
    cout << "7. Enter student telephone 7-digit number: ";
    cin >>  phoneNumber;

    // Create student object
    student student1(id, firstName, lastName, dateOfBirth,address, areaCode, phoneNumber);

    // Return student
    return student1;
}

/*
 * Function that gets information about a course from user.
 * And creates an course object from the course class constructor.
 * returns course object.
 */
course getCourse()
{
    // Initialize variables needed to create student object.
    string code;
    string name;
    string description;
    vector <student> listStudents;
    
    // Ask & save information about course
    cout << "Enter information about course:\n"
            "1. Enter course code: ";
    cin >>  code;

    cout << "2. Enter course name: ";
    cin >>  name;

    cout << "3. Enter course description: ";
    cin >>  description;
    
    // Get four students registered in the course.
    for(int i = 1; i <=4; i++) // Loop 4 times
    {
        student studenti = getStudent();  // create new student
        listStudents.push_back(studenti); // save student in vector.
    }
    
    // Create course object.
    course course1(code, name, description, listStudents);
    
    // return course
    return course1;
}

/*
 * Function that does the menu and choices for commands.
 * Goes in a loop until user chooses to quit.
 */
void menuAction()
{
    // Create a course
    course course1 = getCourse();
   
    //boolean: user can choose options until it is false.
    bool playing = true;
    
    // Variable to save the choice chosen.
    int choice;
    
    // Give choices
    cout << "\nChoose one of the following options: (To test functions of class)\n"
            "1. Get the course code.\n"
            "2. Get the course name.\n"
            "3. Modify the course name.\n"
            "4. Get the course description.\n"
            "5. Modify the course description.\n"
            "6. Add a student to the course.\n"
            "7. Remove a student from the course.\n"
            "8. Search if a student with a certain id number is registered in the course.\n"
            "9. Get the list of students.\n"
            "10. Get the number of registered students.\n"
            "11. Exit.\n\n";

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
        cin >> choice;            // Save input.
    }
    
    // Loop with the current number.
    while(playing)
    {
        cout << "\n";
        switch(choice)
        {
            case 1: // if choice = 1: give course code.
                {   
                    cout << "The course code is: " << course1.getCode();
                    break;
                }
            case 2: // if choice = 2: give course name.
                {
                    cout << "The course name is: " << course1.getName();
                    break;
                }
            case 3: // if choice = 3: modify course name.
                {
                    string name;
                    cout << "Enter the new course name: \n";
                    cin >> name;
                    course1.setName(name);
                    cout << "New course name: " << course1.getName();
                    break;
                }      
            case 4: // if choice = 4: give course description.
                {   cout << "The course description is: " << course1.getDescription();
                    break;
                }
            case 5: // if choice = 5: modify course description.
                {
                    string description;
                    cout << "Enter the new description for the course: \n";
                    cin >> description;
                    course1.setDescription(description);
                    cout << "New description for the course: " << course1.getDescription();
                    break;
                }
            case 6:  // if choice = 6: add student to course.
                {
                    student newStudent = getStudent();
                    course1.addStudent(newStudent);
                    cout << "Student added.";
                    break;
                }
            case 7:  // if choice = 7: remove student from course.
                {
                    bool found = false;
                    student removeStudent = getStudent();
                    found = course1.searchStudent(removeStudent.getId());
                    if(found == true)
                    {
                        course1.removeStudent(removeStudent);
                        cout << "Student removed.";
                        break;
                    }
                    else
                    {
                        cout << "Student is not registered in the course.";
                        break;
                    }
                }
            case 8:  // if choice = 8: find student from id number.
                {   
                    int id;
                    bool found = false;
                    cout << "Please enter the id number of the student: \n";
                    cin >> id;
                    
                    found = course1.searchStudent(id);
                    
                    if(found == true)
                    {
                        cout << "The student is registered in this class";
                    }
                    else if (found == false)
                    {
                        cout << "The student is not registered in this course.";
                    }
                    else
                    {
                        cout << "An error happened.";
                    }
                    break;
                }
            case 9:  // if choice = 9: Print list of students id number.
                {
                    vector <student> listStudents = course1.getStudentList();
                    
                    cout << "The students id numbers are:\n";
                    
                    for(int i = 0; i < listStudents.size(); i++)
                    {
                        cout << listStudents[i].getId() << "\n";
                    }
                    
                    break;
                }
            case 10:  // if choice = 10: Print number of students.
                {
                    int studentsNumb = course1.getNumbStudents();
                    cout << "The total number of registered students is: " << studentsNumb;
                    break;
                }      
            case 11: // if choice = 11: exit loop.
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
            // SAve input
            cin >> choice;
            
            // Check if input is not an integer.
            // Print error message if not an integer and get new input until an integer is inserted.
            // Save correct input in place of wrong input.
            // While loop until an integer is inserted.
            while(!cin)
            {
                cout << "ERROR: The input was not a number, Please enter a number:\n";
                cin.clear();          // Clear the input.
                cin.ignore();         // Ignore the current input and wait for new input.
                cin >> choice;            // Save input.
            }
            
            cout << "\n";
        }
    }
}

int main() 
{
    // ask for course info and choices.
    menuAction();
    
    return 0;
}