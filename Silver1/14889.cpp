#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void f(int i, vector<bool> Team, int Depth, vector<vector<int>>& Mat, int& Result);
int GetTeamAbility(bool t, vector<bool>& Team, vector<vector<int>>& Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<vector<int>> Mat;
    cin >> n;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j) cin >> Mat[i][j];
    }

    int Result = INT32_MAX;
    for(int i = 0; i < n / 2; ++i)
    {
        vector<bool> Team(n, false);
        Team[i] = true;
        f(i, Team, 1, Mat, Result);
    }
    cout << Result;

    return 0;
}

void f(int i, vector<bool> Team, int Depth, vector<vector<int>> &Mat, int &Result)
{
    if(Depth == Mat.size() / 2)
    {
        int a = abs(GetTeamAbility(true, Team, Mat) - GetTeamAbility(false, Team, Mat));
        Result = min(Result, a);
        return;
    }

    for(int j = i + 1; j < Mat.size(); ++j)
    {
        Team[j] = true;
        f(j, Team, Depth + 1, Mat, Result);
        Team[j] = false;
    }
}

int GetTeamAbility(bool t, vector<bool> &Team, vector<vector<int>> &Mat)
{
    int Sum = 0;
    for(int i = 0; i < Team.size(); ++i)
    {
        if(Team[i] != t) continue;
        for(int j = 0; j < Team.size(); ++j)
        {
            if(Team[j] != t) continue;
            Sum += Mat[i][j];
        }
    }
    return Sum;
}
