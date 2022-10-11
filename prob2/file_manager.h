#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define TOKEN_DIVIDER '/'

#include <fstream>
#include <string>
#include <vector>
#include "student_info.h"

class FileManager {
private:
    string path;
    fstream fs;
    ofstream ofs;

public:
    string getPath();
    bool isStreamOpen();
    void coutFileStreamError();

    void openFileStream(char* filename);
    void closeFileStream();
    void getStudentInstancesFromFile(vector<StudentInfo>& list);
    void outputStudentInfoToFile(StudentInfo student);

    void sortInstancesWithOption(vector<StudentInfo>& instances, int option);
};

#endif