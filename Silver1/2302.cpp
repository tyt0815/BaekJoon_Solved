#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> IsVIPSeat(n + 1, false);
    vector<int> p(n + 1, 1);
    for(int i = 0; i < m; ++i)
    {
        int j;
        cin >> j;
        IsVIPSeat[j] = true;
    }
    
    for(int i = 2; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if(!IsVIPSeat[i] && !IsVIPSeat[i - 1]) p[i] += p[i - 2];
    }
    cout << p[n];
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// vector<unordered_map<int, int>> SittingCaseCache;

// int GetSittingCases(int Depth, vector<int>& Seats);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;
//     vector<int> Seats(n + 1, 0);
//     SittingCaseCache = vector<unordered_map<int, int>>(n + 1, unordered_map<int, int>());
//     for(int i = 0; i < m; ++i)
//     {
//         int j;
//         cin >> j;
//         Seats[j] = j;
//     }
    
//     cout << GetSittingCases(1, Seats);

//     return 0;
// }

// int GetSittingCases(int Depth, vector<int>& Seats)
// {
//     if(Depth == Seats.size()) return 1;
//     if(Seats[Depth] == Depth) return GetSittingCases(Depth + 1, Seats);

//     int Target = min(int(Seats.size()), Depth + 2);
//     if(Depth > 1 && Seats[Depth] == Depth - 1) Target = Depth;
//     int Result = 0;
//     for(int i = max(1, Depth - 1); i < Target; ++i)
//     {
//         if(Seats[i] != 0) continue;
//         if(SittingCaseCache[i].find(Depth) == SittingCaseCache[i].end())
//         {
//             Seats[i] = Depth;
//             SittingCaseCache[i][Depth] = GetSittingCases(Depth + 1, Seats);
//             Seats[i] = 0;
//         }
//         Result += SittingCaseCache[i][Depth];
//     }
//     return Result;
// }