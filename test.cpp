#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    for(int i = 0; i <= 100; ++i)
    {
        cout<<i<<": "<<uint64_t(pow(31,i))<<endl;
        if(pow(31,i-1)>pow(31,i)) break;
    }
}