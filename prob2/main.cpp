#include <iostream>
#include <vector>
#include "io_provider.h"
#include "student_info.h"

using namespace std;

void TestStudentSearch()
{
    IOProvider provider;
    vector<StudentInfo> students;

    StudentInfo student1 = StudentInfo("Lisa Simpson", "2006303001", "Computer Engineering", "2000", "01012345678");
    StudentInfo student2 = StudentInfo("Gildong Hong", "2004303077", "Computer Engineering", "1999", "01187651234");
    StudentInfo student3 = StudentInfo("Euije Lee", "2019019718", "Computer Engineering", "2000", "01064082153");
    ;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

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

int main(int argc, char **argv)
{
    IOProvider provider;
    vector<StudentInfo> students;

    int mainMenuOption = -1;
    int insertionOption;
    int searchOption;
    int sortingOption;

    string searchKeyword;

    StudentInfo student1 = StudentInfo("Lisa Simpson", "2006303001", "2000", "Computer Engineering", "01012345678");
    StudentInfo student2 = StudentInfo("Gildong Hong", "2004303077", "1999", "Computer Engineering", "01187651234");
    StudentInfo student3 = StudentInfo("Euije Lee", "2019019718", "2000", "Computer Engineering", "01064082153");

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    while (1)
    {
        provider.IOMainMenu(&mainMenuOption);

        if (mainMenuOption == 1)
        {
        }
        else if (mainMenuOption == 2)
        {
            provider.IOSearch(&searchOption, &searchKeyword);
            provider.outputStudentsInfoWithOption(students, searchOption, searchKeyword);
        }
        else if (mainMenuOption == 3)
        {
            
        }
        else if (mainMenuOption == 4)
        {
            break;
        }
        else
        {
            cout << "Program went something wrong." << endl;
        }
    }

    return 0;
}