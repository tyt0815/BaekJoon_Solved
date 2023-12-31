#include <iostream>

using namespace std;

uint64_t PowMod(uint64_t a, uint64_t b, uint64_t c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint64_t a, b, c;
    cin >> a >> b >> c;

    cout << PowMod(a, b, c);

    return 0;
}

uint64_t PowMod(uint64_t a, uint64_t b, uint64_t c)
{
    if(b == 1)
    {
        return a % c;
    }

    uint64_t Temp = 1;
    // b가 홀수일때
    if(b % 2 == 1)
    {
        b -= 1;
        Temp = a;
    }

    return (PowMod((a * a) % c, b / 2, c) * Temp) % c;
}
