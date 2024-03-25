#include <iostream>
#include <vector>

using namespace std;

inline int GetRoot(int n, vector<int>& Elements);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> Elements(n + 1, 0);
    for(int i = 0; i <= n; ++i) Elements[i] = i;

    for(int i = 0; i < m; ++i)
    {
        int Cmd, a, b;
        cin >> Cmd >> a >> b;
        if(Cmd == 0)
        {
            int ARoot = GetRoot(a, Elements), BRoot = GetRoot(b, Elements);
            if(ARoot > BRoot) Elements[ARoot] = BRoot;
            else Elements[BRoot] = ARoot;
        }
        else
        {
            int ARoot = GetRoot(a, Elements), BRoot = GetRoot(b, Elements);
            if(ARoot == BRoot) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

inline int GetRoot(int n, vector<int> &Elements)
{
    if(n == Elements[n]) return n;
    else return Elements[n] = GetRoot(Elements[n], Elements);
}
