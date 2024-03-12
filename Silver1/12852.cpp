#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> IsVisited(n, false);
    IsVisited[0] = true;
    queue<vector<int>> q;
    q.push({n});
    while(!q.empty())
    {
        vector<int> v = q.front();
        int x = v.back();
        q.pop();
        if(x == 1)
        {
            cout << v.size() - 1 << '\n';
            for(int i = 0; i < v.size(); ++i)
            {
                cout << v[i] << ' ';
            }
            break;
        }
        if(x % 3 == 0 && !IsVisited[x / 3])
        {
            IsVisited[x / 3] = true;
            q.push(v);
            q.back().push_back(x / 3);
        }
        if(x % 2 == 0 && !IsVisited[x / 2])
        {
            IsVisited[x / 2] = true;
            q.push(v);
            q.back().push_back(x / 2);
        }
        if(x - 1 > 0 && !IsVisited[x - 1])
        {
            IsVisited[x - 1] = true;
            q.push(v);
            q.back().push_back(x - 1);
        }
    }

    return 0;
}