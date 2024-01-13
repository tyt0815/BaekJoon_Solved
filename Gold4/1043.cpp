#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int k;
    cin >> n >> m;
    cin >> k;
    vector<bool> IsKnown(n + 1, false);
    vector<bool> IsSayedTruth(m, false);
    vector<vector<int>> PartyMember;
    PartyMember.resize(m);
    for(int i = 0; i < k; ++i)
    {
        int Know;
        cin >> Know;
        IsKnown[Know] = true;
    }
    for(int i = 0 ; i < m; ++i)
    {
        int a;
        cin >> a;
        PartyMember[i].resize(a);
        bool NeedTrue = false;
        for(int j = 0; j < a; ++j)
        {
            cin >>PartyMember[i][j];
            if(IsKnown[PartyMember[i][j]])
            {
                NeedTrue = true;
            }
        }
        if(NeedTrue)
        {
            for(int j = 0; j < a; ++j)
            {
                IsKnown[PartyMember[i][j]] = true;
            }
            IsSayedTruth[i] = true;
        }
    }

    bool Recheck = true;
    while(Recheck)
    {
        Recheck = false;
        for(int i = 0; i < m; ++i)
        {
            if(!IsSayedTruth[i])
            {
                for(int j = 0; j < PartyMember[i].size(); ++j)
                {
                    if(IsKnown[PartyMember[i][j]])
                    {
                        IsSayedTruth[i] = true;
                        Recheck = true;
                        for(int k = 0; k < PartyMember[i].size(); ++k)
                        {
                            IsKnown[PartyMember[i][k]] = true;
                        }
                        break;
                    }
                }
                
            }
        }
    }

    int Count = 0;
    for(int i = 0; i < m; ++i)
    {
        if(!IsSayedTruth[i])
        {
            ++Count;
        }
    }

    cout << Count;

    return 0;
}