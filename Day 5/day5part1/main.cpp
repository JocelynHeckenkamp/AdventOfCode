/*Advent of Code, Day 5, Part 1
Find the highest seat ID in a plane*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");
    if (ifile.fail())
    {
        cout << "Could not open file" << endl;
        return 1;
    }

    string str;
    int highestID = 0;
    int id;
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
        if (id > highestID)
            highestID = id;
    }

    cout << "The highest ID is " << highestID << endl;

    ifile.close();
    return 0;
}
