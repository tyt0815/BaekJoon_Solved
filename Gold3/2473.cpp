#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int64_t> Solutions(N);
    for(int i = 0; i < Solutions.size(); ++i) cin >> Solutions[i];

    sort(Solutions.begin(), Solutions.end());

    int64_t MinSum = 3'000'000'000;
    int64_t A = 0, B = 0, C = 0;
    for(int i = 0; i < N - 2; ++i)
    {
        int j = i + 1, k = N - 1;
        while(j < k)
        {
            int64_t Sum = Solutions[i] + Solutions[j] + Solutions[k];
            if(abs(Sum) < abs(MinSum))
            {
                MinSum = Sum;
                A = Solutions[i];
                B = Solutions[j];
                C = Solutions[k];
            }
            if(Sum > 0) --k;
            else ++j;
        }
    }

    cout << A << ' ' << B << ' ' << C;

    return 0;
}