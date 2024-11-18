// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;


// struct FNodeInfo
// {
//     int NodeNumber = 0;
//     int Depth = 0;
//     vector<int> To;

//     bool operator<(const FNodeInfo& RValue) { return Depth < RValue.Depth; }
// };

// void UpdateDepth(int Node, int Depth, vector<FNodeInfo> &Nodes);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int64_t T;
//     cin >> T;
//     for(int t = 0; t < T; ++t)
//     {
//         // Init
//         int N, K, W;
//         cin >> N >> K;
//         vector<int> BuildTimes(N + 1);
//         vector<FNodeInfo> Nodes(N + 1);
//         vector<int64_t> AccumulatedTime(N + 1, 0);
//         for(int i = 1; i < BuildTimes.size(); ++i)
//         {
//             cin >> BuildTimes[i];
//             AccumulatedTime[i] = BuildTimes[i];
//             Nodes[i].NodeNumber = i;
//         }
//         for(int i = 0; i < K; ++i)
//         {
//             int U, V;
//             cin >> U >> V;
//             Nodes[U].To.push_back(V);
//         }
//         cin >> W;

//         for(int i = 1; i < Nodes.size(); ++i) UpdateDepth(i, 1, Nodes);

//         sort(Nodes.begin(), Nodes.end());
//         int j = 1;
//         for(int j = 1;j < AccumulatedTime.size(); ++j)
//         {
//             const FNodeInfo &Node = Nodes[j];
//             for(int k = 0; k < Node.To.size(); ++k)
//             {
//                 AccumulatedTime[Node.To[k]] = max(AccumulatedTime[Node.To[k]], AccumulatedTime[Node.NodeNumber] + BuildTimes[Node.To[k]]);
//             }
//         }
//         cout << AccumulatedTime[W] << '\n';
//     }

//     return 0;
// }

// void UpdateDepth(int Node, int Depth, vector<FNodeInfo> &Nodes)
// {
//     if(Nodes[Node].Depth >= Depth) return;
//     Nodes[Node].Depth = Depth;
//     for(int i = 0; i < Nodes[Node].To.size(); ++i) UpdateDepth(Nodes[Node].To[i], Depth + 1, Nodes);
// }

#include <iostream>
#include <vector>

using namespace std;

struct FNodeInfo
{
    int BuildTime;
    int64_t AccumulatedTime;
    vector<int> From;
};

int64_t CalcAccumulatedTime(int i, vector<FNodeInfo> &Nodes);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int N, K, W;
        cin >> N >> K;
        vector<FNodeInfo> Nodes(N + 1);
        for(int i = 1; i < Nodes.size(); ++i)
        {
            cin >> Nodes[i].BuildTime;
            Nodes[i].AccumulatedTime = -1;
        }
        for(int i = 0; i < K; ++i)
        {
            int U, V;
            cin >> U >> V;
            Nodes[V].From.push_back(U);
        }
        cin >> W;

        cout << CalcAccumulatedTime(W, Nodes) << '\n';
    }

    return 0;
}

int64_t CalcAccumulatedTime(int i, vector<FNodeInfo> &Nodes)
{
    if(Nodes[i].AccumulatedTime == -1)
    {
        Nodes[i].AccumulatedTime = 0;
        for(int j = 0; j < Nodes[i].From.size(); ++j)
        {
            Nodes[i].AccumulatedTime = max(Nodes[i].AccumulatedTime, CalcAccumulatedTime(Nodes[i].From[j], Nodes));
        }
        Nodes[i].AccumulatedTime += Nodes[i].BuildTime;
    }
    return Nodes[i].AccumulatedTime;
}
