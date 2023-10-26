#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t t;
    
    cin >> t;

    for(uint32_t i = 0; i < t; ++i)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        if(x == 1 && y == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        int a = 0, b = 0;
        int k;
        int EndCondition = min(x, y);
        int Answer = -1;
        while(true)
        {
            if(m * a + x > n * b + y)
            {
                k = n * b + y;
                ++b;
            }
            else if(m * a + x < n * b + y)
            {
                k = m * a + x;
                ++a;
            }
            else
            {
                k = m * a + x;
                Answer = k;
                break;
            }
            if(k % m == EndCondition % m && k % n == EndCondition % n && k != EndCondition)
            {
                break;
            }
        }
        cout << Answer << '\n';
    }

    return 0;
}