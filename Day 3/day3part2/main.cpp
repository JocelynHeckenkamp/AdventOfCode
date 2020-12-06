/*Advent of Code, Day 3, Part 2
Calculate how many trees you will hit on a toboggan for five different paths, and multiply the results*/

#include <iostream>
#include <fstream>
using namespace std;

const int ROWS = 323;

int hitTrees(string [], int, int);

int main()
{
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

    int k1 = hitTrees(forest, 1, 1);
    int k2 = hitTrees(forest, 3, 1);
    int k3 = hitTrees(forest, 5, 1);
    int k4 = hitTrees(forest, 7, 1);
    int k5 = hitTrees(forest, 1, 2);

    cout << "Multiply them together, and you get " << k1 * k2 * k3 * k4 * k5 << endl;

    return 0;
}

hitTrees(string forest[], int stepx, int stepy)
{
    int x = stepx, y = stepy;
    int treeCounter = 0;
    while (y < ROWS)
    {
        if (forest[y][x % 31] == '#')
            treeCounter++;

        x += stepx;
        y += stepy;
    }

    cout << "When x step is " << stepx << " and step y is " << stepy << ", you hit " << treeCounter << " trees" << endl;
    return treeCounter;
}
