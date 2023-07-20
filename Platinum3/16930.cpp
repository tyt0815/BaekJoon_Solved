/*
문제
진영이는 다이어트를 위해 N×M 크기의 체육관을 달리려고 한다. 체육관은 1×1 크기의 칸으로 나누어져 있고, 칸은 빈 칸 또는 벽이다. x행 y열에 있는 칸은 (x, y)로 나타낸다.

매 초마다 진영이는 위, 아래, 오른쪽, 왼쪽 중에서 이동할 방향을 하나 고르고, 그 방향으로 최소 1개, 최대 K개의 빈 칸을 이동한다.

시작점 (x1, y1)과 도착점 (x2, y2)가 주어졌을 때, 시작점에서 도착점으로 이동하는 최소 시간을 구해보자.

입력
첫째 줄에 체육관의 크기 N과 M, 1초에 이동할 수 있는 칸의 최대 개수 K가 주어진다.

둘째 줄부터 N개의 줄에는 체육관의 상태가 주어진다. 체육관의 각 칸은 빈 칸 또는 벽이고, 빈 칸은 '.', 벽은 '#'으로 주어진다.

마지막 줄에는 네 정수 x1, y1, x2, y2가 주어진다. 두 칸은 서로 다른 칸이고, 항상 빈 칸이다.

출력
(x1, y1)에서 (x2, y2)로 이동하는 최소 시간을 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

제한
2 ≤ N, M ≤ 1,000
1 ≤ K ≤ 1,000
1 ≤ x1, x2 ≤ N
1 ≤ y1, y2 ≤ M
*/

#include <iostream>
#include <queue>
#define INF 1000000

using namespace std;

typedef struct
{
    int x;
    int y;
}pos;

int main()
{
    int n, m, k;
    int x1, y1, x2, y2;
    queue<pos> q;
    char** mat;
    int** cnt;
    cin >> n >> m >> k;
    mat = new char*[n];
    cnt = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        mat[i] = new char[m];
        cnt[i] = new int[m];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
            cnt[i][j] = INF;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;
    if(mat[x1][y1] == '#' || mat[x2][y2] == '#')
    {
        cout << -1;
        return 0;
    }
    pos temp;
    temp.x = x1; temp.y = y1;
    mat[x1][y1] = 'x';
    cnt[x1][y1] = 0;
    q.push(temp);
    while(true)
    {
        int x,y;
        temp = q.front();
        q.pop();
        x = temp.x; y = temp.y;
        cout << x << y << endl;
        if(x == x2 && y == y2)
        {
            break;
        }

        for(int i = 1; i < k+1; ++i)
        {
            if(x+i >= 0 && x+i < n)
            {
                if(mat[x+i][y] == '.')
                {
                    if(x+i == x2 && y == y2)
                    {
                        cout << cnt[x][y]+1;
                        return 0;
                    }
                    temp.x = x+i; temp.y = y;
                    q.push(temp);
                    mat[temp.x][temp.y] = 'x';
                    cnt[temp.x][temp.y] = cnt[x][y]+1;
                }
                else if(mat[x+i][y] == '#' || cnt[x+i][y] <= cnt[x][y])
                {
                    break;
                }
            }
        }
        for(int i = -1; i > -(k+1); --i)
        {
            if(x+i >= 0 && x+i < n)
            {
                if(mat[x+i][y] == '.')
                {
                    if(x+i == x2 && y == y2)
                    {
                        cout << cnt[x][y]+1;
                        return 0;
                    }
                    temp.x = x+i; temp.y = y;
                    q.push(temp);
                    mat[temp.x][temp.y] = 'x';
                    cnt[temp.x][temp.y] = cnt[x][y]+1;
                }
                else if(mat[x+i][y] == '#' || cnt[x+i][y] <= cnt[x][y])
                {
                    break;
                }
            }
        }
        for(int i = 1; i < k+1; ++i)
        {
            if(y+i >= 0 && y+i < n)
            {
                if(mat[x][y+i] == '.')
                {
                    if(x == x2 && y+i == y2)
                    {
                        cout << cnt[x][y]+1;
                        return 0;
                    }
                    temp.x = x; temp.y = y+i;
                    q.push(temp);
                    mat[temp.x][temp.y] = 'x';
                    cnt[temp.x][temp.y] = cnt[x][y]+1;
                }
                else if(mat[x][y+i] == '#' || cnt[x][y+i] <= cnt[x][y])
                {
                    break;
                }
            }
        }
        for(int i = -1; i > -(k+1); --i)
        {
            if(y+i >= 0 && y+i < n)
            {
                if(mat[x][y+i] == '.')
                {
                    if(x == x2 && y+i == y2)
                    {
                        cout << cnt[x][y]+1;
                        return 0;
                    }
                    temp.x = x; temp.y = y+i;
                    q.push(temp);
                    mat[temp.x][temp.y] = 'x';
                    cnt[temp.x][temp.y] = cnt[x][y]+1;
                }
                else if(mat[x][y+i] == '#' || cnt[x][y+i] <= cnt[x][y])
                {
                    break;
                }
            }
        }
        

        if(q.empty())
        {
            cnt[x2][y2] = -1;
            break;
        }
    }

    cout << cnt[x2][y2];

    return 0;
}