#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int n, m;
vector<int> Numbers;

void FindNumbers(int Top, vector<int> NumbIndices, int& Size, vector<bool> Visited, unordered_map<int, int> Map);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, int> Map;    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int In;
        cin >> In;
        if(Map.find(In) == Map.end())
        {
            Map[In] = 1;
            Numbers.push_back(In);
        }
        else
        {
            ++Map[In];
        }
    }
    sort(Numbers.begin(), Numbers.end());

    int Size = Numbers.size();
    vector<int> NumbIndices;
    vector<bool> Visited;
    NumbIndices.resize(m);
    Visited.resize(Size);
    for(int i = 0; i < Size; ++i)
    {
        Visited[i] = false;
    }
    for(int i = 0; i < Size; ++i)
    {
        NumbIndices[0] = i;
        --Map[Numbers[i]];
        if(Map[Numbers[i]] == 0)
        {
            Visited[i] = true;
        }
        FindNumbers(1, NumbIndices, Size, Visited, Map);
        ++Map[Numbers[i]];
        Visited[i] = false;
    }

    return 0;
}

void FindNumbers(int Top, vector<int> NumbIndices, int &Size, vector<bool> Visited, unordered_map<int, int> Map)
{
    if(Top == m)
    {
        for(int i = 0; i < m; ++i)
        {
            cout << Numbers[NumbIndices[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < Size; ++i)
    {
        if(Visited[i]) continue;
        NumbIndices[Top] = i;
        --Map[Numbers[i]];
        if(Map[Numbers[i]] == 0)
        {
            Visited[i] = true;
        }
        FindNumbers(Top + 1, NumbIndices, Size, Visited, Map);
        ++Map[Numbers[i]];
        Visited[i] = false;
    }
}
