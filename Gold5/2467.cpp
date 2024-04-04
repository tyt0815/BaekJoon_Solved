#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Solutions(N, 0);
    for(int i = 0; i < N; ++i) cin >> Solutions[i];

    int i = 0, j = N - 1;
    int Solution1 = Solutions[i], Solution2 = Solutions[j];
    int AttributeSum = Solution1 + Solution2;
    while(i < j)
    {
        int TempAttributeSum = Solutions[i] + Solutions[j];
        if(abs(AttributeSum) > abs(TempAttributeSum))
        {
            AttributeSum = TempAttributeSum;
            Solution1 = Solutions[i];
            Solution2 = Solutions[j];
        }
        if(AttributeSum == 0) break;
        if(TempAttributeSum > 0) --j;
        else ++i;
        
    }
    cout << Solution1 << ' ' << Solution2;

    return 0;
}