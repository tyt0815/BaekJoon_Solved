#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> Nodes;
    Nodes.resize(n + 1);
    for(int i  = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        Nodes[v].push_back(u);
    }

    vector<int> Results;
    int MaxHackable = 0;
    for(int i = 1; i <= n; ++i)
    {
        stack<int> s;
        vector<bool> IsVisited(n + 1, false);
        int Hackable = 1;
        s.push(i);
        IsVisited[i] = true;
        while(!s.empty())
        {
            int c = s.top();
            s.pop();
            for(int j = 0; j < Nodes[c].size(); ++j)
            {
                if(IsVisited[Nodes[c][j]]) continue;
                s.push(Nodes[c][j]);
                IsVisited[Nodes[c][j]] = true;
                ++Hackable;
            }
        }
        if(Hackable > MaxHackable)
        {
            Results = {i};
            MaxHackable = Hackable;
        }
        else if(Hackable == MaxHackable) Results.push_back(i);
    }

    for(int i = 0; i < Results.size(); ++i) cout << Results[i] << ' ';

    return 0;
}
