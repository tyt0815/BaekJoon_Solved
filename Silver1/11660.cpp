#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    vector<vector<int>> IntervalSum(n);
    for(int i = 0; i < n; ++i)
    {
        IntervalSum[i].resize(n);
        cin >>IntervalSum[i][0];
        for(int j = 1 ; j < n; ++j)
        {
            cin >>IntervalSum[i][j];
            IntervalSum[i][j] += IntervalSum[i][j - 1];
        }
    }

    for(int k = 0; k < m; ++k)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        int Answer = 0;
        for(int i = x1 ; i <= x2; ++i)
        {
            Answer += IntervalSum[i][y2];
        }
        if(y1 - 1 >= 0)
        {
            for(int i = x1; i <= x2; ++i)
            {
                Answer -= IntervalSum[i][y1 - 1];
            }
        }

        cout << Answer << '\n';
    }


    return 0;
}