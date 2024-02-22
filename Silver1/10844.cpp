#include <iostream>
#define MODN 1000000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p[2][10];
    cin >> n;
    p[1][0] = 0;
    p[1][1] = p[1][2] = p[1][3] = p[1][4] = p[1][5] = p[1][6] = p[1][7] = p[1][8] = p[1][9] = 1;

    for(int i = 2; i <= n; ++i)
    {
        int CurrI = i % 2, PreI = (i + 1) % 2;
        p[CurrI][0] = p[PreI][1];
        p[CurrI][9] = p[PreI][8];
        for(int j = 1; j < 9; ++j)
            p[CurrI][j] = (p[PreI][j - 1] + p[PreI][j + 1]) % MODN;
    }

    int Result = 0;
    for(int i = 0; i < 10; ++i)
    {
        Result = (Result + p[n % 2][i]) % MODN;
    }

    cout << Result;

    return 0;
}