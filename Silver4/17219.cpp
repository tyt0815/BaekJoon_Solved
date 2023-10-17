#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint64_t n, m;
    map<string, string> Memo;
    string DomainName;

    cin >> n >> m;

    for(uint64_t i = 0; i < n; ++i)
    {
        cin >> DomainName;
        cin >> Memo[DomainName];
    }

    for(uint64_t i = 0; i < m; ++i)
    {
        cin >> DomainName;
        cout << Memo[DomainName] << '\n';
    }

    return 0;
}