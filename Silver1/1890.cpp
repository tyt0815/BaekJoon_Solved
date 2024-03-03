#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> GameBoard(n, vector<int>(n, 0));
    vector<vector<uint64_t>> p(n, vector<uint64_t>(n, 0));
    for(int i  = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> GameBoard[i][j];
        }
    }

    p[0][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == n - 1 &&  j == n - 1) continue;
            if(i + GameBoard[i][j] < n) p[i + GameBoard[i][j]][j] += p[i][j];
            if(j + GameBoard[i][j] < n) p[i][j + GameBoard[i][j]] += p[i][j];
        }
    }
    cout << p[n - 1][n - 1];

    return 0;
}