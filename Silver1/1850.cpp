#include <iostream>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    if(b == 0) return a;
    else if(a > b) return gcd(b, a % b);
    else return gcd(a, b % a);
}

int main()
{
    uint64_t a, b;
    cin >> a >> b;
    uint64_t c = gcd(a, b);
    for(int i = 0; i < c; ++i) cout << '1';
    return 0;
}