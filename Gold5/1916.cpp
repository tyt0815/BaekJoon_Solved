// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct SNode
// {
//     int64_t Next;
//     int64_t Fee;
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int64_t n, m, Start, End, Fee;
//     vector<int64_t> p;
//     vector<vector<SNode>> BusInfo;
//     vector<bool> IsVisited;
//     cin >> n >> m;
//     BusInfo.resize(n + 1);
//     p.resize(n + 1);
//     IsVisited.resize(n + 1);
//     for(int64_t i = 0; i < n + 1; ++i)
//     {
//         p[i] = INT64_MAX;
//         IsVisited[i] = false;
//     }
//     for(int64_t i = 0; i < m; ++i)
//     {
//         cin >> Start >> End >> Fee;
//         BusInfo[Start].push_back({End, Fee});
//     }
//     cin >> Start >> End;
//     for(int64_t i = 0; i < BusInfo[Start].size(); ++i)
//     {
//         p[BusInfo[Start][i].Next] = min(BusInfo[Start][i].Fee, p[BusInfo[Start][i].Next]);
//     }
//     IsVisited[Start] = true;
//     while(true)
//     {
//         int64_t MinEdge = 0;
//         for(int64_t i = 1; i < n + 1; ++i)
//         {
//             if(!IsVisited[i] && p[MinEdge] > p[i])
//             {
//                 MinEdge = i;
//             }
//         }

//         IsVisited[MinEdge] = true;
//         if(IsVisited[End])
//         {
//             break;
//         }

//         for(int64_t i = 0; i < BusInfo[MinEdge].size(); ++i)
//         {
//             SNode Target = BusInfo[MinEdge][i];
//             p[Target.Next] = min(p[Target.Next], p[MinEdge] + Target.Fee);
//         }
//     }

//     cout << p[End];

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MaxN = 1000;
constexpr int MaxM = 100000;
constexpr int MaxCost = MaxN * MaxM;

struct FMinHeapNode
{
    struct Less
    {
        bool operator()(FMinHeapNode& A, FMinHeapNode& B) { return A.Cost > B.Cost; }
    };

    int To;
    int Cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B;
    cin >> N >> M;
    vector<vector<int>> Costs(N + 1, vector<int>(N + 1, MaxCost));
    for(int i = 0; i < M; ++i)
    {
        int Cost;
        cin >> A >> B >> Cost;
        Costs[A][B] = min(Costs[A][B], Cost);
    }
    cin >> A >> B;
    A; B;

    vector<int>& CostFromA = Costs[A];
    vector<bool> bVisited(N + 1, false);
    priority_queue<FMinHeapNode, vector<FMinHeapNode>, FMinHeapNode::Less> q;
    for(int i = 1; i < Costs[A].size(); ++i)
    {
        Costs[i][i] = 0;
        if(CostFromA[i] < CostFromA[0]) q.push({i, CostFromA[i]});
    }
    while(!q.empty())
    {
        FMinHeapNode Node;
        while(!q.empty())
        {
            Node = q.top();
            if(!bVisited[Node.To]) break;
            q.pop();
        }
        if(q.empty()) break;
        q.pop();
        bVisited[Node.To] = true;

        for(int i = 1; i < CostFromA.size(); ++i)
        {
            if(CostFromA[i] > CostFromA[Node.To] + Costs[Node.To][i])
            {
                CostFromA[i] = CostFromA[Node.To] + Costs[Node.To][i];
                q.push({i, CostFromA[i]});
            }
        }
    }

    cout << Costs[A][B];

    return 0;
}