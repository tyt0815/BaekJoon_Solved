#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Numbers(N , 0);
    for(int i = 0; i < N; ++i)
    {
        cin >> Numbers[i];
    }

    vector<int> LIS;
    LIS.push_back(Numbers[0]);
    int MaxLength = 0;
    for(int i = 1; i < Numbers.size(); ++i)
    {
        int j = lower_bound(LIS.begin(), LIS.end(), Numbers[i]) - LIS.begin();
        if(j < LIS.size())
        {
            LIS[j] = Numbers[i];
        }
        else
        {
            LIS.push_back(Numbers[i]);
        }
        MaxLength = max(MaxLength, j);
    }
    ++MaxLength;

    cout << MaxLength;

    return 0;
}
