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
vector<vector<int>> Mat;
queue<Point> q;
int Total;
int Cnt = 0;
int Answer = 0;

void ExplorFunc(Point Pos, int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    Total = n * m;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(m);
        for(int j = 0;j < m; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == 1)
            {
                Point Temp;
                Temp.x = i;
                Temp.y = j;
                q.push(Temp);
                ++Cnt;
            }
            if(Mat[i][j] == -1)
            { 
                ++Cnt;
            }
        }
    }


    while (!q.empty())
    {
        Point Temp = q.front();
        Answer = max(Answer, Mat[Temp.x][Temp.y]);
        q.pop();
        
        ExplorFunc(Temp, -1, 0);
        ExplorFunc(Temp, 1, 0);
        ExplorFunc(Temp, 0, -1);
        ExplorFunc(Temp, 0, 1);

        if(Cnt == Total)
        {
            Temp = q.back();
            Answer = Mat[Temp.x][Temp.y];
            break;
        }
    }

    if(Cnt == Total)
    {
        cout << Answer - 1;
    }
    else
    {
        cout << -1;
    }
    

    return 0;
}

void ExplorFunc(Point Pos, int a, int b)
{
    Point Temp = Pos;
    Temp.x += a;
    Temp.y += b;
    if(Temp.x < 0 || Temp.x >= n || Temp.y < 0 || Temp.y >= m) return;
    if(Mat[Temp.x][Temp.y] == 0)
    {
        ++Cnt;
        Mat[Temp.x][Temp.y] = Mat[Pos.x][Pos.y] + 1;
        q.push(Temp);
    }
}