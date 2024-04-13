#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> P1, P2, P3;
    cin >> P1.first >> P1.second >> P2.first >> P2.second >> P3.first >> P3.second;

    int Z = (P2.first - P1.first) * (P3.second - P2.second) - (P2.second - P1.second) * (P3.first - P2.first);
    if(Z > 0) cout << 1;
    else if( Z < 0) cout << -1;
    else cout << 0;

    return 0;
}
