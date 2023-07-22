// 문제: https://www.acmicpc.net/problem/1025

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long FindCPow(long long, long long, long long *[]);

int main(void)
{
    long long n, m;
    // 행렬 만들기
    cin >> n >> m;

    // long long mat[n][m];
    long long **mat = new long long *[n];
    for (int i = 0; i < n; ++i)
    {
        mat[i] = new long long[m];
    }

    for (int i = 0; i < n; ++i)
    {
        long long numbers;
        cin >> numbers;
        for (int j = 0; j < m; ++j)
        {
            int parsing = pow(10, m - j);
            mat[i][j] = (long long)((numbers % parsing) / (parsing / 10));
        }
    }

    cout << FindCPow(n, m, mat);

    return 0;
}

long long FindCPow(long long n, long long m, long long **mat)
{
    long long i, iAdd, j, jAdd, ti, tj;
    long long result = -1;

    for (i = 0; i < n; ++i)
    {

        for (j = 0; j < m; ++j)
        {

            for (iAdd = 0; iAdd < n; ++iAdd)
            {

                for (jAdd = -m; jAdd < m; ++jAdd)
                {
                    if (iAdd == 0 && jAdd == 0)
                    {
                        continue;
                    }
                    long long v = 0, r = 0, count = 1;

                    for (ti = i, tj = j; ti < n && ti >= 0 && tj >= 0 && tj < m; ti += iAdd, tj += jAdd, count *= 10)
                    {
                        v = (v * 10) + mat[ti][tj];
                        r = r + (mat[ti][tj] * count);

                        if ((sqrt(v) == (long long)sqrt(v)) && v > result)
                        {
                            result = v;
                        }
                        if ((sqrt(r) == (long long)sqrt(r)) && r > result)
                        {
                            result = r;
                        }
                    }
                }
            }
        }
    }

    return result;
}