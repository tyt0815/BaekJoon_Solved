#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    vector<vector<int>> Mat;
    vector<int> Items;
    cin >> n >> m >> r;
    Mat.resize(n);
    Items.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            Mat[i][j] = INF;
        }
        Mat[i][i] = 0;
        cin >> Items[i];
    }
    for(int i = 0; i < r; ++i)
    {
        int v, u, w;
        cin >> v >> u >> w;
        --v;--u;
        Mat[v][u] = Mat[u][v] = w;
    }


    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(Mat[i][j] > Mat[i][k] + Mat[k][j])
                {
                    Mat[i][j] = Mat[i][k] + Mat[k][j];
                }
            }
        }
    }

    int MaxValue = 0;
    for(int i = 0; i < n; ++i)
    {
        int Value = 0;
        for(int j = 0; j < n; ++j)
        {
            if(Mat[i][j] <= m)
            {
                Value += Items[j];
            }
        }
        MaxValue = max(MaxValue, Value);
    }

    cout << MaxValue;

    return 0;
}