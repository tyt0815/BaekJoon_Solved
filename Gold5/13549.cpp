#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<int> p;
    cin >> n >> k;

    if(n >= k)
    {
        cout << n - k;
        return 0;
    }

    p.resize(k + 1);

    for(int i = 0; i <= n; ++i)
    {
        p[i] = n - i;
    }

    for(int i = n + 1; i < k + 1; ++i)
    {
        p[i] = p[i - 1] + 1;
        if(i % 2 == 0)
        {
            p[i] = min(p[i], p[i / 2]);
        }
        else
        {
            p[i] = min(p[i], p[(i + 1) / 2] + 1);
        }
    }

    cout << p[k];

    return 0;
}