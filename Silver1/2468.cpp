#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const pair<int, int> FourDirection[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int GetSafeAreaNum(const int RainHieght, const vector<vector<int>>& Heights);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, MaxHeight = 0;
    vector<vector<int>> Heights;
    cin >> n;
    Heights.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Heights[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> Heights[i][j];
            MaxHeight = max(MaxHeight, Heights[i][j]);
        }
    }

    int MaxAreaNum = 1;
    for(int i = 1; i <= MaxHeight; ++i)
    {
        MaxAreaNum = max(MaxAreaNum, GetSafeAreaNum(i, Heights));
    }

    cout << MaxAreaNum;

    return 0;
}

int GetSafeAreaNum(const int RainHieght, const vector<vector<int>> &Heights)
{
    vector<vector<bool>> IsVisited(Heights.size(), vector<bool>(Heights.size(), false));

    int SafeAreaNum = 0;
    for(int i = 0; i < Heights.size(); ++i)
        for(int j = 0; j < Heights[i].size(); ++j)
        {
            if(Heights[i][j] > RainHieght && !IsVisited[i][j])
            {
                ++SafeAreaNum;
                IsVisited[i][j] = true;
                stack<pair<int, int>> s;
                s.push({i, j});
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int a = x + FourDirection[k].first, b = y + FourDirection[k].second;
                        if(a < 0 || a >= Heights.size() || b < 0 || b >= Heights[a].size() || Heights[a][b] <= RainHieght || IsVisited[a][b]) continue;
                        IsVisited[a][b] = true;
                        s.push({a, b});
                    }
                }
            }
        }

    return SafeAreaNum;
}
