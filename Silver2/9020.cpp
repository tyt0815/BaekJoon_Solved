#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 10000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<bool> PrimeNumbers(MAXN + 1, true);
    PrimeNumbers[0] = PrimeNumbers[1] = false;
    for(int i = 2; i < sqrt(MAXN + 1); ++i)
    {
        if(PrimeNumbers[i])
        {
            for(int j = i; i * j < MAXN + 1; ++j)
            {
                PrimeNumbers[i * j] = false;
            }
        }
    }

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        for(int j = n / 2; j > 1; --j)
        {
            if(PrimeNumbers[j] && PrimeNumbers[n - j])
            {
                cout << j << ' ' << n - j << '\n';
                break;
            }
        }
    }

    return 0;
}