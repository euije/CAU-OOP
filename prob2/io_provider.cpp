#include "io_provider.h"
#include "student_info.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void IOProvider::printWrongInputError(int error)
{
    string fields[7] = {
        "",
        "Student name",
        "Student ID",
        "Admission year",
        "Department name",
        "Birth Year",
        "Tel"};

    cout << '\n'
         << "You write wrong " << fields[error] << "." << endl;
    cout << "Please enter " << fields[error] << " again." << endl;
}

void IOProvider::printWrongOptionError(char lowerBound, char upperBound)
{
    cout << '\n';
    cout << "*Caution! You write number with wrong range!" << endl;
    cout << "Please write the number between " << lowerBound << " and " << upperBound << '\n'
         << endl;
}

void IOProvider::inputValidOption(int *option, char lowerBound, char upperBound)
{
    string input;

    while (1)
    {
        cout << "> ";
        std::getline(cin, input);

        if (input.length() == 1)
        {
            if (lowerBound <= input[0] && input[0] <= upperBound){
                *option = input[0] - '0';
                return;
            }
        }

        IOProvider::printWrongOptionError(lowerBound, upperBound);
    }
}

void IOProvider::inputValidSearchKeyword(int option, string *keyword)
{
    // option is only between 1 and 4
    string fields[5] = {
        "",
        "Student name",
        "Student ID",
        "Admission year",
        "Department name"};

    while (1)
    {
        cout << '\n'
             << fields[option] << " keyword? ";
        std::getline(cin, *keyword);

        if (option == 1)
        {
            // name
            if (StudentInfo::isValidName(*keyword))
                break;
            else
            {
                IOProvider::printWrongInputError(1);
            }
        }
        else if (option == 2)
        {
            // student ID
            if (StudentInfo::isValidStudentID(*keyword))
                break;
            else
            {
                IOProvider::printWrongInputError(2);
            }
        }
        else if (option == 3)
        {
            // admission year
            if (StudentInfo::isValidStudentID(*keyword + "000000"))
                break;
            else
            {
                IOProvider::printWrongInputError(3);
            }
        }
        else if (option == 4)
        {
            // department
            if (StudentInfo::isValidDepartment(*keyword))
                break;
            else
            {
                IOProvider::printWrongInputError(4);
            }
        }
        else
        {
            cout << "Program went something wrong." << endl;
            break;
        }
    }
}

void IOProvider::IOMainMenu(int *option)
{
    cout << "1. Insertion" << endl;
    cout << "2. Search" << endl;
    cout << "3. Sorting Option" << endl;
    cout << "4. Exit" << endl;

    IOProvider::inputValidOption(option, '1', '4');

    cout << endl;
}

void IOProvider::IOInsertion(StudentInfo* student, vector<StudentInfo> instances)
{
    string input;

    bool isExist = false;

    while(1){
        cout << "Name ";
        std::getline(cin, input);
        
        if(StudentInfo::isValidName(input)){
            student->setName(input);
            break;
        }

        this->printWrongInputError(1); cout << endl;
    }

    while(1){
        cout << "Student ID (10 digits) ";
        std::getline(cin, input);

        for(int i = 0; i < instances.size(); i++){
            if(instances[i].getStudentID().compare(input) == 0){
                isExist = true;
                continue;
            }
        }
        if(isExist){
            cout << "Error : Already inserted\n" << endl;
            isExist = false;
            continue;
        }

        if(StudentInfo::isValidStudentID(input) && !isExist){
            student->setStudentID(input);
            break;
        }

        this->printWrongInputError(2); cout << endl;
    }

    while(1){
        cout << "Birth Year (4 digits) ";
        std::getline(cin, input);
        
        if(StudentInfo::isValidBirthYear(input)){
            student->setBirthYear(input);
            break;
        }

        this->printWrongInputError(5); cout << endl;
    }

    while(1){
        cout << "Department ";
        std::getline(cin, input);
        
        if(StudentInfo::isValidDepartment(input)){
            student->setDepartment(input);
            break;
        }

        this->printWrongInputError(4); cout << endl;
    }

    while(1){
        cout << "Tel ";
        std::getline(cin, input);
        
        if(StudentInfo::isValidTel(input)){
            student->setTel(input);
            break;
        }

        this->printWrongInputError(6); cout << endl;
    }
}

void IOProvider::IOSearch(int *option, string *keyword)
{
    cout << "- Search -" << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by student ID (10 numbers)" << endl;
    cout << "3. Search by admission year (4 numbers)" << endl;
    cout << "4. Search by department name" << endl;
    cout << "5. List All" << '\n'
         << endl;

    IOProvider::inputValidOption(option, '1', '5');

    /* handling search option */
    if (1 <= *option && *option <= 4)
    {
        IOProvider::inputValidSearchKeyword(*option, keyword);
    }
    else if (*option == 5)
    {
        *keyword = "";
    }
    else
    {
        cout << "Program went something wrong." << endl;
    }
}

void IOProvider::IOSorting(int* option){
    cout << "- Sorting Option -" << endl;
    cout << "1. Sort by Name" << endl;
    cout << "2. Sort by Student ID" << endl;
    cout << "3. Sort by Admission Year" << endl;
    cout << "4. Sort by Department name" << endl;
    
    IOProvider::inputValidOption(option, '1', '4');

    cout << endl;
}

void IOProvider::outputStudentsInfoWithOption(vector<StudentInfo> students, int searchOption, string keyword)
{
    cout << '\n'
         << "<-------------- Start Of Search -------------->" << '\n'
         << endl;

    cout << setw(20) << left << "  Name";
    cout << " ";
    cout << setw(10) << right << "StudentID";
    cout << " ";
    cout << setw(30) << left << "  Dept";
    cout << " ";
    cout << setw(10) << right << "Birth Year";
    cout << " ";
    cout << setw(10) << left << " Tel" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].isSameKeyword(searchOption, keyword))
        {
            IOProvider::printStudentInfoFormatted(students[i]);
        }
    }

    cout << '\n'
         << "<-------------- End Of Search -------------->" << '\n'
         << endl;
}

void IOProvider::printStudentInfoFormatted(StudentInfo student)
{
    string _name = student.getName();
    string _studentID = student.getStudentID();
    string _department = student.getDepartment();
    string _birthYear = student.getBirthYear();
    string _tel = student.getTel();

    cout << setw(20) << left << _name;
    cout << " ";
    cout << setw(10) << right << _studentID;
    cout << " ";
    cout << setw(30) << left << _department;
    cout << " ";
    cout << setw(10) << right << _birthYear;
    cout << " ";
    cout << setw(10) << left << _tel << endl;
}