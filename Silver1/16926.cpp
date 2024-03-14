#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> Mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> Mat[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int Offset = min(min(i ,j), min(n - i - 1, m - j - 1));
            int RotationCount = r;
            int a = i, b = j;
            while(RotationCount > 0)
            {
                int Rotate = RotationCount;
                if(a == Offset && b < m - Offset - 1)
                {
                    Rotate = min(Rotate, m - Offset - 1 - b);
                    b += Rotate;
                }
                else if(a < n - Offset - 1 && b == m - Offset - 1)
                {
                    Rotate = min(Rotate, n - Offset - 1 - a);
                    a += Rotate;
                }
                else if(a == n - Offset - 1 && b > Offset)
                {
                    Rotate = min(Rotate, b - Offset);
                    b -= Rotate;
                }
                else if(a > Offset && b == Offset)
                {
                    Rotate = min(Rotate, a - Offset);
                    a -= Rotate;
                }
                RotationCount -= Rotate;
            }
            cout << Mat[a][b] << ' ';
        }
        cout << '\n';
    }

    return 0;
}