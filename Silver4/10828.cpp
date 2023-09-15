#include <iostream>
#include <string.h>

using namespace std;

class MyStack
{
public:
    MyStack();
    ~MyStack();
    

    void Push(int value);
    int Pop();
    bool IsEmpty();
    int Top();
    void Resize(int NewMax);

private:
    int Size;
    int Max;
    int* Stack;

public:
    int GetSize();
};

int main()
{
    int CommandNumb;
    string Command;
    int value;
    MyStack Stack = MyStack();

    cin >> CommandNumb;

    for(int i = 0; i < CommandNumb; ++i)
    {
        cin >> Command;
        if (Command.compare("push") == 0)
        {
            cin >> value;
            Stack.Push(value);
        }
        else if(Command.compare("pop") == 0)
        {
            cout << Stack.Pop() << endl;
        }
        else if(Command.compare("size") == 0)
        {
            cout << Stack.GetSize() << endl;
        }
        else if(Command.compare("empty") == 0)
        {
            cout << Stack.IsEmpty() << endl;
        }
        else if(Command.compare("top") == 0)
        {
            cout << Stack.Top() << endl;
        }
        else
        {
            cout << "Error: Invalid Command";
            return 1;
        }
    }

    return 0;
}

MyStack::MyStack() :
    Stack(new int[2]),
    Max(2),
    Size(0)
{
}

MyStack::~MyStack()
{
    delete[] Stack;
}

void MyStack::Push(int value)
{
    if(Size == Max)
    {
        Resize(Max * 2);
    }

    Stack[Size++] = value;
}

int MyStack::Pop()
{
    return IsEmpty() ? -1 : Stack[--Size];
}

bool MyStack::IsEmpty()
{
    return Size == 0 ? true : false;
}

int MyStack::Top()
{
    return IsEmpty() ? -1 : Stack[Size-1];
}

int MyStack::GetSize()
{
    return Size;
}

void MyStack::Resize(int NewMax)
{
    int* Temp = Stack;
    Stack = new int[NewMax];
    for(int i = 0; i < Size; ++i)
        {
            Stack[i] = Temp[i];
        }

    delete[] Temp;
    Max = NewMax;
}