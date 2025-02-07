#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool bCycle = false;

int64_t UpdateWeight(int i, const vector<vector<int>> &Nodes, vector<bool> &bParent, vector<pair<int, int64_t>> &NodeInfos);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> Nodes(N + 1);
    while(M--)
    {
        int K;
        cin >> K;
        int U, V;
        cin >> U;
        for(int i = 1; i < K; ++i)
        {
            cin >> V;
            Nodes[V].push_back(U);
            U = V;
        }
    }

    vector<pair<int, int64_t>> NodeInfos(N + 1);
    for(int i = 1; i < Nodes.size(); ++i) NodeInfos[i] = {i, 0};
    for(int i = 1; i <= N; ++i)
    {
        vector<bool> bParent(N + 1, false);
        UpdateWeight(i, Nodes, bParent, NodeInfos);
    }

    sort(NodeInfos.begin(), NodeInfos.end(), [](pair<int, int64_t> A, pair<int, int64_t> B){ return A.second < B.second; });

    if(bCycle) cout << 0;
    else for(int i = 1; i < NodeInfos.size(); ++i) cout << NodeInfos[i].first << '\n';

    return 0;
}

int64_t UpdateWeight(int i, const vector<vector<int>> &Nodes, vector<bool> &bParent, vector<pair<int, int64_t>> &NodeInfos)
{
    if(bParent[i])
    {
        bCycle = true;
        return 0;
    }
    if(NodeInfos[i].second == 0)
    {
        bParent[i] = true;
        vector<bool> bVisited(NodeInfos.size(), false);
        for(int j = 0; j < Nodes[i].size(); ++j)
        {
            if(!bVisited[j])
            {
                bVisited[j] = true;
                NodeInfos[i].second = max(NodeInfos[i].second, UpdateWeight(Nodes[i][j], Nodes,bParent,NodeInfos));
            }
        }
        NodeInfos[i].second += 1;
        bParent[i] = false;
    }
    return NodeInfos[i].second;
}

