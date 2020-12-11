/*Advent of Code, Day 11, Part 1
Calculate how many occupied seats there will people after people stabilize*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// LEN: 98, 10
// WID: 99, 10
const int LEN = 98;
const int WID = 99;

int countNeighbors(char seats[][WID], int row, int column) {
    int neighbors = 0;
    bool t = false;
    bool r = false;
    bool b = false;
    bool l = false;

    if (row > 0) t = true;
    if (row < LEN - 1) b = true;
    if (column > 0) l = true;
    if (column < WID - 1) r = true;

    if (t && l && seats[row-1][column-1] == '#') neighbors++;
    if (t && seats[row-1][column] == '#') neighbors++;
    if (t && r && seats[row-1][column+1] == '#') neighbors++;
    if (r && seats[row][column+1] == '#') neighbors++;
    if (r && b && seats[row+1][column+1] == '#') neighbors++;
    if (b && seats[row+1][column] == '#') neighbors++;
    if (b && l && seats[row+1][column-1] == '#') neighbors++;
    if (l && seats[row][column-1] == '#') neighbors++;

    return neighbors;
}

bool flipSeats(char seats[][WID]) {
    int flipCount = 0;
    int flips[LEN * WID][2];
    for (int r = 0; r < LEN; r++) {
        for (int c = 0; c < WID; c++) {
            if (seats[r][c] == '.') continue;
            int neighbors = countNeighbors(seats, r, c);
            if ((seats[r][c] == 'L' && neighbors == 0) || (seats[r][c] == '#' && neighbors >= 4)) {
                flips[flipCount][0] = r;
                flips[flipCount][1] = c;
                flipCount++;
            }
        }
    }

    if (flipCount == 0) return false;

    for (int i = 0; i < flipCount; i++) {
        int r = flips[i][0];
        int c = flips[i][1];
        if (seats[r][c] == 'L') seats[r][c] = '#';
        else seats[r][c] = 'L';
    }
    return true;
}

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    char seats[LEN][WID];
    string str;

    for (int l = 0; l < LEN; l++) {
        ifile >> str;
        for (int w = 0; w < WID; w++)
            seats[l][w] = str[w];
    }

    while (flipSeats(seats)) continue;

    int occupied = 0;
    for (int r = 0; r < LEN; r++)
        for (int c = 0; c < WID; c++)
            if (seats[r][c] == '#') occupied++;

    cout << occupied << endl;

    return 0;
}
