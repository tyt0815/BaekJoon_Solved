#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> Numbers(N + 1);
    vector<vector<bool>> bPalindrome(N + 1, vector<bool>(N + 1, false));
    for(int i = 1; i < Numbers.size(); ++i) cin >> Numbers[i];

    for(int i = bPalindrome.size() - 1; i > 0; --i)
    {
        bPalindrome[i][i] = true;
        for(int j = i + 1;j < bPalindrome[i].size(); ++j)
        {
            if(Numbers[i] == Numbers[j] && (i + 1 == j || bPalindrome[i + 1][j - 1]))
            {
                bPalindrome[i][j] = true;
            }
        }
    }

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(bPalindrome[a][b]) cout << 1;
        else cout << 0;
        cout << '\n';
    }

    return 0;
}