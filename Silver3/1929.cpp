#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M, N;

    cin >> M >> N;

    bool *bPrime = new bool[N+1];
    bPrime[0] = bPrime[1] = false;
    for(int i = 2; i < N+1; ++i) {bPrime[i] = true;}
    float TargetNumb = sqrt(N);
    for(int i = 2; i <= TargetNumb; ++i)
    {
        if(!bPrime[i]) { continue; }
        for(int j = i; i * j <= N + 1; ++j)
        {
            bPrime[i * j] = false;
        }
    }

    for(int i = M; i < N+1; ++i)
    {
        if(bPrime[i])
        {
            cout << i << "\n";
        }
    }

    delete[] bPrime;

    return 0;
}