#include <iostream>

using namespace std;

typedef pair<int, string> info;

void sort(info*, info*, int, int);

int main()
{
    int n;
    info *persnalInfo, *sorted;
    cin >> n;
    persnalInfo = new info[n];
    sorted = new info[n];

    for(int i= 0; i < n; ++i)
    {
        cin >> persnalInfo[i].first >> persnalInfo[i].second;
    }

    sort(persnalInfo, sorted, 0, n);

    for(int i = 0; i < n; ++i)
    {
        cout << sorted[i].first << " " << sorted[i].second << "\n";
    }

    return 0;
}

void sort(info * input, info* sorted, int start, int end)
{
    if(start + 1 >= end)
    {
        for(int i = start; i < end; ++i){ sorted[i] = input[i]; }
        return;
    }
    int mid = (start + end) / 2;
    sort(input, sorted, start, mid);
    sort(input, sorted, mid, end);
    int i = start, j = mid, k = start;
    while(i < mid && j < end)
    {
        if(input[i].first < input[j].first)
        {
            sorted[k] = input[i];
            ++i; ++k;
        }
        else if(input[i].first > input[j].first)
        {
            sorted[k] = input[j];
            ++j; ++k;
        }
        else
        {
            sorted[k++] = input[i++];
        }
    }
    for(; i < mid; ++i,++k){ sorted[k] = input[i]; }
    for(; j < end; ++j,++k){ sorted[k] = input[j]; }
    for(i = start; i < end; ++i){ input[i] = sorted[i]; }
}