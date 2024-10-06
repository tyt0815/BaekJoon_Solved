// #include <iostream>
// #include <vector>

// using namespace std;

// int NQueen(int x, int y, int Depth, vector<pair<int, int>> Queens, const int& n);
// bool CheckQueens(const int& x, const int& y, const vector<pair<int, int>>& Queens);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     vector<pair<int, int>> Queens;
//     cin >> n;

//     int Count = 0;
//     for(int i = 0; i < n; ++i)
//     {
//         Count += NQueen(0, i, n, Queens, n);
//     }

//     cout << Count;

//     return 0;
// }

// int NQueen(int x, int y, int Depth, vector<pair<int, int>> Queens, const int& n)
// {
//     if(Depth == 1)
//     {
//         return 1;
//     }

//     Queens.push_back({x, y});

//     int Count = 0;
//     int i = x + 1;
//     for(int j = 0; j < n; ++j)
//     {
//         // 다른 퀸 확인
//         if(!CheckQueens(i, j, Queens)) continue;

//         Count += NQueen(i, j, Depth - 1, Queens, n);
//     }
    
//     return Count;
// }

// bool CheckQueens(const int& x, const int& y, const vector<pair<int, int>>& Queens)
// {
//     for(int i = 0; i < Queens.size(); ++i)
//     {
//         // 세로축 확인
//         if(Queens[i].second == y) return false;
//         // 왼쪽 대각 확인
//         if(Queens[i].first - Queens[i].second == x - y) return false;
//         // 오른쪽 대각 확인
//         if(Queens[i].first + Queens[i].second == x + y) return false;
//     }
//     return true;
// }

#include <iostream>
#include <vector>

using namespace std;

int NQueen(int i, vector<int> Queens, const int& n);
bool CheckQueens(int x, int y, const vector<int>& Queens, const int& n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> Queens(n, -1);
    cout << NQueen(0, Queens, n);

    return 0;
}

int NQueen(int i, vector<int> Queens, const int &n)
{
    if(i == n)
    {
        return 1;
    }
    if(i == 7)
        cout << '!';

    int Count = 0;
    
    for(int j = 0; j < n; ++j)
    {
        if(!CheckQueens(i, j, Queens, i)) continue;
        vector<int> Temp = Queens;
        Temp[i] = j;
        Count += NQueen(i + 1, Temp, n);
    }

    return Count;
}

bool CheckQueens(int x, int y, const vector<int> &Queens, const int &n)
{
    for(int i = 0; i < n; ++i)
    {
        if(Queens[i] == y) return false;
        if(i - Queens[i] == x - y) return false;
        if(i + Queens[i] == x + y) return false;
    }

    return true;
}
