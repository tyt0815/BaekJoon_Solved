#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<unordered_map<int, int>> VolumeCache;

int AdjustVoluem(int Volume, int Depth, const vector<int>& V, const int& MaxVolume);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, m;
    cin >> n >> s >> m;
    vector<int> V(n, 0);
    VolumeCache = vector<unordered_map<int, int>>(n, unordered_map<int, int>());
    for(int i = 0; i < n; ++i) cin >> V[i];

    cout << AdjustVoluem(s, 0, V, m);
    

    return 0;
}

int AdjustVoluem(int Volume, int Depth, const vector<int> &V, const int &MaxVolume)
{
    if(Depth == V.size()) return Volume;
    int Result = -1;
    if(VolumeCache[Depth].find(Volume) == VolumeCache[Depth].end())
    {
        if(Volume - V[Depth] >= 0)
        {
            Result = AdjustVoluem(Volume - V[Depth], Depth + 1, V, MaxVolume);
        }
        if(Volume + V[Depth] <= MaxVolume)
        {
            Result = max(Result, AdjustVoluem(Volume + V[Depth], Depth + 1, V, MaxVolume));
        }
        VolumeCache[Depth][Volume] = Result;        
    }
    else
    {
        Result = VolumeCache[Depth][Volume];
    }

    return Result;
}
