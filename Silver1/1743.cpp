#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const pair<int, int> FourDirection[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> Mat(n, vector<char>(m, '.'));
    for(int i = 0; i < k; ++i)
    {
        int u, v;
        cin >> u >> v;
        Mat[u - 1][v - 1] = '#';
    }

    vector<vector<bool>> IsVisited(n, vector<bool>(m, false));
    int MaxCount = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(Mat[i][j] == '#' && !IsVisited[i][j])
            {
                stack<pair<int, int>> s;
                s.push({i, j});
                IsVisited[i][j] = true;
                int Count = 1;
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int a = x + FourDirection[k].first, b = y + FourDirection[k].second;
                        if(a < 0 || a >= n || b < 0 || b >= m  || Mat[a][b] == '.' || IsVisited[a][b]) continue;
                        s.push({a, b});
                        IsVisited[a][b] = true;
                        ++Count;
                    }
                }
                MaxCount = max(MaxCount, Count);
            }
        }
    }

    cout << MaxCount;

    return 0;
}