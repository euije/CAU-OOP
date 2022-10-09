#include <iostream>
#include <vector>
#include "io_provider.h"
#include "student_info.h"

using namespace std;

int main(int argc, char **argv){
    IOProvider provider;
    vector<StudentInfo> students;

    StudentInfo student1 = StudentInfo("Lisa Simpson", "2006303001", "Computer Engineering", "2000", "01012345678");
    StudentInfo student2 = StudentInfo("Gildong Hong", "2004303077", "Computer Engineering", "1999", "01187651234");
    StudentInfo student3 = StudentInfo("Euije Lee", "201901978", "Computer Engineering", "2000", "01064082153");;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    provider.outputMainMenu();
    // provider.inputMainMenu();
    provider.outputStudentInfo(students, 5, "");

    return 0;
}