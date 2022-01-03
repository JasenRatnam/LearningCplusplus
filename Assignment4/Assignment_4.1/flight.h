/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.1: Flights of an airline company.
 * File that contains the specification of the class flight.
 * Initializes the functions and variables used in the class flight.
 */

#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

using namespace std;

class flight {
public:
    // initialize functions in flight class.
    flight();
    flight(int number, string depTime, string depDate, string depCity, string desCity);
    void setNumber(int number);
    void setDepartureTime(string depTime);
    void setDepartureDate(string depDate);
    void setDepartureCity(string depCity);
    void setDestinationCity(string desCity);
    
    int getNumber();
    string getDepartureTime();
    string getDepartureDate();
    string getDepartureCity();
    string getDestinationCity();
    
    
private:
    // Initialize variable in course class. 
    int number;
    string depTime;
    string depDate;
    string depCity;
    string desCity;
};

#endif /* FLIGHT_H */

