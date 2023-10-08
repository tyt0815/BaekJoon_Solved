#include <iostream>
#include <algorithm>

using namespace std;

int CountFunc(long long* cards, long long target, const int& length);
int UpperBinary(long long* cards, long long target, int start, int end, const int& length);
int LowerBinary(long long* cards, long long target, int start, int end);

int main()
{
    int n, m;
    long long *cards, *targets;

    cin >> n;
    cards = new long long[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }

    sort(cards, cards + n);

    cin >> m;
    targets = new long long[m];
    for(int i = 0; i < m; ++i)
    {
        cin >> targets[i];
    }
        
    for(int i = 0; i < m; ++i)
    {
        cout << CountFunc(cards, targets[i], n) << " ";
    }

    return 0;
}


int CountFunc(long long* cards, long long target, const int& length)
{
    int start = 0, end = length;
    int mid;
    /*
    이분  탐색
    */
    while(true)
    {
        mid = (start + end) / 2;
        if(start >= end)
        {
            return 0;
        }
        if(cards[mid] == target)
        {
            break;
        }
        else if(cards[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return UpperBinary(cards, target, start, end, length) - LowerBinary(cards, target, start, end) + 1;
}

int UpperBinary(long long* cards, long long target, int start, int end, const int& length)
{
    int mid;

    while(true)
    {
        mid = (start + end) / 2;
        if(cards[mid] == target && (mid == length - 1 || cards[mid + 1] != target))
        {
            return mid;
        }
        else if(cards[mid] > target)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}
int LowerBinary(long long* cards, long long target, int start, int end)
{
    int mid;

    while(true)
    {
        mid = (start + end) / 2;
        if(cards[mid] == target && (mid == 0 || cards[mid - 1] != target))
        {
            return mid;
        }
        else if(cards[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
}