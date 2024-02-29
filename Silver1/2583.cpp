#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const pair<int, int> FourDirection[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<bool>> Mat(m, vector<bool>(n, false));
    
    for(int i = 0; i < k; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int x = a; x < c; ++x)
            for(int y = b; y < d; ++y) 
                Mat[y][x] = true;
    }

    int AreaNum = 0;
    vector<int> AreaSizes;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(!Mat[i][j])
            {
                ++AreaNum;
                Mat[i][j] = true;
                stack<pair<int, int>> s;
                int Size = 0;
                s.push({i, j});
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    ++Size;
                    for(int k = 0; k < 4; ++k)
                    {
                        int a = x + FourDirection[k].first, b = y + FourDirection[k].second;
                        if(a < 0 || a >= m || b < 0 || b >= n || Mat[a][b]) continue;
                        Mat[a][b] = true;
                        s.push({a, b});
                    }
                }
                AreaSizes.push_back(Size);
            }
        }
    
    sort(AreaSizes.begin(), AreaSizes.end());
    
    cout << AreaNum << '\n';
    for(int i = 0; i < AreaSizes.size(); ++i) cout << AreaSizes[i] << ' ';

    return 0;
}
