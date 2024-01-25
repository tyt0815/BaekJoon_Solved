#include <iostream>
#include <vector>
#define MODUL 1000000007

using namespace std;

uint64_t gdc(uint64_t a, uint64_t b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t m;
    vector<pair<uint64_t, uint64_t>> Dice;  // n면체, 합s
    uint64_t Numerator = 0;
    uint64_t Denominator = 0;
    cin >> m;
    Dice.resize(m);
    uint64_t a, b, c;
    cin >> a >> b;
    c = gdc(a, b);
    Denominator = a / c;
    Numerator = b / c;
    for(uint64_t i = 1; i < m; ++i)
    {
        cin >> a >> b;
        c = gdc(a, b);
        a /= c;
        b /= c;
        c = gdc(Denominator, a);
        b *= (Denominator / c);
        Denominator *= (a / c);
        Numerator *= (a / c);
        Numerator += b;
        c = gdc(Denominator, Numerator);
        Denominator /= c;
        Numerator /= c;
        Numerator %= MODUL;
        Denominator %= MODUL;
    }

    if(Denominator == 1)
    {
        cout << Numerator;
        return 0;
    }

    b = 1;
    while((b * Denominator) % MODUL != 1)
    {
        ++b;
    }
    cout << (Numerator * b) % MODUL;

    return 0;
}

uint64_t gdc(uint64_t a, uint64_t b)
{
    if(b == 0) return a;
    if(a > b) return gdc(b, a % b);
    else return gdc(a, b % a);
}