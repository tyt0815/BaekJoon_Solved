#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001

using namespace std;

struct MinHeapData
{
    int Key;
    int Weight;
    bool operator<(const MinHeapData& Other) const
    {
        return Weight > Other.Weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> Mat;
    vector<vector<vector<int>>> Route;
    Mat.resize(n + 1);
    Route.resize(n + 1);
    for(int i = 1; i < n + 1; ++i)
    {
        Mat[i].resize(n + 1);
        Route[i].resize(n + 1);
        for(int j = 1; j < n + 1; ++j)
        {
            Mat[i][j] = INF;
        }
        Mat[i][i] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(Mat[u][v] > w)
        {
            Mat[u][v] = w;
            Route[u][v].resize(2);
            Route[u][v][0] = u;
            Route[u][v][1] = v;
        }
    }
    int u, v;
    cin >> u >> v;

    priority_queue<MinHeapData> MinHeap;
    for(int i = 1; i < n + 1; ++i)
    {
        if(Mat[u][i] == INF) continue;
        MinHeap.push({i, Mat[u][i]});
    }
    
    vector<bool> IsVisited(n + 1, false);
    while(!MinHeap.empty())
    {
        int Pass = MinHeap.top().Key, Weight = MinHeap.top().Weight;
        MinHeap.pop();
        if(IsVisited[Pass]) continue;
        IsVisited[Pass] = true;
        for(int Target = 1; Target < n + 1; ++Target)
        {
            if(Mat[u][Target] > Mat[u][Pass] + Mat[Pass][Target])
            {
                Mat[u][Target] = Mat[u][Pass] + Mat[Pass][Target];
                Route[u][Target] = Route[u][Pass];
                Route[u][Target].push_back(Target);
                MinHeap.push({Target, Mat[u][Target]});
            }
        }
    }

    cout << Mat[u][v] << '\n';
    cout << Route[u][v].size() << '\n';
    for(int i = 0 ; i < Route[u][v].size(); ++i)
    {
        cout << Route[u][v][i] << ' ';
    }

    return 0;
}