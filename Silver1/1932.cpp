#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, TriSize;
    vector<vector<int>> Triangle;
    vector<vector<int>> p;
    cin >> n;
    Triangle.resize(n);
    p.resize(n);
    for(int i = 0 ; i < n; ++i)
    {
        Triangle[i].resize(i + 1);
        p[i].resize(i + 1);
        for(int j = 0; j < i + 1; ++j)
        {
            cin >> Triangle[i][j];
        }
    }

    p[0][0] = Triangle[0][0];
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            int a = 0, b = 0;
            if(j - 1 >= 0)
            {
                a = p[i - 1][j - 1];
            }
            if(j <= i - 1)
            {
                b = p[i - 1][j];
            }
            p[i][j] = max(a, b) + Triangle[i][j];
        }
    }

    int Answer = 0;
    for(int i = 0; i < n; ++i)
    {
        Answer = max(p[n - 1][i], Answer);
    }

    cout << Answer;

    return 0;
}
