#include <iostream>
#define MODN 10007

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p[2][10];
    cin >> n;
    for(int i = 0; i < 10; ++i) p[1][i] = 1;
    p[0][0] = 1;
    for(int i = 2; i <= n; ++i)
    {
        int Curr = i % 2, Prev = (i + 1) % 2;
        for(int j = 1; j < 10; ++j)
        {
            p[Curr][j] = (p[Prev][j] + p[Curr][j - 1]) % MODN;
        }
    }
    int Result = 0;
    for(int i = 0; i < 10; ++i)
    {
        Result = (Result + p[n % 2][i]) % MODN;
    }
    cout << Result;

    return 0;
}