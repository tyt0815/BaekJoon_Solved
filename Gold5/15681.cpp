#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Nodes;
vector<int> NumChildVertex;

int DFS(int Parent, int Node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;
    Nodes = vector<vector<int>>(N + 1);
    NumChildVertex = vector<int>(N + 1, 0);
    for(int i = 1; i < N; ++i)
    {
        int U, V;
        cin >> U >> V;
        Nodes[U].push_back(V);
        Nodes[V].push_back(U);
    }

    DFS(0, R);
    for(int i = 0; i < Q; ++i)
    {
        int U;
        cin >> U;
        cout << NumChildVertex[U] << '\n';
    }

    return 0;
}

int DFS(int Parent, int Node)
{
    NumChildVertex[Node] = 0;
    for(const auto &Child : Nodes[Node])
    {
        if(Parent != Child)
        {
            NumChildVertex[Node] += DFS(Node, Child);
        }
    }
    return ++NumChildVertex[Node];
}
