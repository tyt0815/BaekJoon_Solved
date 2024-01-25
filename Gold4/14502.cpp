#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int GetSafeArea(vector<vector<int>> Mat);
vector<vector<int>> bfs(vector<vector<int>> Mat, vector<pair<int, int>> VirusPos);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<vector<int>> Mat;
    vector<pair<int, int>> VirusPos;
    cin >> n >> m;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == 2)
            {
                VirusPos.push_back({i, j});
            }
        }
    }
    int MaxSafeArea = 0;
    for(int i = 0; i < n * m; ++i)
    {
        if(Mat[i / m][i % m] > 0) continue;
        Mat[i / m][i % m] = 1;
        for(int j = i + 1; j < n * m; ++j)
        {
            if(Mat[j / m][j % m] > 0) continue;
            Mat[j / m][j % m] = 1;
            for(int k = j + 1; k < n * m; ++k)
            {
                if(Mat[k / m][k % m] > 0) continue;
                Mat[k / m][k % m] = 1;
                MaxSafeArea = max(MaxSafeArea, GetSafeArea(bfs(Mat, VirusPos)));
                Mat[k / m][k % m] = 0;
            }
            Mat[j / m][j % m] = 0;
        }
        Mat[i / m][i % m] = 0;
    }

    cout << MaxSafeArea;

    return 0;
}

int GetSafeArea(vector<vector<int>> Mat)
{
    int Area = 0;
    for(int i = 0; i < Mat.size(); ++i)
    {
        for(int j = 0; j < Mat[i].size(); ++j)
        {
            if(Mat[i][j] == 0)
                ++Area;
        }
    }
    return Area;
}

vector<vector<int>> bfs(vector<vector<int>> Mat, vector<pair<int, int>> VirusPos)
{
    for(int i = 0; i < VirusPos.size(); ++i)
    {
        queue<pair<int, int>> q;
        q.push(VirusPos[i]);
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x + 1 < Mat.size() && Mat[x + 1][y] == 0)
            {
                Mat[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if(x - 1 >= 0 && Mat[x - 1][y] == 0)
            {
                Mat[x - 1][y] = 2;
                q.push({x - 1, y});
            }
            if(y + 1 < Mat[x].size() && Mat[x][y + 1] == 0)
            {
                Mat[x][y + 1] = 2;
                q.push({x, y + 1});
            }
            if(y - 1 >= 0 && Mat[x][y - 1] == 0)
            {
                Mat[x][y - 1] = 2;
                q.push({x, y - 1});
            }
        }
    }

    return Mat;
}
