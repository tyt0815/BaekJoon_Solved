// #include <iostream>
// #include <unordered_map>
// #define MODULARNUM 1000000007

// using namespace std;

// unordered_map<uint64_t, int> FibonacciNumbers;

// int GetFibonacciNumber(int64_t n);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int64_t n;
//     cin >> n;
//     FibonacciNumbers[0] = 0;
//     FibonacciNumbers[1] = 1;
//     cout << GetFibonacciNumber(n);

//     return 0;
// }

// int GetFibonacciNumber(int64_t n)
// {
//     if(FibonacciNumbers.find(n) == FibonacciNumbers.end())
//     {
//         if(n % 2 ==0)
//         {
//             uint64_t a = GetFibonacciNumber(n / 2), b = GetFibonacciNumber((n / 2) - 1);
//             FibonacciNumbers[n] = (a * (a + 2 * b)) % MODULARNUM;
//         }
//         else
//         {
//             uint64_t a = GetFibonacciNumber((n / 2) + 1), b = GetFibonacciNumber(n / 2);
//             FibonacciNumbers[n] = (a * a + b * b) % MODULARNUM;
//         }
//     }

    
//     return FibonacciNumbers[n];
// }


#include <iostream>
#include <unordered_map>

constexpr int Mod = 1000000007;

using namespace std;

unordered_map<int64_t, int64_t> Cache;

int64_t F(int64_t N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    cin >> N;
    Cache[0] = 0; Cache[1] = 1; Cache[2] = 1;
    cout << F(N);

    return 0;
}

int64_t F(int64_t N)
{
    if(Cache.find(N) != Cache.end()) return Cache[N];
    int64_t K = N / 2;
    Cache[N] = (F(K + 1) * F(N - K) + F(K) * F(N - K - 1)) % Mod;
    return Cache[N];
}
