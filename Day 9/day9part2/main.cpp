/*Advent of Code, Day 9, Part 1
Find numbers that add up to the answer from part 1*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int LEN = 623;
const int PREAMBLE = 25;

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    int num, nums[LEN], theAnswer, theOtherAnswer;
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
        theAnswer = nums[i];
        break;
    }

    for (int i = 0; i < LEN; i++) {
        int sum = nums[i];
        for (int j = 1; j < 20; j++) {
            sum += nums[i+j];
            if (sum == theAnswer) {
                const int SIZE = j+1;
                int nnums[SIZE];
                for (int k = i; k <= i+j; k++)
                    nnums[k-i] = nums[k];
                cout << *min_element(nnums, nnums+j+1) + *max_element(nnums, nnums+j+1) << endl;
                return 0;
            }
        }
    }

    return 0;
}
