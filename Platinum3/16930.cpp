#include <iostream>
#include <queue>

using namespace std;

typedef struct
{
    int x;
    int y;
}pos;

bool f(char **mat, int **cnt, queue<pos> &q, pos in, int x2, int y2, int n, int m, int start, int end, int offset, int mod);

int main()
{
    int n, m, k;
    int x1, y1, x2, y2;
    int **cnt;
    queue<pos> q;
    char** mat;
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
    cnt[x1][y1] = 0;
    mat[x1][y1] = 'x';
    q.push(temp);
    while(true)
    {
        temp = q.front();
        q.pop();
        // cout << temp.x << temp.y << endl;

        if(f(mat,cnt,q,temp,x2,y2,n,m,1,k+1,1,0))
        {
            break;
        }
        if(f(mat,cnt,q,temp,x2,y2,n,m,-1,-k-1,-1,0))
        {
            break;
        }
        if(f(mat,cnt,q,temp,x2,y2,n,m,1,k+1,1,1))
        {
            break;
        }
        if(f(mat,cnt,q,temp,x2,y2,n,m,-1,-k-1,-1,1))
        {
            break;
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

bool f(char **mat, int **cnt, queue<pos> &q, pos in, const int x2, const int y2, const int n, const int m, const int start, const int end, const int offset, const int mod)
{
    for(int i = start; i != end; i+=offset)
    {
        int x = in.x ,y = in.y;
        if(mod == 0) { x += i;}
        else { y += i; }
        if(x == x2 && y == y2)
        {
            cnt[x2][y2] = cnt[in.x][in.y] + 1;
            return true;
        }
        if(x >= 0 && x < n && y >= 0 && y < m )
        {
            if(mat[x][y] == '.')
            {
                pos temp;
                temp.x = x; temp.y = y; 
                cnt[x][y] = cnt[in.x][in.y]+1;
                q.push(temp);
                mat[x][y] = 'x';
            }
            else if(mat[x][y] == '#')
            {
                break;
            }
            else if(cnt[x][y] <= cnt[in.x][in.y])
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return false;
}