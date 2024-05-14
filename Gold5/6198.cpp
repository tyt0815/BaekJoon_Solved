#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int64_t> s;
    int64_t Sum = 0;
    for(int i = 0; i < N; ++i)
    {
        int64_t Height;
        cin >> Height;
        while(!s.empty() && s.top() <= Height) s.pop();
        Sum += s.size();
        s.push(Height);
    }
    cout << Sum;

    return 0;
}