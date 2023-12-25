#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<vector<int>> Nodes;
    vector<int> Parent;
    cin >> n;
    Nodes.resize(n + 1);
    Parent.resize(n + 1);
    for(int i = 1; i < n; ++i)
    {
        int j, k;
        cin >> j >> k;
        Nodes[j].push_back(k);
        Nodes[k].push_back(j);
        Parent[i] = 0;
    }
    Parent[n] = 0;

    stack<int> s;
    s.push(1);
    while(!s.empty())
    {
        int ParentNode = s.top();
        s.pop();
        int EdgeNumb = Nodes[ParentNode].size();
        for(int i = 0; i < EdgeNumb; ++i)
        {
            int ConnectedNode = Nodes[ParentNode][i];
            // 연결된 노드가 1(루트)이 아니고 부모노드를 못찾은 경우
            if(ConnectedNode != 1 && Parent[ConnectedNode] == 0)
            {
                Parent[ConnectedNode] = ParentNode;
                s.push(ConnectedNode);
            }
        }
    }
    
    for(int i = 2; i <= n; ++i)
    {
        cout << Parent[i] << '\n';
    }

    return 0;
}