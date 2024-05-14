#include <iostream>

using namespace std;

int IsPalindrome(string s, int Left, int Right);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        string s;
        cin >> s;
        cout << IsPalindrome(s, 0, s.length() - 1) << '\n';
    }

    return 0;
}

int IsPalindrome(string s, int Left, int Right)
{
    int i = Left, j = Right;
    while(i < j)
    {
        if(s[i] == s[j])
        {
            ++i;
            --j;
        }
        else if(Left == 0 && Right + 1 == s.length())
        {
            if(s[i + 1] == s[j] && IsPalindrome(s, i + 1, j) == 0) return 1;
            if(s[i] == s[j - 1] && IsPalindrome(s, i, j - 1) == 0) return 1;
            return 2;
        }
        else return 2;
    }
    return 0;
}
