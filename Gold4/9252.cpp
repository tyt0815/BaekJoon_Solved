#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    vector<vector<int>> DP(A.size(), vector<int>(B.size()));
    DP[0][0] = A[0] == B[0] ? 1 : 0;
    for(int i = 1; i < DP.size(); ++i) DP[i][0] = A[i] == B[0] ? 1 : DP[i - 1][0];
    for(int j = 1; j < DP[0].size(); ++j) DP[0][j] = A[0] == B[j] ? 1 : DP[0][j - 1];

    for(int i = 1; i < DP.size(); ++i)
    {
        for(int j = 1; j < DP[i].size(); ++j)
        {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            if(A[i] == B[j]) DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
        }
    }

    stack<char> AnswerStack;

    for(int i = A.size() - 1, j = B.size() - 1; i >= 0 && j >= 0;)
    {
        if(A[i] == B[j])
        {
            AnswerStack.push(A[i]);
            --i;
            --j;
        }
        else if(i > 0 && j > 0)
        {
            if(DP[i - 1][j] >= DP[i][j - 1]) --i;
            else --j;
        }
        else if(i > 0) --i;
        else if(j > 0) --j;
        else break;
    }

    cout << AnswerStack.size() << endl;
    while(!AnswerStack.empty())
    {
        cout << AnswerStack.top();
        AnswerStack.pop();
    }

    return 0;
}