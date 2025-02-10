#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

// T[n]: 2^n - 1 까지 1의 누적 갯수
array<uint64_t, 60> T;

bool IsPowerOfTwo(uint64_t N);
uint64_t GetPowerOfTwo(uint64_t N);
uint64_t F(uint64_t N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    T[0] = 0;
    uint64_t Pow2 = 1;
    for(int i = 1; i < T.size(); ++i)
    {
        T[i] = Pow2 + 2 * T[i - 1];
        Pow2 <<= 1;
    }

    uint64_t A;
    uint64_t B;
    cin >> A >> B;

    cout << (F(B + 1) - F(A));

    return 0;
}

bool IsPowerOfTwo(uint64_t N)
{
    return N > 0 &&  (N & (N - 1)) == 0;
}

uint64_t GetPowerOfTwo(uint64_t N)
{
    if (!IsPowerOfTwo(N))
    {
        return -1;
    }
    uint64_t Exponent = 0;
    while(N > 1)
    {
        N >>= 1;
        ++Exponent;
    }
    return Exponent;
}

uint64_t F(uint64_t N)
{
    if (N < 2)
    {
        return 0;
    }
    uint64_t Exponent = GetPowerOfTwo(N);
    if (Exponent != -1)
    {
        return T[Exponent];
    }

    uint64_t Temp = N;
    uint64_t Pow2 = 1;
    Exponent = 0;
    while (Temp > 1)
    {
        Temp >>= 1;
        ++Exponent;
        Pow2 <<= 1;
    }
    Temp = N - Pow2;
    return T[Exponent] + F(Temp) + Temp;
}
