// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // int NQueen(int x, int y, int Depth, vector<pair<int, int>> Queens, const int& n);
// // bool CheckQueens(const int& x, const int& y, const vector<pair<int, int>>& Queens);

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int n;
// //     vector<pair<int, int>> Queens;
// //     cin >> n;

// //     int Count = 0;
// //     for(int i = 0; i < n; ++i)
// //     {
// //         Count += NQueen(0, i, n, Queens, n);
// //     }

// //     cout << Count;

// //     return 0;
// // }

// // int NQueen(int x, int y, int Depth, vector<pair<int, int>> Queens, const int& n)
// // {
// //     if(Depth == 1)
// //     {
// //         return 1;
// //     }

// //     Queens.push_back({x, y});

// //     int Count = 0;
// //     int i = x + 1;
// //     for(int j = 0; j < n; ++j)
// //     {
// //         // 다른 퀸 확인
// //         if(!CheckQueens(i, j, Queens)) continue;

// //         Count += NQueen(i, j, Depth - 1, Queens, n);
// //     }
    
// //     return Count;
// // }

// // bool CheckQueens(const int& x, const int& y, const vector<pair<int, int>>& Queens)
// // {
// //     for(int i = 0; i < Queens.size(); ++i)
// //     {
// //         // 세로축 확인
// //         if(Queens[i].second == y) return false;
// //         // 왼쪽 대각 확인
// //         if(Queens[i].first - Queens[i].second == x - y) return false;
// //         // 오른쪽 대각 확인
// //         if(Queens[i].first + Queens[i].second == x + y) return false;
// //     }
// //     return true;
// // }

// #include <iostream>
// #include <vector>

// using namespace std;

// int NQueen(int i, vector<int> Queens, const int& n);
// bool CheckQueens(int x, int y, const vector<int>& Queens, const int& n);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> Queens(n, -1);
//     cout << NQueen(0, Queens, n);

//     return 0;
// }

// int NQueen(int i, vector<int> Queens, const int &n)
// {
//     if(i == n)
//     {
//         return 1;
//     }
//     if(i == 7)
//         cout << '!';

//     int Count = 0;
    
//     for(int j = 0; j < n; ++j)
//     {
//         if(!CheckQueens(i, j, Queens, i)) continue;
//         vector<int> Temp = Queens;
//         Temp[i] = j;
//         Count += NQueen(i + 1, Temp, n);
//     }

//     return Count;
// }

// bool CheckQueens(int x, int y, const vector<int> &Queens, const int &n)
// {
//     for(int i = 0; i < n; ++i)
//     {
//         if(Queens[i] == y) return false;
//         if(i - Queens[i] == x - y) return false;
//         if(i + Queens[i] == x + y) return false;
//     }

//     return true;
// }


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int NQueen(int Y, vector<int>& XPosition);
bool CheckQueen(int X, int Y, const vector<int>& XPosition);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> XPosition(N);

    cout << NQueen(0, XPosition);

    return 0;
}

int NQueen(int Y, vector<int>& XPosition)
{
    if(Y >= XPosition.size()) return 1;
    int Sum = 0;

    for(int X = 0; X < XPosition.size(); ++X)
    {
        if(CheckQueen(X, Y, XPosition))
        {
            XPosition[Y] = X;
            Sum += NQueen(Y + 1, XPosition);
        }
    }

    return Sum;
}

bool CheckQueen(int X, int Y, const vector<int>& XPosition)
{
    for(int V = 0; V < Y; ++V)
    {
        int U = XPosition[V];
        if(X == U || pow(static_cast<float>(Y - V) / (X - U), 2) == 1) return false;
    }

    return true;
}