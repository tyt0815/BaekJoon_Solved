// 문제: https://www.acmicpc.net/problem/1107
// 풀이: https://www.notion.so/tyt0815/1107-64a569a6c870420a902ca954c2d96c43?pvs=4

#include <iostream>
#include <cmath>

using namespace std;

bool buttonTable[] = {true, true, true, true, true, true, true, true, true, true};


bool Check(int n){
    if(n == 0 && !buttonTable[0])
    {
        return false;
    }
    for(int digit = 1; n/digit > 0; digit*=10)
    {
        int num = (n/digit)%10;
        if(!buttonTable[num])
        {
            return false;
        }
    }
    return true;
}

int CalcCnt(int n, int t)
{
    int cnt = 0;
    if(n == 0)
    {
        cnt = 1;
    }
    for(int digit = 1; n/digit > 0; digit*=10)
    {
        ++cnt;
    }

    return abs(t-n) + cnt;
}

void find(int n)
{
    //n: target
    //m: len(enableButtons)
    int i, j;
    int currNum = 0;
    int cnt = abs(100-n);
    
    for(; currNum < 500000 + n; ++currNum)
    {
        if(Check(currNum))
        {
            int temp = CalcCnt(currNum, n);
            if(cnt > temp)
            {
                cnt = temp;
            }
        }   
    }

    cout << cnt;
}

int main()
{
    int n, m, i, j;
    int cnt = 0;
    

    cin >> n >> m;
    for(i = 0; i < m; ++i)
    {
        int broken;
        cin >> broken;
        buttonTable[broken] = false;
    }

    // 모두 박살
    if (m == 10)
    {
        cout << abs(n - 100);
        return 0;
    }

    find(n);

    return 0;
}
