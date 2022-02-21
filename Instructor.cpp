#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <sstream>

using namespace std;

Student Instructor::Sarr[] = {};// student object array
Instructor Instructor::Iarr[] = {}; // instructor object array


/**
 * gets the instructors full name
 *
 * @return IFullnameN full name of instructor
 */
string Instructor::getInstructorName() {
    return IFullnameN;
}
/**
 * gets the instructors username
 *
 * @return IUserName username of instructor
 */
string Instructor::getInstructorUserName() {
    return IUserName;
}

/**
 * gets the instructors password
 *
 * @return IPasswordN
 */
string Instructor::getInstructorPassword() {
    return IPasswordN;

}

/**
 * checks to see if user input matches the username/password
 * of instructor.
 *
 * @return true if login succesful
 * @return false if login failure
 */
bool Instructor::login(string username, string password) {
    bool checkI = false;
    if (username == getInstructorUserName() && password == getInstructorPassword()) {

        checkI = true;
    }
    return checkI;
}

/**
 * This function returns the student with specified lowest grade type.
 *
 *
 * @param gradeType type of grade that is going to be checked
 * @preturn Student object which has the lowest grade
 */
Student Instructor::getMinStudent(int gradeType) {
    Student temp[20];
    string username2, password2, first, last;
    int proj, q2, midt, fin, i = 0;
    ifstream inStudentFile2("students.txt");
    while (inStudentFile2 >> username2 >> password2 >> first >> last >> proj >> q2 >> midt >> fin) {
        temp[i].setUserName(username2);
        temp[i].setPassword(password2);
        temp[i].setStudentName(first + " " + last);
        temp[i].setProjectGrade(proj);
        temp[i].setQuizGrade(q2);
        temp[i].setMidtermGrade(midt);
        temp[i].setFinalGrade(fin);
        i++;
    } // while

    Student minimumgrade = temp[0];
    switch(gradeType) { // switch for each grade type
    case 1:

        for (int i = 0; i < 20; i++) {
            if (temp[i].getProjectGrade() < minimumgrade.getProjectGrade()) {
                minimumgrade = temp[i];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getQuizGrade() < minimumgrade.getQuizGrade()) {
                minimumgrade = temp[i];
            }
        }
        break;
    case 3:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getMidtermGrade() < minimumgrade.getMidtermGrade()) {
                minimumgrade = temp[i];
            }
        }
        break;
    case 4:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getFinalGrade() < minimumgrade.getFinalGrade()) {
                minimumgrade = temp[i];
            }
        }
        break;
    case 5:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getOverallGrade() < minimumgrade.getOverallGrade()) {
                minimumgrade = temp[i];
            }
        }
        break;


    } // switch
    return minimumgrade;
}

/**
 * This function gets the student with the highest grade for the specified grade
 * type.
 *
 *
 * @param gradeType the specified gradetype
 * @return Student object with the higherst score of gradetype
 */
Student Instructor::getMaxStudent(int gradeType) {
    Student temp[20];
    string username2, password2, first, last;
    int proj, q2, midt, fin, i = 0;
    ifstream inStudentFile2("students.txt");
    while (inStudentFile2 >> username2 >> password2 >> first >> last >> proj >> q2 >> midt >> fin) {
        temp[i].setUserName(username2);
        temp[i].setPassword(password2);
        temp[i].setStudentName(first + " " + last);
        temp[i].setProjectGrade(proj);
        temp[i].setQuizGrade(q2);
        temp[i].setMidtermGrade(midt);
        temp[i].setFinalGrade(fin);
        i++;
    } // while

    Student maximumgrade = temp[0];
    switch(gradeType) { // switch for each grade type
    case 1:

        for (int i = 0; i < 20; i++) {
            if (temp[i].getProjectGrade() > maximumgrade.getProjectGrade()) {
                maximumgrade = temp[i];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getQuizGrade() > maximumgrade.getQuizGrade()) {
                maximumgrade = temp[i];
            }
        }
        break;
    case 3:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getMidtermGrade() > maximumgrade.getMidtermGrade()) {
                maximumgrade = temp[i];
            }
        }
        break;
    case 4:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getFinalGrade() > maximumgrade.getFinalGrade()) {
                maximumgrade = temp[i];
            }
        }
        break;
    case 5:
        for (int i = 0; i < 20; i++) {
            if (temp[i].getOverallGrade() > maximumgrade.getOverallGrade()) {
                maximumgrade = temp[i];
            }
        }
        break;


    } // switch
    return maximumgrade;

}

/**
 * This function returns the average score of the
 * specified grade type.
 *
 *
 * @param gradeType the specified gradetype
 * @return avg a double that is the average of the specified gradetype
 */
double Instructor::getAvg(int gradeType) {
    Student temp[20];
    string username2, password2, first, last;
    int proj, q2, midt, fin, i = 0;
    ifstream inStudentFile2("students.txt");
    while (inStudentFile2 >> username2 >> password2 >> first >> last >> proj >> q2 >> midt >> fin) {
        temp[i].setUserName(username2);
        temp[i].setPassword(password2);
        temp[i].setStudentName(first + " " + last);
        temp[i].setProjectGrade(proj);
        temp[i].setQuizGrade(q2);
        temp[i].setMidtermGrade(midt);
        temp[i].setFinalGrade(fin);
        i++;
    } // while

    double avg = 0.0;
    switch(gradeType) { // switch for each grade type
    case 1:

        for (int i = 0; i < 20; i++) {
            avg += temp[i].getProjectGrade();
        }
        avg = avg /20;
        break;
    case 2:
        for (int i = 0; i < 20; i++) {
            avg += temp[i].getQuizGrade();
        }
        avg /= 20;

        break;
    case 3:
        for (int i = 0; i < 20; i++) {
            avg += temp[i].getMidtermGrade();
        }
        avg /= 20;

        break;
    case 4:
        for (int i = 0; i < 20; i++) {
            avg += temp[i].getFinalGrade();
        }
        avg /= 20;

        break;
    case 5:
        for (int i = 0; i < 20; i++) {
            avg += temp[i].getOverallGrade();
        }
        avg /= 20;
        break;


    } // switch
    return avg;

}

/**
 * Sets the instructors name
 *
 * @param name instructors name
 */
void Instructor::setInstructorName(string name) {
    IFullnameN = name;
}
/**
 * sets the instructors password
 *
 * @param password instructors password
 */
void Instructor::setInstructorPassword(string password) {
    IPasswordN = password;
}

/**
 * sets the instructors username
 *
 * @param username the instructors username
 */
void Instructor::setInstructorUsername(string username) {
    IUserName = username;
}
