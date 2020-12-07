/*Advent of Code, Day 6, Part 2
Find the number of unanimous yes answers for each group*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int total = 0;
    ifstream ifile;
    ifile.open("../input.txt");

    string line;
    while (getline(ifile, line))
    {
        string str = "";
        int people = 0;
        while (line.length() != 0)
        {
            people++;
            str += line;
            getline(ifile, line);
        }

        int unanimous_yeses = 0;
        for (int i = 0; i < str.length(); i++)
        {
            int repetitions = count(str.begin(), str.end(), str[i]);
            if (repetitions == people)
                unanimous_yeses++;
        }
        unanimous_yeses /= people;
        total += unanimous_yeses;
    }

    cout << "The total is " << total << endl;
    return 0;
}
