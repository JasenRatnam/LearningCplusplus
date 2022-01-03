/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/04/2018
 * Due: 10/12/2018
 * Assignment 2: Control Statements/ User-Defined Functions
 * This program will use the secant method to compute the root for a function specified
 * in the main code block. 
 */

#include <iostream>
#include<cmath>

using namespace std;

// User function.
float User_Fun(float x)
{
    float y;
    y = (x - exp(-x)); // the function
    return y;  // Returns y.
}

int main ()
{
//
// Define the values
//
// ST_A: User provided starting value A
// ST_B: User provided starting value B
//
// These values are required to begin the iteration as
// difference approximation of derivative requires two points
//
// Min_Mag_F: User provided minimum magnitude of the function
// value. Effectively how close to root is acceptable
// within the numerical resolution of the system.
//
// Iternal values
//
// CNTR: Used to keep track of iteration number
// X_New: Latest estimate of the root
// X_Now: Previous estimate of the root
// X_Pre: The oldest estimate of the root
// F_X_New: The function using the latest estimate of the root
// F_X_Now: The function using the previous estimate of the root
// F_X_Pre: The function using the oldest estimate of the root
// New_Mag_F: The magnitude of the function computed using
// latest estimate of the root
//
int CNTR;
float X_New, X_Now,X_Pre;
float ST_A, ST_B, Min_Mag_F;
float F_X_New, F_X_Now, F_X_Pre;
float New_Mag_F;
//
// Ask for the user to input the starting values and
// the termination conditions
//
// Function in this case will be user defined
//
cout << "This program will compute a root of a pre-set function " << endl;
cout<< " you will enter two starting values for search of root and "<< endl;
cout << " and a ending condition of how small magnitude you will allow."<<endl;
cout <<endl;

cout << "Please type in the value of the first start point "<< endl;
cin >> ST_A;
X_Pre = ST_A; // Load starting value into internal Var.
cout<<endl;

cout << "Please type in the value of the second start point "<< endl;
cin >> ST_B;
X_Now = ST_B; // Load starting value into internal Var.
cout <<endl;

cout << "Please type in the smallest magnitude of the function "<<endl;
cin >> Min_Mag_F;

if (Min_Mag_F < 0)
{ 
   Min_Mag_F = -1 * (Min_Mag_F);  // Pos Magnitude
} 

F_X_Pre = User_Fun(ST_A); // Compute f(ST_A)
F_X_Now = User_Fun(ST_B); // Compute f(ST_B)
cout << "FA =" << F_X_Pre <<" FB = " << F_X_Now << endl;
New_Mag_F = 1000000;     // Intialize ending conditions to dummy value

while (New_Mag_F >= Min_Mag_F)
{
    CNTR++;
    X_New = X_Now - (F_X_Now * (X_Pre-X_Now) / (F_X_Pre-F_X_Now)); //Estimate
    F_X_New = User_Fun(X_New);                                     // Compute Function at root estm.
    cout << "Estimate of root #" << CNTR << " is " << X_New << endl;
    cout << "The function is: " << F_X_New << endl;
    
    if (F_X_New < 0)
    {
        New_Mag_F = -1 * (F_X_New);
    }
    else 
    {
        New_Mag_F = F_X_New;
    }
    
    X_Pre = X_Now;             // Update the values
    X_Now = X_New;             // Update the values
    F_X_Pre = User_Fun(X_Pre); //Update the functions
    F_X_Now = User_Fun(X_Now); //Update the function
    
    if (CNTR >= 100) 
    {
        break; // exit from stuck in loop
    } 
}
return 0;
}