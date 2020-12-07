/*Advent of Code, Day 5, Part 2
Find the missing plane seat*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    string str;
    int counter = 0;
    int ids[824];
    while (ifile >> str)
    {
        int arr[10];
        for (int i = 0; i < 7; i++)
            arr[i] = (str[i] == 'B' ? 1 : 0);
        for (int i = 7; i < 10; i++)
            arr[i] = (str[i] == 'R' ? 1 : 0);
        int id = 0;
        for (int i = 0; i < 10; i++)
            if (arr[i] == 1)
                id += pow(2, 9-i);
        ids[counter] = id;
        counter++;
    }

    for (int i = 11; i < 835; i++)
    {
        int * x = find(ids, ids+824, i);
        if (x == ids+824)
        {
            cout << "I did not find id " << i << endl;
            break;
        }
    }

    ifile.close();
    return 0;
}
