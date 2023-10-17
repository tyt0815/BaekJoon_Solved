#include <iostream>

using namespace std;

struct Step
{
    uint32_t Cont;
    uint32_t NotCont;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint16_t n;
    uint16_t* Stairs;
    Step* Score;

    cin >> n;
    Stairs = new uint16_t[n + 1];
    Score = new Step[n + 1];

    for(int i = 1; i < n + 1; ++i)
    {
        cin >> Stairs[i];
    }

    Score[0] = {0, 0};
    Score[1].Cont = 0;
    Score[1].NotCont = Stairs[1];

    for(int i = 2; i < n + 1; ++i)
    {
        Score[i].Cont = Score[i - 1].NotCont + Stairs[i];
        Score[i].NotCont = max(Score[i - 2].Cont, Score[i - 2].NotCont) + Stairs[i];
    }

    cout << max(Score[n].Cont, Score[n].NotCont);

    return 0;
}