#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

char go = '-', nogo = 'O';

struct node
{
    pair<int, int> loc;
    pair<int, int> last;
    vector<pair<int, int>> connections;
    int cost;
};

int convertor(char ch)
{
    if (ch == go)
        return 0;
    else if (ch == nogo)
        return 1;
    else
        throw;
}

void showmaze2d(vector<vector<int>> maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

void showmazeg(vector<node> mazeg)
{
    for (int i = 0; i < mazeg.size(); i++)
    {
        node localnode = mazeg[i];
        cout << localnode.loc.first << "," << localnode.loc.second;
        for (int k = 0; k < localnode.connections.size(); k++)
        {
            cout << " ->" << localnode.connections[k].first << "," << localnode.connections[k].second;
        }
        cout << endl;
    }
}

vector<vector<int>> readmazefromfile(char *filename)
{
    ifstream file(filename);
    vector<vector<int>> mazeAs2dArray;
    string data;
    while (getline(file, data))
    {
        vector<int> buf;
        for (auto &ch : data)
        {
            buf.push_back(convertor(ch));
        }
        mazeAs2dArray.push_back(buf);
    }
    file.close();
    return mazeAs2dArray;
}

vector<pair<int, int>> findconnection(vector<vector<int>> maze, int i, int j)
{
    int ROW = maze.size();
    int COL = maze[0].size();

    vector<pair<int, int>> connections;
    auto check = [&](int a, int b) {
        if (maze[a][b] == 0)
        {
            connections.push_back(make_pair(a, b));
        }
    };
    // for i and j
    //chech -1 and +1 values
    if (i - 1 > -1)
        check(i - 1, j);
    if (i + 1 < ROW)
        check(i + 1, j);
    if (j - 1 > -1)
        check(i, j - 1);
    if (j + 1 < COL)
        check(i, j + 1);

    return connections;
}

vector<node> mazegraph(vector<vector<int>> mazeAs2dArray)
{
    vector<node> mazeg;
    for (int i = 0; i < mazeAs2dArray.size(); i++)
    {
        for (int j = 0; j < mazeAs2dArray[i].size(); j++)
        {
            if (mazeAs2dArray[i][j] == 1)
                continue;
            node temp;
            temp.loc = make_pair(i, j);
            temp.last = make_pair(-1, -1);
            temp.cost = -1;
            temp.connections = findconnection(mazeAs2dArray, i, j);
            mazeg.push_back(temp);
        }
    }
    return mazeg;
}

int main(int arg, char **argv)
{
    if (arg > 2)
    {
        throw(arg);
    }

    vector<vector<int>> mazeAs2dArray = readmazefromfile(argv[1]);

    int ROW = mazeAs2dArray.size();
    int COL = mazeAs2dArray[0].size();
    showmaze2d(mazeAs2dArray);

    vector<node> mazeg = mazegraph(mazeAs2dArray);
    showmazeg(mazeg);

    pair<int, int> source(0, 0);
    pair<int, int> destination(ROW - 1, COL - 1);

    // vector<pair<int, int>> path =
    return 0;
}
