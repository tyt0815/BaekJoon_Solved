#include <iostream>
#include <vector>
#define INF 1000000000


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<vector<int>> Mat;
    cin >> n >> m;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0 ; j < n; ++j)
        {
            Mat[i][j] = INF;
        }
        Mat[i][i] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
        int a, b, Cost;
        cin >> a >> b >> Cost;
        Mat[a - 1][b - 1] = min(Mat[a - 1][b - 1], Cost);
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

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < n; ++j)
        {
            if(Mat[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << Mat[i][j] << ' ';
            }
        }
        cout << '\n';
    }


    return 0;
}