// #include <iostream>
// #include <vector>

// using namespace std;

// int MinMBTIDistance(vector<string> MBTI);
// int CalcDistance(string a, string b);

// int main()
// {
//     int T;

//     cin >> T;

//     for(int i = 0; i < T; ++i)
//     {
//         int N;
//         cin >> N;
//         vector<string> MBTI;
//         MBTI.resize(N);
//         for(int j = 0; j < N; ++j)
//         {
//             cin >> MBTI[j];
//         }
//         if(N <= 16 * 2)
//         {
//             // 브루트포스
//             cout << MinMBTIDistance(MBTI) << '\n';
//         }
//         else
//         {
//             cout << "0\n";
//         }
//     }

//     return 0;
// }

// int MinMBTIDistance(vector<string> MBTI)
// {
//     int Size = MBTI.size();
//     int Result = INT32_MAX;
//     for(int i = 0; i < Size - 2; ++i)
//     {
//         for(int j = i + 1; j < Size - 1; ++j)
//         {
//             int BetweenIJ = CalcDistance(MBTI[i], MBTI[j]);
//             for(int k = j + 1; k < Size; ++k)
//             {
//                 int Temp = BetweenIJ + CalcDistance(MBTI[i], MBTI[k]) + CalcDistance(MBTI[j], MBTI[k]);
//                 Result = min(Result, Temp);
//                 if(Result == 0)
//                 {
//                     goto LoopOut;
//                 }
//             }
//         }
//     }
//     LoopOut:;
//     return Result;
// }

// int CalcDistance(string a, string b)
// {
//     int Result = 0;
//     for(int i = 0; i < 4; ++i)
//     {
//         if(a[i] != b[i])
//         {
//             ++Result;
//         }
//     }
//     return Result;
// }


#include <iostream>
#include <vector>

using namespace std;

uint64_t CalcMinMBTIDistance(const vector<string>& MBTIs);
uint64_t CalcMBTIDistance(string A, string B);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0 ; i < T; ++i)
    {
        int N;
        cin >> N;
        vector<string> MBTIs(N);
        for(int j = 0 ; j < N; ++j) cin >> MBTIs[j];
        if(N <= 16 * 2) cout << CalcMinMBTIDistance(MBTIs);
        else cout << 0;
        cout << '\n';
    }

    return 0;
}

uint64_t CalcMinMBTIDistance(const vector<string>& MBTIs)
{
    uint64_t MinDistance = UINT64_MAX;

    for(int i = 0 ; i < MBTIs.size() - 2; ++i)
    {
        for(int j = i + 1; j < MBTIs.size() - 1; ++j)
        {
            uint64_t IJ = CalcMBTIDistance(MBTIs[i], MBTIs[j]);
            for(int k = j + 1; k < MBTIs.size(); ++k)
            {
                MinDistance = min(MinDistance, CalcMBTIDistance(MBTIs[k], MBTIs[i]) + CalcMBTIDistance(MBTIs[j], MBTIs[k]) + IJ);
            }
        }
    }

    return MinDistance;
}

uint64_t CalcMBTIDistance(string A, string B)
{
    uint64_t Distance = 0;
    for(int i = 0; i < 4; ++i)
    {
        if(A[i] != B[i]) ++Distance;
    }
    return Distance;
}