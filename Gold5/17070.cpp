#include <iostream>
#include <vector>

using namespace std;

struct SPush
{
    int Right;
    int Down;
    int Cross;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<vector<int>> Mat;
    vector<vector<SPush>> p;
    cin >> n;
    Mat.resize(n);
    p.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        p[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> Mat[i][j];
            p[i][j] = {0, 0, 0};
        }
    }

    for(int i = 1; i < n && Mat[0][i] != 1; ++i)
    {
        p[0][i] = {1, 0, 0};
    }
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            if(Mat[i][j] == 1) continue;
            p[i][j].Right = p[i][j - 1].Right + p[i][j - 1].Cross;
            p[i][j].Down = p[i - 1][j].Down + p[i - 1][j].Cross;
            if(Mat[i - 1][j] != 1 && Mat[i][j - 1] != 1)
            {
                p[i][j].Cross = p[i- 1][j - 1].Right + p[i - 1][j - 1].Down + p[i - 1][j - 1].Cross;
            }
        }
    }

    cout << p[n - 1][n - 1].Right + p[n - 1][n - 1].Down + p[n - 1][n - 1].Cross;

    return 0;
}