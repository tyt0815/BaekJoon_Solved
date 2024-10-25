// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string Str;
//     string Bomb;
//     cin >> Str >> Bomb;
//     string Result;
//     Result.resize(Str.length() + 1);

//     for(int i = 0, j = i; i < Str.length(); ++i, ++j)
//     {
//         Result[j] = Str[i];

//         if(j >= Bomb.length() - 1)
//         {
//             bool IsBoom = true;
//             for(int k = 0; k < Bomb.length(); ++k)
//             {
//                 if(Bomb[k] != Result[j - Bomb.length() + k + 1])
//                 {
//                     IsBoom = false;
//                     break;
//                 }
//             }
//             if(IsBoom)
//             {
//                 j = j - Bomb.length();
//             }
//         }
//         Result[j + 1] = '\0';
//     }

//     if(Result[0] == '\0')
//     {
//         cout << "FRULA";
//     }
//     else
//     {
//         for(int i = 0; Result[i] != '\0'; ++i)
//         {
//             cout << Result[i];
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, Bomb;
    cin >> A >> Bomb;
    stack<char> StringStack;
    stack<int> OffsetStack;
    int BombIndex = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        StringStack.push(A[i]);
        if(A[i] == Bomb[BombIndex]) ++BombIndex;
        else
        {
            OffsetStack.push(BombIndex);
            if(A[i] == Bomb[0])
            {
                BombIndex = 1;
            }
            else
            {
                OffsetStack.push(0);
                BombIndex = 0;
            }
        }
        if(BombIndex == Bomb.length())
        {
            for(int j = 0; j < Bomb.length(); ++j) StringStack.pop();
            if(OffsetStack.empty()) BombIndex = 0;
            else
            {
                BombIndex = OffsetStack.top();
                OffsetStack.pop();
            }
        }
    }
    if(StringStack.empty()) cout << "FRULA";
    else
    {
        string B(StringStack.size(), ' ');
        for(int i = 0; i < B.length(); ++i)
        {
            *(B.end() - 1 - i) = StringStack.top();
            StringStack.pop();
        }
        cout << B;
    }
    return 0;
}