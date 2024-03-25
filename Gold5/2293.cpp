#include <iostream>
#include <vector>

using namespace std;

void f(uint32_t Coin, vector<uint32_t>& p);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<uint32_t> Coins(n, 0);
    vector<uint32_t> p(k + 1, 0);
    for(int i = 0; i < n; ++i) cin >> Coins[i];
    
    p[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        f(Coins[i], p);
    }
    
    cout << p[k];

    return 0;
}

void f(uint32_t Coin, vector<uint32_t> &p)
{
    for(uint32_t i = Coin; i < p.size(); ++i)
    {
        p[i] += p[i - Coin];
    }
}
