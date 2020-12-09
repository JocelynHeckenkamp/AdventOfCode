/*Advent of Code, Day 9, Part 1
Find the number that doesn't follow the pattern*/

#include <iostream>
#include <fstream>
using namespace std;
const int LEN = 623;
const int PREAMBLE = 25;
//const int LEN = 20;
//const int PREAMBLE = 5;

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    int num, nums[LEN];
    for (int i = 0; i < LEN; i++)
        ifile >> nums[i];
    ifile.close();

    for (int i = PREAMBLE; i < LEN; i++) {
        bool good = false;
        for (int j = i-PREAMBLE; j < i; j++) {
            for (int k = i-PREAMBLE; k < i; k++) {
                if (k == j)
                    continue;
                if (nums[j] + nums[k] == nums[i]) {
                    good = true;
                    break;
                }
            }
            if (good) break;
        }
        if (good) continue;
        cout << nums[i] << endl;
        break;
    }

    return 0;
}
