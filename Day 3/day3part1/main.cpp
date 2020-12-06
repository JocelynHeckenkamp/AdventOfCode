/*Advent of Code, Day 3, Part 1
Calculate how many trees you will hit on a toboggan*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int ROWS = 323;

    ifstream inputFile;
    inputFile.open("../input.txt");
    if (inputFile.fail())
    {
        cout << "Couldn't open file" << endl;
        return 1;
    }

    string forest[ROWS];

    int index = 0;
    string str;
    while (inputFile >> str)
    {
        forest[index] = str;
        index++;
    }

    int x = 3, y = 1;
    int treeCounter = 0;
    while (y < ROWS)
    {
        if (forest[y][x % 31] == '#')
            treeCounter++;

        x += 3;
        y++;
    }

    cout << "You hit " << treeCounter << " trees!" << endl;

    return 0;
}
