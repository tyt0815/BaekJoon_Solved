#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(int N);
void SpecialPrime(int Depth, const int &N, vector<int64_t> &Indices);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int64_t Target = pow(10, N);
    vector<int64_t> Indices(N, 0);
    SpecialPrime(0, N, Indices);

    return 0;
}

bool IsPrime(int N)
{
    if((N % 2 == 0 && N != 2) || N < 2) return false;
    for(int i = 3; i * i <=  N; i += 2) 
    {
        if(N % i == 0) return false;
    }
    return true;
}

void SpecialPrime(int Depth, const int &N, vector<int64_t> &Indices)
{
    if(Depth == N)
    {
        for(int i = 0; i < N; ++i) cout << Indices[i];
        cout << '\n';
        return;
    }
    int Offset = 0;
    for(int i = 0; i < Depth; ++i) Offset = (Offset + Indices[i]) * 10;
    for(int i = 0; i < 10; ++i)
    {
        if(IsPrime(Offset + i))
        {
            Indices[Depth] = i;
            SpecialPrime(Depth + 1, N, Indices);
        }
    }
}
