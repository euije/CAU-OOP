#include <string>
#include "student_info.h"

using namespace std;

bool StudentInfo::isValidYear(string _year)
{
    // if _year is not 4 length string
    if (_year.length() != 4)
        return false;

    // if _year has an empty string
    if (_year.find(" ") != string::npos)
        return false;

    // if _year string has non-digits
    if (!StudentInfo::isHasOnlyDigit(_year))
        return false;

    // if _year is not number && not 1900 <= _year <= 2022
    int _year_num = stoi(_year);
    if (!(1900 <= _year_num && _year_num <= 2022))
        return false;

    return true;
}

bool StudentInfo::isHasOnlyDigit(string number)
{
    /*
        "" -> false
        "aaaa" -> false
        "aa11" -> false
        "1111" -> true
    */
    if (number.length() == 0)
        return false;

    for (int i = 0; i < number.length(); i++)
    {
        if (!('0' <= number[i] && number[i] <= '9'))
            return false;
    }

    return true;
}

bool StudentInfo::isHasOnlyAlphabet(string name)
{
    /*
        "" -> false
        "aaaa" -> true
        "aa11" -> false
        "1111" -> false
    */
    if (name.length() == 0)
        return false;

    for (int i = 0; i < name.length(); i++)
    {
        if (!('a' <= name[i] && name[i] <= 'z') && !('A' <= name[i] && name[i] <= 'Z'))
            return false;
    }

    return true;
}

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
    return this->department;
}
string StudentInfo::getTel()
{
    return this->tel;
}

bool StudentInfo::isValidName(string _name)
{
    /*
        "Name" has up to 15 (English) characters
        "Name" should not be blank.
    */

    // if _name is blank
    if (_name.length() == 0)
        return false;

    // string removed blank from _name
    string nameNoSpace;
    while (1)
    {
        if (_name.find(" ") != string::npos)
        {
            _name = _name.erase(_name.find(" "), 1);
        }
        else
        {
            nameNoSpace = _name;
            break;
        }
    }

    // if _name_no_space string has non-alphabet
    if (!StudentInfo::isHasOnlyAlphabet(nameNoSpace))
        return false;

    // if nameNoSpace is longer than MAX_NAME_LEGNTH(15)
    return nameNoSpace.length() <= MAX_NAME_LEGNTH;
}

bool StudentInfo::isValidStudentID(string _studentID)
{
    /*
        "Student ID" should be exactly 10 digits
            where first 4 digits represent addmission year.
        "Student ID" should not be blank.
    */

    // if _studentID is blank
    if (_studentID.length() == 0)
        return false;

    // if _studentID has an empty string
    if (_studentID.find(" ") != string::npos)
        return false;

    // if _studentID string has no digits
    if (!StudentInfo::isHasOnlyDigit(_studentID))
        return false;

    // if admissionYear is valid
    if (!StudentInfo::isValidYear(_studentID.substr(0, 4)))
        return false;

    // if _studentID's length is equal to STUDENT_ID_LENGTH(10)
    return _studentID.length() == STUDENT_ID_LENGTH;
}

bool StudentInfo::isValidBirthYear(string _birthYear)
{
    /*
        "Birth Year" should be exactly 4 digits.
        "Birth Year" is nullable
    */
    if(_birthYear.length() == 0)
        return true;

    return StudentInfo::isValidYear(_birthYear);
}

bool StudentInfo::isValidDepartment(string _department)
{
    return _department.length() <= MAX_DEPARTMENT_LENGTH;
}

bool StudentInfo::isValidTel(string _tel)
{
    /*
        "Tel" has up to 12 digits
    */

    // "Tel" is nullable
    if(_tel.length() == 0)
        return true;

    // if _tel has an empty string
    if (_tel.find(" ") != string::npos)
        return false;

    // if _tel string has non-digits
    if (!StudentInfo::isHasOnlyDigit(_tel))
        return false;

    // if _tel's length is not equal to MAX_TEL_LEGNTH(12)
    return _tel.length() <= MAX_TEL_LEGNTH;
}

StudentInfo::StudentInfo(string _name, string _studentID, string _birthYear, string _department, string _tel)
{
    this->name = _name;
    this->studentID = _studentID;
    this->birthYear = _birthYear;
    this->department = _department;
    this->tel = _tel;
}

/**
 * @brief Returns the result of comparison with student's field and keyword
 *
 * @param searchOption (1, name), (2, studentID), (3, studentID[0-4]), (4, department), (5, ALL)
 * @param keyword keyword given to search for specific field with searchOption
 * @return result of string.compare() as true/false
 */
bool StudentInfo::isSameKeyword(int searchOption, string keyword)
{
    int compareResult = -1;

    if (searchOption == 1)
    {
        compareResult = this->getName().compare(keyword);
    }
    else if (searchOption == 2)
    {
        compareResult = this->getStudentID().compare(keyword);
    }
    else if (searchOption == 3)
    {
        string admissionYear = this->getStudentID().substr(0, 4);
        compareResult = admissionYear.compare(keyword);
    }
    else if (searchOption == 4)
    {
        compareResult = this->getDepartment().compare(keyword);
    }
    else if (searchOption == 5)
    {
        compareResult = 0;
    }

    if (compareResult == 0)
        return true;
    else
        return false;
}