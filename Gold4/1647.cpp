#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FEdge
{
    int A;
    int B;
    int64_t Weight;
    bool operator<(FEdge& RValue){ return Weight < RValue.Weight; }
};

vector<int> Root;
vector<FEdge> Edges;

int GetRoot(int i);
void MergeTree(int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Root.resize(N + 1);
    for(int i = 1; i < Root.size(); ++i) Root[i] = i;
    Edges.resize(M);
    for(int i = 0; i < Edges.size(); ++i)
    {
        int A, B, W;
        cin >> A >> B >> W;
        Edges[i] = {A, B, W};
    }

    sort(Edges.begin(), Edges.end());
    int64_t Sum = 0, MaxWeight = 0;
    for(int i = 0; i < Edges.size(); ++i)
    {
        if(GetRoot(Edges[i].A) == GetRoot(Edges[i].B)) continue;
        MergeTree(Edges[i].A, Edges[i].B);
        Sum += Edges[i].Weight;
        MaxWeight = Edges[i].Weight;
    }

    cout << Sum - MaxWeight;

    return 0;
}

int GetRoot(int i)
{
    if(i == Root[i]) return i;
    return Root[i] = GetRoot(Root[i]);
}

void MergeTree(int i, int j)
{
    int JRoot = GetRoot(j);
    Root[JRoot] = i;
}
