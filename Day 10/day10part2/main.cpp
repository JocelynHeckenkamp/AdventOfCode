/* Advent of Code, Day 1, Part 2
Find the number of possible arrangements*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

const int LEN = 98;

unsigned long long int cache[LEN];

unsigned long long int numOptions(bool options[][2], int index) {
    if (cache[index]) return cache[index];

    if (index >= LEN-1) {
        cache[index] = 1;
        return 1;
    }

    unsigned long long int s1 = 0, s2 = 0, s3 = 0;
    s1 = numOptions(options, index+1);
    if (options[index][0]) s2 += numOptions(options, index+2);
    if (options[index][1]) s3 += numOptions(options, index+3);

    cache[index] = s1 + s2 + s3;
    return s1 + s2 + s3;
}

int main() {
    ifstream ifile;
    ifile.open("../input.txt");

    int nums[LEN+2];
    bool options[LEN][2];
    for (int i = 0; i < LEN; i++) ifile >> nums[i];

    nums[LEN] = 0;
    nums[LEN] = *max_element(nums, nums+LEN) + 3;

    sort(nums, nums+LEN+2);

    for (int i = 0; i < LEN-1; i++) {
        if (nums[i+3] == nums[i] + 3) {
            options[i][0] = true;
            options[i][1] = true;
        } else if (nums[i+2] <= nums[i] + 3) {
            options[i][0] = true;
            options[i][1] = false;
        } else {
            options[i][0] = false;
            options[i][1] = false;
        }
    }

    cout << numOptions(options, 0) << endl;
}
