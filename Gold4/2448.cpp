#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void DrawStar11(int n, pair<int, int> Start, vector<vector<char>>& Stars);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    vector<vector<char>> Stars;
    cin >> n;
    k = log2(n / 3);
    m = 6 * pow(2, k) - 1;
    Stars.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Stars[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            Stars[i][j] = ' ';
        }
    }

    DrawStar11(n, {Stars.size() - 1, 0}, Stars);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << Stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void DrawStar11(int n, pair<int, int> Start, vector<vector<char>>& Stars)
{
    if(n < 3)
    {
        return;
    }
    int k = log2(n / 3);
    int m = 6 * pow(2, k) - 1;
    int i = Start.first, j = Start.second, Cnt = 0;
    while(true)
    {
        if(Cnt == m)
        {
            break;
        }

        if(Cnt % 6 != 5)
        {
            Stars[Start.first][j] = '*';
        }
        Stars[i][j] = '*';

        ++Cnt;
        i = Cnt > m / 2 ? i + 1 : i - 1;
        ++j;
    }

    DrawStar11(n / 2,Start , Stars);
    DrawStar11(n / 2,{Start.first, Start.second + m / 2 + 1} , Stars);
    DrawStar11(n / 2,{Start.first - n / 2, Start.second + m / 4 + 1} , Stars);
}
