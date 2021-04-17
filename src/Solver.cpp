#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "Utils.h"

using namespace std;
convertor chartoint('-', 'O');

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
            buf.push_back(chartoint.dothis(ch));
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

map<pair<int, int>, node> makeMazeGraph(vector<vector<int>> mazeAs2dArray)
{
    map<pair<int, int>, node> mazeg;
    for (int i = 0; i < mazeAs2dArray.size(); i++)
    {
        for (int j = 0; j < mazeAs2dArray[i].size(); j++)
        {
            if (mazeAs2dArray[i][j] == 1)
                continue;
            node temp;
            temp.last = make_pair(-1, -1);
            temp.cost = -1;
            temp.connections = findconnection(mazeAs2dArray, i, j);
            mazeg.insert(make_pair(make_pair(i, j), temp));
        }
    }
    return mazeg;
}

vector<pair<int, int>> Dijkstras_algorithm(map<pair<int, int>, node> maze, pair<int, int> S, pair<int, int> D)
{
    vector<pair<int, int>> Q, done, path;
    maze[S].cost = 0;
    Q.push_back(S);
    while (Q.size() > 0)
    {
        pair<int, int> u = *Q.begin();
        vector<pair<int, int>>::iterator del_pointer = Q.begin();
        for (auto it = Q.begin(); it != Q.end(); ++it)
        {
            if (maze[u].cost > maze[*it].cost)
            {
                cout << "in" << endl;
                u = *it;
                del_pointer = it;
            }
        }
        done.push_back(u);
        Q.erase(del_pointer);

        auto neighbors = maze[u].connections;
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            if (find(done.begin(), done.end(), *it) != done.end())
                continue;
            else
                Q.push_back(*it);
            int alt_cost = maze[u].cost + 1;
            cout<<alt_cost<<endl;
            if (alt_cost < maze[*it].cost)
            {
                maze[*it].cost = alt_cost;
                maze[*it].last = u;
            }
        }
    }
    auto x = maze[D];
    path.push_back(D);
    do
    {
        path.push_back(x.last);
        x = maze[x.last];
    } while (x.last != S);
    return path;
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

    auto mazeAsGraph = makeMazeGraph(mazeAs2dArray);
    // showmazeg(mazeAsGraph);
    cout << "-----------------------------" << endl;
    pair<int, int> source(0, 0);
    pair<int, int> destination(ROW - 1, COL - 1);

    auto path = Dijkstras_algorithm(mazeAsGraph, source, destination);
    showmazeandpath(path, mazeAs2dArray);

    cout << "-----------------------------" << endl;
    return 0;
}
