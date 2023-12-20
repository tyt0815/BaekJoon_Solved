#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> Paper;

int Tet1(int i, int j);
int Tet2(int i, int j);
int Tet3(int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int MaxTetSum = 0;
    cin >> n >> m;
    Paper.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Paper[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            cin >> Paper[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            MaxTetSum = max(MaxTetSum, Tet1(i, j));
            MaxTetSum = max(MaxTetSum, Tet2(i, j));
            MaxTetSum = max(MaxTetSum, Tet3(i, j));
        }
    }

    cout << MaxTetSum;

    return 0;
}

int Tet1(int i, int j)
{
    int Out = 0;
    if(i + 3 < n)
    {
        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 2][j] + Paper[i + 3][j]);
    }
    if(j + 3 < m)
    {
        Out = max(Out, Paper[i][j] + Paper[i][j + 1] + Paper[i][j + 2] + Paper[i][j + 3]);
    }
    return Out;
}

int Tet2(int i, int j)
{
    int Out = 0;
    if(i + 1 < n && j + 1 < m)
    {
        Out = max(Out, Paper[i][j] + Paper[i+1][j] + Paper[i][j+1] + Paper[i+1][j+1]);
    }
    return Out;
}

int Tet3(int i, int j)
{
    int Out = 0;
    if(i + 2 < n && j + 1 < m)
    {
        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 2][j] + Paper[i + 2][j + 1]);
        Out = max(Out, Paper[i][j + 1] + Paper[i + 1][j + 1] + Paper[i + 2][j + 1] + Paper[i + 2][j]);
        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 2][j] + Paper[i][j + 1]);
        Out = max(Out, Paper[i][j + 1] + Paper[i + 1][j + 1] + Paper[i + 2][j + 1] + Paper[i][j]);

        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 1][j + 1] + Paper[i + 2][j + 1]);
        Out = max(Out, Paper[i][j + 1] + Paper[i + 1][j + 1] + Paper[i + 1][j] + Paper[i + 2][j]);

        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 2][j] + Paper[i + 1][j + 1]);
        Out = max(Out, Paper[i][j + 1] + Paper[i + 1][j + 1] + Paper[i + 2][j + 1] + Paper[i + 1][j]);
    }
    if(i + 1 < n && j + 2 < m)
    {
        Out = max(Out, Paper[i + 1][j] + Paper[i][j] + Paper[i][j + 1] + Paper[i][j + 2]);
        Out = max(Out, Paper[i][j] + Paper[i][j + 1] + Paper[i][j + 2] + Paper[i + 1][j + 2]);
        Out = max(Out, Paper[i][j] + Paper[i + 1][j] + Paper[i + 1][j + 1] + Paper[i + 1][j + 2]);
        Out = max(Out, Paper[i + 1][j] + Paper[i + 1][j + 1] + Paper[i + 1][j + 2] + Paper[i][j + 2]);

        Out = max(Out, Paper[i + 1][j] + Paper[i + 1][j + 1] + Paper[i][j + 1] + Paper[i][j + 2]);
        Out = max(Out, Paper[i][j] + Paper[i][j + 1] + Paper[i + 1][j + 1] + Paper[i + 1][j + 2]);

        Out = max(Out, Paper[i][j] + Paper[i][j + 1] + Paper[i][j + 2] + Paper[i + 1][j + 1]);
        Out = max(Out, Paper[i + 1][j] + Paper[i + 1][j + 1] + Paper[i + 1][j + 2] + Paper[i][j + 1]);
    }

    return Out;
}

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}