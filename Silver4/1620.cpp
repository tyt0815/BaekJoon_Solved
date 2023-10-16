#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    uint32_t n, m;
    vector<string> PokeNumb2String;
    map<string, uint32_t> PokeString2Numb;
    string Question;
    cin >> n >> m;

    PokeNumb2String.resize(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> PokeNumb2String[i];
        PokeString2Numb[PokeNumb2String[i]] = i;
    }

    for(int i = 0; i < m; ++i)
    {
        cin >> Question;
        if(isdigit(Question[0]))
        {
            cout << PokeNumb2String[stoi(Question)] << '\n';
        }
        else
        {
            cout << PokeString2Numb[Question] << '\n';
        }
    }

    return 0;
}