#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint64_t n, m, Height, i, SumOfTrees = 0;
    uint64_t *Trees;

    cin >> n >> m;
    Trees = new uint64_t[n];

    for(i = 0; i < n; ++i)
    {
        cin >> Trees[i];
        SumOfTrees += Trees[i];
    }

    sort(Trees, Trees + n);

    for(i = 0; i < n; ++i)
    {
        Height = Trees[i];
        if(SumOfTrees <= m + Height * (n - i))
        {
            break;
        }
        SumOfTrees -= Height;
    }

    Height = (SumOfTrees - m)/(n-i);

    cout << Height;

    return 0;
}