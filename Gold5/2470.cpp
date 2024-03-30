#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline int64_t MixSolution(int64_t a, int64_t b) { return abs(a + b); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int64_t> v(n, 0);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    int64_t Solution[2] = {INT64_MAX / 2, INT64_MAX / 2};
    for(int i = 0; i < n - 1; ++i)
    {
        int Index = lower_bound(v.begin() + 1, v.end(), -v[i]) - v.begin();
        if(Index >= n || MixSolution(v[i], v[Index]) > MixSolution(v[i], v[Index - 1])) --Index;
        if(Index <= i) ++Index;
        if(MixSolution(Solution[0], Solution[1]) > MixSolution(v[i], v[Index]))
        {
            Solution[0] = v[i];
            Solution[1] = v[Index];
        }
    }

    cout << Solution[0] << ' ' << Solution[1];

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// inline int64_t MixSolution(int64_t a, int64_t b) { return abs(a + b); }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int64_t> v(n, 0);
//     for(int i = 0; i < n; ++i) cin >> v[i];
//     sort(v.begin(), v.end());

//     int64_t Solution[2];
//     for(int i = 0; i < n - 1; ++i)
//     {
//         int j;
//         for(j = n - 2; j > i; --j)
//         {
//             if(MixSolution(v[i], v[j]) > MixSolution(v[i], v[j + 1])) break;
//         }
//         ++j;
//         if(MixSolution(Solution[0], Solution[1]) > MixSolution(v[i], v[j]))
//         {
//             Solution[0] = v[i];
//             Solution[1] = v[j];
//         }
//     }

//     cout << Solution[0] << ' ' << Solution[1];

//     return 0;
// }