#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SelectNumber(const int i, vector<int> &NumberSet, vector<bool> &bVisited, vector<bool> &bLinked, const vector<int> &Numbers);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Numbers(N + 1);
    for(int i = 1; i <= N; ++i) cin >> Numbers[i];
    
    vector<bool> bVisited(N + 1, false);
    vector<int> NumberSet;
    bVisited[0] = true;
    for(int i = 1; i <= N; ++i)
    {
        if(!bVisited[i])
        {
            bVisited[i] = true;
            vector<bool> bLinked(N + 1, false);
            bLinked[i] = true;
            SelectNumber(Numbers[i], NumberSet, bVisited, bLinked, Numbers);
        }
    }
    sort(NumberSet.begin(), NumberSet.end());
    cout << NumberSet.size() << '\n';
    for(auto &Number : NumberSet) cout << Number << '\n';

    return 0;
}

int SelectNumber(const int i, vector<int> &NumberSet, vector<bool> &bVisited, vector<bool> &bLinked, const vector<int> &Numbers)
{
    if(bVisited[i])
    {
        if(bLinked[i])
        {
            NumberSet.push_back(i);
            return i;
        }
        else return 0;
    }
    bVisited[i] = true;
    bLinked[i] = true;
    int Root = SelectNumber(Numbers[i], NumberSet, bVisited, bLinked, Numbers);
    if(Root > 0)
    {
        if(Root == i) return 0;
        NumberSet.push_back(i);
        return Root;
    }
    else return 0;
}
