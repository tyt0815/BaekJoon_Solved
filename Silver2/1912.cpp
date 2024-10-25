// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> p;
//     p.resize(n);
//     int m, MaxSum;
//     cin >> m;
//     p[0] = m;
//     MaxSum = m;
//     for(int i = 1; i < n; ++i)
//     {
//         cin >> m;
//         p[i] = max(p[i - 1] + m, m);
//         MaxSum = max(MaxSum, p[i]);
//     }

//     cout << MaxSum;

//     return 0;
// }

#include <iostream>
#include <vector>
#define MIN -1000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Answer = MIN;
    cin >> N;    
    vector<int> p(N + 1, 0);
    for(int i = 1; i <= N; ++i)
    {
        int Number;
        cin >> Number;
        p[i] = p[i - 1] > 0 ? p[i - 1] + Number : Number;
        Answer = max(Answer, p[i]);
    }
    cout << Answer;

    return 0;
}