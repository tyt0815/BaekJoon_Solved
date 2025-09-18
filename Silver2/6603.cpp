#include <iostream>
#include <vector>

using namespace std;

int CandidateSet[50];
int k;

// 
void SelectNumberRecursive(vector<int>& Sequence, const int& Start, const int& Depth)
{
    if(Depth == 0)
    {
        for(const int& Number : Sequence)
        {
            cout << Number << ' ';
        }
        cout << '\n';
        return;
    }
    else
    {
        for(int i = Start; k >= i + Depth; ++i)
        {
            Sequence[Sequence.size() - Depth] = CandidateSet[i];
            SelectNumberRecursive(Sequence, i + 1, Depth - 1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        cin >> k;
        if(k == 0)
        {
            break;
        }

        for(int i = 0; i < k; ++i)
        {
            cin >> CandidateSet[i];
        }

        vector<int> Sequence(6);
        SelectNumberRecursive(Sequence, 0, 6);
        cout << '\n';
    }

    return 0;
}