#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> Receivers(n, 0);
    vector<int> Result(n, -1);
    for(int i = 0; i < n; ++i)
    {
        cin >> Receivers[i];
    }

    stack<int> s;
    s.push(n - 1);
    for(int i = n - 2; i >= 0; --i)
    {
        while(!s.empty())
        {
            if(Receivers[i] < Receivers[s.top()]) break;
            Result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; ++i) cout << Result[i] + 1 << ' ';

    return 0;
}