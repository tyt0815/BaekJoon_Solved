#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int TypeCount = 0, Answer = 0;
    vector<int> FruitCount(10, 0);
    queue<int> Tanghuru;
    for(int i = 0 ; i < N; ++i)
    {
        int Fruit;
        cin >> Fruit;
        if(FruitCount[Fruit]++ == 0)
        {
            ++TypeCount;
        }
        Tanghuru.push(Fruit);

        if(TypeCount == 3)
        {
            while(true)
            {
                int Temp = Tanghuru.front();
                Tanghuru.pop();
                if(--FruitCount[Temp] == 0)
                {
                    --TypeCount;
                    break;
                }
            }
        }
        Answer = max(Answer, static_cast<int>(Tanghuru.size()));
    }

    cout << Answer;

    return 0;
}