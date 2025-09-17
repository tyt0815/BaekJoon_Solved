#include <iostream>
#include <vector>

using namespace std;

void NAndM(vector<int> Sequence, vector<bool>& bVisited, int Depth, const int& N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;

    vector<int> Sequence(M, 0);
    vector<bool> bVisited(N + 1, false);
    NAndM(Sequence, bVisited, M, N);

    return 0;
}

void NAndM(vector<int> Sequence, vector<bool>& bVisited, int Depth, const int& N)
{
    if(Depth > 0)
    {
        for(int i = 1; i <= N; ++i)
        {
            if(!bVisited[i])
            {
                bVisited[i] = true;
                Sequence[Sequence.size() - Depth] = i;
                NAndM(Sequence, bVisited, Depth - 1, N);
                bVisited[i] = false;
            }
        }
    }
    else
    {
        for(const int& Number : Sequence)
        {
            cout << Number << ' ';
        }
        cout << '\n';

        return ;
    }
}
