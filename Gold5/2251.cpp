#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_CAPACITY 200

using namespace std;

bool Cache[MAX_CAPACITY + 1][MAX_CAPACITY + 1][MAX_CAPACITY + 1] = {false};
pair<int, int> Combination[] = {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
void PourAtoB(int &A, int &B, const int &BCapacity);
void PourWater(int *Bottles, const int *Capacity, vector<int> &Result);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Capacity[3];
    cin >> Capacity[0] >> Capacity[1] >> Capacity[2];
    vector<int> Result;

    Cache[0][0][Capacity[2]] = true;
    Result.push_back(Capacity[2]);
    int Beginning[3] = {0, 0, Capacity[2]};
    PourWater(Beginning, Capacity, Result);
    sort(Result.begin(), Result.end());
    cout << Result[0] << ' ';
    for(int i = 1; i < Result.size(); ++i)
    {
        if(Result[i - 1] != Result[i]) cout << Result[i] << ' ';
    }

    return 0;
}

void PourAtoB(int &A, int &B, const int &BCapacity)
{
    if(A > BCapacity - B)
    {
        A -= BCapacity - B;
        B = BCapacity;
    }
    else
    {
        B = B + A;
        A = 0;
    }
}

void PourWater(int *Bottles, const int *Capacity, vector<int> &Result)
{
    for(int i = 0; i < 6; ++i)
    {
        int Temp[3] = {Bottles[0], Bottles[1], Bottles[2]};
        PourAtoB(Temp[Combination[i].first], Temp[Combination[i].second], Capacity[Combination[i].second]);
        if(!Cache[Temp[0]][Temp[1]][Temp[2]])
        {
            Cache[Temp[0]][Temp[1]][Temp[2]] = true;
            if(Temp[0] == 0) Result.push_back(Temp[2]);
            PourWater(Temp, Capacity, Result);
        }
    }
}
