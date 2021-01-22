/*A. Harrison Owen
 *
 *
 */

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
    //getting the file name should be more robust.
    cout << "Enter filename (include '.txt'):";
    getline(cin, fileName);
    //Creates file/opens already existing file.
    //Wipes data from file before user inputs their own.
    newFile.open (fileName, fstream::out | fstream::trunc);
    //If file is not found, exit program.
    if(!newFile){
        cout << "file not found.\n";
        return 0;
    }
    cout << "File created.\n";
    cout << "Enter text to print to the file:\n";
    string userText;
    getline(cin, userText);
    //stops taking user input when user enters "exit".
    //should be more robust
    while (userText != "exit") {
        newFile << userText << endl;
        cout << "USER TEXT HERE:" << userText << endl;
        cout << "Enter text to print to the file:\n";
        getline(cin, userText);
        if (userText == "exit") break;
    }
    cout << "You are finished writing to the file.\n";
    cout << "Closing file.\n";
    newFile.close();
    return 0;
}