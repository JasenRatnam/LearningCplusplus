/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/04/2018
 * Due: 10/12/2018
 * Assignment 2: Control Statements/ User-Defined Functions
 * This program will ask the user to input six numbers sequentially,
 * and sort it using bubble sort.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    /* Create int variables to save the max amount of numbers, an int array to save them
     * and one to temporally hold a number.
     * Create a boolean to know if the number is in the correct format.
    */
    int maxNumb = 6;
    int numb[6];
    int tempHolder;
    bool correctNumber = false;
    
    // Explain program to user.
    cout << "This program will read six numbers typed in by you \n"
         << "And then sort and print out the sorted numbers\n";
    
    // For loop to get the 6 numbers from user. 
    for(int i = 0; i < maxNumb; i++)
    {
        // Ask for input from user and save it in array.
        cout << "Please type in the first number\n";
        cin >> numb[i];
        
        // While loop to ensure that the number is correct
        while(correctNumber != true)
        {
            // Check input is an integer
            if(!cin)
            {
                cout << "ERROR: The input was not a number, Please enter a integer number \n";
                cin.clear();                                                     // Clear the input.
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');        // Ignore the current input and wait for new input.
                cin >> numb[i];                                                  // Save new input, go back in loop
            }
            
            // Else input is correct
            else 
            {   
                correctNumber = true;                                 
            }
        }
        
        // Reset boolean for next number
        correctNumber = false; 
    }
    
    // Used to debug program: gives the numbers in unsorted order.
    // for(int i = 0; i < maxNumb; i++)
    // {    
    //     cout << "not sorted numbers: " << numb[i] << "\n";
    // }
    
    /* Bubble sort:
     * Compare adjacent entries 
     * and swap them if not in the correct number
     */
    for(int j = 0; j < maxNumb; j++)
    {
        for(int k = 0; k < (maxNumb-j); k++)
        {
            // If current number is bigger than the next
            if(numb[k] > numb[k+1]) 
            {   // Move it to the next space.
                tempHolder = numb[k];
                numb[k] = numb[k+1];
                numb[k+1] = tempHolder;
            }
        }
    }
    
    // Print all elements in array.
    // Sorted number in ascending.
    for(int y = 0; y < maxNumb; y++)
    {
        cout << numb[y] << " ";
    }
    
    return 0;
}

