/* Advent of Code, Day 1, Part 1
Find the jump sizes*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int LEN = 98;

int main() {
    ifstream ifile;
    ifile.open("../input.txt");

    int nums[LEN+2];
    for (int i = 0; i < LEN; i++) ifile >> nums[i];

    nums[LEN] = 0;
    nums[LEN] = *max_element(nums, nums+LEN) + 3;

    sort(nums, nums+LEN+2);

    int jumps1 = 0, jumps3 = 0;
    for (int i = 0; i < LEN+1; i++) {
        if (nums[i+1] - nums[i] == 3) jumps3++;
        else if (nums[i+1] - nums[i] == 1) jumps1++;
    }

    cout << jumps3 * jumps1 << endl;
}
