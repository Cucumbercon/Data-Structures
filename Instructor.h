#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Student.h"


using std::string;

/**
 * the instructor class is responsible for instructor methods and variables
 *
 */
class Instructor {

    //instructor variables
    string IUserName, IPasswordN, IFullnameN;

    //object arrays
    static Instructor Iarr[3];

    static Student Sarr[20];




public:

    Instructor(){}; // constructor

    ~Instructor(){}; // destructor

    bool login(string username, string password); // login method to login

    string getInstructorName(); // gets the instructors name

    string getInstructorUserName(); // gets the instructors username

    string getInstructorPassword(); // gets the instructors password

    Student getStudent(string username); // gets the students username

    Student getMinStudent(int gradeType); //gets the minimum score and name of student for gradetype

    Student getMaxStudent(int gradeType);//get the maximum score and name of student for gradetype

    double getAvg(int gradeType);//gets the average score for gradetype

    void setInstructorName(string name);// sets instructors name

    void setInstructorPassword(string password); // sets instructors password

    void setInstructorUsername(string username); // sets instructors username


};

#endif
