/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/20/2018
 * Due: 11/25/2018
 * Assignment 5: User-Defined Classes/ Pointers
 * 5.1: Date class that creates a date with day, month and year
 * Driver that contains the main function to test the class Date.
 * Prompt user to enter information about two dates.
 * Creates two objects of the class date with given information.
 * Test all member functions of the class.
 */

#include <iostream>
#include "Date.h"
using namespace std;

// Constructor
Date::Date (int d, int m, int y)
{
 day = d;
 month = m;
 year = y ;
}

// sets date
void Date::setDate(int d, int m, int y)
{
 day = d;
 month = m;
 year = y ;
}

// returns the letter equivalent of the month.
string Date::getMonth()
{
   if(month == 1)
   { 
       return "January";
   }
   
   if(month == 2)
   { 
       return "February";
   }
   
   if(month == 3)
   { 
       return "March";
   }
   
   if(month == 4)
   { 
       return "April";
   }
   
   if(month == 5)
   { 
       return "May";
   }
   
   if(month == 6)
   { 
       return "June";
   }
   
   if(month == 7)
   { 
       return "July";
   }
   if(month == 8)
   { 
       return "August";
   }
   if(month == 9)
   { 
       return "September";
   }
   if(month == 10)
   { 
       return "October";
   }
   if(month == 11)
   { 
       return "November";
   }
   if(month == 12)
   { 
       return "December";
   }
}

// Displays new year message if new year.
void Date::newYear()
{
    if(month ==1 && day == 1)
    {
        cout << "Happy New Year!\n";
    }
}

// Compares 2 dates.
// return true if the same.
// return false otherwise.
bool Date::compareDate(Date date)
{
    if(this->day == date.day)
    {
        if(this->month == date.month)
        {
            if(this->year == date.year)
            {
                return true;
            }
        }
    }
    return false;
}

// prints date
void Date::printDate() const
{
cout << month << "/" << day << "/" << year << "\n";
}
