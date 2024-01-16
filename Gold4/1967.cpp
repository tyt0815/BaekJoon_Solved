#include <iostream>
#include <vector>

using namespace std;

struct SNode
{
    int Node;
    int w;
};

void FindLeftRightMax(int Parent, const vector<vector<SNode>>& Nodes, vector<vector<int>>& Result);
int FindMaxDiameter(const vector<int>& LeftRightMax);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<vector<SNode>> Nodes;
    cin >> n;
    Nodes.resize(n + 1);
    for(int i = 1; i < n; ++i)
    {
        int Parent, Child, w;
        cin >> Parent >> Child >> w;
        Nodes[Parent].push_back({Child, w});
    }

    vector<vector<int>> LeftRightMax;
    LeftRightMax.resize(n + 1);
    FindLeftRightMax(1, Nodes, LeftRightMax);

    int MaxDiameter = 0;
    for(int i = 1; i < n + 1; ++i)
    {
        MaxDiameter = max(MaxDiameter, FindMaxDiameter(LeftRightMax[i]));
    }

    cout << MaxDiameter;

    return 0;
}

void FindLeftRightMax(int Parent, const vector<vector<SNode>> &Nodes, vector<vector<int>> &Result)
{
    int ChildNum = Nodes[Parent].size();
    for(int i = 0; i < ChildNum; ++i)
    {
        FindLeftRightMax(Nodes[Parent][i].Node, Nodes, Result);
        int m = 0;
        for(int j = 0; j < Result[Nodes[Parent][i].Node].size(); ++j)
        {
            m = max(m, Result[Nodes[Parent][i].Node][j]);
        }
        Result[Parent].push_back(m + Nodes[Parent][i].w);
    }
}

int FindMaxDiameter(const vector<int> &LeftRightMax)
{
    int Selected;
    int n = 0, m = 0;
    for(int i = 0; i < LeftRightMax.size(); ++i)
    {
        if(n < LeftRightMax[i])
        {
            Selected = i;
            n = LeftRightMax[i];
        }
    }

    for(int i = 0; i < LeftRightMax.size(); ++i)
    {
        if(i == Selected) continue;
        if(m < LeftRightMax[i])
        {
            m = LeftRightMax[i];
        }
    }
    return n + m;
}
