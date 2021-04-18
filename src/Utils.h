#include <bits/stdc++.h>
#include <vector>

using namespace std;

class convertor
{
    char go, nogo;

public:
    convertor()
    {
        go = '-', nogo = 'O';
    }
    convertor(char go, char nogo)
    {
        this->go = go;
        this->nogo = nogo;
    }
    int dothis(char ch)
    {
        if (ch == go)
            return 0;
        else if (ch == nogo)
            return 1;
        else
            throw;
    }
};

struct node
{
    pair<int, int> loc;
    pair<int, int> last;
    vector<pair<int, int>> connections;
    int cost;
};

void showmaze2d(vector<vector<int>> maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
            cout << maze[i][j] << " ";

        cout << endl;
    }
}

void showmazeg(map<pair<int, int>, node> mazeg)
{
    for (auto i = mazeg.begin(); i != mazeg.end(); i++)
    {
        node localnode = i->second;
        cout << i->first.first << "," << i->first.second;
        for (int k = 0; k < localnode.connections.size(); k++)
        {
            cout << " ->" << localnode.connections[k].first << "," << localnode.connections[k].second;
        }
        cout << endl;
    }
}

void showpath(vector<pair<int, int>> path)
{
    for (auto it = path.begin(); it != path.end(); ++it)
        cout << it->first << " " << it->second << endl;
}

void showmazeandpath(vector<pair<int, int>> path, vector<vector<int>> maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {

            pair<int, int> temp(i, j);
            if (find(path.begin(), path.end(), temp) != path.end())
                cout << "+"
                     << " ";
            else
                cout << maze[i][j] << " ";
        }

        cout << endl;
    }
}

void showmazeandcost(map<pair<int, int>, node> MazeGraph, vector<vector<int>> mazeArray)
{
    for (int i = 0; i < mazeArray.size(); i++)
    {
        for (int j = 0; j < mazeArray[i].size(); j++)
        {
            pair<int, int> temp(i, j);
            cout << MazeGraph[temp].cost << "  ";
        }

        cout << endl;
    }
}
