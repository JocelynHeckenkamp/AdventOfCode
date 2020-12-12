/*Advent of Code, Day 12, Part 2
Find the new manhattan distance of the ship*/

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
    int x = 0, y = 0;
    int wx = 10, wy = 1;

    while (ifile >> str) {
        char ch = str[0];
        int num = stoi(str.substr(1));

        if (ch == 'N') wy += num;
        else if (ch == 'E') wx += num;
        else if (ch == 'S') wy -= num;
        else if (ch == 'W') wx -= num;
        else if (ch == 'F') {
            x += num * wx;
            y += num * wy;
        }
        else {
            int sx = wx, sy = wy;
            int dx = round(cos(num * PI / 180));
            int dy = round(sin(num * PI / 180));
            if (dy == 0) {
                wx *= dx;
                wy *= dx;
            } else if ((dy == 1 && ch == 'L') || (dy == -1 && ch == 'R')) {
                wx = sy;
                wy = sx;
                wx *= -1;
            } else if ((dy == 1 && ch == 'R') || (dy == -1 && ch == 'L')) {
                wx = sy;
                wy = sx;
                wy *= -1;
            }
        }
    }

    cout << abs(x) + abs(y) << endl;

    return 0;
}
