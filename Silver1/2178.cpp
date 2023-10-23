#include <iostream>
#include <queue>

using namespace std;

struct Position
{
    int x;
    int y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    vector<vector<char>> Maze;
    vector<vector<int>> CountTable;

    cin >> n >> m;
    Maze.resize(n);
    CountTable.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Maze[i].resize(m);
        CountTable[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            cin >> Maze[i][j];
            CountTable[i][j] = 0;
        }
    }

    Maze[0][0] = '!';
    CountTable[0][0] = 1;

    queue<Position> q;
    q.push({0, 0});

    while (!q.empty())
    {
        Position Pos = q.front();
        Position Temp;
        q.pop();
        for(int i = -1; i < 2; ++i)
        {
            Temp.x = Pos.x + i; Temp.y = Pos.y;
            if(Temp.x > -1 && Temp.x < n && Maze[Temp.x][Temp.y] == '1')
            {
                Maze[Temp.x][Temp.y] = '!';
                CountTable[Temp.x][Temp.y] = CountTable[Pos.x][Pos.y] + 1;
                q.push(Temp);
                if(Temp.x == n - 1 && Temp.y == m)
                {
                    goto ToEnd;
                }
            }
        }
        for(int i = -1; i < 2; ++i)
        {
            Temp.x = Pos.x; Temp.y = Pos.y + i;
            if(Temp.y > -1 && Temp.y < m && Maze[Temp.x][Temp.y] == '1')
            {
                Maze[Temp.x][Temp.y] = '!';
                CountTable[Temp.x][Temp.y] = CountTable[Pos.x][Pos.y] + 1;
                q.push(Temp);
                if(Temp.x == n - 1 && Temp.y == m)
                {
                    goto ToEnd;
                }
            }
        }
    }

    ToEnd:;
    cout << CountTable[n-1][m-1];

    return 0;
}