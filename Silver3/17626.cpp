#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;
    uint32_t *p;

    cin >> n;
    p = new uint32_t[n+1];
    p[1] = 1;

    for(uint32_t i = 2; i < n+1; ++i)
    {
        uint32_t Temp = static_cast<uint32_t>(sqrt(i));
        if(Temp * Temp == i)
        {
            p[i] = 1;
            continue;
        }
        p[i] = 5;
        for(uint32_t j = 1; j <= i/2; ++j)
        {
            p[i] = min(p[i], p[j] + p[i - j]);
            if(p[i] == 1) { break; }
        }
    }

    cout << p[n];

    return 0;
}