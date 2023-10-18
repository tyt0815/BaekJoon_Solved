#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;
    uint64_t *p;

    cin >> n;

    p = new uint64_t[max(n+1, uint32_t(3))];

    p[0] = 0;
    p[1] = 1;
    p[2] = 3;
    for(uint32_t i = 3; i < n+1; ++i)
    {
        p[i] = (p[i - 1] + (p[i - 2] * 2)) % 10007;
    }

    cout << p[n];

    return 0;
}