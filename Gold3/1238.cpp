#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> Mat;
    Mat.resize(n + 1);
    for(int i = 1; i < n + 1; ++i)
    {
        Mat[i].resize(n + 1);
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
        Mat[u][v] = w;
    }

    for(int k = 1; k < n + 1; ++k)
        for(int i = 1; i < n + 1; ++i)
            for(int j = 1; j < n + 1; ++j)
                Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
    
    int LongTime = 0;
    for(int i = 1; i < n + 1; ++i)
    {

        LongTime = max(LongTime, Mat[i][x] + Mat[x][i]);
    }
    cout << LongTime;

    return 0;
}