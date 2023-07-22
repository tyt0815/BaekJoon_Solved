// 문제: https://www.acmicpc.net/problem/1083
// 풀이: https://www.notion.so/tyt0815/1083-e8c7cd63d28544d7ad005d15fd7ffbd7?pvs=4

#include <iostream>

using namespace std;

int main()
{
    long long n = 0;
    long long* ary;
    long long s;
    cin >> n;
    ary = new long long[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> ary[i];
    }
    cin >> s;
    s = min(s, (n * (n - 1))/2);
    
    for(int start = 0; s > 0 && start < n; ++start)
    {
        long long maxValue = -1;
        long long maxValueI = -1;
        long long range = min(s + 1, n - start) + start;
        for(int i = start; i < range; ++i)
        {
            if (ary[i] > maxValue)
            {
                maxValue = ary[i];
                maxValueI = i;
            }
        }
        for(int i = maxValueI; i > start; --i)
        {
            ary[i] = ary[i-1];
        }
        ary[start] = maxValue;
        s -= (maxValueI - start);
    }

    cout << ary[0];
    for(int i = 1; i < n; ++i)
    {
        cout << " " << ary[i];
    }

    return 0;
}