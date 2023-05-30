// 문제: https://www.acmicpc.net/problem/1389
// 풀이:

#include <iostream>
#include <vector>
#include <stack>

#define INF 99999

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int *kevinNum = new int[n+1];
    vector<int> *graph = new vector<int>[n+1];
    int **mat = new int*[n+1];
    

    for(int i = 0; i < n+1; ++i)
    {
        kevinNum[i] = 0;
        mat[i] = new int[n+1];
        for(int j = 0; j < n+1; ++j)
        {
            if(i == j)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        mat[a][b] = mat[b][a] = 1;
    }

    
    for(int i = 1; i < n+1; ++i)
    {
        for(int j = 1; j < n+1; ++j)
        {
            for( int k = 1; k < n+1; ++k)
            {
                if(mat[i][k] > mat[i][j] + mat[j][k])
                {
                    mat[i][k] = mat[k][i] = mat[i][j] + mat[j][k];
                }
            }
        }
    }
    

    for(int i = 1; i < n+1; ++i)
    {
        for(int j = 1; j < n+1; ++j)
        {
            kevinNum[i] += mat[i][j];
        }
    }
    int result = INF;
    for(int i = 1; i < n+1; ++i)
    {
        result = min(result, kevinNum[i]);
    }
    for(int i = 1; i < n+1; ++i)
    {
        if(kevinNum[i] == result)
        {
            cout << i;
            break;
        }
    }

    return 0;
}