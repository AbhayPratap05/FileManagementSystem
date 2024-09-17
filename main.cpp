#include <iostream>
#include "FileManager.h"

int main(){
    int choice;
    string filename, content, directory;
    bool append;
    
    while (true)
    {
        cout << "\n********** File Management System **********\n" << endl;
        cout << "1: Create File" << endl;
        cout << "2: Delete File" << endl;
        cout << "3: Read File" << endl;
        cout << "4: Write to File" << endl;
        cout << "5: List Files in Directory" << endl;
        cout << "6: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "\nEnter filename: ";
            getline(cin, filename);
            cout << "Enter the content to the file: ";
            getline(cin, content);
            FileManager::createFile(filename, content);
            break;
        
        case 2:
            cout << "\nEnter filename: ";
            getline(cin, filename);
            FileManager::deleteFile(filename);
            break;
        
        case 3:
            cout << "\nEnter filename: ";
            getline(cin, filename);
            FileManager::readFile(filename);
            break;

        case 4:
            cout << "\nEnter filename: ";
            getline(cin, filename);
            cout << "Enter the content to the file: ";
            getline(cin, content);
            cout << "1: Append\n2: Overwrite\nEnter (1/0): ";
            cin >> append;
            cin.ignore();
            FileManager::writeFile(filename, content, append);
            break;

        case 5:
            cout << "\nEnter directory: ";
            getline(cin, directory);
            FileManager::listFile(directory);
            break;
        
        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cerr << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    
}