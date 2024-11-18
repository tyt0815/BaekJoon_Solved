#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Count = 0;
    cin >> N;
    vector<int64_t> PrimeSums(1, 0);
    {
        vector<bool> bPrime(N + 1, true);
        bPrime[0] = bPrime[1] = false;
        for(int i = 2, Target = sqrt(N); i <= Target; ++i)
        {
            if(bPrime[i])
            {
                for(int j = i * i; j <= N; j += i) bPrime[j] = false;
            }
        }
        for(int i = 2; i <= N; ++i)
        {
            if(bPrime[i]) 
            {
                PrimeSums.push_back(i + PrimeSums.back());
            }
        }
    }

    for(int i = PrimeSums.size() - 1; i > 0; --i)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            int64_t Sum = PrimeSums[i] - PrimeSums[j];
            if(Sum == N) ++Count;
            else if(Sum > N) break;
        }
    }

    cout << Count;

    return 0;
}