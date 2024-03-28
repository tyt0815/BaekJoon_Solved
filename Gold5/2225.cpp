#include <iostream>
#include <vector>
#define MODULAR 1000000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<uint32_t>> p(n + 1, vector<uint32_t>(k + 1, 0));
    
    p[0][0] = 1;
    for(int j = 0; j <= k; ++j) p[0][j] = 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j) p[i][j] = (p[i - 1][j] + p[i][j - 1]) % MODULAR;
    }

    cout << p[n][k];

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #define MODULAR 1000000000

// using namespace std;

// vector<unordered_map<int, int>> Cache;

// int f(int Target, int k, const int n);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     cin >> n >> k;
//     Cache.resize(k + 1);

//     cout << f(n, k, n);

//     return 0;
// }

// int f(int Target, int k, const int n)
// {
//     if(Cache[k].find(Target) != Cache[k].end()) return Cache[k][Target];
//     if(k == 1)
//     {
//         if(Target > n) return 0;
//         else return 1;
//     }
    
//     int Result = 0;
//     for(int i = 0; i <= n; ++i)
//     {
//         if(i > Target) break;
//         Result = (Result + f(Target - i, k - 1, n)) % MODULAR;
//     }

//     Cache[k][Target] = Result % MODULAR;
//     return Result;
// }
