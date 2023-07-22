// 문제: https://www.acmicpc.net/problem/1092
// 풀이: https://www.notion.so/tyt0815/1092-1e8778aa8e954ffaaf6227bae6b20b39?pvs=4

#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;

int main()
{
    int n, m, cnt = 0;
    int *canMoveBoxNumb;
    double *l, *a;
    double maxL = 0, maxA = 0;
    
    cin >> n;
    l = new double[n];
    canMoveBoxNumb = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> l[i];
        if(l[i] > maxL) { maxL = l[i]; }
    }
    cin >> m;
    a = new double[m];
    for(int i = 0; i < m; ++i)
    {
        cin >> a[i];
        if(a[i] > maxA) { maxA = a[i]; }
    }

    // 크레인이 모든화물을 옮길 수 없는 경우
    if(maxA > maxL)
    {
        cout << -1;
        return 0;
    }

    sort(l, l + n);
    sort(a, a + m);

    int i, j;
    int boxNumb = 0;
    int maxj = m-1;
    while(maxj > -1)
    {
        for(i = n-1; i > -1; --i)      // 크레인
        {
            for(j = maxj; j > -1; --j)   // 박스
            {
                if(a[j] == -1) continue;
                if(a[j] <= l[i])
                {
                    a[j] = -1;
                    break;
                }
            }
        }
        ++cnt;
        while(a[maxj] == -1 && maxj > -1){--maxj;}
    }
    

    cout << cnt;

    return 0;
}
