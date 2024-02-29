#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    if(S == G)
    {
        cout << '0';
        return 0;
    }

    queue<pair<int, int>> q;
    vector<bool> IsVisited(F + 1, false);
    IsVisited[0] = IsVisited[S] = true;
    q.push({S, 0});
    while(true)
    {
        if(q.empty())
        {
            cout << "use the stairs";
            break;
        }
        int CurrFloor = q.front().first, Count = q.front().second;
        q.pop();
        
        if(CurrFloor + U == G || CurrFloor - D == G)
        {
            cout << Count + 1;
            break;
        }

        if(CurrFloor + U <= F && !IsVisited[CurrFloor + U])
        {
            IsVisited[CurrFloor + U] = true;
            q.push({CurrFloor + U, Count + 1});
        }
        if(CurrFloor - D > 0 && !IsVisited[CurrFloor - D])
        {
            IsVisited[CurrFloor - D] = true;
            q.push({CurrFloor - D, Count + 1});
        }
    }

    return 0;
}

/*
2n - 1 - (2m - 1) = k
2(n - m) = k
k: 짝수

2n - 2m = k
2(n - m) = k
k: 짝수

2n - (2m - 1) = k
2(n - m) - 1 = k
k: 홀수
*/