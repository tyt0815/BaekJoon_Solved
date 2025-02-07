#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct FNodeInfo
{
    vector<int> From;
    vector<int> To;
    int Number = 0;
    int Topology = 0;
    int EdgeCount = 0;
};

int UpdateTopology(int Node, vector<FNodeInfo>& NodeInfos);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;
    vector<FNodeInfo> NodeInfos(N + 1);
    for(int i = 0; i < M; ++i)
    {
        int U;
        int V;
        cin >> U >> V;
        NodeInfos[V].To.push_back(U);
        NodeInfos[U].From.push_back(V);
        NodeInfos[V].EdgeCount += 1;
    }
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 1; i < NodeInfos.size(); ++i)
    {
        NodeInfos[i].Number = i;
        UpdateTopology(i, NodeInfos);
        if(NodeInfos[i].EdgeCount == 0)
        {
            PQ.push(i);
        }
    }

    while(!PQ.empty())
    {
        int Node = PQ.top();
        PQ.pop();
        cout << Node << ' ';
        
        for(int NextNode : NodeInfos[Node].From)
        {
            --NodeInfos[NextNode].EdgeCount;
            if(NodeInfos[NextNode].EdgeCount == 0)
            {
                PQ.push(NextNode);
            }
        }
    }

    return 0;
}

int UpdateTopology(int Node, vector<FNodeInfo> &NodeInfos)
{
    if(NodeInfos[Node].Topology == 0)
    {
        for(int NextNode : NodeInfos[Node].To)
        {
            NodeInfos[Node].Topology = max(NodeInfos[Node].Topology, UpdateTopology(NextNode, NodeInfos));
        }
        ++NodeInfos[Node].Topology;
    }

    return NodeInfos[Node].Topology;
}
