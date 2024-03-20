#include <iostream>
#include <vector>

using namespace std;

void DrawStars(int Size, int i, int j, vector<vector<char>>& Stars);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> Stars(n, vector<char>(n, ' '));

    DrawStars(n, 0, 0, Stars);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << Stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void DrawStars(int Size, int i, int j, vector<vector<char>> &Stars)
{
    if(Size % 3 != 0) return;
    if(Size == 3)
    {
        for(int a = 0; a < 3; ++a)
        {
            for(int b = 0; b < 3; ++b)
            {
                if(a == 1 && b == 1) continue;
                Stars[i + a][j + b] = '*';
            }
        }
    }
    int Offset = Size / 3;
    for(int a = 0; a < 3; ++a)
    {
        for(int b = 0; b < 3; ++b)
        {
            if(a == 1 && b == 1) continue;
            DrawStars(Offset, i + a * Offset, j + b * Offset, Stars);
        }
    }
}
