// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     cin >> n >> k;
//     vector<pair<int, int>> p;
//     p.resize(max(n, k) + 3);

//     int m;
//     p[0] = {n, 1};
//     if(n < 2)
//     {
//         m = 3;
//         p[1] = {abs(n - 1), 1};
//         p[2] = {p[1].first + 1, 2};
//     }
//     else
//     {
//         for(int i = 1; i < n + 1; ++i)
//         {
//             p[i] = {n - i, 1};
//         }
//         if(n % 2 == 0)
//         {
//             m = n + 1;
//         }
//         else
//         {
//             p[n + 1] = {1, 1};
//             m = n + 2;
//         }
//     }
    
//     // 홀수일때
//     // case1: i - 1에서 오는 방법
//     // case2: i + 1에서 오는 방법
//     // 짝수일때
//     // case3: i - 1에서 오는 방법
//     // case4: i / 2에서 오는 방법
//     for(int i = m; i < k + 1; i += 2)
//     {   
//         // case1:
//         p[i] = {p[i - 1].first + 1, p[i - 1].second};
//         // case4:
//         p[i + 1] = {p[(i + 1) / 2].first + 1, p[(i + 1) / 2].second};
//         // case2:
//         if(p[i].first > p[i + 1].first + 1)
//         {
//             p[i] = {p[i + 1].first + 1, p[i + 1].second};
//         }
//         else if(p[i].first == p[i + 1].first + 1)
//         {
//             p[i].second += p[i + 1].second;
//         }
//         // case3:
//         else if(p[i + 1].first == p[i].first + 1)
//         {
//             p[i + 1].second += p[i].second;
//         }
//         else if(p[i + 1].first > p[i].first + 1)
//         {
//             p[i + 1] = p[i];
//             p[i + 1].first += 1;
//         }
//     }

//     cout << p[k].first << '\n' << p[k].second;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void UpdateP(int i, int j, vector<pair<int, int>>& p, queue<int>& q);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> p(max(n, k) + 2, {0, 0});
    p[n].second = 1;

    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        UpdateP(i, i + 1, p, q);
        UpdateP(i, i - 1, p, q);
        UpdateP(i, i * 2, p, q);
    }

    cout << p[k].first << '\n' << p[k].second;
    return 0;
}

void UpdateP(int i, int j, vector<pair<int, int>> &p, queue<int> &q)
{
    if(j < 0 || j >= p.size()) return;
    if(p[j].second == 0 || p[j].first > p[i].first + 1)
    {
        p[j] = p[i];
        ++p[j].first;
        q.push(j);
    }
    else if(p[j].first == p[i].first + 1)
    {
        p[j].second += p[i].second;
    }
}
