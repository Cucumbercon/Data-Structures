#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::string;
/**
 * The student class which handles methods and student object variables
 *
 */
class Student {

    // Student variables
    string UserName, Password, fullName;

    int projectGrade, quizGrade, midtermGrade, finalGrade;


public:


    Student(){}; // constructor

    ~Student(){}; // destructor

    bool login(string username, string password); // login method

    string getStudentName(); // gets students naem

    string getUserName(); // gets students username

    string getPassword(); // gets students password

    int getProjectGrade(); // gets students project grade

    int getQuizGrade(); // get students quiz grade

    int getMidtermGrade(); // gets students midterm grade

    int getFinalGrade(); // get students final grade

    double getOverallGrade(); // gets students overall grade

    void setStudentName(string fullName); // sets students name

    void setProjectGrade(int grade); // sets students project grade

    void setQuizGrade(int grade); // sets students quiz grade

    void setMidtermGrade(int grade); // sets students midterm grade

    void setFinalGrade(int grade); // sets students final grade

    void setUserName(string username); // sets students username

    void setPassword(string password); // sets students password
}; // Student

#endif
