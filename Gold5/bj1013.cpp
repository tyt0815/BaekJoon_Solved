// 문제:  https://www.acmicpc.net/problem/1013

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        string str;
        cin >> str;
        if (regex_match(str, regex("(100+1+|01)+")))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}