#include <iostream>
#include <vector>

using namespace std;

pair<int, int> StealCandy(int i, vector<bool>& bVisited, const vector<vector<int>>& Relations, const vector<int>& CandyNum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    int K;
    cin >> N >> M >> K;

    vector<int> CandyNum(N + 1);
    for(int i = 1; i < CandyNum.size(); ++i)
    {
        cin >> CandyNum[i];
    }

    vector<vector<int>> Relations(N + 1);
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        Relations[a].push_back(b);
        Relations[b].push_back(a);
    }

    vector<pair<int, int>> Info;
    vector<bool> bVisited(N + 1, false);
    for(int i = 1; i <= N; ++i)
    {
        if(!bVisited[i])
        {
            Info.push_back(StealCandy(i, bVisited, Relations, CandyNum));
        }
    }

    vector<int> DP(K, 0);
    for(int i = 0; i < Info.size(); ++i)
    {
        for(int j = DP.size() - 1; j - Info[i].second >= 0; --j)
        {
            DP[j] = max(DP[j], DP[j - Info[i].second] + Info[i].first);
        }
    }
    cout << DP.back();
    return 0;
}

pair<int, int> StealCandy(int i, vector<bool> &bVisited, const vector<vector<int>> &Relations, const vector<int>& CandyNum)
{
    pair<int, int> Result(0, 0);
    if(!bVisited[i])
    {
        bVisited[i] = true;
        for(const int& Freinds : Relations[i])
        {
            pair<int, int> Temp = StealCandy(Freinds, bVisited, Relations, CandyNum);
            Result.first += Temp.first;
            Result.second += Temp.second;
        }
        Result.first += CandyNum[i];
        Result.second += 1;
    }
    return Result;
}
