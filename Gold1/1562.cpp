#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1'000'000'000;

int Step(int N, int Prev, int Mask, vector<vector<vector<long long>>>& Table)
{
    if(Table[N][Prev][Mask] > -1)
    {
        return Table[N][Prev][Mask];
    }
    else if(N == 0)
    {
        return Mask == ((1 << 10) - 1);
    }
    else
    {
        int Count = 0;
        if(Prev > 0)
        {
            Count = (Count + Step(N - 1, Prev - 1, Mask | (1 << Prev - 1), Table)) % MOD;
        }
        if(Prev < 9)
        {
            Count = (Count + Step(N - 1, Prev + 1, Mask | (1 << Prev + 1), Table)) % MOD;       
        }

        return Table[N][Prev][Mask] = Count;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<vector<vector<long long>>> Table(N, vector<vector<long long>>(10, vector<long long>(1 << 10, -1)));

    int Count = 0;
    for(int i = 1; i < 10; ++i)
    {
        Count = (Count + Step(N - 1, i, 1 << i, Table)) % MOD;
    }

    cout << Count;

    return 0;
}