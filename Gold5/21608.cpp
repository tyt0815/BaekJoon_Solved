#include <iostream>
#include <vector>
#define MAX_NUM_PREFER 4

using namespace std;

pair<int, int> FourDirection[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void CalcPreferenceAndBlank(int x, int y, vector<int> &Prefer, const vector<vector<int>> &Mat, int& p, int& b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> Mat(N, vector<int>(N, 0));
    vector<vector<int>> Prefer(N * N + 1, vector<int>(MAX_NUM_PREFER, 0));
    for(int i = 0; i < N * N; ++i)
    {
        int StudentID;
        cin >> StudentID;
        for(int j = 0; j < MAX_NUM_PREFER; ++j) cin >> Prefer[StudentID][j];

        int NumPrefer = 0, NumBlank = 0, r = N, c = N;
        for(int x = 0; x < N; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                if(Mat[x][y] != 0) continue;
                int p = 0, b = 0;
                CalcPreferenceAndBlank(x, y, Prefer[StudentID], Mat, p, b);

                if(p > NumPrefer ||
                (p == NumPrefer && b > NumBlank) ||
                (p == NumPrefer && b == NumBlank && x < r) || 
                (p == NumPrefer && b == NumBlank && x == r && y < c)
                )
                {
                    r = x;
                    c = y;
                    NumPrefer = p;
                    NumBlank = b;
                }
            }
        }
        Mat[r][c] = StudentID;
    }

    int Sum = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int p = 0, b = 0;
            CalcPreferenceAndBlank(i, j, Prefer[Mat[i][j]], Mat, p, b);
            if(p == 2) p = 10;
            else if(p == 3) p = 100;
            else if (p == 4) p = 1000;
            Sum += p;
        }
    }

    cout << Sum;

    return 0;
}

void CalcPreferenceAndBlank(int x, int y, vector<int> &Prefer, const vector<vector<int>> &Mat, int &p, int &b)
{
    for(int k = 0; k < 4; ++k)
    {
        int z = x + FourDirection[k].first, w = y + FourDirection[k].second;
        if(z < 0 || z >= Mat.size() || w < 0 || w >= Mat[z].size()) continue;
        if(Mat[z][w] == 0) ++b;
        else
        {
            for(auto ID : Prefer)
            {
                if(ID == Mat[z][w])
                {
                    ++p;
                    break;
                }
            }
        }
    }
}
