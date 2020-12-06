/*Advent of Code, Day 2, Part 2
Find how many passwords are valid from a list*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("../input.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open" << endl;
        return 0;
    }

    int validPasswords = 0;
    int index1, index2;
    size_t indexHolder;
    char theChar;
    int charCounter;
    string str1, str2, str3;

    while (inputFile >> str1 >> str2 >> str3)
    {
        index1 = stoi(str1, &indexHolder);
        index2 = stoi(str1.substr(indexHolder + 1));
        theChar = str2[0];

        charCounter = 0;
        if (str3[index1-1] == theChar)
            charCounter++;
        if (str3[index2-1] == theChar)
            charCounter++;

        if (charCounter == 1)
            validPasswords++;
    }

    cout << "There are " << validPasswords << " valid passwords" << endl;

    return 0;
}
