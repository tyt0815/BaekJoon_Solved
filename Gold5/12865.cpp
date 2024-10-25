// 

#include <iostream>
#include <vector>

constexpr int MaxWeight = 100000;

using namespace std;

struct FItemInfo
{
    int Weight;
    int Value;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<FItemInfo> Items(N); 
    for(int i = 0; i < Items.size(); ++i) cin >> Items[i].Weight >> Items[i].Value;

    vector<int> p(K+1, 0);
    for(int i = 0; i < Items.size(); ++i)
    {
        const FItemInfo& Item = Items[i];
        for(int CurrentWeight = K; CurrentWeight >= Item.Weight; --CurrentWeight)
        {
            int PrevWeight = CurrentWeight - Item.Weight;
            if(p[PrevWeight] + Item.Value > p[CurrentWeight])
            {
                p[CurrentWeight] = p[PrevWeight] + Item.Value;
            }
        }
    }

    int MaxValue = 0;
    for(int i = 0; i < p.size(); ++i) MaxValue = max(MaxValue, p[i]);
    cout << MaxValue;

    return 0;
}