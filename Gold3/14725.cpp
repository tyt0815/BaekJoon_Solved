#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

struct FExploreInfo
{
    vector<string> Feeds;

    bool operator<(const FExploreInfo& Another)
    {
        int i = 0;
        while(true)
        {
            if(this->Feeds.size() <= i)
            {
                return true;
            }
            else if(Another.Feeds.size() <= i)
            {
                return false;
            }
            else if(this->Feeds[i] == Another.Feeds[i])
            {
                ++i;
            }
            else
            {
                return this->Feeds[i] < Another.Feeds[i];
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;      // 먹이의 정보 개수
    cin >> N;

    vector<FExploreInfo> ExploreInfos(N);
    for(int i = 0; i < ExploreInfos.size(); ++i)
    {
        int K;      // 먹이 정보 개수
        cin >> K;
        
        ExploreInfos[i].Feeds.resize(K);
        for(int j = 0; j < ExploreInfos[i].Feeds.size(); ++j)
        {
            cin >> ExploreInfos[i].Feeds[j];
        }
    }

    sort(ExploreInfos.begin(), ExploreInfos.end());

    for(int i = 0; i < ExploreInfos[0].Feeds.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            cout << "--";
        }
        cout << ExploreInfos[0].Feeds[i] << '\n';
    }

    for(int k = 1; k < ExploreInfos.size(); ++k)
    {
        int i = 0;
        while(ExploreInfos[k - 1].Feeds[i] == ExploreInfos[k].Feeds[i])
        {
            ++i;
        }

        for(; i < ExploreInfos[k].Feeds.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                cout << "--";
            }
            cout << ExploreInfos[k].Feeds[i] << '\n';
        }
    }

    return 0;
}