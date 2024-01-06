#include <iostream>

using namespace std;

void DownWard(int* Ladder, int* PrevResult, int* Result, int (*Comparison)(int, int));

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int Ladder[3], MaxResult[2][3], MinResult[2][3];
    cin >> n;

    cin >> MaxResult[0][0] >> MaxResult[0][1] >> MaxResult[0][2];
    MinResult[0][0] = MaxResult[0][0];
    MinResult[0][1] = MaxResult[0][1];
    MinResult[0][2] = MaxResult[0][2];

    for(int i = 1; i < n; ++i)
    {
        int j = i % 2;
        int k = (j + 1) % 2;
        cin >> Ladder[0] >> Ladder[1] >> Ladder[2];
        DownWard(Ladder, MaxResult[k], MaxResult[j], [](int a, int b){ return max(a, b); });
        DownWard(Ladder, MinResult[k], MinResult[j], [](int a, int b){ return min(a, b); });
    }

    int i = (n - 1) % 2;
    cout << max(max(MaxResult[i][0], MaxResult[i][1]), MaxResult[i][2]) << ' ' << min(min(MinResult[i][0], MinResult[i][1]), MinResult[i][2]);

    return 0;
}

void DownWard(int* Ladder, int* PrevResult, int* Result, int (*Comparison)(int, int))
{
    Result[0] = Comparison(PrevResult[0], PrevResult[1]) + Ladder[0];
    Result[1] = Comparison(Comparison(PrevResult[0], PrevResult[1]), PrevResult[2]) + Ladder[1];
    Result[2] = Comparison(PrevResult[1], PrevResult[2]) + Ladder[2];
    return;
}
