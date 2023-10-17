#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
public:
    Interval():
        mStart(0),
        mEnd(0),
        mSum(0)
    {}
    uint32_t mStart;
    uint32_t mEnd;
    uint64_t mSum;

    vector<uint32_t> CommIntervIndices;
};
void SumInterval(Interval& Input);
void FindCommonInterval(Interval& a, Interval& b);

uint32_t n, m, *Numbers;
Interval *Questions;
Interval *CommonInterval;
uint32_t ComInterSize = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    Numbers = new uint32_t[n + 1];
    Questions = new Interval[m];
    CommonInterval = new Interval[m];
    for(uint32_t i = 1; i <= n; ++i)
    {
        cin >> Numbers[i];
    }

    for(uint32_t i = 0; i < m; ++i)
    {
        cin >> Questions[i].mStart >> Questions[i].mEnd;
        for(uint32_t j = 0; j < i; ++j)
        {
            FindCommonInterval(Questions[i], Questions[j]);
        }
    }
    for(uint32_t i = 0; i < m; ++i)
    {
        SumInterval(Questions[i]);
        cout << Questions[i].mSum << '\n';
    }

    delete[] Numbers;
    delete[] Questions;
    delete[] CommonInterval;
    return 0;
}

void SumInterval(Interval& Input)
{
    for(uint32_t i = Input.mStart; i < Input.mEnd + 1; ++i)
    {
        for(uint32_t j = 0; j < Input.CommIntervIndices.size(); ++j)
        {
            if(CommonInterval[Input.CommIntervIndices[j]].mStart == i && CommonInterval[Input.CommIntervIndices[j]].mEnd <= Input.mEnd)
            {
                Input.mSum += CommonInterval[j].mSum;
                i = CommonInterval[j].mEnd;
                goto Retry;
            }
        }
        Input.mSum += Numbers[i];
        Retry:;
    }
}

void FindCommonInterval(Interval& a, Interval& b)
{
    Interval Temp;
    Temp.mStart = max(a.mStart, b.mStart);
    Temp.mEnd = min(a.mEnd, b.mEnd);
    if(Temp.mStart >= Temp.mEnd) { return; }
    
    SumInterval(Temp);
    a.CommIntervIndices.push_back(ComInterSize);
    b.CommIntervIndices.push_back(ComInterSize);
    CommonInterval[ComInterSize++] = Temp;
}