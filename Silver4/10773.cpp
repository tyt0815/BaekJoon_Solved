#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int K;
    int Input;
    int Sum = 0;
    stack<int> S;

    cin >> K;

    for(int i = 0; i < K; ++i)
    {
        cin >> Input;
        if(Input == 0 && !S.empty())
        {
            S.pop();
            continue;
        }
        S.push(Input);
    }

    while(!S.empty())
    {
        Sum += S.top();
        S.pop();
    }
    cout << Sum;

    return 0;
}