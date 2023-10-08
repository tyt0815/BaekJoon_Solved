#include <iostream>

using namespace std;

int main()
{
    uint64_t k, n;
    cin >> k >> n;

    uint64_t *LANs = new uint64_t[k];
    uint64_t Devide = 0;
    for(int i = 0; i < k; ++i) 
    { 
        cin >> LANs[i];
        Devide += (LANs[i] / n) + 1;
    }
    
    uint64_t TotalLAN, Quot, NextDevide;
    while(true)
    {
        TotalLAN = 0;
        NextDevide = 0;
        for(int i = 0; i < k; ++i)
        {
            Quot = LANs[i] / Devide;
            TotalLAN += Quot;
            if(LANs[i] / (Quot + 1) > NextDevide)
            {
                NextDevide = LANs[i] / (Quot + 1);
            }
        }
        if(TotalLAN >= n)
        {
            break;
        }
        
        Devide = NextDevide;
    }

    cout << Devide;

    delete[] LANs;
    return 0;
}