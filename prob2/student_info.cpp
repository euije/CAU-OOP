#include <string>
#include "student_info.h"

using namespace std;

string StudentInfo::getName()
{
    return this->name;
}
string StudentInfo::getStudentID()
{
    return this->studentID;
}
string StudentInfo::getBirthYear()
{
    return this->birthYear;
}
string StudentInfo::getDepartment()
{
    return this->deparment;
}
string StudentInfo::getTel()
{
    return this->tel;
}

StudentInfo::StudentInfo(string _name, string _studentID, string _birthYear, string _department, string _tel){
    this->name = _name;
    this->studentID = _studentID;
    this->birthYear = _birthYear;
    this->department = _department;
    this->tel = _tel;
}

/**
 * @brief Returns the result of comparison with student's field and keyword
 * 
 * @param student the instance of the information of a student
 * @param searchOption (1, name), (2, studentID), (3, studentID[0-4]), (4, department), (5, ALL)
 * @param keyword keyword given to search for specific field with searchOption
 * @return result of string.compare()
 */
int StudentInfo::isSameKeyword(StudentInfo student, int searchOption, string keyword){
    if(searchOption == 1){
        return student.getName().compare(keyword);
    }
    else if(searchOption == 2){
        return student.getStudentID().compare(keyword);
    }
    else if(searchOption == 3){
        string admissionYear = student.getStudentID().substr(0, 4);
        return admissionYear.compare(keyword);
    }
    else if(searchOption == 4){
        return student.getDepartment().compare(keyword);
    }
    else if(searchOption == 5){
        return 1;
    }
    
    return 0;
}