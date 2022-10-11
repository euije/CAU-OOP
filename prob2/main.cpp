#include <iostream>
#include "io_provider.h"
#include "student_info.h"
#include "file_manager.h"

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 2){
        cout << "*Caution! : Please write exactly one file name" << endl;
        return -1;
    }
    
    FileManager manager;
    vector<StudentInfo> students;
    IOProvider provider;

    int mainMenuOption = 4;
    int searchOption = 5;
    int sortingOption = 1;

    string searchKeyword = "";

    manager.openFileStream(argv[1]);
    manager.getStudentInstancesFromFile(students);
    manager.sortInstancesWithOption(students, 1);

    while (1)
    {
        provider.IOMainMenu(&mainMenuOption);

        if (mainMenuOption == 1)
        {
            StudentInfo temp = StudentInfo("", "", "", "", "");
            provider.IOInsertion(&temp, students);
            students.push_back(temp);
            manager.outputStudentInfoToFile(temp);
            manager.sortInstancesWithOption(students, sortingOption);
        }
        else if (mainMenuOption == 2)
        {
            provider.IOSearch(&searchOption, &searchKeyword);
            provider.outputStudentsInfoWithOption(students, searchOption, searchKeyword);
        }
        else if (mainMenuOption == 3)
        {
            provider.IOSorting(&sortingOption);
            manager.sortInstancesWithOption(students, sortingOption);
        }
        else if (mainMenuOption == 4)
        {
            manager.closeFileStream();
            break;
        }
        else
        {
            cout << "Program went something wrong." << endl;
        }
    }

    return 0;
}