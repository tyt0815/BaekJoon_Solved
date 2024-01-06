#include <iostream>
#include <memory>

using namespace std;

class BST
{
public:
    struct SNode
    {
        uint32_t Data;
        shared_ptr<SNode> Left;
        shared_ptr<SNode> Right;
    };

    void AddNode(const uint32_t Key);
    void PostOrder(const shared_ptr<SNode>& Node);

private:
    shared_ptr<SNode> Root = nullptr;

public:
    const shared_ptr<SNode>& GetRoot() { return Root; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    BST BinarySearchTree;
    
    while(true)
    {
        uint32_t Key;
        cin >> Key;
        if(cin.eof()) { break; }
        BinarySearchTree.AddNode(Key);
    }

    BinarySearchTree.PostOrder(BinarySearchTree.GetRoot());

    return 0;
}

void BST::AddNode(const uint32_t Key)
{
    SNode* TempNode = new SNode;
    TempNode->Data = Key;
    TempNode->Left = nullptr;
    TempNode->Right = nullptr;
    if(Root == nullptr)
    {
        Root = shared_ptr<SNode>(TempNode);
        return;
    }

    shared_ptr<SNode> Parent = Root;
    while(Parent != nullptr)
    {
        if(Parent->Data > TempNode->Data)
        {
            if(Parent->Left == nullptr)
            {
                Parent->Left = shared_ptr<SNode>(TempNode);
                return;
            }
            else
            {
                Parent = Parent->Left;
            }
        }
        else
        {
            if(Parent->Right == nullptr)
            {
                Parent->Right = shared_ptr<SNode>(TempNode);
                return;
            }
            else
            {
                Parent = Parent->Right;
            }
        }
    }
}

void BST::PostOrder(const shared_ptr<SNode> &Node)
{
    if(Node == nullptr)
    {
        return;
    }

    PostOrder(Node->Left);
    PostOrder(Node->Right);
    cout << Node->Data << '\n';
}
