#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    vector<int> Budget;
    int MaxBudget = 0;
    cin >> n;
    Budget.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> Budget[i];
        MaxBudget = max(MaxBudget, Budget[i]);
    }
    cin >> m;

    int MaximumPrice = m / n;
    while(true)
    {
        int Sum = 0;
        int OverCount = 0;
        for(int i = 0; i < n; ++i) 
        {
            if(MaximumPrice < Budget[i])
            {
                Sum += MaximumPrice;
                ++OverCount;
            }
            else
            {
                Sum += Budget[i];
            }
        }
        if(OverCount == 0)
        {
            MaximumPrice = MaxBudget;
            break;
        }
        if((m - Sum) / OverCount > 0)
        {
            MaximumPrice += (m - Sum) / OverCount;
        }
        else if(Sum > m)
        {
            MaximumPrice /= 2;
        }
        else break;
    }

    cout << MaximumPrice;

    return 0;
}