#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, l;
    cin >> n >> w >> l;
    vector<int> Trucks(n, 0);
    for(int i = 0; i < n; ++i) cin >> Trucks[i];

    int Result = 1, Weight = Trucks[0], Front = 0, Back = 1;
    vector<int> Pos(n, 0);
    Pos[0] = 1;
    while(Back < n)
    {
        if(Weight + Trucks[Back] <= l)
        {
            Weight += Trucks[Back];
            ++Back;
            for(int i = Front; i < Back; ++i) Pos[i] += 1;
            if(Pos[Front] > w)
            {
                Weight -= Trucks[Front];
                ++Front;
            }
            ++Result;
        }
        else
        {
            int ElapsedTime = w - Pos[Front] + 1;
            for(int i = Front; i < Back; ++i) Pos[i] += ElapsedTime;
            Weight -= Trucks[Front];
            ++Front;
            Result += ElapsedTime;
            if(Weight + Trucks[Back] <= l)
            {
                Weight += Trucks[Back];
                Pos[Back] = 1;
                ++Back;
            }
        }
    }
    Result += w - Pos[Back - 1] + 1;

    cout << Result;

    return 0;
}