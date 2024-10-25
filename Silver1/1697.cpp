// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n ,k, ArraySize;
//     vector<int> p;

//     cin >> n >> k;
//     if(n >= k)
//     {
//         cout << n - k;
//         return 0;
//     }
//     p.resize(k + 1);

//     for(int i = 0; i < n; ++i)
//     {
//         p[i] = n - i;
//     }
//     p[n] = 0;
//     for(int i = n + 1; i < k + 1; ++i)
//     {
//         if(i % 2 == 0)
//         {
//             p[i] = min(p[i - 1] + 1, p[i / 2] + 1);
//         }
//         else
//         {
//             p[i] = min(p[i - 1] + 1, p[(i+1) / 2] + 2);
//         }
//     }

//     cout << p[k];

//     return 0;
// }


#include <iostream>
#include <queue>
#include <array>

constexpr int MinPos = 0;
constexpr int MaxPos = 100000;

using namespace std;

void Visit(int Target ,int CurrentPosition);

array<int64_t, MaxPos + 1> ElapsedTimes;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >>K;

    for(auto& Item : ElapsedTimes) Item = -1;
    ElapsedTimes[N] = 0;
    q.push(N);
    while(!q.empty() && ElapsedTimes[K] < 0)
    {
        int CurrentPos = q.front();
        q.pop();
        Visit(CurrentPos + 1, CurrentPos);
        Visit(CurrentPos - 1, CurrentPos);
        Visit(2 * CurrentPos, CurrentPos);
    }

    cout << ElapsedTimes[K];

    return 0;
}

void Visit(int Target, int CurrentPosition)
{
    if(Target < MinPos || Target > MaxPos || ElapsedTimes[Target] >= 0) return;
    ElapsedTimes[Target] = ElapsedTimes[CurrentPosition] + 1;
    q.push(Target);
}
