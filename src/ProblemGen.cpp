#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

char go = '-', nogo = 'O';

char decideblock()
{
    int val = rand() % 100;
    if (val > 10)
        return go;
    else
        return nogo;
}

int main(int argc, char **argv)
{
    ofstream file("problem/question.txt");
    srand(time(0));

    int ROW = stoi(argv[1]), COL = stoi(argv[2]);
    file << go;
    for (int i = 0; i < ROW - 1; i++)
    {
        for (int j = i == 0 ? 1 : 0; j < COL; j++)
        {
            file << decideblock();
        }
        file << endl;
    }
    for (int i = 0; i < COL - 1; i++)
    {
        file << decideblock();
    }
    file << go << endl;
    file.close();
    return 0;
}