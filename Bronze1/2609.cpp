/*
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

// 최대공약수
uint64_t f1(int a, int b)
{
    if(b == 0) return a;
    if(a>b)
    {
        return f1(b, a%b);
    }
    else
    {
        return f1(a,b%a);
    }
}
// 최소공배수
uint64_t f2(int a, int b)
{
    return a * b / f1(a,b);
}
int main()
{
    int n,m;
    cin >> n >> m;
    cout << f1(n,m) << "\n" << f2(n,m);

    return 0;
}

