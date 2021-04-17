#include <iostream>
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
