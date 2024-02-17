#include <iostream>
#include <vector>
#define MODN 9901

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p;
    p.resize(n + 1);
    p[0] = 1;
    p[1] = 3;
    for(int i = 2; i <= n; ++i)
    {
        p[i] = p[i - 1] * 2 + p[i - 2];
        p[i] %= MODN;
    }

    cout << p[n];

    return 0;
}