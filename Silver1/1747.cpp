#include <iostream>
#include <vector>
#include <cmath>
#define MAXRANGE 1003002

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> PrimeNumbers(MAXRANGE, true);
    PrimeNumbers[0] = PrimeNumbers[1] = false;
    for(int i = 2; i * i < MAXRANGE; ++i)
    {
        if(PrimeNumbers[i])
        {
            for(int j = i; i * j < MAXRANGE; ++j) PrimeNumbers[i * j] = false;
        }
    }

    vector<vector<int>> p;
    p.resize(2);
    p[0].resize(9);
    p[1].resize(9);
    for(int i = 0; i < 9; ++i)
    {
        p[0][i] = i + 1;
        p[1][i] = 10 * (i + 1) + i + 1;
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < p[i].size(); ++j)
        {
            if(p[i][j] >= n && PrimeNumbers[p[i][j]])
            {
                cout << p[i][j];
                return 0;
            }
        }
    }
    int i = 2;
    while(true)
    {
        p.resize(i + 1);
        for(int j = 1; j < 10; ++j)
        {
            int Base = j * pow(10, i) + j;
            if(Base >= n && PrimeNumbers[Base])
            {
                cout << Base;
                return 0;
            }
            p[i].push_back(Base);            
            for(int k = i % 2; k < i; k += 2)
            {
                for(int t = 0; t < p[k].size(); ++t)
                {
                    p[i].push_back(Base + p[k][t] * pow(10, (i - k) / 2));
                    if(p[i].back() >= n && PrimeNumbers[p[i].back()])
                    {
                        cout << p[i].back();
                        return 0;
                    }
                }
            }
        }
        ++i;
    }

    cout << "No";

    return 0;
}

