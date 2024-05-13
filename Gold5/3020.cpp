#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;
    vector<int> Top(H + 1, 0), Bottom(H + 1, 0);
    for(int i = 0; i < N / 2; ++i)
    {
        int B, T;
        cin >> B >> T;
        ++Bottom[B];
        ++Top[H - T + 1];
    }

    for(int i = 1; i < H; ++i)
    {
        Bottom[H - i] += Bottom[H - i + 1];
        Top[i + 1] += Top[i];
    }

    int MinCollision = INT32_MAX, Count = 0;
    for(int i = 1; i <= H; ++i)
    {
        int Collision = Top[i] + Bottom[i];
        if(MinCollision > Collision)
        {
            MinCollision = Collision;
            Count = 1;
        }
        else if(MinCollision == Collision)
        {
            ++Count;
        }
    }
    cout << MinCollision << ' ' << Count;

    return 0;
}