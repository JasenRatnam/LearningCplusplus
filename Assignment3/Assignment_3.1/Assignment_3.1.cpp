/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/22/2018
 * Due: 10/26/2018
 * Assignment 3: User-Defined Functions/ Arrays
 * This is a menu-driven program that gets an integer between 10 and 999 
 * and the user can choose to display the digits, reverse the digits, sum the digits
 * or returns true if if at least one of the digits is a prime number
 */

#include <iostream>
#include<cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

/*
 * Function that gets the input from the user.
 * Makes sure that the input is between 10 and 999.
 * Makes sure input is a number.
 * Returns input integer.
 */
int getInput()
{
    int userInput;
    
    // Ask for input.
    cout << "Please enter an integer between 10 and 999 : \n";
    cin >> userInput;
    
    // Make sure its a number
    
    if(!cin)
    {
        cin.clear();                                                             // Clear the input.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                     // Ignore the current input and wait for new input.
        cout << "ERROR: The input was not a number.\n";
        getInput();                    // Recursive function, goes back in function                                           // Save new input. 
    }
    
    // Make sure input is in correct range.
    if(userInput < 10 || userInput > 999)
    {
        cin.clear();                                                             // Clear the input.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                     // Ignore the current input and wait for new input.
        cout << "ERROR: The input is not in the correct range.\n";
        getInput();                  // Recursive function, goes back in function 
    }
    
    return userInput;  // return input.
}

/*
 * Get the digits of the input number.
 * Make them in the correct order.
 * return the digits in a vector<int>.
 */
vector<int> getDigits(int input)
{
    vector<int> digits;  // initialize vector.
    
    // Get digits.
    while(input)
    {
        int digit = input % 10;
        digits.push_back(digit);
        input = input/10;
    }
   
    // Reverse order of digits to be in correct order
    reverse(digits.begin(),digits.end());  
    
    // Print digits
//    for(auto digit : digits)
//    {
//        cout << digit << " ";
//    }
    return digits;
}

/*
 * Get the sum of the digits.
 * return int values.
 */
int sumDigits(vector<int> digits)
{
    int sum = accumulate(digits.begin(), digits.end(), 0);
    return sum;
}

/*
 * Display the digits in correct format in output.
 */
void displayDigits(vector<int> digits)
{
    //string digitsString;
    
//    for(auto digit : digits)
//    {
//        cout << digit << "-";
//    }
    
    cout << digits[0];  // Print first digit.
    // Print the rest with "-" between them.
    for(auto i = digits.begin()+1; i != digits.end(); ++i)
        cout << '-'<< *i;
}

// Functions the gives the int number in reverse order.
int reverseDigits(int userInput)
{
    int remainder = 0;
    int reverse  = 0;
    
    while(userInput > 0)
    {
        remainder = userInput % 10;
        reverse = reverse*10 + remainder;
        userInput = userInput/10;
    }
    return reverse;
}

/*
 * Check if at least on digits is a prime number.
 * returns boolean with answer.
 */
bool primeDigit(vector<int> digits)
{
    bool prime = false;
    for(auto digit : digits)
    {
        for(int i = 2; i < digit; i++)
        {
            if(digit % i == 0)
            {
                prime = true;
            }
        }
    }
    
    return prime;
}

/*
 * Function that does the menu and choices fro commands.
 * Goes in a loop until user chooses to quit.
 */
void menuAction()
{
    // Get input
    int input = getInput();
    cout << "\n";
    
    // get digits.
    vector<int> digits = getDigits(input);
    int choice;
    int rev;
    bool playing = true;
    
    // Give choices
    cout << "\nChoose one of the following options: \n"
            "1. Display the digits that composes the number.\n"
            "2. Reverse the digits of the number.\n"
            "3. Sum of the digits of the number.\n"
            "4. Is at least one of the digit a prime number?\n"
            "5. Exit.\n\n";

    // Save choice.
    cin >> choice;
    cout << "\n";
    
    // Loop with the current number.
    while(playing)
    {
        switch(choice)
        {
            case 1:
                // Display number.
                    cout << "The digits of the number are: ";
                    displayDigits(digits);
                    cout << "\n";
                    break;
            case 2:
                // Reverse number:
                    rev = reverseDigits(input);
                    cout << "The new (reversed) number is: "
                         << rev << "\n";
                    break;
            case 3:
                // Sum of digits:
                    cout << "The sum of the digits of the number is: "
                         << sumDigits(digits) << "\n";
                    break;
            case 4:
                // is at least one of the digit prime:
                    cout << "At least one of the digits ";
                    if(primeDigit(digits) == true)
                    {
                        cout << "is ";
                    }
                    else
                    {
                        cout << "is not ";
                    }

                    cout << "a prime number.\n";
                    break;
            case 5:
                // Quit program:
                    playing = false;
                    break;
            default: cout << "Invalid input.\n";
        }
    
        // Ask for new input.
        if(playing) 
        {
            cout << "\nPlease choose another option from the menu: ";

            cin >> choice;
            cout << "\n";
        }
    }
}

int main() 
{
    // Does the menu.
    menuAction();
    
    return 0;
}

