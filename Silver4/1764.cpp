#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    map<string, bool> NotListen;
    map<string, bool>::iterator MapIter;
    vector<string> Result;

    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
    {
        string Input;
        cin >> Input;
        NotListen[Input] = false;
    }
    for(int i = 0; i < m; ++i)
    {
        string Input;
        cin >> Input;
        MapIter = NotListen.find(Input);
        if(MapIter != NotListen.end())
        {
            Result.push_back((*MapIter).first);
        }
    }

    sort(Result.begin(), Result.end());

    cout << Result.size() << '\n';
    for(int i = 0; i < Result.size(); ++i)
    {
        cout << Result[i] << '\n';
    }

    return 0;
}