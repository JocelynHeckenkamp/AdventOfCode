/*Advent of Code, Day 8, Part 2
Find the value of acc when the program is fixed*/

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

    int loc, acc;
    string directions[LEN][2];
    for (int i = 0; i < LEN; i++)
        ifile >> directions[i][0] >> directions[i][1];

    for (int i = 1; i < LEN; i++) {
        string ph;
        if (directions[i][0] == "acc")
            continue;
        else {
            ph = directions[i][0];
            if (ph == "nop")
                directions[i][0] = "jmp";
            else
                directions[i][0] = "nop";
        }

        loc = 0, acc = 0;
        int pli = 0, prevLocs[1000];

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
            if (loc >= LEN)
            {
                cout << acc << endl;
                return 0;
            }
        }
        directions[i][0] = ph;
    }

    ifile.close();
    return 0;
}

bool notInArray(int arr[], int lastIndex, int num) {
    for (int i = 0; i < lastIndex; i++)
        if (arr[i] == num)
            return false;

    return true;
}
