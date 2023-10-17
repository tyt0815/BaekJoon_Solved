#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint16_t NumComp;
    uint32_t NumEdges;
    vector<vector<uint16_t>> NetworkGraph;
    vector<bool> SearchTable;
    queue<uint16_t> q;
    uint32_t Cnt = -1;

    cin >> NumComp >> NumEdges;

    NetworkGraph.resize(NumComp + 1);
    SearchTable.resize(NumComp + 1);
    for(uint16_t i = 0; i <= NumComp; ++i)
    {
        SearchTable[i] = false;
    }
    for(uint32_t i = 0; i < NumEdges; ++i)
    {
        uint16_t a, b;
        cin >> a >> b;

        NetworkGraph[a].push_back(b);
        NetworkGraph[b].push_back(a);
    }

    q.push(1);
    while (!q.empty())
    {
        uint16_t Back = q.front();
        if(!SearchTable[Back])
        {
            ++Cnt;
            SearchTable[Back] = true;
            vector<uint16_t>::iterator Iter = NetworkGraph[Back].begin();
            for(; Iter != NetworkGraph[Back].end(); ++Iter)
            {
                if(!SearchTable[*Iter])
                {
                    q.push(*Iter);
                }
            }
        }
        q.pop();
    }
    
    cout << Cnt;

    return 0;
}