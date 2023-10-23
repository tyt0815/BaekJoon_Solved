#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n ,k, ArraySize;
    vector<int> p;

    cin >> n >> k;
    if(n >= k)
    {
        cout << n - k;
        return 0;
    }
    p.resize(k + 1);

    for(int i = 0; i < n; ++i)
    {
        p[i] = n - i;
    }
    p[n] = 0;
    for(int i = n + 1; i < k + 1; ++i)
    {
        if(i % 2 == 0)
        {
            p[i] = min(p[i - 1] + 1, p[i / 2] + 1);
        }
        else
        {
            p[i] = min(p[i - 1] + 1, p[(i+1) / 2] + 2);
        }
    }

    cout << p[k];

    return 0;
}