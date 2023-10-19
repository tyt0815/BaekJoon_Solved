#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<uint32_t, uint32_t> POINT;

void SearchCampus(POINT Pos, int i, int j);

uint32_t n, m;
vector<vector<char>> Campus;
queue<POINT> q;
uint32_t Cnt = 0;
POINT Start;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;
    Campus.resize(n);
    for(uint32_t i = 0; i < n; ++i)
    {
        Campus[i].resize(m);
        for(uint32_t j = 0; j < m; ++j)
        {
            cin >> Campus[i][j];
            if(Campus[i][j] == 'I')
            {
                Start = POINT(i, j);
            }
        }
    }

    q.push(Start);
    while(!q.empty())
    {
        POINT Pos = q.front();
        SearchCampus(Pos, -1, 0);
        SearchCampus(Pos, 1, 0);
        SearchCampus(Pos, 0, -1);
        SearchCampus(Pos, 0, 1);
        q.pop();
    }
    
    if(Cnt == 0) cout << "TT";
    else cout << Cnt;

    return 0;
}

void SearchCampus(POINT Pos, int i, int j)
{
    int x = Pos.first, y = Pos.second;
    while (true)
    {
        x += i, y += j;
        if(!(x > -1 && x < n && y > -1 && y < m)) break;
        if(Campus[x][y] == 'X') break;
        if(Campus[x][y] == 'I') continue;
        if(Campus[x][y] == 'P') ++Cnt;
        Campus[x][y] = 'I';
        
        q.push(POINT(x, y));
    }
    
    
}