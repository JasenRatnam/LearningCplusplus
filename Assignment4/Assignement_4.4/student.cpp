/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.4: class that represent the students of a university.
 * creates object student.
 */

#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Default constructor of student with default values.
 * Creates a student object.
 */
student::student() 
{
    setId(1);
    setFName("Default");
    setLName("Default");
    setDateBirth("Default");
    setAddress("Default");
    setAreaCode(1);
    setPhoneNumber("Default");
}

/*
 * Constructor of student with user given variables.
 * Gets:
 * student id.
 * student firstName.
 * student lastName.
 * student date of birth.
 * student address.
 * student area code.
 * student phone number.
 */
student::student(int id, string firstName, string lastName, string dateBirth, 
                 string address, int areaCode, string phoneNumber)
{
    setId(id);
    setFName(firstName);
    setLName(lastName);
    setDateBirth(dateBirth);
    setAddress(address);
    setAreaCode(areaCode);
    setPhoneNumber(phoneNumber);
}

/*
 * Sets the id variable to given int id number.
 */
void student::setId(int number)
{
    id = number;
}

/*
 * Sets the student first name variable to given string first name.
 */
void student::setFName(string firstName)
{
    this->firstName = firstName;
}

/*
 * Sets the student last name variable to given string last name.
 */
void student::setLName(string lastName)
{
    this->lastName = lastName;
}

/*
 * Sets the student date of birth variable to given string date of birth name.
 */
void student::setDateBirth(string dateBirth)
{
    dateOfBirth = dateBirth;
}

/*
 * Sets the student address variable to given string address.
 */
void student::setAddress(string address)
{
    this->address = address;
}

/*
 * Sets the student area code variable to given int area code.
 */
void student::setAreaCode(int areaCode)
{
    this->areaCode = areaCode;
}

/*
 * Sets the student phone number variable to given string phone number.
 */
void student::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

/*
 * return the student id number.
 */
int student::getId()
{
    return id;
}

/*
 * return the student first name.
 */
string student::getFName()
{
    return firstName;
}

/*
 * return the student last name.
 */
string student::getLName()
{
    return lastName;
}

/*
 * return the student date of birth.
 */
string student::getDateBirth()
{
    return dateOfBirth;
}

/*
 * return the student address.
 */
string student::getAddress()
{
    return address;
}

/*
 * return the student area code.
 */
int student::getAreaCode()
{
    return areaCode;
}

/*
 * return the student phone number.
 */
string student::getPhoneNumber()
{
    return phoneNumber;
}

/*
 * Function that checks if two students have the same last name.
 * gets second student as input.
 * returns boolean true if yes, false if no.
 */
 bool student::sameLName(student student2)
 {
    sameLN = false;
    if(this->getLName() == student2.getLName())
    {
        sameLN = true;
    }

    return sameLN;
 }
 
 /*
 * Function that checks if two students are roommates.
 * Gets second student has input.
 * returns boolean true if same address.
 * false if not.
 */
 bool student::roomates(student student2)
 {
    roommates = false;
    if(this->getAddress() == student2.getAddress())
    {
        roommates = true;
    }

    return roommates;
 }
 
 /*
 * Function that gets the age of the student.
  * returns the age of student.
 */
 int student::getAge()
 {
     //age = 2018 - dateOfBirth;
     return age;
 }
 
 /*
  * Function that gets the full name of the student as a string.
  * returns full name.
 */
 string student::getFullName()
 {
     fullName = firstName + " " + lastName;
     return fullName;
 }


