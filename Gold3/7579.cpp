#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int MaxMemory = 0;
    cin >> N >> M;
    vector<pair<int, int>> Memory(N);


    for(int i = 0; i < N; ++i) cin >> Memory[i].first;
    for(int i = 0; i < N; ++i) 
    {
        cin >> Memory[i].second;
        MaxMemory += Memory[i].second;
    }


    vector<int64_t> DP(MaxMemory + 1, 0);
    int Target = 0;
    for(int i = 0; i < N; ++i)
    {
        Target = min(MaxMemory, Memory[i].second + Target);
        for(int j = Target; j >= Memory[i].second; --j) 
            DP[j] = max(DP[j], DP[j - Memory[i].second] + Memory[i].first);
        for(int j = Target + 1; j < DP.size(); ++j) 
            DP[j] = max(DP[j], DP[Target]);
    }
 
    for(int i = 0; i < DP.size(); ++i)
    {
        if(DP[i] >= M)
        {
            cout << i;
            break;
        }
    }

    return 0;
}