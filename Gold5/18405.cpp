#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const pair<int, int> FourDirections[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> Mat(N, vector<int>(N, 0));
    queue<pair<int, int>> q;
    {
        vector<vector<pair<int, int>>> Temp(K + 1);
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> Mat[i][j];
                if(Mat[i][j] > 0)
                {
                    Temp[Mat[i][j]].push_back({i, j});
                }
            }
        }
        for(const auto &VirusTypes : Temp)
        {
            for(const auto &Pos : VirusTypes) q.push(Pos);
        }
    }
    int S, X, Y;
    cin >> S >> X >> Y;
    
    for(int i = 0; i < S; ++i)
    {
        queue<pair<int, int>> Temp;
        while (!q.empty())
        {
            pair<int, int> Pos = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d)
            {
                int A = Pos.first + FourDirections[d].first, B = Pos.second + FourDirections[d].second;
                if(A >= 0 && A < N && B >= 0 && B < N && Mat[A][B] == 0)
                {
                    Mat[A][B] = Mat[Pos.first][Pos.second];
                    Temp.push({A, B});
                }
            }
        }
        q = Temp;
    }
    cout << Mat[X - 1][Y - 1];

    return 0;
}