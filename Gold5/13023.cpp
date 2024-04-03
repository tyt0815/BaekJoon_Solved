#include <iostream>
#include <vector>
#define TARGETNUM 5

using namespace std;

bool DFS(int i, int Depth, const vector<vector<int>>& Nodes, vector<bool>& IsVisited);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> Nodes(n, vector<int>());
    
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        Nodes[u].push_back(v);
        Nodes[v].push_back(u);
    }
    
    vector<bool> IsVisited(n, false);
    for(int i = 0; i < n; ++i)
    {
        if(DFS(i, 0, Nodes, IsVisited))
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}

bool DFS(int i, int Depth, const vector<vector<int>> &Nodes, vector<bool> &IsVisited)
{
    if(Depth + 1 == TARGETNUM) return true;

    IsVisited[i] = true;

    for(int j = 0; j < Nodes[i].size(); ++j)
    {
        if(!IsVisited[Nodes[i][j]])
        {
            if(DFS(Nodes[i][j], Depth + 1, Nodes, IsVisited)) return true;
        }
    }

    IsVisited[i] = false;
    return false;
}
