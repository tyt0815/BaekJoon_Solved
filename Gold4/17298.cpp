#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Sequence(N);
    for(int& Number : Sequence)
    {
        cin >> Number;
    }

    vector<int> RightBigNumberIndices(N, -1);

    for(int i = RightBigNumberIndices.size() - 2; i >= 0; --i)
    {
        if(Sequence[i] < Sequence[i + 1])
        {
            RightBigNumberIndices[i] = i + 1;
        }
        else
        {
            for(int j = RightBigNumberIndices[i + 1]; j >= 0;)
            {
                if(Sequence[j] > Sequence[i])
                {
                    RightBigNumberIndices[i] = j;
                    break;
                }
                j = RightBigNumberIndices[j];
            }
        }
    }

    for(int Index : RightBigNumberIndices)
    {
        cout << (Index >= 0 ? Sequence[Index] : -1) << ' ';
    }

    return 0;
}