/*Advent of Code, Day 7, Part 2
Find the number of bags needed*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 594;
int calcBags(string [][2], string, int);

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    string subBags[500];
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

    cout << calcBags(rules, "shiny gold", 1) - 1 << endl;

    ifile.close();
    return 0;
}

int calcBags(string rules[][2], string bagDesc, int multiplier)
{
    for (int i = 0; i < SIZE; i++)
    {
        int x = rules[i][0].find(bagDesc);
        if (x != -1)
        {
            if (rules[i][1].find("no other bags") != -1)
                return multiplier;
            else
            {
                int subBags = 0;
                int bookmark = 0, b2 = 0;
                while (bookmark < rules[i][1].length())
                {
                    int number = stoi(rules[i][1].substr(bookmark));
                    bookmark += 2;
                    b2 = rules[i][1].substr(bookmark).find(" ");
                    string str1 = rules[i][1].substr(bookmark, b2);
                    bookmark += b2 + 1;
                    b2 = rules[i][1].substr(bookmark).find(" ");
                    string str2 = rules[i][1].substr(bookmark, b2);
                    bookmark += b2 + 4;
                    if (rules[i][1].substr(bookmark, 1) == "s")
                        bookmark++;
                    bookmark += 2;
                    string str = str1 + " " + str2;

                    subBags += calcBags(rules, str, number);
                }

                return (subBags * multiplier + multiplier);
            }

            break;
        }
    }
}
