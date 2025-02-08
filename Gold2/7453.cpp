#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // 문제해결
    vector<int64_t> ABSum, CDSum;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            ABSum.push_back(A[i] + B[j]);
            CDSum.push_back(C[i] + D[j]);
        }
    }
    sort(ABSum.begin(), ABSum.end());
    sort(CDSum.begin(), CDSum.end());
    int64_t Count = 0;
    int64_t a = lower_bound(ABSum.begin(), ABSum.end(), -CDSum.back()) - ABSum.begin();
    int64_t b = ABSum.size();
    int64_t c = CDSum.size();
    int64_t d = CDSum.size();
    while(a < ABSum.size())
    {
        b = upper_bound(ABSum.begin() + a, ABSum.end(), ABSum[a]) - ABSum.begin();
        c = lower_bound(CDSum.begin(), CDSum.begin() + c, -ABSum[a]) - CDSum.begin();
        d = upper_bound(CDSum.begin() + c, CDSum.end(), -ABSum[a]) - CDSum.begin();
        Count += (b - a) * (d - c);
        if(c == 0)
        {
            break;
        }
        d = c;
        c = lower_bound(CDSum.begin(), CDSum.begin() + d, CDSum[d - 1]) - CDSum.begin();
        a = lower_bound(ABSum.begin() + b, ABSum.end(), -CDSum[c]) - ABSum.begin();
        b = upper_bound(ABSum.begin() + a, ABSum.end(), -CDSum[c]) - ABSum.begin();
        Count += (b - a) * (d - c);
        a = b;
    }

    cout << Count;

    return 0;
}