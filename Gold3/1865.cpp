#include <iostream>
#include <vector>

#define INF 1000000

using namespace std;

bool TestCase();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; ++i)
    {
        if(TestCase())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return  0;
}

bool TestCase()
{
    int n, m, w;
    cin >> n >> m >> w;
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
        int s, e, t;
        cin >> s >> e >> t;
        Mat[s][e] = min(Mat[s][e], t);
        Mat[e][s] = min(Mat[e][s], t);
    }
    for(int i = 0; i < w; ++i)
    {
        int s, e, t;
        cin >> s >> e >> t;
        Mat[s][e] = min(Mat[s][e], -t);
    }

    for(int k = 1; k < n + 1; ++k)
        for(int i = 1; i < n + 1; ++i)
            for(int j = 1; j < n + 1; ++j)
                Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
    for(int i = 1; i < n + 1; ++i)
    {
        if(Mat[i][i] < 0) return true;
    }

    return false;
}
