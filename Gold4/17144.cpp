#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> SpreadDust(vector<vector<int>> Mat);
vector<vector<int>> CleaningAir(vector<vector<int>> Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, t;
    cin >> r >> c >> t;
    vector<vector<int>> Mat;
    Mat.resize(r);
    for(int i = 0 ; i < r; ++i)
    {
        Mat[i].resize(c);
        for(int j = 0; j < c; ++j)
        {
            cin >> Mat[i][j];
        }
    }

    for(int i = 0; i < t; ++i)
    {
        Mat = SpreadDust(Mat);
        Mat = CleaningAir(Mat);
    }
    int RemainedDust = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(Mat[i][j] != -1)
            {
                RemainedDust += Mat[i][j];
            }
        }
    }

    cout << RemainedDust;
    return 0;
}

vector<vector<int>> SpreadDust(vector<vector<int>> Mat)
{
    vector<vector<int>> Result;
    Result.resize(Mat.size());
    for(int i = 0; i < Mat.size(); ++i)
    {
        Result[i].resize(Mat[i].size());
        for(int j = 0; j < Mat[i].size(); ++j)
        {
            Result[i][j] = 0;
        }
    }
    for(int i = 0; i < Mat.size(); ++i)
    {
        for(int j = 0; j < Mat[i].size(); ++j)
        {
            int SpreadedDust = Mat[i][j] / 5;
            if(SpreadedDust > 0)
            {
                if(i + 1 < Mat.size() && Mat[i + 1][j] != -1)
                {
                    Result[i + 1][j] += SpreadedDust;
                    Mat[i][j] -= SpreadedDust;
                }
                if(i - 1 >= 0 && Mat[i - 1][j] != -1)
                {
                    Result[i - 1][j] += SpreadedDust;
                    Mat[i][j] -= SpreadedDust;
                }
                if(j + 1 < Mat[i].size() && Mat[i][j + 1] != -1)
                {
                    Result[i][j + 1] += SpreadedDust;
                    Mat[i][j] -= SpreadedDust;
                }
                if(j - 1 >= 0 && Mat[i][j - 1] != -1)
                {
                    Result[i][j - 1] += SpreadedDust;
                    Mat[i][j] -= SpreadedDust;
                }
            }
            Result[i][j] += Mat[i][j];
        }
    }

    return Result;
}

vector<vector<int>> CleaningAir(vector<vector<int>> Mat)
{
    for(int i = 2; i < Mat.size(); ++i)
    {
        if(Mat[i][0] != -1) continue;

        int r = i - 1, c = 0;
        for(;r > 0; --r) Mat[r][c] = Mat[r - 1][c];
        for(;c < Mat[r].size() - 1; ++c) Mat[r][c] = Mat[r][c + 1];
        for(;r < i; ++r) Mat[r][c] = Mat[r + 1][c];
        for(;c > 1; --c) Mat[r][c] = Mat[r][c - 1];
        Mat[r][c] = 0;
        r = i + 2; c = 0;
        for(;r < Mat.size() - 1; ++r) Mat[r][c] = Mat[r + 1][c];
        for(;c < Mat[r].size() - 1; ++c) Mat[r][c] = Mat[r][c + 1];
        for(;r > i + 1; --r) Mat[r][c] = Mat[r - 1][c];
        for(;c > 1; --c) Mat[r][c] = Mat[r][c - 1];
        Mat[r][c] = 0;
        ++i;
    }
    return Mat;
}
