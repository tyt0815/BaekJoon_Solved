#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 회전 초밥 벨트의 접시의 수
    int d; // 초밥의 가짓수
    int k; // 연속해서 먹는 접시의 수 (k <= N)
    int c; // 쿠폰 번호(c <= d)

    cin >> N >> d >> k >> c;

    vector<int> Sushis(N);     // 회전초밥의 초밥 (1이상 d이하 정수)
    for(int& Sushi : Sushis)
    {
        cin >> Sushi;
    }

    int MaxCount = 0;                 // 손님이 먹을 수 있는 초밥 가짓수의 최댓값
    vector<int> CountSushis(d + 1, 0); 
    CountSushis[c] = 1;
    int Count = 1;

    // 첫번째 접시부터 k개 먹었을때 먹은 초밥의 가짓수 계산
    for(int i = 0; i < k; ++i)
    {
        if (CountSushis[Sushis[i]] == 0)
        {
            ++Count;
        }
        ++CountSushis[Sushis[i]];
    }

    MaxCount = Count;

    for(int i = 1; i < Sushis.size(); ++i)
    {
        const int& PopedSushi = Sushis[i - 1];
        if(--CountSushis[PopedSushi] == 0)
        {
            --Count;
        }

        int LastPlateIndex = (i + k - 1) % Sushis.size();
        const int& PushedSushi = Sushis[LastPlateIndex];
        if (CountSushis[PushedSushi] == 0)
        {
            ++Count;
        }
        ++CountSushis[PushedSushi];

        MaxCount = max(MaxCount, Count);
    }

    cout << MaxCount;

    return 0;
}