// #include <iostream>
// #include <vector>
// #include <queue>
// #define INF 99999999

// using namespace std;

// struct SNode
// {
//     int Node;
//     int w;
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int v, e;
//     int Start;
//     vector<vector<SNode>> Graph;
//     cin >> v >> e;
//     cin >> Start;
//     Graph.resize(v + 1);
//     for(int i = 0; i < e; ++i)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         Graph[a].push_back({b, w});
//     }

//     vector<int> MinDist(v + 1, INF);
//     vector<bool> IsVisited(v + 1, false);
//     MinDist[Start] = 0;

//     auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; };
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> MinHeap(compare);// first: key, second: weight
//     MinHeap.push({Start, 0});
//     MinHeap.push({0, INF});
//     while(true)
//     {
//         pair<int, int> Node;
//         while(true)
//         {
//             if(!IsVisited[MinHeap.top().first])
//             {
//                 Node = MinHeap.top();
//                 MinHeap.pop();
//                 break;
//             }
//             MinHeap.pop();
//         }
//         if(Node.second == INF)
//         {
//             break;
//         }
//         IsVisited[Node.first] = true;

//         pair<int, int> Next = {0, INF};
//         for(int i = 0; i < Graph[Node.first].size(); ++i)
//         {
//             if(MinDist[Graph[Node.first][i].Node] > MinDist[Node.first] + Graph[Node.first][i].w)
//             {
//                 MinDist[Graph[Node.first][i].Node] = MinDist[Node.first] + Graph[Node.first][i].w;
//                 MinHeap.push({Graph[Node.first][i].Node, MinDist[Graph[Node.first][i].Node]});
//             }
//         }

//     }

//     for(int i = 1; i < v + 1; ++i)
//     {
//         if(MinDist[i] == INF)
//         {
//             cout << "INF\n";
//         }
//         else
//         {
//             cout << MinDist[i] << '\n';
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <queue>
#include <unordered_map>

constexpr int Inf = 999999;

using namespace std;

struct FNode
{
    int To;
    int Weight;

    struct Greater
    {
        bool operator()(FNode A, FNode B) { return A.Weight > B.Weight; }
    };
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<FNode>> Distances(V + 1);
    {
        vector<unordered_map<int, int>> Temp(V + 1);
        for(int i = 0; i < E; ++i)
        {
            int X, Y, W;
            cin >> X >> Y >> W;
            if(Temp[X].find(Y) == Temp[X].end()) Temp[X][Y] = Inf;
            Temp[X][Y] = min(Temp[X][Y], W);
        }
        for(int i = 1; i <= V; ++i)
        {
            for(unordered_map<int, int>::iterator Iter = Temp[i].begin(); Iter != Temp[i].end(); ++Iter)
            {
                Distances[i].push_back({Iter->first, Iter->second});
            }
        }
    }
    

    vector<bool> bVisited(V + 1, false);
    vector<int> DistancesFromK(V + 1, Inf);
    priority_queue<FNode, vector<FNode>, FNode::Greater> PQ;
    for(int i = 0; i < Distances[K].size(); ++i)
    {
        DistancesFromK[Distances[K][i].To] = Distances[K][i].Weight;
        PQ.push({Distances[K][i].To, Distances[K][i].Weight});
    }
    DistancesFromK[K] = 0;
    bVisited[K] = true;
    while(true)
    {
        while(!PQ.empty() && bVisited[PQ.top().To]) PQ.pop();
        if(PQ.empty()) break;
        FNode Node = PQ.top();
        bVisited[Node.To] = true;
        PQ.pop();
        
        const int& Stopover = Node.To;
        for(int i = 0; i < Distances[Stopover].size(); ++i)
        {
            const int& Target = Distances[Stopover][i].To;
            const int& StopoverToTargetWeight = Distances[Stopover][i].Weight;
            if(DistancesFromK[Target] > DistancesFromK[Stopover] + StopoverToTargetWeight)
            {
                DistancesFromK[Target] = DistancesFromK[Stopover] + StopoverToTargetWeight;
                PQ.push({Target, DistancesFromK[Target]});
            }
        }
    }

    for(int i = 1; i <= V; ++i)
    {
        if(DistancesFromK[i] == Inf) cout << "INF";
        else cout << DistancesFromK[i];
        cout << '\n';
    }

    return 0;
}