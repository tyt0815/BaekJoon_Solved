#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const pair<int, int> FourDirections[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> Mat(n, vector<int>(m, 0));
    vector<vector<bool>> IsVisited(n, vector<bool>(m, false));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> Mat[i][j];
        }
    }
        
    int DrawingsCount = 0, MaxSize = 0;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(Mat[i][j] == 1 && !IsVisited[i][j])
            {
                ++DrawingsCount;
                IsVisited[i][j] = true;

                int DrawingSize = 1;
                stack<pair<int, int>> s;
                s.push({i, j});
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int a = x + FourDirections[k].first, b = y + FourDirections[k].second;
                        if(a < 0 || a >= n || b < 0 || b >= m || Mat[a][b] == 0 || IsVisited[a][b]) continue;
                        s.push({a, b});
                        IsVisited[a][b] = true;
                        ++DrawingSize;
                    }
                }
                MaxSize = max(MaxSize, DrawingSize);
            }
        }
    }
        
    cout << DrawingsCount << '\n' << MaxSize;
        

    return 0;
}