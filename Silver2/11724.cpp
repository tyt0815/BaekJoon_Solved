#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n, m;
    vector<vector<uint32_t>> Nodes;
    bool *SearchTable;
    uint32_t Count = 0;;

    cin >> n >> m;
    Nodes.resize(n+1);
    SearchTable = new bool[n+1];
    for(uint32_t i = 0; i < n+1; ++i) { SearchTable[i] = false; }

    for(uint32_t i = 0; i < m; ++i)
    {
        uint32_t a, b;
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    for(uint32_t i = 1; i < n+1; ++i)
    {
        if(SearchTable[i]) { continue; }
        ++Count;
        queue<uint32_t> q;
        q.push(i);
        while (!q.empty())
        {
            uint32_t Node = q.front();
            q.pop();
            if(!SearchTable[Node])
            {
                SearchTable[Node] = true;
                for(uint32_t j = 0; j < Nodes[Node].size(); ++j)
                {
                    if(!SearchTable[Nodes[Node][j]])
                    {
                        q.push(Nodes[Node][j]);
                    }
                }
            }

        }
        
    }
    
    cout << Count;

    return 0;
}