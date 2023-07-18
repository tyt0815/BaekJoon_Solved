#include <iostream>

using namespace std;

int main()
{
    int n;
    int* input;
    int cnt = 0, maxN = 0;
    bool *prime;

    cin >> n;
    input = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
        maxN = max(maxN, input[i]);
    }
    
    prime = new bool[maxN+1];
    prime[0] = prime[1] = false;
    for(int i = 2; i < maxN+1; ++i){ prime[i] = true; }
    for(int i = 2; i*i <= maxN;++i)
    {
        if(prime[i] == true)
        {
            for(int j = i; i*j <=maxN; ++j)
            {
                prime[i*j] = false;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(prime[input[i]]){ ++cnt; }
    }
    cout << cnt;
    
    return 0;
}