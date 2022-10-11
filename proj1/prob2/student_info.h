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
class StudentInfo
{
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

    string getName() { return this->name; }
    string getStudentID() { return this->studentID; }
    string getBirthYear() { return this->birthYear; }
    string getDepartment() { return this->department; }
    string getTel() { return this->tel; }

    void setName(string _name) { this->name = _name; }
    void setStudentID(string _studentID) { this->studentID = _studentID; }
    void setBirthYear(string _birthYear) { this->birthYear = _birthYear; }
    void setDepartment(string _department) { this->department = _department; }
    void setTel(string _tel) { this->tel = _tel; }

    static bool isValidName(string _name);
    static bool isValidStudentID(string _studentID);
    static bool isValidBirthYear(string _birthYear);
    static bool isValidDepartment(string _department);
    static bool isValidTel(string _tel);

    static int compareName(StudentInfo a, StudentInfo b);
    static int compareStudentID(StudentInfo a, StudentInfo b);
    static int compareAdmissionYear(StudentInfo a, StudentInfo b);
    static int compareDepartment(StudentInfo a, StudentInfo b);

    bool isSameKeyword(int searchOption, string keyword);
};

#endif