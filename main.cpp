#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;

int main () {
    //fstream was chosen for its ability to read and write
    fstream newFile;
    string fileName;
    cout << "Enter filename:";
    getline(cin, fileName);
    //creates file/opens already existing file
    newFile.open (fileName);
    if(!newFile){
        cout << "file not found.\n";
        return 0;
    }
    cout << "File created.\n";
    cout << "Enter text to print to the file:\n";
    string userText;
    getline(cin, userText);
    while (userText != "exit") {
        newFile << userText;
        cout << "Enter text to print to the file:\n";
        string userText;
        getline(cin, userText);
        if (userText == "exit") break;
    }
    cout << "You are finished writing to the file.\n";
    cout << "Closing file.\n";
//    newFile >> "dummy test";

    newFile.close();
    return 0;
}