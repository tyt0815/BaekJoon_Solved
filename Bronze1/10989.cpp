/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <iostream>

using namespace std;

int main()
{
    uint n;
    uint ary[10001];
    uint minN = 10001, maxN = 0;
    for(int i = 0; i < 10001; ++i)
    {
        ary[i] = 0;
    }
    cin >> n;
    for(uint i = 0; i < n; ++i)
    {
        uint a;
        cin >> a;
        ++ary[a];
        minN = min(minN, a);
        maxN = max(maxN, a);
    }
    for(uint i = minN; i <= maxN; ++i)
    {
        for(uint j = 0; j < ary[i]; ++j) { cout << i << '\n'; }
    }
    return 0;
}