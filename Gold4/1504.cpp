#include <iostream>
#include <vector>

using namespace std;

struct SEdgeInfo
{
    int To;
    int w;
};

void FindMinDist(int Start, vector<vector<SEdgeInfo>> Nodes, vector<int>& MinDist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ,e;
    int v, u;
    vector<vector<SEdgeInfo>> Nodes;
    cin >> n >> e;
    Nodes.resize(n + 1);
    for(int i = 0; i < e; ++i)
    {
        int w;
        cin >> v >> u >> w;
        Nodes[v].push_back({u, w});
        Nodes[u].push_back({v, w});
    }
    cin >> v >> u;

    vector<int> FromOne, FromV, FromU;
    FindMinDist(1, Nodes, FromOne);
    FindMinDist(v, Nodes, FromV);
    FindMinDist(u, Nodes, FromU);

    if(FromOne[v] == INT32_MAX || FromOne[u] == INT32_MAX || FromOne[n] == INT32_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << min(FromOne[v] + FromV[u] + FromU[n], FromOne[u] + FromU[v] + FromV[n]);

    return 0;
}

void FindMinDist(int Start, vector<vector<SEdgeInfo>> Nodes, vector<int> &MinDist)
{
    vector<bool> IsVisited(Nodes.size(), false);
    MinDist.resize(Nodes.size(), INT32_MAX);
    MinDist[Start] = 0;
    while(true)
    {
        int PassNode = 0;
        for(int i = 1; i < Nodes.size(); ++i)
        {
            if(!IsVisited[i] && MinDist[PassNode] > MinDist[i])
            {
                PassNode = i;
            }
        }
        if(PassNode == 0)
        {
            return;
        }
        IsVisited[PassNode] = true;
        for(int i = 0; i < Nodes[PassNode].size(); ++i)
        {
            MinDist[Nodes[PassNode][i].To] = min(MinDist[Nodes[PassNode][i].To], MinDist[PassNode] + Nodes[PassNode][i].w);
        }
    }
}
