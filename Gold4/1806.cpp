#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    int Sum = 0, MinLen = N, i = 0;
    queue<int> Q;
    for(i = 0; i < N; ++i)
    {
        int Value;
        cin >> Value;
        Sum += Value;
        Q.push(Value);
        if(Sum >= S) break;
    }
    while(Sum - Q.front() >= S)
    {
        Sum -= Q.front();
        Q.pop();
    }
    MinLen = Q.size();

    for(++i; i < N; ++i)
    {
        int Value;
        cin >> Value;
        Sum += Value;
        Q.push(Value);
        while(Sum - Q.front() >= S)
        {
            Sum -= Q.front();
            Q.pop();
        }
        MinLen = min(MinLen, static_cast<int>(Q.size()));
    }

    if(Sum >= S) cout << MinLen;
    else cout << 0;

    return 0;
}