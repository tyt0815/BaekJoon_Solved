#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> Coins(n, 0);
    vector<int> p(k + 1, -1);
    for(int i = 0; i < n; ++i) cin >> Coins[i];

    p[0] = 0;
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i < Coins[j] || p[i - Coins[j]] == -1) continue;
            if(p[i] == -1 || p[i] > p[i - Coins[j]] + 1)
            {
                p[i] = p[i - Coins[j]] + 1;
            }
        }
    }

    cout << p[k];

    return 0;
}