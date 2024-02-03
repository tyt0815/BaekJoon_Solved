#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> Mat;
pair<int, int> BabyPos;
int BabySize = 2;
int EatCount = 0;
int Time = 0;

bool FindFish();
void ExplorePos(int i, int j, int CurrTime, vector<vector<int>>& VisitTime, queue<pair<int, int>>& q);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == 9)
            {
                BabyPos = {i , j};
                Mat[i][j] = 0;
            }
        }
    }

    while(FindFish());

    cout << Time;

    return 0;
}

bool FindFish()
{
    queue<pair<int, int>> q;
    q.push(BabyPos);
    vector<vector<int>> VisitTime;
    VisitTime.resize(n);
    for(int i = 0; i < n; ++i)
    {
        VisitTime[i].resize(n);
        VisitTime[i].assign(n, -1);
    }
    VisitTime[BabyPos.first][BabyPos.second] = 0;
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        ExplorePos(i - 1, j, VisitTime[i][j], VisitTime, q);
        ExplorePos(i, j - 1, VisitTime[i][j], VisitTime, q);
        ExplorePos(i, j + 1, VisitTime[i][j], VisitTime, q);
        ExplorePos(i + 1, j, VisitTime[i][j], VisitTime, q);
    }
    if(VisitTime[BabyPos.first][BabyPos.second] > 0)
    {
        Mat[BabyPos.first][BabyPos.second] = 0;
        ++EatCount;
        if(EatCount == BabySize)
        {
            ++BabySize;
            EatCount = 0;
        }
        Time += VisitTime[BabyPos.first][BabyPos.second];
        return true;
    }
    return false;
}

void ExplorePos(int i, int j, int CurrTime, vector<vector<int>> &VisitTime, queue<pair<int, int>>& q)
{
    if(i < 0 || i >= n || j < 0 || j >= n || VisitTime[i][j] != -1 || Mat[i][j] > BabySize) return;
    if(VisitTime[BabyPos.first][BabyPos.second] != 0)
        if(CurrTime + 1 > VisitTime[BabyPos.first][BabyPos.second] || (i > BabyPos.first || (i == BabyPos.first && j > BabyPos.second)))
            return;

    VisitTime[i][j] = CurrTime + 1;
    if(Mat[i][j] > 0 && Mat[i][j] < BabySize)
    {
        BabyPos = {i, j};
    }
    else if(Mat[i][j] == 0 || Mat[i][j] == BabySize)
    {
        q.push({i, j});    
    }
    return;
}
