/*
문제
자연수 
\(N\)과 정수 
\(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
\(N\)과 
\(K\)가 주어진다. (1 ≤ 
\(N\) ≤ 10, 0 ≤ 
\(K\) ≤ 
\(N\))

출력
 
\(\binom{N}{K}\)를 출력한다.
*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    if(k < 0 || k > n) { cout << 0; }
    else
    {
        int c = 1;
        for(int i = 0; i < k; ++i)
        {
            c *= (n-i);
        }
        for(int i = 0; i < k; ++i)
        {
            c /= (k-i);
        }
        cout << c;
    }

    return 0;
}