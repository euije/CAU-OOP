#include <algorithm>
#include <vector>
#include <sstream>
#include "student_info.h"
#include "file_manager.h"

void FileManager::sortInstancesWithOption(vector<StudentInfo> &instances, int option)
{
    if (option == 1)
    {
        std::sort(instances.begin(), instances.end(), StudentInfo::compareName);
    }
    else if (option == 2)
    {
        std::sort(instances.begin(), instances.end(), StudentInfo::compareStudentID);
    }
    else if (option == 3)
    {
        std::sort(instances.begin(), instances.end(), StudentInfo::compareAdmissionYear);
    }
    else if (option == 4)
    {
        std::sort(instances.begin(), instances.end(), StudentInfo::compareDepartment);
    }
    else
    {
        std::sort(instances.begin(), instances.end(), StudentInfo::compareName);
    }
}

string FileManager::getPath()
{
    return this->path;
}

bool FileManager::isStreamOpen(){
    return this->fs.is_open();
}

void FileManager::coutFileStreamError(){
    cout << "FileStream Error: Please do openFileStream() first\n" << endl;
}

void FileManager::openFileStream(char *filename)
{
    while (1)
    {
        this->fs.open(filename);

        if (this->fs.is_open())
        {
            cout << "You open " << filename << " file successfully!\n" << endl;
            this->ofs.open(filename, ios::app);
            this->path = filename;
            break;
        }
        else
        {
            cout << filename << " doesn't exist in this directory" << endl;
            ofstream ofs(filename);
            if (ofs.is_open())
            {
                cout << filename << " file has successfully created" << endl;
                ofs.close();
            }
        }
    }
}

void FileManager::closeFileStream(){
    this->fs.close();
    this->ofs.close();
}

void FileManager::getStudentInstancesFromFile(vector<StudentInfo>& list){
    if(!this->isStreamOpen()){
        this->coutFileStreamError();
        return;
    }

    char line[256];
    while(this->fs.getline(line, 256)){
        istringstream ss(line);
        string stringBuffer;

        string info[5];

        for(int i = 0; getline(ss, stringBuffer, TOKEN_DIVIDER); i++){
            info[i] = stringBuffer;
        }
        
        StudentInfo student = StudentInfo(info[0], info[1], info[2], info[3], info[4]);
        list.push_back(student);
    }
}

void FileManager::outputStudentInfoToFile(StudentInfo student){
    if(!this->isStreamOpen()){
        this->coutFileStreamError();
        return;
    }

    // this->ofs << '\n';
    this->ofs << student.getName() + '/' + student.getStudentID() + '/' + student.getBirthYear()
            + '/' + student.getDepartment() + '/' + student.getTel() + '\n';
}