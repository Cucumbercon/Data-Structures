#include "Student.h"
#include "Instructor.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * Main method allows user to login as a student or
 * instructor and view student grades
 *
 * @param argc number of userinput
 * @param argv file names
 * @return int status
 */
int main(int argc, char* argv[]) {
    int i = 0; //counter
    int k = 0; // counter
    char gradeinput; // char input variable
    int userType = 0; // int input variable
    string userinputname, userinputp;// string input variables

    Student Sarr[20]; // initializing student object array
    Instructor Iarr[3]; // initializing instructor object array

    if (argc > 3) { // checks amount of args
        cerr << "too many arguments, should only have 2 files" << endl;
        exit(1);
    }

    ifstream inInstructorFile(argv[1], ios::in); // set Instructor.txt to inInstructorFile
    ifstream inStudentFile(argv[2], ios::in); // set Student.txt to inStudentFile

    if (!inStudentFile || !inInstructorFile) { // checks args
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    string Iusername, Ipassword, IFirstname, ILastname; // Iarr variables
    string Susername, Spassword, SFirstname, SLastname; // Sarr variables
    int projectgrade, quizgrade, midtermgrade, finalgrade; // Sarr gradetypes

    while(userType != 3) { // While to keep looping back to usertype login
        cout << "User types, " << endl;
        cout << "     1 - Instructor" << endl;
        cout << "     2 - Student   " << endl;
        cout << "Select a login user type or enter 3 to exit: ";
        cin >> userType;
        cout << "\n";


        while (inInstructorFile >> Iusername >> Ipassword >> IFirstname >> ILastname) {
            Iarr[k].setInstructorUsername(Iusername);
            Iarr[k].setInstructorPassword(Ipassword);
            Iarr[k].setInstructorName(IFirstname + " " + ILastname);
            k++;
        } // initializing all Instructor variable in Iarr array


        while (inStudentFile >> Susername >> Spassword >> SFirstname >> SLastname >>
        projectgrade >> quizgrade >> midtermgrade >> finalgrade) {
            Sarr[i].setUserName(Susername);
            Sarr[i].setPassword(Spassword);
            Sarr[i].setStudentName(SFirstname + " " + SLastname);
            Sarr[i].setProjectGrade(projectgrade);
            Sarr[i].setQuizGrade(quizgrade);
            Sarr[i].setMidtermGrade(midtermgrade);
            Sarr[i].setFinalGrade(finalgrade);
            i++;
        } // initializing all Student variables in Sarr array


        if (userType == 1) { // beginning of instructor login
            // Instructor login welcome asks for input
            cout << "Enter credentials to login, " << endl;
            cout << "        Enter username: ";
            cin >> userinputname;
            cout << "        Enter password: ";
            cin >> userinputp;
            cout << "\n";

            int instructorinput = 0;
            int l;
            for (l = 0; l < 3; l++) { // looping instructor object array for matching username/pass
                if (Iarr[l].login(userinputname, userinputp) == 1) {
                    cout << "You are now logged in as instructor " <<
                        Iarr[l].getInstructorName() << "\n" <<endl;


                    while ((instructorinput < 1) || (instructorinput > 2)) { // while check if valid
                        cout << "Query options, " << endl;
                        cout << "       1 - view grades of a student" << endl;
                        cout << "       2 - view stats" << endl;
                        cout << "Enter option number: ";
                        cin >> instructorinput;
                        cout << "\n";


                        if ((instructorinput < 1) || (instructorinput > 2)) {
                            cout << "Invalid option. Please enter a valid option.\n " << endl;

                        }

                    }


                    if (instructorinput == 1) { // Input for specific students GRADES
                        int b;
                        string instructorinputS = " ";
                        int CheckS = 0;
                        while (CheckS != 1) { // while loop for invalid input
                            cout << "Enter student username to view grades: ";
                            cin >> instructorinputS;
                            cout << "\n";

                            for (b = 0; b < 20; b++) {
                                if (instructorinputS == Sarr[b].getUserName()) {
                                    CheckS = 1;
                                    break;
                                }
                            }
                            if (b == 20) {
                                cout << "Student username is not vaild\n" << endl;
                            }

                        }



                        for (int i = 0; i < 20; i++) { // looping array for matching student user
                            if (instructorinputS == Sarr[i].getUserName()) { // prints student/grade
                                cout << "Student name: " << Sarr[i].getStudentName()
                                     << endl;
                                cout << "        Project    " << Sarr[i].getProjectGrade() <<
                                    "%" << endl;
                                cout << "        Quiz       " << Sarr[i].getQuizGrade()    <<
                                    "%" << endl;
                                cout << "        Midterm    " << Sarr[i].getMidtermGrade() <<
                                    "%" << endl;
                                cout << "        Final      " << Sarr[i].getFinalGrade() <<
                                    "%" << endl;
                                cout << "        Overall    " << Sarr[i].getOverallGrade()
                                     << "%\n" << endl;
                                break;
                            }

                        }

                    } else if (instructorinput == 2) { // input for GRADE stats
                        Instructor instructorobject;
                        int u;
                        int check2 = 0;
                        while (check2 != 1) { // while for invalid input
                            cout << "Grade types," << endl;
                            cout << "        1 - Project grade" << endl;
                            cout << "        2 - Quiz grade" << endl;
                            cout << "        3 - Midterm grade" << endl;
                            cout << "        4 - Final grade" << endl;
                            cout << "        5 - Overall grade" << endl;
                            cout << "Select a grade type to view stats: ";
                            cin >> u;
                            Student Sgrade = instructorobject.getMinStudent(u);
                            Student Maxgrade = instructorobject.getMaxStudent(u);
                            double avg = instructorobject.getAvg(u);
                            cout << "\n";

                            if (u < 6 && u > 0) { // if statement for invalid/valid input
                                switch (u) { // switch for grade stats
                                case 1:
                                    cout << "Project grade stats, " << endl;

                                    cout << "        min     " << Sgrade.getProjectGrade()
                                         << "% (" << Sgrade.getStudentName() << ")\n";
                                    cout << "        max     " << Maxgrade.getProjectGrade()
                                         << "% (" << Maxgrade.getStudentName() << ")\n";
                                    cout << "        avg     " << avg
                                         << "%\n" << endl;

                                    check2 = 1;
                                    break;
                                case 2:
                                    cout << "Quiz grade stats, " << endl;

                                    cout << "        min     " << Sgrade.getQuizGrade()
                                         << "% (" << Sgrade.getStudentName() << ")\n";
                                    cout << "        max     " << Maxgrade.getQuizGrade()
                                         << "% (" << Maxgrade.getStudentName() << ")\n";
                                    cout << "        avg     " << avg
                                         << "%\n" << endl;

                                    check2 = 1;
                                    break;
                                case 3:
                                    cout << "Midterm grade stats, " << endl;

                                    cout << "        min     " << Sgrade.getMidtermGrade()
                                         << "% (" << Sgrade.getStudentName() << ")\n";
                                    cout << "        max     " << Maxgrade.getMidtermGrade()
                                         << "% (" << Maxgrade.getStudentName() << ")\n";
                                    cout << "        avg     " << avg
                                         << "%\n" << endl;

                                    check2 = 1;
                                    break;
                                case 4:
                                    cout << "Final grade stats, " << endl;

                                    cout << "        min     " << Sgrade.getFinalGrade()
                                         << "% (" << Sgrade.getStudentName() << ")\n";
                                    cout << "        max     " << Maxgrade.getFinalGrade()
                                         << "% (" << Maxgrade.getStudentName() << ")\n";
                                    cout << "        avg     " << avg
                                         << "%\n" << endl;

                                    check2 = 1;
                                    break;

                                case 5:
                                    cout << "Overall grade stats, " << endl;

                                    cout << "        min     " << Sgrade.getOverallGrade()
                                         << "% (" << Sgrade.getStudentName() << ")\n";
                                    cout << "        max     " << Maxgrade.getOverallGrade()
                                         << "% (" << Maxgrade.getStudentName() << ")\n";
                                    cout << "        avg     " << avg
                                         << "%\n" << endl;
                                    check2 = 1;
                                    break;
                                }

                            } else {
                                cout << "Invalid option. Please enter a valid option.\n" << endl;
                            }
                        }
                    }
                    break;
                }
            }
            if (l == 3) {
                cout << "Login as instructor failed." << "\n" << endl;
            }
        }

        if (userType == 2) { // Beginning of student login
            cout << "Enter credentials to login, " << endl;
            cout << "        Enter username: ";
            cin >> userinputname;
            cout << "        Enter password: ";
            cin >> userinputp;
            cout << "\n";


            int j;
            for (j = 0; j < 20; j++) {

                if (Sarr[j].login(userinputname, userinputp) == 1) { // view student grades
                    cout << "You are now logged in as student " << Sarr[j].getStudentName() << endl;
                    cout << "\n";
                    cout << "Do you want to view grades (y/n)? ";
                    cin >> gradeinput;
                    cout << "\n";
                    if (gradeinput == 'y') {
                        cout << "Student name: " << Sarr[j].getStudentName() << "\n";
                        cout << "        Project " << Sarr[j].getProjectGrade() << "%\n";
                        cout << "        Quiz    " << Sarr[j].getQuizGrade() << "%\n";
                        cout << "        Midterm " << Sarr[j].getMidtermGrade() << "%\n";
                        cout << "        Final   " << Sarr[j].getFinalGrade() << "%\n";
                        cout << "        Overall " << Sarr[j].getOverallGrade() << "%\n" << endl;

                        break;
                    } else {
                        break;
                    }
                }
            }
            if (j == 20) {
                cout << "Login as student failed.\n" << endl;

            } // cycles through Sarr array to see if username/password matches

        } else if (userType == 3) { // exits if userType is 3
            exit(0);
        } else if (userType < 1 || userType > 3) {
            cerr << "Invalid option. Please enter a valid option." << endl;
            cout << "\n";
        } // invaild option if statement
    } // while method
} // Main
