/*Advent of Code, Day 12, Part 1
Find the manhattan distance of the ship*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
const long double PI = 3.141592653589793238462643383279502884;

int main()
{
    ifstream ifile;
    ifile.open("../input.txt");

    string str;
    int x = 0, y = 0, deg = 0;

    while (ifile >> str) {
        char ch = str[0];
        int num = stoi(str.substr(1));

        if (ch == 'N') y += num;
        else if (ch == 'E') x += num;
        else if (ch == 'S') y -= num;
        else if (ch == 'W') x -= num;
        else if (ch == 'F') {
            int dx = cos(deg * PI / 180);
            int dy = sin(deg * PI / 180);
            x += num * dx;
            y += num * dy;
        }
        else if (ch == 'L') deg += num;
        else if (ch == 'R') deg -= num;
    }

    cout << abs(x) + abs(y) << endl;

    return 0;
}
