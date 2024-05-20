#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, W;
    cin >> T >> W;
    vector<int> DropInfo(2, 0);
    int Prev = 1;
    for(int i = 0; i < T; ++i)
    {
        int Curr;
        cin >> Curr;
        if(Curr == Prev) ++DropInfo.back();
        else
        {
            Prev = Curr;
            DropInfo.push_back(1);
        }
    }

    vector<vector<int>> DP(W + 1, vector<int>(DropInfo.size(), 0));
    {
        int Sum = 0;
        for(int i = 1; i < DP[0].size(); i += 2)
        {
            Sum += DropInfo[i];
            DP[0][i] = Sum;
        }
    }
    int MaxAmount = 0;
    for(int i = 1; i < DP.size(); ++i)
    {
        DP[i][1] = DropInfo[1];
        for(int j = 1; j < DP[i].size(); ++j)
        {
            DP[i][j] = max(DP[i - 1][j - 1], DP[i][j - 2]);
            DP[i][j] += DropInfo[j];
            MaxAmount = max(MaxAmount, DP[i][j]);
        }
    }
    cout << MaxAmount;

    return 0;
}