// 문제: https://www.acmicpc.net/problem/28085
// 풀이: 

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int *boat;
    bool *isCross;
    int firstI = 0, secondI = 0;
    int result = 0;

    cin >> n;

    boat = new int[n];
    isCross = new bool[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> boat[i];
        isCross[i] = false;
    }

    sort(boat, boat+n);

    if(n == 1)
    {
        cout << boat[0];
        return 0;
    }
    if(boat[0] == boat[n-1])
    {
        cout << -1;
        return 0;
    }
    if(n == 2)
    {
        cout << max(boat[0], boat[1]);
        return 0;
    }

    for(int i = firstI+1; i < n; ++i)
    {
        if(boat[firstI] < boat[i])
        {
            secondI = i;
            break;
        }
    }

    // i == 0: 사람이 건너지 않음
    // i == 1: 사람이 건넘
    for(int i = 0, j = n-1;;i = (i+1)%2)
    {
        // 무게가 가장 작은 배와 그다음 작은 배가 건너지 못함, 사람도 건너지 못한상태
        if(!isCross[firstI] && !isCross[secondI])
        {
            // i == 0인 경우만 있음
            result += boat[secondI];
            isCross[firstI] = isCross[secondI] = true;
        }
        // 무게가 가장 작은 배와 그다음 작은 배가 둘다 건넘, 사람은 건넌 상태
        else if(isCross[firstI] && isCross[secondI])
        {
            if(isCross[j])
            {
                break;
            }
            if(boat[firstI] == boat[j])
            {
                result += boat[secondI];
                isCross[secondI] = false;
            }
            // i == 1인 경우만 있음
            else
            {
                result += boat[firstI];
                isCross[firstI] = false;
            }
        }
        // 무게가 두번째로 작은 배만 건넘
        else if(!isCross[firstI] && isCross[secondI])
        {
            // 사람이 건너지 못한 상태
            if(i == 0)
            {
                int withJ;
                for(withJ = j-1; withJ >= 0; --withJ)
                {
                    if(boat[withJ] < boat[j] && !isCross[withJ]){ break; }
                }
                result += boat[j];
                isCross[withJ] = isCross[j] = true;
                               
            }
            // 사람이 건넌 상태
            else
            {
                result += boat[secondI];
                isCross[secondI] = false;
            }
        }
        // 무게가 제일 작은 배만 건넘
        else
        {
            if(i == 0)
            {
                result += boat[secondI];
                isCross[secondI] = isCross[j] = true;
                               
            }
            else
            {
                result += boat[firstI];
                isCross[firstI] = true;
            }
        }
        for(;j>=0;--j)
        {
            if(!isCross[j]){ break; }
        }
       
    }
    
    cout << result;

    return 0;
}