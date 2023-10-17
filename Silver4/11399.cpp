#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    uint32_t n;
    uint32_t* p;
    uint64_t Answer = 0;
    uint64_t Temp = 0;

    cin >> n;
    p = new uint32_t[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    sort(p, p+n);

    for(uint32_t i = 0; i < n; ++i)
    {
        Temp = (Temp + p[i]);
        Answer += Temp;
    }

    cout << Answer;

    return 0;
}