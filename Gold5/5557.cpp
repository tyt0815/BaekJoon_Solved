#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<unordered_map<int, uint64_t>> Cache;

uint64_t DFS(int Depth, int Sum, const vector<int> &Numbers);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Numbers(N, 0);
    for(int i = 0; i < N; ++i) cin >> Numbers[i];
    Cache.resize(N);

    cout << DFS(1, Numbers[0], Numbers);

    return 0;
}

uint64_t DFS(int Depth, int Sum, const vector<int> &Numbers)
{
    if(Sum < 0 || Sum > 20) return 0;
    if(Depth == Numbers.size() - 1)
    {
        if(Sum == Numbers.back()) return 1;
        else return 0;
    }
    if(Cache[Depth].find(Sum) == Cache[Depth].end())
    {
        Cache[Depth][Sum] = DFS(Depth + 1, Sum + Numbers[Depth], Numbers) + DFS(Depth + 1, Sum - Numbers[Depth], Numbers);
    }
    
    return Cache[Depth][Sum];
}
