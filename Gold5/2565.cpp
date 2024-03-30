#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> Wires(n, {0, 0});
    vector<int> p(n, 1);
    for(int i = 0; i < n; ++i) cin >> Wires[i].first >> Wires[i].second;
    sort(Wires.begin(), Wires.end(), [](pair<int, int> X, pair<int, int> Y){ return X.first < Y.first; });

    int m = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(Wires[i].second > Wires[j].second)
                p[i] = max(p[i], p[j] + 1);
        }
        m = max(m, p[i]);
    }

    cout << n - m;

    return 0;
}