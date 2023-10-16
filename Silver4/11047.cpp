#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n,k;
    uint32_t* Coins;
    uint32_t Answer = 0;

    cin >> n >> k;
    Coins = new uint32_t[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> Coins[i];
    }

    for(uint32_t i = n-1; i > 0; --i)
    {
        if(k / Coins[i] != 0)
        {
            Answer += k / Coins[i];
            k = k % Coins[i];
        }
    }
    Answer += k;

    cout << Answer;

    delete[] Coins;
    return 0;
}