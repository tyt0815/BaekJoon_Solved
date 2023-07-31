#include <iostream>

using namespace std;

void sortF(int*, int*, int, int);

int main()
{
    int n;
    int *input, *sorted;
    cin >> n;
    input = new int[n];
    sorted = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
        sorted[i] = input[i];
    }

    sortF(input, sorted, 0, n);

    for(int i = 0; i < n; ++i)
    {
        cout << sorted[i] << '\n';
    }

    return 0;
}

void sortF(int* input, int* sorted, int start, int end)
{
    if(start + 1 >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    sortF(input, sorted, start, mid);
    sortF(input, sorted, mid, end);
    int i = start, j = mid, k = start;
    while(i < mid && j < end)
    {
        if(input[i] < input[j])
        {
            sorted[k] = input[i];
            ++i; ++k;
        }
        else if(input[i] > input[j])
        {
            sorted[k] = input[j];
            ++j; ++k;
        }
    }
    for(; i < mid; ++i,++k){ sorted[k] = input[i]; }
    for(; j < end; ++j,++k){ sorted[k] = input[j]; }
    for(i = start; i < end; ++i){ input[i] = sorted[i]; }
}