#ifndef IO_PROVIDER_H
#define IO_PROVIDER_H

#include "student_info.h"
#include <vector>

class IOProvider {
private:
    int mainMenuOption;
    int insertionOption;
    int searchOption;
    int sortingOption;

public:
    void outputMainMenu();
    void inputMainMenu();
    void IOinsertion();
    void outputStudentInfo(vector<StudentInfo> students, int searchOption, string keyword);

    int isSameKeyword(StudentInfo student, int searchOption, string keyword);
    void printStudentInfoFormatted(StudentInfo student);
};
#endif