// #include <iostream>
// #include <vector>
// #include <cmath>


// using namespace std;

// void DrawStar11(int n, pair<int, int> Start, vector<vector<char>>& Stars);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k, m;
//     vector<vector<char>> Stars;
//     cin >> n;
//     k = log2(n / 3);
//     m = 6 * pow(2, k) - 1;
//     Stars.resize(n);
//     for(int i = 0; i < n; ++i)
//     {
//         Stars[i].resize(m);
//         for(int j = 0; j < m; ++j)
//         {
//             Stars[i][j] = ' ';
//         }
//     }

//     DrawStar11(n, {Stars.size() - 1, 0}, Stars);

//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < m; ++j)
//         {
//             cout << Stars[i][j];
//         }
//         cout << '\n';
//     }

//     return 0;
// }

// void DrawStar11(int n, pair<int, int> Start, vector<vector<char>>& Stars)
// {
//     if(n < 3)
//     {
//         return;
//     }
//     int k = log2(n / 3);
//     int m = 6 * pow(2, k) - 1;
//     int i = Start.first, j = Start.second, Cnt = 0;
//     while(true)
//     {
//         if(Cnt == m)
//         {
//             break;
//         }

//         if(Cnt % 6 != 5)
//         {
//             Stars[Start.first][j] = '*';
//         }
//         Stars[i][j] = '*';

//         ++Cnt;
//         i = Cnt > m / 2 ? i + 1 : i - 1;
//         ++j;
//     }

//     DrawStar11(n / 2,Start , Stars);
//     DrawStar11(n / 2,{Start.first, Start.second + m / 2 + 1} , Stars);
//     DrawStar11(n / 2,{Start.first - n / 2, Start.second + m / 4 + 1} , Stars);
// }


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void DrawStar(int i, int j, int N, vector<vector<char>>& Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<char>> Mat(N, vector<char>(2 * N, ' '));
    DrawStar(N - 1, 0, N, Mat);
    for(const auto& Row : Mat)
    {
        for(const auto& Cell: Row) cout << Cell;
        cout << '\n';
    }

    return 0;
}

void DrawStar(int i, int j, int N, vector<vector<char>> &Mat)
{
    if(N == 3)
    {
        Mat[i][j] = Mat[i][j + 1] = Mat[i][j + 2] = Mat[i][j + 3] = Mat[i][j + 4] = '*';
        Mat[i - 1][j + 1] = Mat[i - 1][j + 3] = '*';
        Mat[i - 2][j + 2] = '*';
        return;
    }
    DrawStar(i, j, N / 2, Mat);
    DrawStar(i, j + N, N / 2, Mat);
    DrawStar(i - N / 2, j + N / 2, N / 2, Mat);
}
