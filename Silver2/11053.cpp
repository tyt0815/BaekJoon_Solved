#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, MaxL = 0;
    vector<int> p, Numbers;
    cin >> n;
    Numbers.resize(n);
    p.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> Numbers[i];
    }

    for(int i = 0; i < n; ++i)
    {
        p[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(Numbers[i] > Numbers[j])
                p[i] = max(p[i], p[j] + 1);
        }
        MaxL = max(MaxL, p[i]);
    }

    cout << MaxL;

    return 0;
}