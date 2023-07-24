#include <iostream>

using namespace std;

void quick_sort(int*, int, int);
void swap_element_in_array(int*, int, int);

int main()
{
    int n;
    int *input;
    cin >> n;
    input = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    quick_sort(input, 0, n);

    for(int i = 0; i < n; ++i)
    {
        cout << input[i] << '\n';
    }

    return 0;
}

void quick_sort(int* input, int start, int end)
{
    int pivot = (start + end) / 2;
    if(pivot == start || pivot == end)
    {
        return;
    }
    for(int i = start; i < pivot; ++i)
    {
        if(input[i] > input[pivot])
        {
            swap_element_in_array(input, i, pivot+1);
            --pivot;
            --i;
        }
    }
    for(int i = pivot +1; i < end; ++i)
    {
        if(input[i] < input[pivot])
        {
            swap_element_in_array(input, i, pivot-1);
            ++pivot;
            --i;
        }
    }
    quick_sort(input, start, pivot);
    quick_sort(input, pivot+1, end);
}

void swap_element_in_array(int* input, int i, int to)
{
    int temp
}