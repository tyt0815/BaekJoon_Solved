#include <iostream>
#include <algorithm>

using namespace std;

struct XPos
{
    long long Data;
    uint32_t OriginIndex;
    uint32_t Pressed;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;
    XPos *x;

    cin >> n;
    x = new XPos[n];

    for(uint32_t i = 0; i < n; ++i)
    {
        cin >>x[i].Data;
        x[i].OriginIndex = i;
        x[i].Pressed = 0;
    }
    
    sort(x, x+n, [](XPos a, XPos b)
    {
        return a.Data < b.Data;
    }
    );

    long long Temp =x[0].Data;
    x[0].Pressed = 0;
    for(uint32_t i = 1; i < n; ++i)
    {
        if(Temp == x[i].Data)
        {
            x[i].Pressed = x[i-1].Pressed;
        }
        else
        {
            Temp = x[i].Data;
            x[i].Pressed = x[i-1].Pressed + 1;
        }
    }

    sort(x, x+n, [](XPos a, XPos b)
    {
        return a.OriginIndex < b.OriginIndex;
    }
    );

    for(uint32_t i = 0; i < n; ++i)
    {
        cout << x[i].Pressed << ' ';
    }

    delete[] x;
    return 0;
}