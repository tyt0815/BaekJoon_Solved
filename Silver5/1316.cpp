#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int Result = 0;
    while (N--)
    {
        string s;
        cin >> s;
        vector<bool> bVisited(100, false);
        bVisited[s[0]] = true;
        for(int i = 1 ; i < s.length(); ++i)
        {
            if(bVisited[s[i]] && s[i - 1] != s[i])
            {
                goto ENDWHILE;
            }
            bVisited[s[i]] = true;
        }

        ++Result;

        ENDWHILE:;
    }

    cout << Result;    

    return 0;
}