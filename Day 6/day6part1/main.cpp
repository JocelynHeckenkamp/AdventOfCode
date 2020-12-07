/*Advent of Code, Day 6, Part 1
Find the number of yes answers for each group*/

#include <iostream>
#include <fstream>
#include <string>
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
        while (line.length() != 0)
        {
            str += line;
            getline(ifile, line);
        }

        int letters = 1;
        for (int i = 1; i < str.length(); i++)
        {
            int repeated = false;
            for (int j = 0; j < i; j++)
                if (str[i] == str[j])
                {
                    repeated = true;
                    break;
                }
            if (!repeated)
                letters++;
        }
        total += letters;
    }

    cout << "The total is " << total << endl;
    return 0;
}
