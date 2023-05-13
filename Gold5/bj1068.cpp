// 문제: https://www.acmicpc.net/problem/1068
// 풀이: https://www.notion.so/tyt0815/1068-f707562b3349447b852d69b586970055?pvs=4

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    // 초기화
    int n, delNode;
    int* node;
    vector<int>* tree;
    queue<int> q;
    bool* isLeaf;
    cin >> n;
    node = new int[n]();
    tree = new vector<int>[n]();
    isLeaf = new bool[n];
    for(int i = 0; i < n; ++i) { isLeaf[i] = true; }
    for(int i = 0; i < n; ++i)
    {
        cin >> node[i];
        if (node[i] != -1)
        { 
            isLeaf[node[i]] = false;
            tree[node[i]].push_back(i);
        }
        
    }
    cin >> delNode;
    // 노드 및 노드의 자식노드 제거
    // 삭제노드의 부모노드가 리프노드인지
    int parentNode = -1;
    for(int i = 0; i < n; ++i)
    {
        vector<int>::iterator iter = tree[i].begin();
        for(;iter != tree[i].end(); ++iter)
        {
            if(*iter == delNode)
            {
                parentNode = i;
                break;
            }
        }
        if( parentNode != -1) {break;}
    }
    if(tree[parentNode].size() == 1)
    {
        isLeaf[parentNode] = true;
    }
    q.push(delNode);
    // 삭제노드의 자손노드들 삭제
    while(!q.empty())
    {
        int nNumb = q.front();
        isLeaf[nNumb] = false;
        q.pop();
        vector<int>::iterator iter = tree[nNumb].begin();
        for(;iter != tree[nNumb].end(); ++iter)
        {
            q.push(*iter);
        }

    }   
    // count
    int count=0;
    for(int i = 0; i < n; ++i)
    {
        if(isLeaf[i]){ ++count; }
    }
    cout << count;

    return 0;
}