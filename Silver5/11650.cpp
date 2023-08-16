#include "iostream"
#include "vector"

using namespace std;

typedef pair<int, int> POS;
void sortPos(POS*, POS*, int, int);

int main()
{
    int n;
    POS *pos, *sorted;
    cin >> n;
    pos = new POS[n];
    sorted = new POS[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    sortPos(pos, sorted, 0, n);

    for(int i = 0; i < n; ++i)
    {
        cout << sorted[i].first << " " << sorted[i].second << "\n";
    }

    return 0;
}

void sortPos(POS* ary, POS* sorted, int start, int end)
{
    if(start + 1 == end)
    {
        sorted[start] = ary[start];
        return;
    }
    int mid = (start + end) / 2;
    sortPos(ary, sorted, start, mid);
    sortPos(ary, sorted, mid, end);
    
    int i = start, j = mid, k = start;
    for(;i < mid && j < end;)
    {
        if(sorted[i].first < sorted[j].first)
        {
            ary[k++] = sorted[i++];
        }
        else if(sorted[i].first > sorted[j].first)
        {
            ary[k++] = sorted[j++];
        }
        else
        {
            if(sorted[i].second < sorted[j].second)
            {
                ary[k++] = sorted[i++];
            }
            else
            {
                ary[k++] = sorted[j++];
            }
        }
    }
    for(;i < mid;){ ary[k++] = sorted[i++]; }
    for(;j < end;){ ary[k++] = sorted[j++]; }
    for(i = start; i < end; ++i){ sorted[i] = ary[i]; }
    return;
}