#include <iostream>
#include <vector>

using namespace std;

struct SNodeInfo
{
    int Key;
    int Weight;
};

int CalcTreeDiameter(int i, vector<pair<int, vector<SNodeInfo>>>& Nodes, vector<bool>& IsVisited);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, vector<SNodeInfo>>> Nodes;
    vector<int> Radius(n + 1, 0);
    Nodes.resize(n + 1);
    for(int i = 0; i < n; ++i)
    {
        int u, v, w;
        cin >> u;
        while(true)
        {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            Nodes[u].second.push_back({v, w});
        }
    }
    vector<bool> IsVisited(n + 1, false);
    cout << CalcTreeDiameter(1, Nodes, IsVisited);

    return 0;
}

int CalcTreeDiameter(int i, vector<pair<int, vector<SNodeInfo>>>& Nodes, vector<bool>& IsVisited)
{
    IsVisited[i] = true;
    int Diameter = 0;
    int Radius1 = 0, Radius2 = 0;
    for(int j = 0; j < Nodes[i].second.size(); ++j)
    {
        SNodeInfo Child = Nodes[i].second[j];
        if(IsVisited[Child.Key]) continue;
        Diameter = max(Diameter, CalcTreeDiameter(Child.Key, Nodes, IsVisited));
        if(min(Radius1, Radius2) < Nodes[Child.Key].first + Child.Weight)
        {
            Radius2 = max(Radius1, Radius2);
            Radius1 = Nodes[Child.Key].first + Child.Weight;
        }
    }
    Nodes[i].first = max(Radius1, Radius2);
    return max(Diameter, Radius1 + Radius2);
}
