#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
using namespace std;

class FileManager{
    public:

        static void createFile(const string& filename, const string& content);

        static void deleteFile(const string& filename);

        static void readFile(const string& filename);

        static void writeFile(const string& filename, const string& content, bool append = false);

        static void listFile(const string& directory);
};


#endif