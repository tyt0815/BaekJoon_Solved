#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void ExploreIsland(int i, int j, vector<vector<int>>& Mat);
void CheckGround(int i, int j, vector<vector<int>>& Mat, stack<pair<int, int>>& s);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        vector<vector<int>> Mat;
        Mat.resize(h);
        for(int i = 0; i < h; ++i)
        {
            Mat[i].resize(w);
            for(int j = 0; j < w; ++j) cin >> Mat[i][j];
        }

        int Count = 0;
        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                if(Mat[i][j] == 1) 
                {
                    ++Count;
                    ExploreIsland(i, j, Mat);
                }
            }
        }
        cout << Count << '\n';
    }

    return 0;
}

void ExploreIsland(int i, int j, vector<vector<int>> &Mat)
{
    stack<pair<int, int>> s;
    CheckGround(i, j, Mat, s);
    while(!s.empty())
    {
        int x = s.top().first, y = s.top().second;
        s.pop();
        for(int a = -1; a < 2; ++a)
            for(int b = -1; b < 2; ++b)
            {
                if(a == 0 && b == 0) continue;
                CheckGround(x + a, y + b, Mat, s);
            }
    }
}

void CheckGround(int i, int j, vector<vector<int>> &Mat, stack<pair<int, int>> &s)
{
    if(i < 0 || i >= Mat.size() || j < 0 || j >= Mat[i].size() || Mat[i][j] == 0) return;

    Mat[i][j] = 0;
    s.push({i, j});
}
