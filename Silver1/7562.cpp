#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const pair<int, int> NightMove[] = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };
struct SPos
{
    int x;
    int y;
    int Count;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int m, x, y, TargetX, TargetY;
        cin >> m >> x >> y >> TargetX >> TargetY;
        if(x == TargetX && y == TargetY) 
        {
            cout << "0\n";
            continue;
        }
        vector<vector<bool>> IsVisited(m, vector<bool>(m, false));
        queue<SPos> q;
        q.push({x, y, 0});
        while(!q.empty())
        {
            x = q.front().x;
            y = q.front().y;
            int Count = q.front().Count;
            q.pop();
            for(int j = 0; j < 8; ++j)
            {
                int a = x + NightMove[j].first, b = y + NightMove[j].second;
                if(a < 0 || a >= m || b < 0 || b >= m || IsVisited[a][b]) continue;
                if(a == TargetX && b == TargetY)
                {
                    cout << Count + 1 << '\n';
                    goto TestCaseEnd;
                }
                IsVisited[a][b] = true;
                q.push({a, b, Count + 1});
            }
        }
        TestCaseEnd:;
    }

    return 0;
}
