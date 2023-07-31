// 문제: https://www.acmicpc.net/problem/18185
// 풀이: 

#include <iostream>
#define B 3
#define C 2

using namespace std;

typedef struct
{
    int b;
    int c;
    int c2;
}ramen;


void printAry(int* ary, int end)
{
    for(int i = 0; i < end; ++i) cout << ary[i] << " ";
    cout << endl;
}

int main()
{
    int n, value = 0;
    ramen *amount;
    cin >> n;
    amount = new ramen[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> amount[i].b;
        amount[i].c = amount[i].c2 = 0;
    }

    for(int i = 0; i < n - 1; ++i)
    {
        int update_amount = min(amount[i].b, amount[i+1].b);
        amount[i+1].b -= update_amount;
        amount[i+1].c += update_amount;
        if(i > 0)
        {
            update_amount = min(amount[i].c, amount[i+1].b);
            amount[i+1].b -= update_amount;
            amount[i+1].c2 += update_amount;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        value += amount[i].b * B + amount[i].c * C + amount[i].c2 * C;
    }

    cout << value;

    return 0;
}