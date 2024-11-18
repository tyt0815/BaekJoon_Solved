#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FNodeInfo
{
    int NodeNumber;
    uint64_t Weight;
    bool bVisited;
    bool operator<(const FNodeInfo& RValue) { return Weight < RValue.Weight; }
};

uint64_t UpdateAccumulatedWeight(int n, vector<FNodeInfo>& NodeInfos, const vector<vector<int>> &Nodes);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> Nodes(N + 1);
    vector<FNodeInfo> NodeInfos(N + 1, {0, 0, false});
    for(int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        if(A != B) Nodes[B].push_back(A);
    }

    for(int i = 1; i <= N; ++i)
    {
        NodeInfos[i].NodeNumber = i;
        UpdateAccumulatedWeight(i, NodeInfos, Nodes);
    }

    sort(NodeInfos.begin(), NodeInfos.end());

    for(int i = 1; i < NodeInfos.size(); ++i)
    {
        cout << NodeInfos[i].NodeNumber << ' ';
    }

    return 0;
}

uint64_t UpdateAccumulatedWeight(int n, vector<FNodeInfo>& NodeInfos, const vector<vector<int>> &Nodes)
{
    if(!NodeInfos[n].bVisited)
    {
        NodeInfos[n].bVisited = true;
        NodeInfos[n].Weight = 0;
        for(int i = 0; i < Nodes[n].size(); ++i)
        {
            NodeInfos[n].Weight = max(NodeInfos[n].Weight, UpdateAccumulatedWeight(Nodes[n][i], NodeInfos, Nodes));
        }
        NodeInfos[n].Weight += 1;
    }
    return NodeInfos[n].Weight;
}
