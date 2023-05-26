// 문제: https://www.acmicpc.net/problem/1003
// 풀이: https://www.notion.so/tyt0815/1003-14787e9f4cab4fe3ad5507adb5022f59?pvs=4

#include <iostream>

using namespace std;

int main()
{
    int *p1,*p0;
    int maxN = 0, n;
    int *q;
    cin >> n;
    q = new int[n];

    for(int i = 0; i < n;++i)
    {
        cin >> q[i];
        maxN = max(maxN, q[i]);
    }

    p1 = new int[maxN+1];
    p0 = new int [maxN+1];

    p0[0] = 1;  p1[0] = 0;
    if(maxN > 0)
    {
        p0[1] = 0;  p1[1] = 1;
    }

    for(int i = 2; i < maxN+1; ++i)
    {
        p0[i] = p0[i-1] + p0[i-2];
        p1[i] = p1[i-1] + p1[i-2];
    }

    for(int i = 0; i < n; ++i)
    {
        cout << p0[q[i]] << " " << p1[q[i]] << endl;
    }


    return 0;
}