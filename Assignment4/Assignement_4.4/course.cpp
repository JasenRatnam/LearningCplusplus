
/*
 * Author: Jasen Ratnam 40094237
 * Date: 11/04/2018
 * Due: 11/11/2018
 * Assignment 4: Strings/ User-Defined Classes
 * 4.4: create a class course, represents the course offered with students enrolled.
 * course.cpp: contains the implementation of the member functions of the class.
 * constructor takes in:
 * string code of course
 * string name of course
 * string description of course
 * an vector of students in the course.
 */

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include "course.h"
#include "student.h"

using namespace std;

/*
 * Default constructor of course with default values.
 * Creates a course object.
 */
course::course() 
{
    setCode("default");
    setName("default");
    setDescription("default");
}

/*
 * Constructor of course with user given variables.
 * Gets:
 * course code.
 * course name.
 * course description.
 * vector of students.
 * Creates a course object.
 */
course::course(string code, string name, string description, vector <student> listStudents)
{ 
    setCode(code);
    setName(name);
    setDescription(description);
    setStudentList(listStudents);
}

/*
 * Sets the code variable to given string.
 */
void course::setCode(string code)
{
    this->code = code;
}

/*
 * Sets the name variable to given string.
 */
void course::setName(string name)
{
    this->name = name;
}

/*
 * Sets the description variable to given string.
 */
void course::setDescription(string description)
{
    this->description = description;
}

/*
 * Sets the vector variable to given vector student..
 */
void course::setStudentList(vector <student> listStudents)
{
    this->listStudents = listStudents;
}
    
/*
 * Function that returns the course code.
 */
string course::getCode()
{
    return code;
}

/*
 * Function that returns the course name.
 */
string course::getName()
{
    return name;
}

/*
 * Function that returns the course description.
 */
string course::getDescription()
{
    return description;
}

/*
 * Function that returns the number of students in the course.
 */
int course::getNumbStudents()
{
    return listStudents.size();
}

/*
 * Function that returns the list of students.
 */
vector <student> course::getStudentList()
{
    return listStudents;
}

/*
 * Function that adds a student to the vector of students enrolled to the course.
 */
void course::addStudent(student newStudent)
{
    listStudents.push_back(newStudent);
}

/*
 * Function that removes a student from the vector of students enrolled to the course.
 * Gets a student as input.
 */
void course::removeStudent(student removeStudent) 
{
    // gets id number of student to remove.
    int id = removeStudent.getId();
    
    // Loops that go trough every element of the vector.
    for(int i = 0; i < listStudents.size(); i++)
    {
        // Check if every element of a vector has the same id as the one given.
        if(listStudents[i].getId() == id)
        {            
            // Remove student.
            listStudents.erase(listStudents.begin() + (i));
        }
    }
}

/*
 * Function that searches for a student with a id number.
 * Gets the id number as the input.
 * Returns a boolean saying if such a students exists in the vector.
 */
bool course::searchStudent(int id)
{
    bool found;
    // Loop to go trough every student.
    for(int i = 0; i < listStudents.size(); i++)
    {
        // Student found.
        // If id matches:
        if(listStudents[i].getId() == id)
        {           
            // bool is true
            return true;
        }
    }
    return false;
}



