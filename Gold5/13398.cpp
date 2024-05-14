#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Numbers(N + 1, 0);
    for(int i = 1; i <= N; ++i)
    {
        cin >> Numbers[i];
    }

    int MaxSum = Numbers[1];
    vector<pair<int, int>> DP(N + 1, {0, 0});
    DP[1] = {Numbers[1], Numbers[1]};
    for(int i = 2; i <= N; ++i)
    {
        if(DP[i - 1].first <= 0) DP[i].first = Numbers[i];
        else DP[i].first = DP[i - 1].first + Numbers[i];

        DP[i].second = max(DP[i - 1].second, DP[i - 2].first) + Numbers[i];
        DP[i].second = max(DP[i].first, DP[i].second);
        MaxSum = max(MaxSum, DP[i].second);
    }

    cout << MaxSum;

    return 0;
}