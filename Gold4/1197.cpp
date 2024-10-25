#include <iostream>
#include <queue>

using namespace std;

struct FNode
{
    int To;
    int64_t Weight;
    struct Greater
    {
        bool operator()(FNode U, FNode V) { return U.Weight > V.Weight; }
    };
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    vector<vector<FNode>> Graph(V + 1);
    priority_queue<FNode, vector<FNode>, FNode::Greater> PQ;
    for(int i = 0; i < E; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Graph[A].push_back({B, C});
        Graph[B].push_back({A, C});
    }

    vector<bool> bVisited(V + 1, false);
    int Cnt = 1;
    int64_t Sum = 0;
    for(int i = 0; i < Graph[1].size(); ++i) PQ.push(Graph[1][i]);
    bVisited[1] = true;

    while(Cnt < V)
    {
        while(bVisited[PQ.top().To]) PQ.pop();
        FNode Node = PQ.top();
        PQ.pop();
        Sum += Node.Weight;
        ++Cnt;
        bVisited[Node.To] = true;
        for(int i = 0; i < Graph[Node.To].size(); ++i)
        {
            if(bVisited[Graph[Node.To][i].To]) continue;
            PQ.push(Graph[Node.To][i]);
        }
    }
    cout << Sum;

    return 0;
}
