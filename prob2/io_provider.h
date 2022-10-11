#ifndef IO_PROVIDER_H
#define IO_PROVIDER_H

#include "student_info.h"
#include <vector>

class IOProvider {
private:
    static void inputValidOption(int *option, char lowerBound, char upperBound);
    static void inputValidSearchKeyword(int option, string* keyword);
    static void printWrongInputError(int error);
    static void printWrongOptionError(char lowerBound, char upperBound);

public:
    void IOMainMenu(int* option);
    void IOInsertion(StudentInfo* student, vector<StudentInfo> instances);
    void IOSearch(int* option, string* keyword);
    void IOSorting(int* option);

    void outputStudentsInfoWithOption(vector<StudentInfo> students, int searchOption, string keyword);
    static void printStudentInfoFormatted(StudentInfo student);
};
#endif