#include <iostream>

constexpr int MAX_SIZE = 10;

using namespace std;

int N;
int Board[MAX_SIZE][MAX_SIZE];
bool DownCross[MAX_SIZE * 2 - 1];
int Table[MAX_SIZE * 2 - 1][1 << (MAX_SIZE * 2 - 1)];

int Solve(const int Depth, const int BitMask)
{
    if(Depth == N * 2 - 1)
    {
        return 0;
    }
    if(Table[Depth][BitMask] > -1)
    {
        return Table[Depth][BitMask];
    }

    Table[Depth][BitMask] = Solve(Depth + 1, BitMask);
    const int iLimit = N - abs(N - 1 - Depth);
    for(int i = 0; i < iLimit; ++i)
    {
        int Offset = Depth < N ? 0 : Depth - N + 1;
        int x = Depth - i - Offset;
        int y = i + Offset;
        int DownCrossIndex = N - 1 - (x - y);

        if(Board[x][y] == 1 && !DownCross[DownCrossIndex])
        {
            DownCross[DownCrossIndex] = true;
            Table[Depth][BitMask] = max(Table[Depth][BitMask], Solve(Depth + 1, BitMask + (1 << DownCrossIndex)) + 1);
            DownCross[DownCrossIndex] = false;
        }
    }

    return Table[Depth][BitMask];
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
        }
    }
    fill(DownCross, DownCross + MAX_SIZE * 2 - 1, false);
    fill(Table[0], Table[0] + (MAX_SIZE * 2 - 1) * (1 << (MAX_SIZE * 2 - 1)), -1);

    cout << Solve(0, 0);

    return 0;
}