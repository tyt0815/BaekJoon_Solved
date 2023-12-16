#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int Cnt = 0;
    int Ladder[100];
    bool t[100];
    cin >> n >> m;
    for(int i = 0; i < 100; ++i)
    {
        Ladder[i] = 0;
        t[i] = false;
    }
    for(int i = 0; i < n + m; ++i)
    {
        int j;
        cin >> j;
        cin >> Ladder[j];
    }

    queue<int> q;
    q.push(1);

    while(true)
    {
        ++Cnt;
        queue<int> NextQ;
        while(!q.empty())
        {
            int Pos = q.front();
            q.pop();
            for(int i = 1; i < 7; ++i)
            {
                if (Pos + i == 100)
                {
                    goto WhileEnd;
                }
                else if(Pos + i < 100)
                {
                    if(Ladder[Pos + i] == 0 && !t[Pos + i])
                    {
                        NextQ.push(Pos + i);
                        t[Pos + i] = true;
                    }
                    else if(Ladder[Pos + i] != 0 && !t[Ladder[Pos + i]])
                    {
                        NextQ.push(Ladder[Pos + i]);
                        t[Ladder[Pos + i]] = true;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        q = NextQ;
    }
    WhileEnd:;
    cout << Cnt;

    return 0;
}