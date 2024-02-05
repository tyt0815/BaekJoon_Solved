#include <iostream>
#include <stack>

using namespace std;

inline int GetOperatorPriority(char o);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> s;
    while(true)
    {
        char Input;
        cin >> Input;
        if(cin.eof())
        {
            break;
        }
        if(Input == '+' || Input == '-' || Input == '*' || Input == '/')
        {
            int InputPriority = GetOperatorPriority(Input);
            while(!s.empty() && InputPriority >= GetOperatorPriority(s.top()))
            {
                if(s.top() == '(')
                    break;
                cout << s.top();
                s.pop();
            }
            s.push(Input);
        }
        else if(Input == '(')
        {
            s.push(Input);
        }
        else if(Input == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        // Operand
        else
        {
            cout << Input;
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}

inline int GetOperatorPriority(char o)
{
    if(o == '*' || o == '/') return 0;
    if(o == '+' || o == '-') return 1;
    return 3;
}
