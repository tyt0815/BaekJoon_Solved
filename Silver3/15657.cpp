#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> N;

void dfs(int Top, vector<int> Numbers);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> Numbers;
    cin >> n >> m;
    Numbers.resize(n);
    N.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> N[i];
    }
    sort(N.begin(), N.end());
    for(int i = 0; i < n; ++i)
    {
        Numbers[0] = i;
        dfs(1, Numbers);
    }

    return 0;
}

void dfs(int Top, vector<int> Numbers)
{
    if(Top == m)
    {
        for(int i = 0; i < m; ++i)
        {
            cout << N[Numbers[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = Numbers[Top - 1]; i < n; ++i)
    {
        Numbers[Top] = i;
        dfs(Top + 1, Numbers);
    }
}