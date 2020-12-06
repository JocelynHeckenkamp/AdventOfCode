/*Advent of Code, Day 4, Part 1
Determine if a passport is valid*/

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
        cout << "Couldn't open file" << endl;
        return 1;
    }

    int validPassports = 0;
    string str, data;

    while (getline(inputFile, data))
    {
        while (getline(inputFile, str) && str.length() != 0)
            data = data + str;

        if (data.find("byr") != -1 && data.find("iyr") != -1 && data.find("eyr") != -1 &&
            data.find("hgt") != -1 && data.find("hcl") != -1 && data.find("ecl") != -1 &&
            data.find("pid") != -1)
            validPassports++;
    }

    cout << "There were " << validPassports << " valid passports" << endl;

    return 0;
}
