#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int GetRoot(const int i, vector<int>& Root);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> Nodes(M);
    vector<int> Root(N);
    for(int i = 0; i < N; ++i) Root[i] = i;
    for(int i = 0; i < M; ++i) cin >> Nodes[i].first >> Nodes[i].second;

    for(int i = 0; i < M; ++i)
    {
        const int &X = Nodes[i].first, &Y = Nodes[i].second;
        if(GetRoot(X, Root) == GetRoot(Y, Root))
        {
            cout << i + 1;
            return 0;
        }
        Root[GetRoot(Y, Root)] = GetRoot(X, Root);
    }
    cout << 0;

    return 0;
}

int GetRoot(const int i, vector<int>& Root)
{
    if(Root[i] == i) return i;
    else return Root[i] = GetRoot(Root[i], Root);
}