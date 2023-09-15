#include <iostream>

using std::cout;
using std::cin;
using std::max;

int main()
{
    int N;
    int* Amount;
    cin >> N;

    Amount = new int[max(N+1, 6)];

    Amount[0] = Amount[1] = Amount[2] = Amount[4] = -1;
    Amount[3] = Amount[5] = 1;

    for(int i = 6; i < N+1; ++i)
    {
        if(Amount[i-3] == -1 && Amount[i-5] == -1)
        {
            Amount[i] = -1;
        }
        else if(Amount[i-3] == -1)
        {
            Amount[i] = Amount[i-5] + 1;
        }
        else if(Amount[i-5] == -1)
        {
            Amount[i] = Amount[i-3] + 1;
        }
        else
        {
            Amount[i] = Amount[i-3] < Amount[i-5] ? Amount[i-3] + 1 : Amount[i-5] + 1;
        }
    }

    cout << Amount[N];

    return 0;
}