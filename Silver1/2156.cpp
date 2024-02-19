#include <iostream>
#include <vector>

using namespace std;

struct SDP
{
    int Value;
    bool Curr;
    bool Pre;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> Drinks;
    vector<SDP> p;
    cin >> n;
    Drinks.resize(n + 1);
    p.resize(n + 1);
    for(int i = 1; i <= n; ++i) cin >> Drinks[i];

    p[0] = {0, false, false};
    p[1] = {Drinks[1], true, false};
    for(int i = 2; i <= n; ++i)
    {
        if(p[i - 1].Curr && p[i - 1].Pre)
        {
            if(p[i - 1].Value > p[i - 2].Value + Drinks[i])
            {
                p[i] = p[i - 1];
                p[i].Pre = p[i].Curr;
                p[i].Curr = false;
            }
            else
            {
                p[i].Value = p[i - 2].Value + Drinks[i];
                p[i].Curr = true;
                p[i].Pre = false;
            }
            if(p[i].Value < p[i - 3].Value + Drinks[i - 1] + Drinks[i])
            {
                p[i].Value = p[i - 3].Value + Drinks[i - 1] + Drinks[i];
                p[i].Curr = p[i].Pre = true;
            }
        }
        else
        {
            p[i].Value = p[i - 1].Value + Drinks[i];
            p[i].Pre = p[i - 1].Curr;
            p[i].Curr = true;
        }
    }

    cout << p[n].Value;

    return 0;
}