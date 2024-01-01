#include <iostream>
#include <vector>

using namespace std;

struct SNode
{
    int Left;
    int Right;
};

void Preorder(int CurrNode, vector<SNode> BiTree);
void Inorder(int CurrNode, vector<SNode> BiTree);
void Postorder(int CurrNode, vector<SNode> BiTree);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<SNode> BiTree;
    cin >> n;
    BiTree.resize(n);

    for(int i = 0 ; i < n; ++i)
    {
        char Parent, Left, Right;
        cin >> Parent >> Left >> Right;
        BiTree[Parent - 'A'].Left = Left - 'A';
        BiTree[Parent - 'A'].Right = Right - 'A';
    }

    Preorder(0, BiTree);
    cout << '\n';
    Inorder(0, BiTree);
    cout << '\n';
    Postorder(0, BiTree);
    cout << '\n';

    return 0;
}

void Preorder(int CurrNode, vector<SNode> BiTree)
{
    if(CurrNode == '.' - 'A')
    {
        return;
    }
    cout << char(CurrNode + 'A');

    Preorder(BiTree[CurrNode].Left, BiTree);
    Preorder(BiTree[CurrNode].Right, BiTree);
}

void Inorder(int CurrNode, vector<SNode> BiTree)
{
    if(CurrNode == '.' - 'A')
    {
        return;
    }

    Inorder(BiTree[CurrNode].Left, BiTree);
    cout << char(CurrNode + 'A');
    Inorder(BiTree[CurrNode].Right, BiTree);
}

void Postorder(int CurrNode, vector<SNode> BiTree)
{
    if(CurrNode == '.' - 'A')
    {
        return;
    }

    Postorder(BiTree[CurrNode].Left, BiTree);
    Postorder(BiTree[CurrNode].Right, BiTree);
    cout << char(CurrNode + 'A');
}
