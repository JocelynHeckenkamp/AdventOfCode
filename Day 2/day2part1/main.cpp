/*Advent of Code, Day 2
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
    int minChars, maxChars;
    size_t indexHolder;
    char theChar;
    int charCounter;
    string str1, str2, str3;

    while (inputFile >> str1 >> str2 >> str3)
    {
        minChars = stoi(str1, &indexHolder);
        maxChars = stoi(str1.substr(indexHolder + 1));
        theChar = str2[0];

        charCounter = 0;
        for (int i = 0; i < str3.length(); i++)
            if (str3[i] == theChar)
                charCounter++;

        if (charCounter >= minChars && charCounter <= maxChars)
            validPasswords++;
    }

    cout << "There are " << validPasswords << " valid passwords" << endl;

    return 0;
}
