#include <iostream>
#include <vector>
#include <queue>
#define TMT(Pos) Tomato[Pos.m][Pos.n][Pos.h]

using namespace std;

struct Pos
{
    int m;
    int n;
    int h;
};

int m, n, h;
int ZeroCount = 0;
vector<vector<vector<int>>> Tomato;     // 순서대로 가로, 세로, 높이
queue<Pos> q;
void CheckFunc(Pos Temp, int i, int j, int k);

int main()
{
    
    cin >> m >> n >> h;
    Tomato.resize(m);
    for(int i = 0; i < m; ++i)
    {
        Tomato[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            Tomato[i][j].resize(h);
        }
    }
    for(int k = 0; k < h; ++k)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int i = 0; i < m; ++i)
            {
                cin >> Tomato[i][j][k];
                if(Tomato[i][j][k] == 1)
                {
                    q.push({i, j, k});
                }
                else if(Tomato[i][j][k] == 0)
                {
                    ++ZeroCount;
                }
            }
        }
    }

    
    int DayCnt = 0;

    if(ZeroCount == 0)
    {
        cout << 0;
        return 0;
    }

    while(!q.empty())
    {
        Pos Temp = q.front();
        DayCnt = TMT(Temp);
        q.pop();
        CheckFunc(Temp, -1, 0, 0);
        CheckFunc(Temp, 1, 0, 0);
        CheckFunc(Temp, 0, -1, 0);
        CheckFunc(Temp, 0, 1, 0);
        CheckFunc(Temp, 0, 0, -1);
        CheckFunc(Temp, 0, 0, 1);
    }
    if(ZeroCount == 0)
    {
        --DayCnt;
        cout << DayCnt; 
    }
    else
    {
        cout << -1;
    }

    return 0;
}

void CheckFunc(Pos Temp, int i, int j, int k)
{
    Pos SidePos = Temp;
    SidePos.m += i;
    SidePos.n += j;
    SidePos.h += k;
    if(SidePos.m > -1 && SidePos.m < m && SidePos.n > -1 && SidePos.n < n && SidePos.h > -1 && SidePos.h < h
    && TMT(SidePos) == 0)
    {
        TMT(SidePos) = TMT(Temp) + 1;
        q.push(SidePos);
        --ZeroCount;
    }
}
