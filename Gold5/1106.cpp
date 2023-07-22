// 문제: https://www.acmicpc.net/problem/1106
// 풀이: https://www.notion.so/tyt0815/1106-0554b4ccefe74344900000e53d6979a4?pvs=4

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int c, n;
    unsigned int *cost, *cpc;   // cpc: Costomer per cost
    uint* p, *q;
    int i, j;

    cin >> c >> n;

    cost = new unsigned int[n];
    cpc = new unsigned int[n];
    p = new unsigned int[c+1];
    q = new unsigned int[c+1];
    for(i = 0; i < n; ++i)
    {
        cin >> cost[i] >> cpc[i];
    }
    
    p[0] = q[0] = 0;
    for(i = 1; i < c+1; ++i)
    {
        if(q[i-1] >= i)
        {
            p[i] = p[i-1];
            q[i] = q[i-1];
        }
        else
        {
            uint minCost = 0, maxCpc = 0;
            
            for(j = 0; j < n; ++j)
            {
                if(i >= cpc[j])     // i - cpc[j] >= 0 했다가 uint형이라 큰일날뻔함
                {
                    if((p[i - cpc[j]] + cost[j] < minCost || minCost == 0) || (p[i - cpc[j]] + cost[j] == minCost && maxCpc < q[i - cpc[j]] + cpc[j]))
                    {
                        minCost = p[i - cpc[j]] + cost[j];
                        maxCpc = q[i - cpc[j]] + cpc[j];
                    }
                }
                else
                {
                    if((cost[j] < minCost || minCost == 0) || (cost[j] == minCost && maxCpc < cpc[j]))
                    {
                        minCost = cost[j];
                        maxCpc = cpc[j];
                    }
                }

            }
            p[i] = minCost;
            q[i] = maxCpc;
        }
        // cout << p[i] << ", " << q[i] << endl;
    }

    
    cout << p[c];
    return 0;
}
