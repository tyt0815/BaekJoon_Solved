// #include <iostream>
// #include <string.h>

// using namespace std;

// class MyStack
// {
// public:
//     MyStack();
//     ~MyStack();
    

//     void Push(int value);
//     int Pop();
//     bool IsEmpty();
//     int Top();
//     void Resize(int NewMax);

// private:
//     int Size;
//     int Max;
//     int* Stack;

// public:
//     int GetSize();
// };

// int main()
// {
//     int CommandNumb;
//     string Command;
//     int value;
//     MyStack Stack = MyStack();

//     cin >> CommandNumb;

//     for(int i = 0; i < CommandNumb; ++i)
//     {
//         cin >> Command;
//         if (Command.compare("push") == 0)
//         {
//             cin >> value;
//             Stack.Push(value);
//         }
//         else if(Command.compare("pop") == 0)
//         {
//             cout << Stack.Pop() << endl;
//         }
//         else if(Command.compare("size") == 0)
//         {
//             cout << Stack.GetSize() << endl;
//         }
//         else if(Command.compare("empty") == 0)
//         {
//             cout << Stack.IsEmpty() << endl;
//         }
//         else if(Command.compare("top") == 0)
//         {
//             cout << Stack.Top() << endl;
//         }
//         else
//         {
//             cout << "Error: Invalid Command";
//             return 1;
//         }
//     }

//     return 0;
// }

// MyStack::MyStack() :
//     Stack(new int[2]),
//     Max(2),
//     Size(0)
// {
// }

// MyStack::~MyStack()
// {
//     delete[] Stack;
// }

// void MyStack::Push(int value)
// {
//     if(Size == Max)
//     {
//         Resize(Max * 2);
//     }

//     Stack[Size++] = value;
// }

// int MyStack::Pop()
// {
//     return IsEmpty() ? -1 : Stack[--Size];
// }

// bool MyStack::IsEmpty()
// {
//     return Size == 0 ? true : false;
// }

// int MyStack::Top()
// {
//     return IsEmpty() ? -1 : Stack[Size-1];
// }

// int MyStack::GetSize()
// {
//     return Size;
// }

// void MyStack::Resize(int NewMax)
// {
//     int* Temp = Stack;
//     Stack = new int[NewMax];
//     for(int i = 0; i < Size; ++i)
//         {
//             Stack[i] = Temp[i];
//         }

//     delete[] Temp;
//     Max = NewMax;
// }


#include <iostream>
#include <vector>

using namespace std;

class IntStack
{
public:
    void Push(int X);

    int Pop();

    int Size();

    bool Empty();

    int Top();

private:
    vector<int> Container;
    size_t StackSize = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    IntStack Stack;
    while(N--)
    {
        string Cmd;
        cin >> Cmd;
        if(Cmd == "push")
        {
            int x;
            cin >> x;
            Stack.Push(x);
        }
        else if(Cmd == "pop")
        {
            cout << Stack.Pop() << "\n";
        }
        else if(Cmd == "size")
        {
            cout << Stack.Size() << "\n";
        }
        else if(Cmd == "empty")
        {
            cout << Stack.Empty() << "\n";
        }
        else if(Cmd == "top")
        {
            cout << Stack.Top() << "\n";
        }
        else
        {
            throw;
        }
    }
}

void IntStack::Push(int X)
{
    if(StackSize >= Container.size())
    {
        Container.push_back(X);
    }
    else
    {
        Container[StackSize] = X;
    }
    ++StackSize;
}

int IntStack::Pop()
{
    return Empty() ? -1 : Container[StackSize-- - 1];
}

int IntStack::Size()
{
    return StackSize;
}

bool IntStack::Empty()
{
    return StackSize <= 0;
}

int IntStack::Top()
{
    return Empty() ? -1 : Container[StackSize - 1];
}
