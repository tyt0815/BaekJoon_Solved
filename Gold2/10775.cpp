#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int64_t> Link;

int64_t GetNextGate(int64_t i);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t G;
    int64_t P;
    cin >> G >> P;
    vector<int64_t> gi(P);
    for(int64_t &Element : gi)
    {
        cin >> Element;
    }
    Link.resize(G + 1);
    for(int64_t i = 0; i < Link.size(); ++i)
    {
        Link[i]  = i;
    }

    int64_t i = 0;
    for (; i < gi.size(); ++i)
    {
        int64_t Gate = GetNextGate(gi[i]);
        if (Gate == 0)
        {
            break;
        }
        Link[Gate] = Link[Gate - 1];
    }

    cout << i;

    return 0;
}

int64_t GetNextGate(int64_t i)
{
    if (i != Link[i])
    {
        Link[i] = GetNextGate(Link[i]);
    }
    return Link[i];
}
