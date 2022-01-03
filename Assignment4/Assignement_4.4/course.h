
/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.4: create a class course, represents the course offered with students enrolled.
 * course.h: contains specification of the class.
 * Initializes functions and variables.
 */

#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include <string>
#include "student.h"

using namespace std;


class course {
public:
    // initialize functions in course class.
    course();
    course(string code, string name, string description, vector <student> listStudents);
    void setCode(string code);
    void setName(string name);
    void setDescription(string description);
    void setStudentList(vector <student> listStudents);
    
    string getCode();
    string getName();
    string getDescription();
    int getNumbStudents();
    vector <student> getStudentList();
    
    void addStudent(student newStudent);
    void removeStudent(student removeStudent);
    bool searchStudent(int id);
    
    
    
private:
    // Initialize variable in course class. 
    string code;
    string name;
    string description;
    vector <student> listStudents;
};

#endif /* COURSE_H */

