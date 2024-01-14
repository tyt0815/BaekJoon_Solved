#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

struct SNode
{
    int Node;
    int w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    int Start;
    vector<vector<SNode>> Graph;
    cin >> v >> e;
    cin >> Start;
    Graph.resize(v + 1);
    for(int i = 0; i < e; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Graph[a].push_back({b, w});
    }

    vector<int> MinDist(v + 1, INF);
    vector<bool> IsVisited(v + 1, false);
    MinDist[Start] = 0;

    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> MinHeap(compare);// first: key, second: weight
    MinHeap.push({Start, 0});
    MinHeap.push({0, INF});
    while(true)
    {
        pair<int, int> Node;
        while(true)
        {
            if(!IsVisited[MinHeap.top().first])
            {
                Node = MinHeap.top();
                MinHeap.pop();
                break;
            }
            MinHeap.pop();
        }
        if(Node.second == INF)
        {
            break;
        }
        IsVisited[Node.first] = true;

        pair<int, int> Next = {0, INF};
        for(int i = 0; i < Graph[Node.first].size(); ++i)
        {
            if(MinDist[Graph[Node.first][i].Node] > MinDist[Node.first] + Graph[Node.first][i].w)
            {
                MinDist[Graph[Node.first][i].Node] = MinDist[Node.first] + Graph[Node.first][i].w;
                MinHeap.push({Graph[Node.first][i].Node, MinDist[Graph[Node.first][i].Node]});
            }
        }

    }

    for(int i = 1; i < v + 1; ++i)
    {
        if(MinDist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << MinDist[i] << '\n';
        }
    }

    return 0;
}