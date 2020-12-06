/* Advent of Code, Day 1, Part 2
Find three numbers in the list that add to 2020, then multiply them.*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");
    if (inputFile.fail())
    {
        cout << "Open failed" << endl;
        return 1;
    }

    int numbers[200];
    int counter = 0;

    while (inputFile >> numbers[counter])
        counter++;

    for (int i = 0; i < 200; i++)
        for (int j = (i + 1); j < 200; j++)
            for (int k = (i + 2); k < 200; k++)
                if (numbers[i] + numbers[j] + numbers[k] == 2020)
                {
                    cout << numbers[i] << " * " << numbers[j] << " * " << numbers[k] << " =" << endl;
                    cout << "When you multiply them, you get, " << numbers[i]*numbers[j]*numbers[k] << endl;
                }


    return 0;
}
