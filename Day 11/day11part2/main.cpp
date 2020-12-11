/*Advent of Code, Day 11, Part 2
Calculate how many occupied seats there will people after people stabilize, but in a different way*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int LEN = 98;
const int WID = 99;

int countNeighbors(char [][WID], int, int);
bool flipSeats(char [][WID]);

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

int countNeighbors(char seats[][WID], int row, int column) {
    int neighbors = 0;

    for (int r = row-1, c = column-1; r >= 0 && c >= 0; r--, c--) {
        if (seats[r][c] == 'L') break;
        else if (seats[r][c] == '#') {neighbors++; break;}
    }

    for (int r = row-1; r >= 0; r--) {
        if (seats[r][column] == 'L') break;
        else if (seats[r][column] == '#') {neighbors++; break;}
    }

    for (int r = row-1, c = column+1; r >= 0 && c < WID; r--, c++) {
        if (seats[r][c] == 'L') break;
        else if (seats[r][c] == '#') {neighbors++; break;}
    }

    for (int c = column+1; c < WID; c++) {
        if (seats[row][c] == 'L') break;
        else if (seats[row][c] == '#') {neighbors++; break;}
    }

    for (int r = row+1, c = column+1; r < LEN && c < WID; r++, c++) {
        if (seats[r][c] == 'L') break;
        else if (seats[r][c] == '#') {neighbors++; break;}
    }

    for (int r = row+1; r < LEN; r++) {
        if (seats[r][column] == 'L') break;
        else if (seats[r][column] == '#') {neighbors++; break;}
    }

    for (int r = row+1, c = column-1; r < LEN && c >= 0; r++, c--) {
        if (seats[r][c] == 'L') break;
        else if (seats[r][c] == '#') {neighbors++; break;}
    }

    for (int c = column-1; c >= 0; c--) {
        if (seats[row][c] == 'L') break;
        else if (seats[row][c] == '#') {neighbors++; break;}
    }

    return neighbors;
}

bool flipSeats(char seats[][WID]) {
    int flipCount = 0;
    int flips[LEN * WID][2];
    for (int r = 0; r < LEN; r++) {
        for (int c = 0; c < WID; c++) {
            if (seats[r][c] == '.') continue;
            int neighbors = countNeighbors(seats, r, c);
            if ((seats[r][c] == 'L' && neighbors == 0) || (seats[r][c] == '#' && neighbors >= 5)) {
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
