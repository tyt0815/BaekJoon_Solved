#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n + 1, INT32_MAX);
    p[0] = 0;
    p[1] = 1;
    for(int i = 2; i < n + 1; ++i)
    {
        for(int j = 1; i - (j * j) >= 0; ++j)
        {
            p[i] = min(p[i], p[i - (j * j)] + 1);
        }
    }

    cout << p[n];

    return 0;
}