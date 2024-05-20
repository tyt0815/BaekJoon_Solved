#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 10000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, K;
    cin >> N >> K;
    vector<int> NumBottle(log2(MAXN) + 1, 0); // 물병의 갯수, 물의 양
    NumBottle[1] = N;
    int64_t Sum = N;
    int i = 1, Lowest = 1;
    while(Sum > K)
    {
        if(NumBottle[i] / 2 > 0)
        {
            int Temp = NumBottle[i] / 2;
            NumBottle[i] -= Temp * 2;
            NumBottle[i + 1] += Temp;
            Sum -= Temp;
            if(NumBottle[Lowest] == 0) Lowest = i + 1;
            ++i;
        }
        else
        {
            NumBottle[0] += pow(2, Lowest - 1);
            NumBottle[Lowest] += 1;
            i = Lowest;
            Sum += 1;
        }
    }
    cout << NumBottle[0];

    return 0;
}