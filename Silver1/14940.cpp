#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;
};

int n,m;
vector<vector<char>> Mat;
vector<vector<int>> Dist;
queue<Point> q;

void ExplorFunc(Point Pos, int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Point Target;


    cin >> n >> m;
    Mat.resize(n);
    Dist.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(m);
        Dist[i].resize(m);
        for(int j = 0;j < m; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == '0')
            {
                Dist[i][j] = 0;
            }
            else if(Mat[i][j] == '1')
            {
                Dist[i][j] = -1;
            }
            if(Mat[i][j] == '2')
            {
                Target.x = i;
                Target.y = j;
                Dist[i][j] = 0;
            }
            
        }
    }

    q.push(Target);

    while (!q.empty())
    {
        Point Temp = q.front();
        q.pop();
        
        ExplorFunc(Temp, -1, 0);
        ExplorFunc(Temp, 1, 0);
        ExplorFunc(Temp, 0, -1);
        ExplorFunc(Temp, 0, 1);
        
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << Dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void ExplorFunc(Point Pos, int a, int b)
{
    Point Temp = Pos;
    Temp.x += a;
    Temp.y += b;
    if(Temp.x < 0 || Temp.x >= n || Temp.y < 0 || Temp.y >= m) return;
    if(Mat[Temp.x][Temp.y] == '1')
    {
        Mat[Temp.x][Temp.y] = '3';
        Dist[Temp.x][Temp.y] = Dist[Pos.x][Pos.y] + 1;
        q.push(Temp);
    }
}