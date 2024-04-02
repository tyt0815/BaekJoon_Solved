#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const pair<int, int> FourDirection[] = {{-1 ,0}, {0, -1}, {1, 0}, {0, 1}};

struct FQData
{
    int X;
    int Y;
    int Depth;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    vector<vector<char>> Mat(r, vector<char>(c, ' '));
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j) cin >> Mat[i][j];
    }

    int MaxDistance = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(Mat[i][j] == 'L')
            {
                vector<vector<bool>> IsVisited(r, vector<bool>(c, false));
                IsVisited[i][j] = true;
                queue<FQData> q;
                q.push({i, j, 0});
                int MaxDepth = 0;
                while(!q.empty())
                {
                    int X = q.front().X, Y = q.front().Y, Depth = q.front().Depth;
                    MaxDepth = max(MaxDepth, Depth);
                    q.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int A = X + FourDirection[k].first, B = Y + FourDirection[k].second;
                        if(A >= 0 && A < r && B >= 0 && B < c && !IsVisited[A][B] && Mat[A][B] == 'L')
                        {
                            IsVisited[A][B] = true;
                            q.push({A, B, Depth + 1});
                        }
                    }
                }

                MaxDistance = max(MaxDistance, MaxDepth);
            }
        }
    }

    cout << MaxDistance;

    return 0;
}