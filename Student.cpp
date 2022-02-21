#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;
// Variables for methods
string UserName, Password, fullName;

int projectGrade, quizGrade, midtermGrade, finalGrade;

/**
 * Login for student, checks if user inputted the correct
 * username/password
 *
 * @param username student username
 * @param password student password
 * @return true if login is succesful
 * @return false if login is failure
 */
bool Student::login(string username, string password) {
    bool check = false;

    if (username == getUserName() && password == getPassword()) {
        check = true;
    }

    return check;
}

/**
 * Gets the name of the specified student
 *
 * @return fullName students name
 */
string Student::getStudentName() {
    return fullName;
}

/**
 * Gets the project grade of specified student
 *
 * @return projectGrade project grade of student
 */
int Student::getProjectGrade() {
    return projectGrade;
}


/**
 * Gets the quiz grade of the specified student.
 *
 * @return quizGrade quiz grade of student
 */
int Student::getQuizGrade() {
    return quizGrade;
}

/**
 * gets the midterm grade of the specified student.
 *
 * @return midtermGrade midterm grade of student
 */
int Student::getMidtermGrade() {
    return midtermGrade;
}

/**
 * gets the final grade of the specified student
 *
 * @return finalGrade final grade of student
 */
int Student::getFinalGrade() {
    return finalGrade;
}

/**
 * Gets the Username of student
 *
 * @return UserName username of student
 */
string Student::getUserName() {
    return UserName;
}
/**
 * gets the password of a student
 *
 * @return Password password of student
 */
string Student::getPassword() {
    return Password;
}

/**
 * Get the overall grade of a student
 *
 *
 * @return overallsum overall sum of a student
 */
double Student::getOverallGrade() {
    double overallsum;

    overallsum = ((getProjectGrade() * 0.30) + (getQuizGrade() * .10) +
    (getMidtermGrade() * .20) + (getFinalGrade() * .40));

    return overallsum;
}
/**
 * Sets the full name of a student
 *
 * @param name string of student name
 */
void Student::setStudentName(string Name) {
    fullName = Name;
}

/**
 * sets the project grade of a student
 *
 * @param pgrade project grade of student
 */
void Student::setProjectGrade(int pgrade) {
    projectGrade = pgrade;
}

/**
 * sets the quiz grade of a student
 *
 * @param qgrade quiz grade of student
 */
void Student::setQuizGrade(int qgrade) {
    quizGrade = qgrade;
}

/**
 * sets the midtermgrade of a student
 *
 * @param mgrade midterm grade of student
 */
void Student::setMidtermGrade(int mgrade) {
    midtermGrade = mgrade;
}

/**
 * sets the final grade of a student
 *
 * @param fgrade final grade of student
 */
void Student::setFinalGrade(int fgrade) {
    finalGrade = fgrade;
}

/**
 * sets the username of student
 *
 * @param username username of student
 */
void Student::setUserName(string username) {
    UserName = username;
}

/**
 * sets the password of a student
 *
 * @param password password of student
 */
void Student::setPassword(string password) {
    Password = password;
}
