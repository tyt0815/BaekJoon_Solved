#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct QData
{
    int i;
    int j;
    int Depth;
    bool CanBreak;
};

bool SearchWay(int i, int j, int Depth, bool CanBreak, queue<QData>& q, vector<vector<int>>& Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<vector<int>> Mat;
    cin >> n >> m;
    Mat.resize(n);
    for(int i = 0 ; i < n; ++i)
    {
        Mat[i].resize(m);
        for(int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            Mat[i][j] = c - '0';
        }
    }

    if(n == 1 && m == 1)
    {
        cout << 1;
        return 0;
    }

    int MinDist = -1;
    queue<QData> q;
    q.push({0, 0, 1, true});
    Mat[0][0] = -1;
    while(!q.empty())
    {
        QData Front = q.front();
        q.pop();
        int i = Front.i, j = Front.j, Depth = Front.Depth;
        bool CanBreak = Front.CanBreak;
        if(SearchWay(i - 1, j, Depth, CanBreak, q, Mat))
        {
            MinDist = Depth + 1;
            break;
        }
        if(SearchWay(i + 1, j, Depth, CanBreak, q, Mat))
        {
            MinDist = Depth + 1;
            break;
        }
        if(SearchWay(i, j - 1, Depth, CanBreak, q, Mat))
        {
            MinDist = Depth + 1;
            break;
        }
        if(SearchWay(i, j + 1, Depth, CanBreak, q, Mat))
        {
            MinDist = Depth + 1;
            break;
        }
    }

    cout << MinDist;

    return 0;
}

bool SearchWay(int i, int j, int Depth, bool CanBreak, queue<QData> &q, vector<vector<int>>& Mat)
{
    if(i < 0 || j < 0 || i >= Mat.size() || j >= Mat[0].size() || Mat[i][j] == -1) return false;
    if(!CanBreak && (Mat[i][j] == 1 || Mat[i][j] == 2)) return false;

    if(i == Mat.size() - 1 && j == Mat[i].size() - 1)
    {
        return true;
    }

    // 0 1 2
    if(CanBreak)
    {
        if(Mat[i][j] != 1)
        {
            q.push({i, j, Depth + 1, true});
        }
        else
        {
            q.push({i, j, Depth + 1, false});
        }
        Mat[i][j] = -1;
    }
    // 0
    else
    {
        q.push({i, j, Depth + 1, false});
        Mat[i][j] = 2;
    }

    return false;
}
