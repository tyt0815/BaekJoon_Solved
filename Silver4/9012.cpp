#include <iostream>
#include <stack>

using namespace std;

bool CheckVPS();

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        if(CheckVPS()) { cout << "YES" << '\n'; }
        else { cout << "NO" << '\n'; }
    }

    return 0;
}

bool CheckVPS()
{
    string ps;
    cin >> ps;
    stack<char> s;
    for(int j = 0; j < ps.length(); ++j)
    {
        if(ps[j] == '(')
        {
            s.push('(');
        }
        else
        {
            if(s.size() == 0) { return false; }
            s.pop();
        }
    }
    if(s.size() != 0) { return false; }
    return true;
}