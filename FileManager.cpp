#include "FileManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <iomanip>

namespace fs = std::filesystem;

void FileManager::createFile(const string& filename, const string& content){
    ofstream file(filename);
    if(file.is_open()){
        file << content << endl;
        file.close();
        cout << "File '" << filename << "' is created successfully!" << endl;
    }
    else{
        cerr << "Can't create the file!" << endl;
    }
}

void FileManager::deleteFile(const string& filename){
    if (fs::remove(filename))
    {
        cout << filename << ": Successfully deleted!" << endl;
    }
    else{
        cerr << "Unable to delete file or file does not exist." << endl;
    }
}

void FileManager::readFile(const string& filename){
    ifstream file(filename);
    if(file.is_open()){
        cout << "File contents: " << endl;
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else{
        cerr << "Uable to open the file for reading" << endl;
    }
}

void FileManager::writeFile(const string& filename, const string& content, bool append){
    ofstream file;
    if(append){
        file.open(filename, ios_base::app);
        cout << "File found, writing content...\n";
    }
    else{
        file.open(filename);
        cout << "File did'nt exists, creating the file...\n";
    }
    if(file.is_open()){
        file << content << endl;
        file.close();
        cout << "File '" << filename << "' is updated successfully!" << endl;
    }
    else{
        std::cerr << "Unable to open/create file for writing." << std::endl;
    }
}

void FileManager::listFile(const string& directory){
    try
    {
        cout << "Files: "<<endl;
        
        for (const auto& entry : fs::directory_iterator(directory)) {
            auto filename = entry.path().filename().string();
            cout << setw(30) << filename;
            
            if (fs::is_directory(entry)) {
                cout << "\t [Directory]";
            } else if (fs::is_regular_file(entry)) {
                cout << "\t [File]";
            }

            cout << endl;
        }
    }
    catch(const fs::filesystem_error& e)
    {
        cerr << "Error listing files: " << e.what() << endl;
    }
    
}