#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> N;

void dfs(int Top, vector<int> Numbers, vector<bool> Visited);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> Numbers;
    vector<bool> Visited;
    cin >> n >> m;
    N.resize(n);
    Visited.resize(n);
    Numbers.resize(m);
    for(int i = 0; i < n; ++i)
    {
        cin >> N[i];
    }

    sort(N.begin(), N.end());

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ;j < n; ++j)
        {
            Visited[j] = false;
        }
        Numbers[0] = i;
        Visited[i] = true;
        dfs(1, Numbers, Visited);
    }


    return 0;
}

void dfs(int Top, vector<int> Numbers, vector<bool> Visited)
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

    for(int i = 0; i < n; ++i)
    {
        if(!Visited[i])
        {
            Visited[i] = true;
            Numbers[Top] = i;
            dfs(Top + 1, Numbers, Visited);
            Visited[i] = false;
        }
    }
}