#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    long long *ary, *request;
    cin >> n;
    ary = new long long[n];
    for(i = 0; i < n; ++i)
    {
        cin >> ary[i];
    }
    cin >> m;
    request = new long long[m];
    for(i = 0; i < m; ++i)
    {
        cin >> request[i];
    }

    sort(ary, ary + n);

    for(i = 0; i < m; ++i)
    {
        if(binary_search(ary, ary+n, request[i])){ cout << 1 << '\n'; }
        else { cout << 0 << '\n'; }
    }

    return 0;
}