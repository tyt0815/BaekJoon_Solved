// #include <iostream>
// #include <vector>

// using namespace std;

// vector<vector<int>> Costs;
// vector<vector<vector<int>>> Cache;  // 1D: HouseNumber, 2D: FirtHouseColor, 3D: HouseNumber - 1 House Color

// int DFS(const int HouseNumber, vector<int>& Selections);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;
//     cin >> N;
//     Costs.resize(N, vector<int>(3));
//     Cache.resize(N, vector<vector<int>>(3, vector<int>(3, -1)));
//     for(auto& Cost : Costs) cin >> Cost[0] >> Cost[1] >> Cost[2];

//     vector<int> Selections(N);
//     int Result = INT32_MAX;
//     for(int Color = 0; Color < 3; ++Color)
//     {
//         Selections[0] = Color;
//         Result = min(Result, DFS(1, Selections) + Costs[0][Color]);
//     }
//     cout << Result;

//     return 0;
// }

// int DFS(const int HouseNumber,vector<int>& Selections)
// {
//     int Result = INT32_MAX;
//     if(HouseNumber == Costs.size() - 1)
//     {
//         for(int Color = 0; Color < 3; ++Color)
//         {
//             if(Selections[0] != Color && Selections[HouseNumber - 1] != Color)
//             {
//                 Result = min(Result, Costs[HouseNumber][Color]);
//             }
//         }
//         return Result;
//     }
//     else if(Cache[HouseNumber][Selections[0]][Selections[HouseNumber - 1]] == -1) 
//     {
//         for(int Color = 0; Color < 3; ++Color)
//         {
//             if(Selections[HouseNumber - 1] != Color)
//             {
//                 Selections[HouseNumber] = Color;
//                 Result = min(Result, DFS(HouseNumber + 1, Selections) + Costs[HouseNumber][Color]);
//             }
//         }
//         Cache[HouseNumber][Selections[0]][Selections[HouseNumber - 1]] = Result;
//     }

//     return Cache[HouseNumber][Selections[0]][Selections[HouseNumber - 1]];
// }

#include <iostream>
#include <vector>

constexpr int Inf = 1000000;

using namespace std;

enum {R, G, B};

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> Costs(N, vector<int>(3));
    for(auto& Cost : Costs) cin >> Cost[R] >> Cost[G] >> Cost[B];
    vector<vector<vector<int>>> DP(3, vector<vector<int>>(N, vector<int>(3))); // 1D First House Color, 2D Current House Number, 3D Current House Color;
    DP[R][0][R] = Costs[0][R];
    DP[G][0][G] = Costs[0][G];
    DP[B][0][B] = Costs[0][B];
    DP[R][0][G] = DP[R][0][B] = DP[G][0][R] = DP[G][0][B] = DP[B][0][R] = DP[B][0][G] = Inf;

    for(int HouseNumber = 1; HouseNumber < N; ++HouseNumber)
    {
        DP[R][HouseNumber][R] = min(DP[R][HouseNumber - 1][G], DP[R][HouseNumber - 1][B]) + Costs[HouseNumber][R];
        DP[R][HouseNumber][G] = min(DP[R][HouseNumber - 1][R], DP[R][HouseNumber - 1][B]) + Costs[HouseNumber][G];
        DP[R][HouseNumber][B] = min(DP[R][HouseNumber - 1][R], DP[R][HouseNumber - 1][G]) + Costs[HouseNumber][B];

        DP[G][HouseNumber][R] = min(DP[G][HouseNumber - 1][G], DP[G][HouseNumber - 1][B]) + Costs[HouseNumber][R];
        DP[G][HouseNumber][G] = min(DP[G][HouseNumber - 1][R], DP[G][HouseNumber - 1][B]) + Costs[HouseNumber][G];
        DP[G][HouseNumber][B] = min(DP[G][HouseNumber - 1][R], DP[G][HouseNumber - 1][G]) + Costs[HouseNumber][B];

        DP[B][HouseNumber][R] = min(DP[B][HouseNumber - 1][G], DP[B][HouseNumber - 1][B]) + Costs[HouseNumber][R];
        DP[B][HouseNumber][G] = min(DP[B][HouseNumber - 1][R], DP[B][HouseNumber - 1][B]) + Costs[HouseNumber][G];
        DP[B][HouseNumber][B] = min(DP[B][HouseNumber - 1][R], DP[B][HouseNumber - 1][G]) + Costs[HouseNumber][B];
    }

    cout << min(DP[R][N - 1][G], min(DP[R][N - 1][B], min(DP[G][N - 1][R], min(DP[G][N - 1][B], min(DP[B][N - 1][R], DP[B][N - 1][G])))));

    return 0;
}