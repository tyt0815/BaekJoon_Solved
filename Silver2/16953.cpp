#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int Cnt = 1;
    cin >> a >> b;

    while(a != b)
    {
        if(a > b)
        {
            cout << -1;
            return 0;
        }


        // b가 짝수인 경우
        if(b % 2 == 0)
        {
            b /= 2;
        }
        // 1의 자리가 1인 경우
        else if(b % 10 == 1)
        {
            b /= 10;
        }
        else
        {
            cout << -1;
            return 0;
        }
        ++Cnt;
    }

    cout << Cnt;

    return 0;
}