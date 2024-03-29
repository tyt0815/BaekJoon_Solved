#include <iostream>
#include <vector>

using namespace std;

struct SThing
{
    int Weight;
    int Value;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<vector<int>> p;  // [허용된 물건][가방의 무게]
    vector<SThing> Things;
    cin >> n >> k;
    p.resize(n + 1);
    Things.resize(n + 1);
    p[0].resize(k + 1);
    Things[0] = {0, 0};
    for(int j = 0; j < k + 1; ++j)
    {
        p[0][j] = 0;
    }
    for(int i = 1; i < n + 1; ++i)
    {
        cin >> Things[i].Weight >> Things[i].Value;
        p[i].resize(k + 1);
        for(int j = 0; j < k + 1; ++j)
        {
            p[i][j] = 0;
        }
    }

    // 가방의 무게 loop
    for(int j = 1; j < k + 1; ++j)
    {
        // 허용된 물건 loop
        for(int i = 1; i < n + 1; ++i)
        {
            if(Things[i].Weight > j)
            {
                p[i][j] = i > 0 ? p[i - 1][j] : 0;
            }
            else
            {
                p[i][j] = max(p[i - 1][j], p[i - 1][j - Things[i].Weight] + Things[i].Value);
            }
        }
    }

    cout << p[n][k];

    return 0;
}