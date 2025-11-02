#include <iostream>
#include <vector>

constexpr int INF = 20000000;

using namespace std;

int N;
int Mat[16][16];
int Table[16][1 << 16];

int Solve(const int CurrentPos, const int VisitBitMask)
{
    if(Table[CurrentPos][VisitBitMask] > 0)
    {
        return Table[CurrentPos][VisitBitMask];
    }
    else if(VisitBitMask == (1 << N) - 1)
    {
        return Mat[CurrentPos][0] == 0 ? INF : Mat[CurrentPos][0];
    }
    else
    {
        int MinCost = INF;
        for(int i = 0; i < N; ++i)
        {
            if(Mat[CurrentPos][i] > 0 && ((1 << i) & VisitBitMask) == 0)
            {
                MinCost = min(MinCost, Mat[CurrentPos][i] + Solve(i, VisitBitMask + (1 << i)));
            }
        }

        return Table[CurrentPos][VisitBitMask] = MinCost;
    }
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
            cin >> Mat[i][j];
        }
    }

    fill(Table[0], Table[0] + (16 * (1 << 16)), 0);
    
    cout << Solve(0, 1);

    return 0;
}