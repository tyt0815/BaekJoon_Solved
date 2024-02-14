#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 123456

using namespace std;

void FindPrimeNumbers(vector<int>& PrimeNumbers);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> PrimeNumbers(MAXN * 2 + 1, false);
    FindPrimeNumbers(PrimeNumbers);

    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        int Count = 0;
        for(int j = n + 1; j <= 2 * n; ++j)
        {
            if(PrimeNumbers[j])
            {
                ++Count;
            }
        }
        cout << Count << '\n';
    }

    return 0;
}

void FindPrimeNumbers(vector<int> &PrimeNumbers)
{
    int n = PrimeNumbers.size();
    PrimeNumbers.assign(n, true);
    PrimeNumbers[0] = PrimeNumbers[1] = false;
    for(int i = 2; i < sqrt(n); ++i)
    {
        if(PrimeNumbers[i])
        {
            for(int j = i; i * j < n; ++j)
            {
                PrimeNumbers[i * j] = false;
            }
        }
    }
}
