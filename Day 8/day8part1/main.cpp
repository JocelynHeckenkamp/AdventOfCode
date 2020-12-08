/*Advent of Code, Day 8, Part 1
Find the value of acc when the program halts*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
const int LEN = 626;

bool notInArray(int [], int, int);

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    int loc = 0;
    int prevLocs[1000];
    int pli = 0;
    int acc = 0;
    string directions[LEN][2];
    for (int i = 0; i < LEN; i++)
        ifile >> directions[i][0] >> directions[i][1];

    while (notInArray(prevLocs, pli, loc)) {
        string direction = directions[loc][0];
        int param = stoi(directions[loc][1]);

        prevLocs[pli] = loc;
        pli++;

        if (direction == "acc") {
            acc += param;
            loc++;
        } else if (direction == "nop") {
            loc++;
        } else {
            loc += param;
        }
    }
    cout << acc << endl;

    ifile.close();
    return 0;
}

bool notInArray(int arr[], int lastIndex, int num) {
    for (int i = 0; i < lastIndex; i++)
        if (arr[i] == num)
            return false;

    return true;
}
