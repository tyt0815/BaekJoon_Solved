#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> Infos(N);    // first: Weight, second: Value
    for(int i = 0; i < Infos.size(); ++i)
    {
        cin >> Infos[i].first >> Infos[i].second;
    }

    vector<int> Bags(K);
    for(int i = 0; i < Bags.size(); ++i)
    {
        cin >> Bags[i];
    }

    sort(Infos.begin(), Infos.end(), [](pair<int, int> A, pair<int, int> B){ return A.first < B.first; });
    sort(Bags.begin(), Bags.end());

    priority_queue<int> PQ;
    int64_t Sum = 0;
    for(int i = 0, j = 0; i < Bags.size(); ++i)
    {
        while(j < Infos.size() && Bags[i] >= Infos[j].first)
        {
            PQ.push(Infos[j++].second);
        }

        if(!PQ.empty())
        {
            Sum += PQ.top();
            PQ.pop();
        }
    }
    
    cout << Sum;

    return 0;
}