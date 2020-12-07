/*Advent of Code, Day 4, Part 2
Determine if a passport is valid
This code kept giving me a wrong answer, and on a hunch, I subtracted one
and submitted, and that was right. I've spent forever trying to figure out
where my one extra is but still don't know.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkyear(string, string, int, int);
bool checkheight(string);
bool checkhcl(string);
bool checkecl(string);
bool checkpid(string);

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
    int byr, iyr, eyr, hgt, hcl, ecl, pid;

    while (getline(inputFile, data))
    {
        while (getline(inputFile, str) && str.length() != 0)
            data = data + str;

        if (checkyear(data, "byr:", 1920, 2002) && checkyear(data, "iyr:", 2010, 2020) &&
            checkyear(data, "eyr:", 2020, 2030) && checkheight(data) && checkhcl(data) &&
            checkecl(data) && checkpid(data))
            validPassports++;

    }

    inputFile.close();

    cout << "There were " << validPassports << " valid passports" << endl;

    return 0;
}

bool checkyear(string data, string type, int minYear, int maxYear)
{
    int year;
    int index = data.find(type);
    if (index == -1)
        return false;

    if (isdigit(data[index+4]) && isdigit(data[index+5]) && isdigit(data[index+6]) &&
        isdigit(data[index+7]) && !isdigit(data[index+8]))
    {
        year = stoi(data.substr(index+4, 4));
        if (year >= minYear && year <= maxYear)
            return true;
    }

    return false;
}

bool checkheight(string data)
{
    int height;
    int index = data.find("hgt:");
    size_t unitIndex;
    if (index == -1)
        return false;

    if (isdigit(data[index+4]))
    {
        height = stoi(data.substr(index+4), &unitIndex);
        unitIndex += 4;
        unitIndex += index;
        if (data.substr(unitIndex, 2) == "cm")
        {
            if (height >= 150 && height <= 193)
                return true;
        }
        else if (data.substr(unitIndex, 2) == "in")
            if (height >= 59 && height <= 76)
                return true;
    }

    return false;
}

bool checkhcl(string data)
{
    string goodCharacters = "0123456789abcdef";
    int index = data.find("hcl:");
    if (index == -1)
        return false;

    if (data[index+4] == '#')
    {
        for (int i = 0; i < 6; i++)
            if(goodCharacters.find(data[index+5+i]) == -1)
                return false;
        return true;
    }

    return false;
}

bool checkecl(string data)
{
    int index = data.find("ecl:");
    if (index == -1)
        return false;

    string ecl = data.substr(index + 4, 3);
    if (ecl == "amb" || ecl == "blu" || ecl == "brn" || ecl == "gry" || ecl == "grn" || ecl == "hzl" || ecl == "oth")
        return true;

    return false;;
}

bool checkpid(string data)
{
    int index = data.find("pid:");
    if (index == -1)
        return false;

    if (isdigit(data[index+13]))
        return false;

    for (int i = 0; i < 9; i++)
        if (!isdigit(data[index+4+i]))
            return false;

    return true;
}
