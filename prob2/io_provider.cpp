#include "io_provider.h"
#include "student_info.h"
#include <iostream>
#include <vector>

using namespace std;

void IOProvider::outputMainMenu(){
    cout << "1. Insertion" << endl;
    cout << "2. Search" << endl;
    cout << "3. Sorting Option" << endl;
    cout << "4. Exit" << endl;
    cout << "> ";
}

void IOProvider::inputMainMenu(){
    cin >> this->mainMenuOption;
}

void IOProvider::IOinsertion(){

    cout << "Name ";
}

void IOProvider::outputStudentInfo(vector<StudentInfo> students, int searchOption, string keyword){
    cout << "Name" << "StudentID" << "Dept" << "Birth Year" << "Tel" << endl;

    for(int i = 0; i < students.size(); i++){
        if(isSameKeyword(students[i], searchOption, keyword)){
            printStudentInfoFormatted(students[i]);
        }
    }
}

void IOProvider::printStudentInfoFormatted(StudentInfo student){
    string _name = student.getName();
    string _studentID = student.getStudentID();
    string _department = student.getDepartment();
    string _birthYear = student.getBirthYear();
    string _tel = student.getTel();

    cout << _name << _studentID << _department << _birthYear << _tel << endl;
}