#include <iostream>
#include <vector>
#define MOD 1000000000000000000

using namespace std;

void BuildTower(int From, int To, int Temp, int Height);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<uint64_t>> p(n + 1, vector<uint64_t>(2, 0));
    p[1][0] = 1;
    for(int i = 2; i <= n; ++i)
    {
        p[i][1] = 2 * p[i - 1][1];
        p[i][0] = 2 * p[i - 1][0] + 1;
        if(p[i][0] / MOD > 0)
        {
            p[i][1] += p[i][0] / MOD;
            p[i][0] = p[i][0] % MOD;
        }
    }
    if(p[n][1] > 0) cout << p[n][1];
    cout << p[n][0];
    if(n <= 20) BuildTower(1, 3, 2, n);

    return 0;
}

void BuildTower(int From, int To, int Temp, int Height)
{
    if(Height == 1)
    {
        cout << '\n' << From << ' ' << To;
        return;
    }
    BuildTower(From, Temp, To, Height - 1);
    cout << '\n' << From << ' ' << To;
    BuildTower(Temp, To, From, Height - 1);
}
