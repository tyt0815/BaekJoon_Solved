#include <iostream>

using namespace std;

int main()
{
    uint64_t n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int m = i;
        while(m % 5 == 0)
        {
            m /= 5;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}