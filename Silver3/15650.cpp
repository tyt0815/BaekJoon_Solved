#include <iostream>
#include <vector>

using namespace std;
int n, m;
void dfs(int Top, vector<int> Numbers);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> Numbers;
    cin >> n >> m;
    Numbers.resize(m);

    for(int i = 1; i < n - m + 2; ++i)
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
            cout << Numbers[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = Numbers[Top - 1] + 1; n - i >= m - Top - 1; ++i)
    {
        Numbers[Top] = i;
        dfs(Top + 1, Numbers);
    }
}
