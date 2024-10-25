// #include <iostream>
// #define MAXLEN 4000

// using namespace std;

// int main()
// {
//     string A, B;
//     cin >> A >> B;

//     int Length = 0;
//     int p[MAXLEN + 1][MAXLEN + 1] = { 0 };
//     int N = A.length(), M = B.length();
//     for(int i = 1; i <= N; ++i)
//     {
//         for(int j = 1; j <= M; ++j)
//         {
//             if(A[i - 1] == B[j - 1])
//             {
//                 p[i][j] = p[i - 1][j - 1] + 1;
//                 Length = max(Length, p[i][j]);
//             }
//         }
//     }    

//     cout << Length;

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;
    vector<vector<int>> DP(A.length() + 1, vector<int>(B.length() + 1, 0));
    int Answer = 0;
    for(int i = 1; i < DP.size(); ++i)
    {
        int a = i - 1;
        for(int j = 1; j < DP[i].size(); ++j)
        {
            int b = j - 1;
            if(A[a] == B[b])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                Answer = max(Answer, DP[i][j]);
            }
        }
    }
    cout << Answer;

    return 0;
}