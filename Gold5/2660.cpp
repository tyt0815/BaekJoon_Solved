#include <iostream>
#include <vector>
#define INF INT32_MAX / 2

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> Nodes(N + 1, vector<int>(N + 1, INF));
    vector<int> Scores(N + 1, 0);
    while(true)
    {
        int U, V;
        cin >> U >> V;
        if(U == -1 && V == -1) break;
        Nodes[U][V] = Nodes[V][U] = 1;
    }

    for(int k = 1; k <= N; ++k)
    {
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= N; ++j)
            {
                if(Nodes[i][j] > Nodes[i][k] + Nodes[k][j])
                {
                    Nodes[i][j] = Nodes[i][k] + Nodes[k][j];
                }
            }
        }
        Nodes[k][k] = 0;
    }
    int CandidateScore = INF, CandidateNum = 0;
    vector<int> Candidates(N + 1, 0);
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            Scores[i] = max(Scores[i], Nodes[i][j]);
        }
        if(CandidateScore > Scores[i])
        {
            CandidateNum = 1;
            CandidateScore = Scores[i];
            Candidates[CandidateNum - 1] = i;
        }
        else if(CandidateScore == Scores[i]) Candidates[CandidateNum++] = i;
    }
    cout << CandidateScore << ' ' << CandidateNum << '\n';
    for(int i = 0; i < CandidateNum; ++i) cout << Candidates[i] << ' ';

    return 0;
}