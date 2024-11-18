// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// void InitVector(vector<int64_t> &V, unordered_map<int64_t, int64_t>& VMemory);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int64_t T;
//     vector<int64_t> A, B;
//     unordered_map<int64_t, int64_t> AMemory, BMemory;
//     cin >> T;
//     InitVector(A, AMemory);
//     InitVector(B, BMemory);

//     int64_t Count = 0;
//     unordered_map<int64_t, int64_t>::iterator AIter = AMemory.begin();
//     while(AIter != AMemory.end())
//     {
//         if(BMemory.find(T - AIter->first) != BMemory.end()) Count += AIter->second * BMemory[T - AIter->first];
//         ++AIter;
//     }

//     cout << Count;

//     return 0;
// }

// void InitVector(vector<int64_t> &V, unordered_map<int64_t, int64_t>& VMemory)
// {
//     int N;
//     cin >> N;
//     V.resize(N + 1);
//     V[0] = 0;
//     for(int i = 1; i <= N; ++i)
//     {
//         cin >> V[i];
//         V[i] += V[i - 1];
//     }
//     for(int i = 0; i < V.size(); ++i)
//     {
//         for(int j = i + 1; j < V.size(); ++j)
//         {
//             int Sum = V[j] - V[i];
//             if(VMemory.find(Sum) == VMemory.end()) VMemory[Sum] = 0;
//             ++VMemory[Sum];
//         }
//     }
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InitArray(vector<int64_t>& V);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t T;
    vector<int64_t> A, B;
    cin >> T;
    InitArray(A);
    InitArray(B);
    
    int64_t Count = 0;
    int64_t i = 0;
    while(i < A.size())
    {
        int64_t j = lower_bound(A.begin() + i, A.end(), A[i] + 1) - A.begin();
        int64_t Temp = lower_bound(B.begin(), B.end(), T - A[i] + 1) - lower_bound(B.begin(), B.end(), T - A[i]);
        Count += (j - i) * Temp;
        i = j;
    }
    cout << Count;

    return 0;
}

void InitArray(vector<int64_t>& V)
{
    int64_t N;
    cin >> N;
    vector<int64_t> Temp(N + 1, 0);
    for(int64_t i = 1; i <= N; ++i)
    {
        cin >> Temp[i];
        Temp[i] += Temp[i - 1];
    }
    V.resize(N * (N + 1) / 2);
    for(int64_t i = 0, k = 0; i < N; ++i)
    {
        for(int64_t j = i + 1; j <= N; ++j, ++k)
        {
            V[k] = Temp[j] - Temp[i];
        }
    }
    sort(V.begin(), V.end());
}
