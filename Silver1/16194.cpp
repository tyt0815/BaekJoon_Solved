#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> Cards(n + 1, 0);
    vector<int> p(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> Cards[i];

    for(int i = 1; i <= n; ++i)
    {
        p[i] = Cards[i];
        for(int j = 1; j <= i / 2; ++j)
        {
            p[i] = min(p[i], p[j] + p[i - j]);
        }
    }
    cout << p[n];

    return 0;
}