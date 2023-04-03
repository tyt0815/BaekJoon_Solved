// 문제: https://www.acmicpc.net/problem/1038
// 풀이: https://tyt0815.notion.site/1038-0ab64cfbba0441dfa3ba00813c225c6a

#include <iostream>
#include <vector>

using namespace std;

long long ReducingNumb(long long);
int Combination(long long, long long);

int main()
{
    long long n;

    cin >> n;

    cout << ReducingNumb(n);

    return 0;
}

long long ReducingNumb(long long n)
{
    long long result = -1;
    // p: 현재수, count: 몇번째 수인지, addP 몇자리 수씩 더할지, power = 현재 몇자리 수인지. 즉 addp = 10^power
    long long p = 0, count = 0, addP = 1, power = 0;

    while (true)
    {
        // count가 요구사항 n과 동일하면 루프를 빠져나옴
        if (count == n)
        {
            return p;
        }
        // p가 최대 감소하는 수인 9876543210이 되면 -1을 리턴
        else if (p >= 9876543210)
        {
            return -1;
        }
        // 가장 큰 자릿수단위로 확인하기 위해 addP를 올린다.
        // 가장 큰 자릿수가 현재 수가 맞는지 확인
        if ((p / addP) >= power)
        {
            int comb = Combination((long long)(p / addP), power);
            if (count + comb > n)
            {
                break;
            }

            count += comb;
        }
        p += addP;
        if (p / addP >= 10)
        {
            addP *= 10;
            ++power;
        }
    }

    while (true)
    {
        int m = (int)(p / addP);
        addP /= 10;
        --power;

        for (int i = 1; i < m; ++i)
        {
            int comb = Combination(m, power);
            cout << m << " " << addP << " " << power << " " << i << " " << count << " " << comb << endl;
            if (count + comb == n)
            {
                count += comb;
                p += addP * i;
                break;
            }
            else if (count + comb > n)
            {
                p += addP * i;
                break;
            }
            count += comb;
        }

        if (count == n)
        {
            break;
        }
    }

    return p;
}

int Combination(long long n, long long r)
{
    long long result = 1, temp;

    if (n < r)
    {
        return 0;
    }
    if (n - r < r)
    {
        r = n - r;
    }
    for (int i = 0; i < r; ++i, --n)
    {
        result *= n;
    }
    for (int i = 0, temp = r; i < r; ++i, --temp)
    {
        result /= temp;
    }

    return result;
}