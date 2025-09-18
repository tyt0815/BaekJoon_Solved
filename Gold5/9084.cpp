#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;      // 테스크 케이스 개수
    cin >> T;

    while(T--)
    {
        int N;      // 동전의 가짓수
        cin >> N;
        vector<int> CoinTypes(N);       // 동전의 종류. 오름차순
        for(int& CoinType : CoinTypes)
        {
            cin >> CoinType;
        }

        int M;      // 목표 금액
        cin >> M;
        
        vector<int> DP(M + 1, 0);
        for(int i = 0; i < DP.size(); i += CoinTypes[0])
        {
            DP[i] = 1;
        }

        for(int j = 1; j < CoinTypes.size(); ++j)
        {
            for(int i = CoinTypes[j]; i < DP.size(); ++i)
            {
                DP[i] += DP[i - CoinTypes[j]];
            }
        }


        cout << DP.back() << '\n';
    }


    return 0;
}