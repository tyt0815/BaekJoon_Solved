#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class CEditer
{
public:
    CEditer(string s);

    void MoveCursorLeft();
    void MoveCursorRight();
    void DeleteAtCursor();
    void InsertAtCursor(char c);
    void PrintString();
private:
    struct SNode
    {
        char c;
        shared_ptr<SNode> Prev;
        shared_ptr<SNode> Next;
    };
    shared_ptr<SNode> Root;
    shared_ptr<SNode> Cursor;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;
    CEditer Editer(s);

    for(int i = 0; i < n; ++i)
    {
        char Cmd;
        cin >> Cmd;
        if(Cmd == 'L')
        {
            Editer.MoveCursorLeft();
        }
        else if(Cmd == 'D')
        {
            Editer.MoveCursorRight();
        }
        else if(Cmd == 'B')
        {
            Editer.DeleteAtCursor();
        }
        else if(Cmd == 'P')
        {
            cin >> Cmd;
            Editer.InsertAtCursor(Cmd);
        }
    }

    Editer.PrintString();

    return 0;
}

CEditer::CEditer(string s): Root(nullptr), Cursor(nullptr)
{
    SNode Temp = {'\0', nullptr, nullptr};
    Root = make_shared<SNode>(Temp);
    Cursor = Root;
    for(int i = 0; i < s.length(); ++i)
    {
        InsertAtCursor(s[i]);
    }
}

void CEditer::MoveCursorLeft()
{
    if(Cursor->Prev)
        Cursor = Cursor->Prev;
}

void CEditer::MoveCursorRight()
{
    if(Cursor->Next)
        Cursor = Cursor->Next;
}

void CEditer::DeleteAtCursor()
{
    if(Cursor->Prev == nullptr) return;
    if(Cursor->Prev == Root) Root = Cursor;
    shared_ptr<SNode> Prev = Cursor->Prev->Prev;
    if(Prev) Prev->Next = Cursor;
    Cursor->Prev = Prev;
}

void CEditer::InsertAtCursor(char c)
{
    SNode Temp = {c, Cursor->Prev, Cursor};
    shared_ptr<SNode> TempNode = make_shared<SNode>(Temp);
    if(Cursor->Prev)
    {
        Cursor->Prev->Next = TempNode;
    }
    else
    {
        Root = TempNode;
    }
    Cursor->Prev = TempNode;
}

void CEditer::PrintString()
{
    shared_ptr<SNode> Iter = Root;
    while(Iter->c != '\0')
    {
        cout << Iter->c;
        Iter = Iter->Next;
    }
}
