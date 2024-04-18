#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> Vertices(n, {0, 0});
    for(int i = 0; i < n; ++i) cin >> Vertices[i].first >> Vertices[i].second;

    double Area = 0;
    for(int i = 1; i < n - 1; ++i)
    {
        pair<int64_t, int64_t> V1 = {Vertices[i].first - Vertices[0].first, Vertices[i].second - Vertices[0].second};
        pair<int64_t, int64_t> V2 = {Vertices[i + 1].first - Vertices[0].first, Vertices[i + 1].second - Vertices[0].second};
        Area += V1.first * V2.second - V1.second * V2.first;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(Area) / 2.0f;
    return 0;
}
