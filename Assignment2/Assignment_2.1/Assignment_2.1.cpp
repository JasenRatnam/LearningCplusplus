/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/04/2018
 * Due: 10/12/2018
 * Assignment 2: Control Statements/ User-Defined Functions
 * This program will take in a student number of 5 digits, the students gender, their age
 * and their program of study. For as much students as wanted and the user should enter -1 to say they have no more students
 * The program will output the statistics for all the students.
 * The total number of students.
 * The number of male students.
 * The number of female students.
 * And the number of students in every program inputed.
 *******************************************************************************
 * The last part of the program was inspired from a youTube video of coding.
 * The video explained how to get the amount of times a string was inputed and 
 * output the string and the number of repetition. This was done with the use of Vectors.
 * Title: C++ Program: Counts how many times each word appears in the input.
 * Author: BeginnerPrograms.
 * Date: Jun. 4, 2015.
 * Availability: https://www.youtube.com/watch?v=mdBcXvNOajU&t=0s&list=WL&index=290.
 *******************************************************************************
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    /* Int variables to save the student ID number, the number of students, 
    * the sexe equivalent in int, the number of males, the number of females
    * & the age of the student.
    */
    int studentNumber;
    int numbOfStudent = 0;
    int sexe;
    int numbOfMale = 0;
    int numbOfFemale = 0;
    int age;
    
    // Double variable to save the average age.
    double avgAge = 0;
    
    /* Boolean variables to know if the student ID number, the sexe & the age is
    *  in the correct format.
    */
    bool correctNumber = false;
    bool correctSexe = false;
    bool correctAge = false;
    
    // String variables to save the string of the students program.
    string programs;
    // Vector to hold strings.
    vector <string> stringHolder;
    
    // Get the first 5-digit student number.
    cout << "Please enter a 5-digit student number: \n";
    cin >> studentNumber;
    
    // While loop to get the information of all students.
    while(studentNumber != -1)
    {
        // While loop to ensure that the student number is correct
        while(correctNumber != true)
        {
            // Check input is an integer
            if(!cin)
            {
                cout << "ERROR: The input was not a number, Please enter a 5-digit integer student number: \n";
                cin.clear();                                                      // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');         // Ignore the current input and wait for new input.
                cin >> studentNumber;                                             // Save new input.
            }
            
            else
            {   // Count length of input:
                int studentNumberCopy = studentNumber;                           // Get copy.
                int length;
                for(length = 0; studentNumberCopy > 0; length ++)                // For loop to count number of digit in ID number.
                {
                    studentNumberCopy = studentNumberCopy/10;
                }

                // If the ID is not 5 digit.
                if(length != 5) 
                {
                    cout << "Error: Please enter a 5-digit student number: \n";
                    cin.clear();                                                 // Clear the input.
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');    // Ignore the current input and wait for new input.
                    cin >> studentNumber;                                        // Save new input and go in loop again
                }
                
                // If the ID is of the correct length.
                else if(length == 5) 
                {
                    correctNumber = true; 
                }
            }
        }
        // Reset boolean to false for next student.
        correctNumber = false; 
        
        // Increment the number of students. 
        numbOfStudent++;  
        
        // Ask for the sexe of the student.
        cout << "Gender (1= male, 2= female): \n";
        cin >> sexe;
        
        // Check if the sexe int equivalent is correct
        while(correctSexe != true)
        {
            // Check if it is an int.
            if(!cin) 
            {
                cout << "ERROR: The input was not a number, Please enter a single digit integer 1 or 2: \n";
                cin.clear();                                                     // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');        // Ignore the current input and wait for new input.
                cin >> sexe;                                                     // Save input.
            }
            
            // if the int is a 1 or 2.
            else if(sexe == 1 || sexe == 2) 
            {
                correctSexe = true;    
                
                // If 1, increment the number of males.
                if(sexe == 1) 
                {
                    numbOfMale++;
                }
                
                // If 2, increment the number of females.
                else if( sexe == 2) 
                {
                    numbOfFemale++;
                }
            }
            
            // If its not a 1 or 2.
            else  
            {
                cout << "ERROR: Please enter a single digit integer 1 or 2: \n"; // ask for new input and go in loop again.
                cin.clear();                                                     // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');        // Ignore the current input and wait for new input.
                cin >> sexe;
            }
            
        }
        // Reset boolean for next sexe.
        correctSexe = false; 
        
        // Ask for the age of student.
        cout << "Age: \n";
        cin >> age;
        
        // Check if the age is correct.
        while(correctAge != true)
        {
            // Check if input is integer.
            if(!cin) 
            {   // Ask for new input and go in loop again.
                cout << "ERROR: The input was not a number, Please enter an integer greater than 0: \n";
                cin.clear();                                                     // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');        // Ignore the current input and wait for new input.
                cin >> age;                                                      // Save input.
            }
            
            // If the age is a negative number.
            else if (age < 0)  
            {   // Ask for new input and redo loop
                cout << "ERROR: Please enter an integer greater than 0: \n";
                cin.clear();                                                     // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');        // Ignore the current input and wait for new input.
                cin >> age;
            }
            
            // The input is correct, make the boolean true.
            else 
            {
                correctAge = true;
            }
        }
        // Reset boolean for next age.
        correctAge = false; 
        
        // Add all of the ages together.
        avgAge = avgAge + age;  
        
        // Get program of study
        cout << "Program of study: \n";  
        cin >> programs;
        
        // Add programs to vector, stringHolder.
        stringHolder.push_back(programs); 
      
        // Ask for new student number and repeat loop.
        cout << "\n";
        cout << "Please enter a 5-digit student number: \n";
        cin >> studentNumber;
    } // end loop if -1 is entered
    
    // Get the average age of all student, by dividing sum of age by number of students.
    avgAge = avgAge/numbOfStudent; 
    
    // Sort all programs of students in alphabetical order.
    sort(stringHolder.begin(), stringHolder.end());  
    
    // Intialize the word count of repetitions to 1.
    // Because every word is repeated at least one.
    int wordCount = 1; 
    
    // Make the string program = to the first element of the vector.
    programs = stringHolder[0]; 
  
    cout << "\nStatistics:\n"
         << "Total number of students is: " << numbOfStudent << "\n"             // Show number of total students
         << "Number of male students is: " << numbOfMale << "\n"                 // Show number of males.
         << "Number of female students is: " << numbOfFemale << "\n"             // Show number of females.
         << "Average age of students is: " << avgAge << "\n";                    // Show the average age.
    
    // For loop to calculate the number of students in every course and display.
    for(int i = 1; i < numbOfStudent; i++) 
    {
        // If the first program is not the same as the second,
        // then print the number of students counted in this program.
        if(programs != stringHolder[i]) 
        {
            cout << "Number of " << programs << " students: " << wordCount << "\n";
            wordCount = 0;
            programs = stringHolder[i];
        }
        
        // Else increment the word count.
        else
        {
            wordCount++; 
        }
    }
    
    // Print last program.
    cout << "Number of " << programs << " students: " << wordCount << "\n";  
    
    return 0;
}
