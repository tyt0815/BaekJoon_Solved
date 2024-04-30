#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> v(N + 2, {0, 0});
    for(int i = 1; i <= N; ++i) cin >> v[i].first >> v[i].second;
    
    vector<pair<int, int>> p(N + 1, {0, 0});
    for(int i = 1; i <= N; ++i)
    {
        p[i] = p[i - 1];
        --p[i].first;
        if(i + v[i].first - 1 > N) continue;
        for(int j = 1; j <= i; ++j)
        {
            if(p[i - j].first <= j)
            {
                if((p[i].second < p[i - j].second + v[i].second) ||
                 (p[i].second == p[i - j].second + v[i].second && p[i].first > v[i].first))
                {
                    p[i].first = v[i].first;
                    p[i].second = p[i - j].second + v[i].second;
                }
                break;
            }
        }
    }
    cout << p[N].second;

    return 0;
}
