#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
#define INTERNALAIR INF - 1

using namespace std;

void UpdateExternalAir(pair<int, int> Start, vector<vector<int>>& Mat);
void PushExternalAir(int i, int j, int t, queue<pair<int, int>>& q, vector<vector<int>>& Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, CheeseNum = 0;
    cin >> n >> m;
    vector<vector<int>> Mat;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == 1)
            {
                Mat[i][j] = INF;
                ++CheeseNum;
            } 
            else Mat[i][j] = INTERNALAIR;
        }
        
    }
    
    Mat[0][0] = 0;
    UpdateExternalAir({0, 0}, Mat);

    int MaxTime = 0;
    while(CheeseNum > 0)
    {
        for(int x = 0; x < n; ++x)
        {
            for(int y = 0; y < m; ++y)
            {
                if  (Mat[x][y] != INF) continue;
                vector<int> Surroundings;
                Surroundings.resize(4);
                Surroundings[0] = Mat[x - 1][y];
                Surroundings[1] = Mat[x][y - 1];
                Surroundings[2] = Mat[x + 1][y];
                Surroundings[3] = Mat[x][y + 1];
                sort(Surroundings.begin(), Surroundings.end());
                if(Surroundings[1] > MaxTime)
                {
                    continue;
                }
                --CheeseNum;
                Mat[x][y] = Surroundings[1] + 1;
                UpdateExternalAir({x, y}, Mat);
            }
        }
        ++MaxTime;
    }

    cout << MaxTime;

    return 0;
}

void UpdateExternalAir(pair<int, int> Start, vector<vector<int>> &Mat)
{
    queue<pair<int, int>> q;
    q.push({Start.first, Start.second});
    Mat[Start.first][Start.second] = Mat[Start.first][Start.second];
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        PushExternalAir(i - 1, j, Mat[Start.first][Start.second], q, Mat);
        PushExternalAir(i, j - 1, Mat[Start.first][Start.second], q, Mat);
        PushExternalAir(i + 1, j, Mat[Start.first][Start.second], q, Mat);
        PushExternalAir(i, j + 1, Mat[Start.first][Start.second], q, Mat);
    }
}

void PushExternalAir(int i, int j, int t, queue<pair<int, int>>& q, vector<vector<int>> &Mat)
{
    if(i == -1 || i == Mat.size() || j == -1 || j == Mat[i].size() || Mat[i][j] != INTERNALAIR) return;

    Mat[i][j] = t;
    q.push({i, j});
}

/*
5 5
0 0 0 0 0
0 1 1 1 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0


6 6
0 0 0 0 0 0
0 1 1 1 1 0
0 1 1 1 1 0
0 1 1 1 1 0
0 1 1 1 1 0
0 0 0 0 0 0

6 5
0 0 0 0 0
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0

5 6
0 0 0 0 0 0
0 1 1 1 1 0
0 1 1 1 1 0
0 1 1 1 1 0
0 0 0 0 0 0

8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0

*/