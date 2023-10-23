#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MeetingTime
{
    uint32_t Start;
    uint32_t End;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n, Cnt = 1;
    vector<MeetingTime> Times;
    
    cin >> n;
    Times.resize(n);
    
    for(uint32_t i = 0; i < n; ++i)
    {
        cin >> Times[i].Start >> Times[i].End;
    }

    sort(Times.begin(), Times.end(), [](MeetingTime a, MeetingTime b)
        {
            if(a.End == b.End)
            {
                return a.Start < b.Start;
            }
            return a.End < b.End;   
        });

    MeetingTime Temp = Times[0];
    for(uint32_t i = 1; i < n ; ++i)
    {
        if(Times[i].Start >= Temp.End)
        {
            ++Cnt;
            Temp = Times[i];
        }
    }

    cout << Cnt;

    return 0;
}