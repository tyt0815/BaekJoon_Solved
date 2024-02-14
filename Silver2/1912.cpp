#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p;
    p.resize(n);
    int m, MaxSum;
    cin >> m;
    p[0] = m;
    MaxSum = m;
    for(int i = 1; i < n; ++i)
    {
        cin >> m;
        p[i] = max(p[i - 1] + m, m);
        MaxSum = max(MaxSum, p[i]);
    }

    cout << MaxSum;

    return 0;
}