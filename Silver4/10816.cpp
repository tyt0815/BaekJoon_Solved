#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<long long, int> Card;  // <숫자, 갯수>

void sortCard(Card *input, Card *sorted, int start, int end, bool* table, int& n);

int main()
{
    int n, m;
    bool *table;
    Card *cards;

    cin >> n;
    cards = new Card[n];
    table = new bool[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> cards[i].first;
        cards[i].second = 1;
        table[i] = true;
    }

    return 0;
}

void sortCard(Card *input, Card *sorted, int start, int end, bool* table, int& n)
{
    if(start + 1 == end)
    {
        sorted[start] = input[start];
        return;
    }
    int mid = (start + end) / 2;
    sortCard(input, sorted, start, mid, table, n);
    sortCard(input, sorted, mid, end, table, n);
    int i = start, j = mid, k = start;
    while(i < mid && j < end)
    {
        if(!table[i])
        {
            ++i;
            continue;
        }
        if(!table[j])
        {
            ++j;
            continue;
        }
        if(sorted[i].first < sorted[j].first)
        {
            input[k++] = sorted[i++];
        }
        else if(sorted[i].first > sorted[j].first)
        {
            input[k++] = sorted[j++];
        }
        else
        {
            sorted[i].second += sorted[j].second;
            table[j++] = false;
            input[k++] = sorted[i++];
            --n;
        }
    }
    for(;i < mid; ++i)
    {
        if(!table[i]){ continue; }
        input[k++] = sorted[i];
    }
    for(;j < end; ++j)
    {
        if(!table[j]){ continue; }
        input[k++] = sorted[j];
    }
    for()
}