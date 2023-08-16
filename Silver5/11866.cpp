#include <iostream>

using namespace std;


typedef class listNode *listPointer;
class listNode
{
public:
    listNode(int i);
    listNode(int i, listPointer first, listPointer last);
    ~listNode();

private:
    int numb;
    listPointer pre;
    listPointer next;
public:
    listPointer GetPre();
    listPointer GetNext();
    int GetNumb();
};

int main()
{
    int n, k;
    listPointer start = new listNode(1);
    listPointer pre = start;
    cin >> n >> k;

    for(int i = 1; i < n; ++i)
    {
        pre = new listNode(i + 1, start, pre);
    }

    cout << "<";
    listPointer current = start;
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = 0; j < k-1; ++j)
        {
            current = current->GetNext();
        }
        cout << current->GetNumb() << ", ";
        current = current->GetNext();
        delete current->GetPre();
    }
    cout << current->GetNumb() << ">";
    
    return 0;
}

listNode::listNode(int i)
{
    numb = i;
    pre = this;
    next = this;
}

listNode::listNode(int i, listPointer first, listPointer last)
{
    numb = i;
    pre = last;
    last->next = this;
    first->pre = this;
    next = first;
}

listNode::~listNode()
{
    pre->next = this->next;
    next->pre = this->pre;
}

listPointer listNode::GetPre()
{
    return pre;
}

listPointer listNode::GetNext()
{
    return next;
}

int listNode::GetNumb()
{
    return numb;
}