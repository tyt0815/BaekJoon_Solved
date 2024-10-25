// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string A, B;
//     vector<vector<int>> p;
//     cin >> A >> B;
//     p.resize(A.length() + 1);
    
//     for(int i = 0; i < p.size(); ++i)
//     {
//         p[i].resize(B.length() + 1);
//         for(int j = 0; j < p[i].size(); ++j)
//         {
//             p[i][j] = 0;
//         }
//     }

//     for(int i = 1; i < p.size(); ++i)
//     {
//         int a = i - 1;
//         for(int j = 1; j < p[i].size(); ++j)
//         {
//             int b = j - 1;
//             p[i][j] = max(p[i - 1][j], p[i][j - 1]);
//             if(A[a] == B[b])
//             {
//                 p[i][j] = max(p[i][j], p[i - 1][j - 1] + 1);
//             }
//         }
//     }

//     cout << p[A.length()][B.length()];

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
    for(int i = 1; i < DP.size(); ++i)
    {
        int AIndex = i - 1;
        for(int j = 1; j < DP[i].size(); ++j)
        {
            int BIndex = j - 1;
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            if(A[AIndex] == B[BIndex]) DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
        }
    }

    cout << DP[A.length()][B.length()];

    return 0;
}