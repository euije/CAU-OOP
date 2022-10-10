#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>

using namespace std;

#define MAX_NAME_LEGNTH 15
#define STUDENT_ID_LENGTH 10
#define BIRTH_YEAR_LENGTH 4
#define MAX_DEPARTMENT_LENGTH 1000
#define MAX_TEL_LEGNTH 12

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

    static bool isValidYear(string _year);
    static bool isHasOnlyDigit(string number);
    static bool isHasOnlyAlphabet(string name);

public:
    StudentInfo(string _name, string _studentID, string _birthYear, string _department, string _tel);

    string getName();
    string getStudentID();
    string getBirthYear();
    string getDepartment();
    string getTel();
    
    static bool isValidName(string _name);
    static bool isValidStudentID(string _studentID);
    static bool isValidBirthYear(string _birthYear);
    static bool isValidDepartment(string _department);
    static bool isValidTel(string _tel);

    bool isSameKeyword(int searchOption, string keyword);
};

#endif