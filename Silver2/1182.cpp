#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> Numbers;

void GetSubsequenceNumbers(int i, int Sum, int& Count);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    Numbers.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> Numbers[i];
    }

    vector<vector<int>> p;
    p.resize(n);

    int Count = 0;
    for(int i = 0; i < n; ++i)
    {
        GetSubsequenceNumbers(i, Numbers[i], Count);
    }

    cout << Count;

    return 0;
}

void GetSubsequenceNumbers(int i, int Sum, int &Count)
{
    if(Sum == s) ++Count;
    if(i >= n) return;
    
    for(int j = i + 1; j < n; ++j)
    {
        GetSubsequenceNumbers(j, Sum + Numbers[j], Count);
    }
}
