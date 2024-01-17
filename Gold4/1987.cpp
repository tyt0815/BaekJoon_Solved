#include <iostream>
#include <vector>

using namespace std;

int dfs(int x, int y, int Depth, vector<bool>& IsVisited, vector<vector<int>>& Board);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    vector<vector<int>> Board;
    cin >> r >> c;
    Board.resize(r);
    for(int i = 0 ; i < r; ++i)
    {
        Board[i].resize(c);
        for(int j = 0; j < c; ++j)
        {
            char c;
            cin >> c;
            Board[i][j] = c - 'A';
        }
    }

    vector<bool> IsVisited(30, false);
    cout << dfs(0,0,1, IsVisited, Board);

    return 0;
}

int dfs(int x, int y, int Depth, vector<bool> &IsVisited, vector<vector<int>> &Board)
{
    if(IsVisited[Board[x][y]])
    {
        return Depth - 1;
    }
    IsVisited[Board[x][y]] = true;

    int MaxDist = Depth;

    // 상
    if(x - 1 > -1)
    {
        MaxDist = dfs(x - 1, y, Depth + 1, IsVisited, Board);
    }
    // 좌
    if(y - 1 > -1)
    {
        MaxDist = max(MaxDist, dfs(x, y - 1, Depth + 1, IsVisited, Board));
    }
    // 하
    if(x + 1 < Board.size())
    {
        MaxDist = max(MaxDist, dfs(x + 1, y, Depth + 1, IsVisited, Board));
    }
    // 우
    if(y + 1 < Board[0].size())
    {
        MaxDist = max(MaxDist, dfs(x, y + 1, Depth + 1, IsVisited, Board));
    }
    IsVisited[Board[x][y]] = false;
    return MaxDist;
}
