/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.3: class that represent the students of a university.
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class student {
public:
    // initialize functions in course class.
    student();
    student(int id, string firstName, string lastName, string dateBirth, 
    string address, int areaCode, string phoneNumber, int birthYear);
    void setId(int number);
    void setFName(string firstName);
    void setLName(string lastName);
    void setDateBirth(string dateBirth);
    void setAddress(string address);
    void setAreaCode(int areaCode);
    void setPhoneNumber(string phoneNumber);
    void setBirthYear(int birthYear);
    
    int getId();
    string getFName();
    string getLName();
    string getDateBirth();
    string getAddress();
    int getAreaCode();
    string getPhoneNumber();
    bool sameLName(student student2);
    bool roomates(student student2);
    int getAge();
    string getFullName();
    
private:
    // Initialize variable in course class.
    int age;
    string fullName;
    int id;
    string firstName;
    string lastName;
    string dateOfBirth;
    string address;
    int areaCode;
    string phoneNumber;
    bool sameLN;
    bool roommates;
    int birthYear;

};

#endif /* STUDENT_H */

