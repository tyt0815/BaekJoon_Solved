#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> Numbers;
    cin >> n;
    Numbers.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> Numbers[i];
    }

    vector<int> Up, Down;
    Up.resize(n); Down.resize(n);
    Up[0] = 1;
    Down[n - 1] = 1;
    for(int i = 1; i < n; ++i)
    {
        Up[i] = Down[n - 1 - i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(Numbers[i] > Numbers[j])
            {
                Up[i] = max(Up[i], Up[j] + 1);
            }
            else if(Numbers[i] == Numbers[j])
            {
                Up[i] = max(Up[i], Up[j]);
            }
            if(Numbers[n - 1 - i] > Numbers[n - 1 - j])
            {
                Down[n - 1 - i] = max(Down[n - 1 - i], Down[n - 1 - j] + 1);
            }
            else if(Numbers[n - 1 - i] == Numbers[n - 1 - j])
            {
                Down[n - 1 - i] = max(Down[n - 1 - i], Down[n - 1 - j]);
            }
        }
    }

    int MaxLen = 0;
    for(int i = 0; i < n; ++i)
    {
        MaxLen = max(MaxLen, Up[i] + Down[i]);
    }
    --MaxLen;
    cout << MaxLen;

    return 0;
}
