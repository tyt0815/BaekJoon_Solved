#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n, m;
    uint64_t *IntervalSums;     // n번째 인덱스에 0 ~ n까지의 합이 들어감

    cin >> n >> m;
    IntervalSums = new uint64_t[n+1];
    IntervalSums[0] = 0;
    for(uint32_t i = 1; i < n+1; ++i)
    {
        uint32_t InputValue;
        cin >>InputValue;
        IntervalSums[i] = IntervalSums[i-1] + InputValue;
    }

    for(uint32_t i = 0; i < m; ++i)
    {
        uint32_t a, b;
        cin >> a >> b;
        cout << IntervalSums[b] - IntervalSums[a-1] << '\n';
    }

    return 0;
}