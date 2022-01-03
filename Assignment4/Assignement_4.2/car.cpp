/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.2: Cars which represents cars of a car rental company.
 * car class that represents the cars of a car rental company.
 * Defined with the following attributes:
 * id (int)
 * brand (string)
 * type (string
 * And has functions that return the attributes.
 */

#include "car.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Default constructor of car with default values.
 * Creates a car object.
 */
car::car() 
{
    setId(1);
    setBrand("Honda");
    setType("Sedan");
}

/*
 * Constructor of car with user given variables.
 * Gets:
 * car id.
 * car brand.
 * car type.
 * Creates a car object.
 */
car::car(int id, string brand, string type) 
{
    setId(id);
    setBrand(brand);
    setType(type);
}

/*
 * Sets the id variable to given int.
 */
void car::setId(int idNumb) 
{  
    id = idNumb;
}

/*
 * Sets the brand variable to given string.
 */
void car::setBrand(string carBrand) 
{  
    brand = carBrand;
}

/*
 * Sets the type variable to given string.
 */
void car::setType(string carType) 
{  
    type = carType;
}

/*
 * Function that returns the car id number.
 */
int car::getId()
{
    return id;
}

/*
 * Function that returns the car brand.
 */
string car::getBrand()
{
    return brand;
}

/*
 * Function that returns the car type.
 */
string car::getType()
{
    return type;
}
