#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>

using namespace std;

#define NAME_MAX_LEGNTH 15
#define STUDENT_ID_LENGTH 10
#define BIRTH_YEAR_LENGTH 4
#define DEPARTMENT_LENGTH
#define TEL_MAX_LEGNTH 12

/**
 * @brief Class that contains information of student
 * 
 * @param name not nullable, up to 15
 * @param studentID not nullable, exactly 10, 
 * @param birthYear exactly 4
 * @param department up to string.MAX_LENGTH
 * @param tel up to 12
 */
class StudentInfo {
private:
    string name;
    string studentID;
    string birthYear;
    string department;
    string tel;

public:
    StudentInfo(string _name, string _studentID, string _birthYear, string _department, string _tel);

    string getName();
    string getStudentID();
    string getBirthYear();
    string getDepartment();
    string getTel();

    int isSameKeyword(StudentInfo student, int searchOption, string keyword);
};

#endif