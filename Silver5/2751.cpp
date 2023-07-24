#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin(), v.end());

    vector<int>::iterator iter = v.begin();
    for(; iter != v.end(); ++iter)
    {
        cout << *iter << "\n";
    }

    return 0;
}