#include <iostream>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    uint64_t n, *p;
    uint16_t *TestCase, MaxTestCase = 0, ArraySize;

    cin >> n;
    TestCase = new uint16_t[n+1];
    for(uint64_t i = 0; i < n; ++i)
    {
        cin >>TestCase[i];
        MaxTestCase = max(MaxTestCase, TestCase[i]);
    }

    ArraySize = max(uint16_t(8), MaxTestCase);
    p = new uint64_t[ArraySize + 1];
    
    p[1] = p[2] = p[3] = 1;
    p[4] = p[5] = 2;
    p[6] = 3;
    p[7] = 4;
    p[8] = 5;

    for(uint64_t i = 9; i < ArraySize + 1; ++i)
    {
        p[i] = p[i-5] + p[i-1];
    }

    for(uint64_t i = 0; i < n; ++i)
    {
        cout << p[TestCase[i]] << '\n';
    }

    return 0;
}