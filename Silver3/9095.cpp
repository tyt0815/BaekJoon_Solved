#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t t;
    uint32_t* n, *p;
    uint32_t MaxN = 0;

    cin >> t;

    n = new uint32_t[t];
    for(uint32_t i = 0; i < t; ++i)
    {
        cin >> n[i];
        MaxN = max(MaxN, n[i]);
    }
    p = new uint32_t[MaxN];
    
    p[0] = 0;
    p[1] = 1;
    if(MaxN > 1) { p[2] = 2; }
    if(MaxN > 2) { p[3] = 4; }
    for(uint32_t i = 4; i <= MaxN; ++i)
    {
        p[i] = p[i - 1] + p[i - 2] + p[i - 3];
    }

    for(uint32_t i = 0; i < t; ++i)
    {
        cout << p[n[i]] << '\n';
    }

    delete[] n;
    return 0;
}