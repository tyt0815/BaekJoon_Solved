#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;

    cin >> n;
    uint32_t m;
    while(true)
    {
        m = sqrt(n);
        n /= m;
    }

    return 0;
}