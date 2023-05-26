// 문제: https://www.acmicpc.net/problem/1012
// 풀이: https://www.notion.so/tyt0815/1012-101e46f31ee04d299eca76ef380da6a3?pvs=4

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int> cordinate;

int main()
{
    int t, m, n, k, x, y;
    int i, j;
    bool **mat;
    bool **isChecked;
    cin >> t;
    // t번 테스트
    for(i = 0; i < t; ++i)
    {
        int need = 0;
        vector<cordinate> v;
        //테스트    
        cin >> m >> n >> k;
        mat = new bool*[m];
        isChecked = new bool*[m];
        // 0으로 초기화됨
        for(j = 0; j < m; ++j)
        {
            mat[j] = new bool[n];
            isChecked[j] = new bool[n];
        }

        for(int a = 0; a < m; ++a)
        {
            for(int b = 0; b < n; ++b)
            {
                mat[a][b] = false;
                isChecked[a][b] = false;
            }
        }

        for(j = 0; j < k; ++j)
        {
            cin >> x >> y;
            mat[x][y] = true;
            cordinate pos = make_tuple(x, y);
            v.push_back(pos);
        }        

        vector<cordinate>::iterator iter = v.begin();
        for(;iter != v.end(); ++iter)
        {
            x = get<0>(*iter);
            y = get<1>(*iter);
            if(isChecked[x][y]) { continue; }
            queue<cordinate> q;
            q.push(*iter);
            isChecked[x][y] = true;
            while(!q.empty())
            {
                cordinate pos = q.front();
                q.pop();
                x = get<0>(pos); y = get<1>(pos);
                // cout << x << ", " << y << endl
                // 오른쪽
                if(x+1 < m && !isChecked[x+1][y] && mat[x+1][y])
                {
                    pos = make_tuple(x+1, y);
                    q.push(pos);
                    isChecked[x+1][y] = true;
                }
                // 왼쪽
                if(x-1 > -1 && !isChecked[x-1][y] && mat[x-1][y])
                {
                    pos = make_tuple(x-1, y);
                    q.push(pos);
                    isChecked[x-1][y] = true;
                }
                // 위
                if(y+1 < n && !isChecked[x][y+1] && mat[x][y+1])
                {
                    pos = make_tuple(x, y+1);
                    q.push(pos);
                    isChecked[x][y+1] = true;
                }
                // 아래
                if(y-1 > -1 && !isChecked[x][y-1] && mat[x][y-1])
                {
                    pos = make_tuple(x, y-1);
                    q.push(pos);
                    isChecked[x][y-1] = true;
                }
            }
            // cout << endl;
            ++need;
        }
        cout << need << endl;
    } 



    return 0;
}