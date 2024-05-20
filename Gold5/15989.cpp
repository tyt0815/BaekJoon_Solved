#include <iostream>
#include <vector>
#define MAXN 10000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> DP(MAXN + 1, 0);
    DP[0] = 1;
    for(int j = 1; j < 4; ++j)
    {
        for(int k = j; k <= MAXN; ++k)
        {
            DP[k] += DP[k - j];
        }
    }

    int T;
    cin >> T;
    for(int i = 0 ; i < T; ++i)
    {
        int N;
        cin >> N;
        cout << DP[N] << '\n';
    }
    

    return 0;
}