#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#define BEERBOX 20
#define METER_PER_BEER 50
constexpr int MaxWalkableDistance = BEERBOX * METER_PER_BEER;

using namespace std;

struct FData
{
    int Position;
    int WalkableDistance;
};

inline int CalcDistance(pair<int, int> A, pair<int, int> B) { return abs(A.first - B.first) + abs(A.second - B.second); }
void WalkWithBeer();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) WalkWithBeer();

    return 0;
}

void WalkWithBeer()
{
    int n;
    cin >> n;

    vector<unordered_set<int>> Cache(n + 1, unordered_set<int>());   
    pair<int, int> Target;
    vector<pair<int, int>> Stores(n + 1, {0, 0});
    for(int i = 0; i <= n; ++i) cin >> Stores[i].first >> Stores[i].second;
    cin >> Target.first >> Target.second;

    queue<FData> q;
    q.push({0, MaxWalkableDistance});
    while(!q.empty())
    {
        FData Data = q.front();
        if(CalcDistance(Stores[Data.Position], Target) <= Data.WalkableDistance)
        {
            cout << "happy\n";
            return;
        }
        q.pop();
        for(int i = 1; i <= n; ++i)
        {
            int Dist = CalcDistance(Stores[Data.Position], Stores[i]);
            if(Cache[i].find(Dist) == Cache[i].end() && Data.WalkableDistance >= Dist)
            {
                Cache[i].insert(Dist);
                FData Temp = Data;
                Temp.Position = i;
                Temp.WalkableDistance = (Data.WalkableDistance - Dist) % METER_PER_BEER;
                Temp.WalkableDistance += MaxWalkableDistance;
                q.push(Temp);
            }
        }
    }
    cout << "sad\n";
}
