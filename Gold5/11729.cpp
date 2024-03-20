#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void BuildTower(int From, int To, int Temp, int Height);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << fixed << setprecision(0) << pow<uint64_t>(2, n) - 1;
    BuildTower(1, 3, 2, n);

    return 0;
}

void BuildTower(int From, int To, int Temp, int Height)
{
    if(Height == 1) 
    {
        cout << '\n' << From << ' ' << To;
        return;
    }
    BuildTower(From, Temp, To, Height - 1);
    cout << '\n' << From << ' ' << To;
    BuildTower(Temp, To, From, Height - 1);
}