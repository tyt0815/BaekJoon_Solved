#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> CardPrices, p;
    cin >> n;
    CardPrices.resize(n + 1);
    p.resize(n + 1);
    for(int i = 0; i < n; ++i)
    {
        cin >> CardPrices[i + 1];
    }

    p[0] = 0;
    p[1] = CardPrices[1];
    for(int i = 2; i <= n; ++i)
    {
        p[i] = CardPrices[i];
        for(int j = 1; j <= i / 2; ++j)
        {
            p[i] = max(p[i], p[j] + p[i - j]);
        }
    }

    cout << p[n];

    return 0;
}