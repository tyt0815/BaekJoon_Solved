#include <iostream>
#include <string>
#include <stack>

#define MAX_STR_LEN 101

using namespace std;

bool CheckBalance(string InputStr);

int main()
{
    string Str;
    while(true)
    {
        getline(cin, Str);
    
        if(!Str.compare("."))
        {
            break;
        }
        cout << (CheckBalance(Str) ? "yes" : "no") << "\n";
    }

    return 0;
}

bool CheckBalance(string InputStr)
{
    int Len = InputStr.length();
    stack<char> s;
    for(int i = 0; i < Len; ++i)
    {
        if(InputStr[i] == '(' || InputStr[i] == '[')
        {
            s.push(InputStr[i]);
        }
        else if(InputStr[i] == ')')
        {
            if(!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if(InputStr[i] == ']')
        {
            if(!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty() ? true : false;
}