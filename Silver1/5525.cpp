#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p, i, Cnt = 0;
    string InputString;

    cin >> n >> m;
    cin >> InputString;

    p = 2 * n + 1;
    for(i = 0; i + p - 1 < m; ++i)
    {
        if(InputString[i] == 'I') break;
    }
    ++i;
    --p;
    
    while(i + p - 1 < m)
    {
        char CmpChar = p % 2 == 0 ? 'O' : 'I';
        if(InputString[i] != CmpChar)
        {
            p = 2 * n  +1;
            for(; i + p - 1 < m; ++i)
            {
                if(InputString[i] == 'I') break;
            }
            ++i;
            --p;
            continue;
        }
        if(p == 1)
        {
            ++Cnt;
            ++i;
            ++p;
            continue;
        }
        ++i;
        --p;
    }

    cout << Cnt;
    return 0;
}