#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> Matrixs(N);
    vector<vector<uint64_t>> DP(N, vector<uint64_t>(N, UINT32_MAX)); 
    for(int i = 0; i < N; ++i) 
    {
        DP[i][i] = 0;
        cin >> Matrixs[i].first >> Matrixs[i].second;
    }
    for(int k = 1; k < N; ++k)
    {
        for(int j = k; j < N; ++j)
        {
            int i = j - k;
            for(int u = i; u < j; ++u)
            {
                DP[i][j] = min(DP[i][j], DP[i][u] + DP[u + 1][j] + Matrixs[i].first * Matrixs[u].second * Matrixs[j].second);
            }
        }
    }

    cout << DP[0].back();

    return 0;
}