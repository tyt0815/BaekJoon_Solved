// 문제: https://www.acmicpc.net/problem/1041
// 풀이: https://tyt0815.notion.site/1041-3f3e74acbbc24b06a304dd0cc89947ed

#include <iostream>
#include <cmath>

using namespace std;

enum{A ,B ,C ,D ,E ,F};

int main()
{
    // N, A, B, C, D, E ,F 입력받기
    long long n;
    long long* dice = new long long[6];
    long long maxValue = 0;
    cin >> n;
    for (int i = 0; i < 6; ++i)
    {
        cin >> dice[i];
        maxValue += dice[i];
    }
    // N이 1일때
    if(n == 1)
    {
        long long m = 0;
        for(int i = 0; i < 6; ++i)
        {
            if(dice[i] > m){m = dice[i];}
        }
        cout << (maxValue - m);
        return 0;
    }

    // 3면 최솟값
    long long threeSidesMin = maxValue;
    long long sideFaces[] = {
        dice[B] + dice[C],
        dice[C] + dice[E],
        dice[E] + dice[D],
        dice[D] + dice[B]
    };
    for(int i = 0; i < 4; ++i)
    {
        if (dice[A] + sideFaces[i] < threeSidesMin) {threeSidesMin = dice[A] + sideFaces[i];}
        if (dice[F] + sideFaces[i] < threeSidesMin) {threeSidesMin = dice[F] + sideFaces[i];}
    }
    // 1면 최솟값
    long long oneSideMin = maxValue;
    for(int i = 0; i < 6; ++i)
    {
        if(dice[i] < oneSideMin) {oneSideMin = dice[i];}
    }
    // 2면 최솟값
    long long twoSidesMin = maxValue;
    for(int i = 0; i < 6; ++i)
    {
        for(int j = i+1; j < 6; ++j)
        {
            if(j == 5-i){ continue; }
            if(dice[i] + dice[j] < twoSidesMin){ twoSidesMin = dice[i] + dice[j]; }
        }
    }
    // 합산
    long long sum = (threeSidesMin * 4) + (oneSideMin * (5*n*n - 16*n + 12)) + (twoSidesMin * (8 * n - 12));
    cout << sum;
    // return
    return 0;
}