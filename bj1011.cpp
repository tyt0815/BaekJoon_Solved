// 문제: https://www.acmicpc.net/problem/1011

#include <iostream>

using namespace std;

int main(void)
{
    long long x, y, k, n, distance;
    cin >> n;
    long long counts[n];

    for (int i = 0; i < n; ++i)
    {
        // 초기화
        cin >> x >> y;
        distance = y - x;
        k = 1;
        for (; (k) * (k + 1) < distance; ++k)
        {
        }
        // --k;
        if (distance <= k * k)
            counts[i] = (2 * k) - 1;
        else
            counts[i] = 2 * k;
    }

    for (int i = 0; i < n; ++i)
        cout << counts[i] << endl;

    return 0;
}