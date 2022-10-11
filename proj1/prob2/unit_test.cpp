#include "unit_test.h"

void TestStudentSearch()
{
    IOProvider provider;
    vector<StudentInfo> students;

    StudentInfo student1 = StudentInfo("Lisa Simpson", "2006303001", "2000", "Computer Engineering", "01012345678");
    StudentInfo student2 = StudentInfo("Gildong Hong", "2004303077", "1999", "Computer Engineering", "01187651234");
    StudentInfo student3 = StudentInfo("Euije Lee", "2019019718", "1999", "Computer Engineering", "01064082153");
    StudentInfo student4 = StudentInfo("Einstein", "1990123458", "1998", "Physics", "01064090000");
    StudentInfo student5 = StudentInfo("Srinivasan", "2003123456", "2003", "Electronic Engineering", "01064069999");
    StudentInfo student6 = StudentInfo("Califieri", "2004122456", "2001", "Biology", "01064075000");
    StudentInfo student7 = StudentInfo("Mozart", "2007123456", "1995", "Music", "01064087000");

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);
    students.push_back(student6);
    students.push_back(student7);

    provider.outputStudentsInfoWithOption(students, 1, "Lisa Simpson");
    provider.outputStudentsInfoWithOption(students, 2, "2019019718");
    provider.outputStudentsInfoWithOption(students, 3, "2004");
    provider.outputStudentsInfoWithOption(students, 4, "1999");
    provider.outputStudentsInfoWithOption(students, 5, "");
}

void TestStudentInfoValidation()
{
    string input;

    std::getline(cin, input);

    /* private methods
        cout << "isValidYear : " << (StudentInfo::isValidYear(input) ? "true" : "false") << endl;
        cout << "isHasOnlyDigit : " << (StudentInfo::isHasOnlyDigit(input) ? "true" : "false") << endl;
        cout << "isHasOnlyAlphabet : " << (StudentInfo::isHasOnlyAlphabet(input) ? "true" : "false") << '\n' << endl;
    */

    cout << "isValidName : " << (StudentInfo::isValidName(input) ? "true" : "false") << endl;
    cout << "isValidStudentID : " << (StudentInfo::isValidStudentID(input) ? "true" : "false") << endl;
    cout << "isValidBirthYear : " << (StudentInfo::isValidBirthYear(input) ? "true" : "false") << endl;
    cout << "isValidDepartment : " << (StudentInfo::isValidDepartment(input) ? "true" : "false") << endl;
    cout << "isValidTel : " << (StudentInfo::isValidTel(input) ? "true" : "false") << endl;
}