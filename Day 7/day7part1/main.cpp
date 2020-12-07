/*Advent of Code, Day 7, Part 1
Find the number of possible outer bags*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 594;
int NUM_FOUND = 0;

void check(string [][2], string[], string);
bool inArray(string [], string, int);

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");
    if (ifile.fail())
    {
        cout << "Failed to open file" << endl;
        return 1;
    }

    string validBags[500];
    string rules[SIZE][2];
    string str;
    int counter = 0;
    while (getline(ifile, str))
    {
        int x = str.find("contain");
        rules[counter][0] = str.substr(0, x-6);
        rules[counter][1] = str.substr(x+8);
        counter++;
    }

    check(rules, validBags, "shiny gold");

    int bookmark = 0;
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = bookmark; i < NUM_FOUND; i++)
            check(rules, validBags, validBags[i]);

        bookmark = NUM_FOUND;
    }

    cout << "There are " << NUM_FOUND << " valid bags" << endl;

    ifile.close();
    return 0;
}

bool inArray(string arr[], string str, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        if (arr[i] == str)
            return true;

    return false;
}

void check(string rules[][2], string validBags[], string bagDesc)
{
    for (int i = 0; i < SIZE; i++)
    {
        int x = rules[i][1].find(bagDesc);
        if (x != -1)
        {
            if (inArray(validBags, rules[i][0], SIZE)) {}
            else {
                validBags[NUM_FOUND] = rules[i][0];
                NUM_FOUND++;
            }
        }
    }
}
