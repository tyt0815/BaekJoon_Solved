#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> t;
    for(int k = 0; k < t; ++k)
    {
        vector<vector<int>> Sticker(2);
        vector<vector<int>> p(2);
        cin >> n;
        Sticker[0].resize(n);
        Sticker[1].resize(n);
        p[0].resize(n);
        p[1].resize(n);

        for(int i = 0 ; i < 2; ++i)
        {
            for(int j = 0 ; j < n; ++j)
            {
                cin >> Sticker[i][j];
            }
        }

        p[0][0] = Sticker[0][0];
        p[1][0] = Sticker[1][0];

        if(n > 1)
        {
            p[0][1] = Sticker[0][1] + p[1][0];
            p[1][1] = Sticker[1][1] + p[0][0];
        }

        for(int i = 2; i < n; ++i)
        {
            p[0][i] = max(p[1][i - 1], p[1][i - 2]);
            p[0][i] += Sticker[0][i];
            p[1][i] = max(p[0][i - 1], p[0][i - 2]);
            p[1][i] += Sticker[1][i];
        }
        cout << max(p[0][n-1], p[1][n-1]) << '\n';
    }
    return 0;
}