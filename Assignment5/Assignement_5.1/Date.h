/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/20/2018
 * Due: 11/25/2018
 * Assignment 5: User-Defined Classes/ Pointers
 * 5.1: Date class that creates a date with day, month and year
 * File that contains the specification of the class Date.
 * Initializes the functions and variables used in the class DAte.
 */
#ifndef DATE_H
#define DATE_H

using namespace std;

class Date 
{
    // initialize functions in date class.
    public:
        Date(int=1, int=1, int=2000);   // sets day, month, year
        void setDate(int, int, int);    // sets the date
        void printDate() const;         // prints date to the screen
        string getMonth();              // Get the month in letters
        void newYear();                 // display "Happy new year!" if new year
        bool compareDate(Date date);    // Compares 2 date
        
    // Initialize variable in course class. 
    private:
        int day;
        int month;
        int year;
};
#endif /* DATE_H_ */


