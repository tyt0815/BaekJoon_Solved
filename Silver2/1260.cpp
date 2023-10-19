// 문제: https://www.acmicpc.net/problem/1260
// 풀이: https://www.notion.so/tyt0815/1260-6c07e097769c4b56ae44102c29929793?pvs=4

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<int> *graph, int v, int n);
void bfs(vector<int> *graph, int v, int n);

int main()
{
    int n, m, v;    // 정점의 수, 간선의 수, 시작 노드

    cin >> n >> m >> v;

    vector<int> *graph = new vector<int>[n+1];

    // 그래프 구성
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n+1; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, v, n);
    cout << endl;
    bfs(graph, v, n);

    return 0;
}


void dfs(vector<int> *graph, int v, int n)
{   
    bool *table = new bool[n + 1];
    for(int i = 0; i < n + 1; ++i)
    {
        table[i] = false;
    }

    stack<int> s;
    s.push(v);
    table[v] = true;
    cout << v << " ";

    while(!s.empty())
    {
        int curr = s.top();
        vector<int>::iterator iter = graph[curr].begin();
        for(;iter != graph[curr].end(); ++iter)
        {
            if(!table[*iter])
            {
                s.push(*iter);
                table[*iter] = true;
                cout << *iter << " ";
                break;
            }
        }
        if(iter == graph[curr].end())
        {
            s.pop();
        }
    }


}
void bfs(vector<int> *graph, int v, int n)
{
    bool *table = new bool[n + 1];
    for(int i = 0; i < n + 1; ++i)
    {
        table[i] = false;
    }

    queue<int> q;
    q.push(v);
    table[v] = true;

    cout << v << " ";

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();        // front 데이터를 삭제함
        vector<int>::iterator iter = graph[curr].begin();
        for(;iter != graph[curr].end(); ++iter)
        {
            if(!table[*iter])
            {
                q.push(*iter);
                table[*iter] = true;
                cout << *iter << " ";
            }
        }
    }
}