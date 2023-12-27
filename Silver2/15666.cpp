#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int n, m;
vector<int> Numbers;

void FindNumbers(int Top, vector<int> NumbIndex);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> NumbIndex;
    unordered_map<int, bool> NumbCount;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int Input;
        cin >> Input;
        if(NumbCount.find(Input) == NumbCount.end())
        {
            NumbCount[Input] = true;
            Numbers.push_back(Input);
        }
    }
    sort(Numbers.begin(), Numbers.end());
    NumbIndex.resize(m);
    int NSize = Numbers.size();
    for(int i = 0; i < NSize; ++i)
    {
        NumbIndex[0] = i;
        FindNumbers(1, NumbIndex);
    }
}

void FindNumbers(int Top, vector<int> NumbIndex)
{
    if(Top == m)
    {
        for(int i = 0 ; i < m; ++i)
        {
            cout << Numbers[NumbIndex[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int NSize = Numbers.size();
    for(int i = NumbIndex[Top - 1]; i < NSize; ++i)
    {
        NumbIndex[Top] = i;
        FindNumbers(Top + 1, NumbIndex);
    }
}
