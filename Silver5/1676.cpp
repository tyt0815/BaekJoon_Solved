#include <iostream>

using namespace std;

// int main()
// {
//     uint64_t n, m = 1, cnt = 0;
//     cin >> n;
//     for(int i = 1; i <= n; ++i)
//     {
//         m *= i;
//         while(m % 10 == 0)
//         {
//             m/=10;
//             ++cnt;
//         }
        
//         m %= 10000000000000;
//     }

//     cout << cnt;

//     return 0;
// }
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