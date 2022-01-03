/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.2: Cars which represents cars of a car rental company.
 * Contains the specification of the class.
 * Initializes the functions and variables used in the class car.
 */

#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class car {
public:
    // initialize functions in course class.
    car();
    car(int id, string brand, string type);
    void setId(int number);
    void setBrand(string depTime);
    void setType(string depDate);
    
    int getId();
    string getBrand();
    string getType();
    
    
private:
    // Initialize variable in course class. 
    int id;
    string brand;
    string type;

};

#endif /* CAR_H */

