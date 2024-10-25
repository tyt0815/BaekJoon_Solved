// #include <iostream>

// using namespace std;

// uint64_t f(uint64_t n, uint64_t x);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     uint64_t a[2], b[2], c[2];
//     a[0] = f(n, 5);
//     a[1] = f(n, 2);
//     b[0] = f(m, 5);
//     b[1] = f(m, 2);
//     c[0] = f(n - m, 5);
//     c[1] = f(n - m, 2);
    
//     cout << min(a[0] - b[0] - c[0], a[1] - b[1] - c[1]);

//     return 0;
// }

// uint64_t f(uint64_t n, uint64_t x)
// {
//     int Count = 0;
//     for(uint64_t i = x; n / i >= 1; i *= x)
//     {
//         Count += n / i;
//     }
//     return Count;
// }

#include <iostream>
#include <vector>

using namespace std;

// 1*2*3* ...*Target의 인수 d의 갯수
int64_t f(int64_t Target, int64_t d);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    if(M == 0)
    {
        cout << 0;
        return 0;
    }
    int64_t N2 = f(N, 2) - f(N - M, 2), N5 = f(N, 5) - f(N - M, 5), M2 = f(M, 2), M5 = f(M, 5);
    cout << min(abs(N2 - M2), abs(N5 - M5));

    return 0;
}

int64_t f(int64_t Target, int64_t d)
{
    int64_t Temp = d, Sum = 0;
    while(Temp <= Target)
    {
        Sum += Target / Temp;
        Temp *= d;
    }
    return Sum;
}