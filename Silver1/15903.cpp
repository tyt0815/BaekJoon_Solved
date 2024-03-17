#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> Cards;
    for(int i = 0; i < n; ++i)
    {
        uint64_t Card;
        cin >> Card;
        Cards.push(Card);
    }

    for(int i = 0; i < m; ++i)
    {
        uint64_t x = Cards.top();
        Cards.pop();
        uint64_t y = Cards.top();
        Cards.pop();
        Cards.push(x + y);
        Cards.push(x + y);
    }

    uint64_t SumOfCards = 0;
    while(!Cards.empty())
    {
        SumOfCards += Cards.top();
        Cards.pop();
    }

    cout << SumOfCards;

    return 0;
}