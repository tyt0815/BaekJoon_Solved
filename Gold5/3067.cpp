#include <iostream>
#include <vector>
#define MAX_TARGET 10000
#define MAX_COIN_TYPE 20

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> CoinTypes(MAX_COIN_TYPE, 0);
    vector<uint64_t> p(MAX_TARGET + 1, 0);
    
    for(int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        for(int i = 0; i < N; ++i) cin >> CoinTypes[i];
        int Target;
        cin >> Target;

        p.assign(Target + 1, 0);
        p[0] = 1;
        // 사용할 코인의 수: i + 1
        for(int i = 0; i < N; ++i)
        {
            // 코인으로 j를 만들 수 있는 가짓수
            for(int j = 1; j <= Target; ++j)
            {
                if(j >= CoinTypes[i]) p[j] += p[j - CoinTypes[i]];
            }
        }

        cout << p[Target] << '\n';
    }

    return 0;
}