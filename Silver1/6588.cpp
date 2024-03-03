#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 1000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> IsPrimeNumbers(MAXN , true);
    IsPrimeNumbers[0] = IsPrimeNumbers[1] = false;
    for(int i = 4; i < MAXN; i += 2) IsPrimeNumbers[i] = false;
    for(int i = 3; i < MAXN; i += 2)
    {
        if(IsPrimeNumbers[i])
        {
            if(i <= sqrt(MAXN))
                for(int j = i; i * j < MAXN; ++j) 
                    IsPrimeNumbers[i * j] = false;
            
        }
    }
    vector<pair<int, int>> p(MAXN + 1, {0, 0});
    for(int i = 6; i <= MAXN; i += 2)
    {
        for(int j = i - 3; j > 0; j -= 2)
        {
            if(i - j < 3) break;
            if(IsPrimeNumbers[j] && IsPrimeNumbers[i - j])
            {
                p[i] = {i - j, j};
                break;
            }
        }
    }

    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        if(p[n].first == 0) cout << "Goldbach's conjecture is wrong.\n";
        else cout << n << " = " << p[n].first << " + " << p[n].second << '\n';
    }

    return 0;
}