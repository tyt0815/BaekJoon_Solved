// 문제: https://www.acmicpc.net/problem/1038
// 풀이: https://tyt0815.notion.site/1038-0ab64cfbba0441dfa3ba00813c225c6a

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// long long ReducingNumb(long long);

// int main()
// {
//     long long n;

//     cin >> n;

//     cout << ReducingNumb(n);

//     return 0;
// }

// long long ReducingNumb(long long n)
// {
//     long long numb = 0, cnt = 0;
//     long long p = 0, addN = 1, addNP = 0;

//     while (true)
//     {
//         if (cnt == n)
//         {
//             break;
//         }
//         else if (numb >= 9876543210)
//         {
//             return -1;
//         }

//         // 좌측으로 이동가능
//         if (numb / addN >= 10)
//         {
//             // addN을 더할수 있음
//             if ((numb / (addN * 10)) % 10 > ((numb / addN) % 10) + 1)
//             {
//                 numb += addN;
//                 ++cnt;
//                 addN = 1;
//                 addNP = 0;
//             }
//             // addN을 더할수 없음
//             else
//             {
//                 addN *= 10;
//                 ++addNP;
//                 numb /= addN;
//                 numb *= addN;
//                 for (int i = 0; i < addNP; ++i)
//                 {
//                     numb += i * pow(10, i);
//                 }
//             }
//         }
//         // 좌측으로 이동 불가능(0~9)
//         else
//         {
//             while (true)
//             {
//                 numb += addN;
//                 // 자릿수가 바뀐경우
//                 if (numb / addN >= 10)
//                 {
//                     addN *= 10;
//                     ++addNP;
//                     ++p;
//                 }
//                 if (numb / addN >= p)
//                 {
//                     numb /= addN;
//                     numb *= addN;
//                     break;
//                 }
//             }
//             for (int i = 0; i < p; ++i)
//             {
//                 numb += i * pow(10, i);
//             }
//             ++cnt;
//             addN = 1;
//             addNP = 0;
//         }
//     }

//     return numb;
// }

#include <iostream>
#include <queue>

using namespace std;

long long ReducingNumb(long long);

int main()
{

    long long n;

    cin >> n;

    cout << ReducingNumb(n);

    return 0;
}

long long ReducingNumb(long long n)
{
    queue<long long> q;
    long long result;

    for (int i = 1; i < 10; ++i)
    {
        q.push(i);
    }

    // 한자리수
    if (0 <= n && n < 10)
    {
        return n;
    }
    // 범위초과
    else if (n > 1022)
    {
        return -1;
    }

    int count = 10;
    while (count <= n && q.empty() == false)
    {
        long long num = q.front();
        q.pop();

        int last = num % 10;
        for (int i = 0; i < last; ++i)
        {
            q.push(num * 10 + i);
            if (count == n)
            {
                result = num * 10 + i;
                ++count;
                break;
            }
            ++count;
        }
    }

    return result;
}