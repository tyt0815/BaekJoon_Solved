// #include <iostream>
// #include <vector>

// constexpr int INF = 100000000;

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;      // 노드의 개수
//     int M;      // 알고싶은 노드 쌍의 개수
//     cin >> N >> M;
    
//     vector<vector<int>> Mat(N + 1, vector<int>(N + 1, INF));

//     for(int i = 0; i < N - 1; ++i)
//     {
//         int u;
//         int v;
//         int w;
//         cin >> u >> v >> w;
//         Mat[u][v] = min(Mat[u][v], w);
//         Mat[v][u] = Mat[u][v];
//     }

//     for(int k = 1; k <= N; ++k)
//     {
//         for(int j = 1; j <= N; ++j)
//         {
//             for(int i = 1; i <= N; ++i)
//             {
//                 Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
//             }
//         }
//     }

//     for(int i = 0; i < M; ++i)
//     {
//         int u;
//         int v;
//         cin >> u >> v;
//         cout << Mat[u][v] << '\n';
//     }

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

struct FEdge
{
    int Node;
    int Weight;
};

int CalcDistanceRecursive(const vector<vector<FEdge>>& Nodes, int Current, int Target, vector<bool>& bVisited, int Sum)
{
    if(Current == Target)
    {
        return Sum;
    }
    
    bVisited[Current] = true;
    for(int i = 0; i < Nodes[Current].size(); ++i)
    {
        if(bVisited[Nodes[Current][i].Node])
        {
            continue;
        }
        int Dist = CalcDistanceRecursive(Nodes, Nodes[Current][i].Node, Target, bVisited, Sum + Nodes[Current][i].Weight);
        if(Dist > 0)
        {
            return Dist;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;      // 노드의 개수
    int M;      // 알고싶은 노드 쌍의 개수
    cin >> N >> M;
    
    vector<vector<FEdge>> Nodes(N + 1);
    for(int i = 0; i < N - 1; ++i)
    {
        int U;
        int V;
        int W;
        cin >> U >> V >> W;
        Nodes[U].push_back({V, W});
        Nodes[V].push_back({U, W});
    }

    while(M--)
    {
        vector<bool> bVisited(N + 1, false);
        int U;
        int V;
        cin >> U >> V;
        cout << CalcDistanceRecursive(Nodes, U, V, bVisited, 0) << '\n';
    }
    return 0;
}