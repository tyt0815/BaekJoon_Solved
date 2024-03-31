#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string In;
    cin >> In;

    stack<char> ParenStack;
    stack<int> ValueStack;
    int Value = 0;
    for(int i = 0; i < In.length(); ++i)
    {
        if(In[i] == '(' || In[i] =='[')
        {
            if(Value > 0) 
            {
                ParenStack.push('+');
                ValueStack.push(Value);
                Value = 0;
            }
            ParenStack.push(In[i]);
        }
        else
        {
            if(ParenStack.empty() || (In[i] == ')' && ParenStack.top() != '(') || (In[i] == ']' && ParenStack.top() != '['))
            {
                cout << 0;
                return 0;
            }
            ParenStack.pop();
            int Temp;
            if(In[i] == ')') Temp = 2;
            else Temp = 3;
            if(Value == 0) Value = Temp;
            else Value *= Temp;

            if(!ParenStack.empty() && ParenStack.top() == '+')
            {
                ParenStack.pop();
                if(!ValueStack.empty())
                {
                    Value += ValueStack.top();
                    ValueStack.pop();
                }
            }
        }
    }

    if(!ParenStack.empty())
    {
        cout << 0;
    }
    else cout << Value;

    return 0;
}
