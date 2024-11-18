#include <iostream>
#include <vector>

constexpr int MaxX = 1000000;

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> Cards(N);
    vector<int> Scores(MaxX + 1, 0);
    vector<int> bSelected(MaxX + 1, false);
    for(int& Card : Cards)
    {
        cin >> Card;
        bSelected[Card] = true;
    }

    for(int i = 0; i < Cards.size(); ++i)
    {
        for(int j = Cards[i] * 2; j <= MaxX; j += Cards[i])
        {
            if(bSelected[j])
            {
                ++Scores[Cards[i]];
                --Scores[j];
            }
        }
    }

    for(int i = 0; i < Cards.size(); ++i) cout << Scores[Cards[i]] << ' ';

    return 0;
}