#include <iostream>
#define CHESS_SIZE 8

using namespace std;

int CheckMinPainting(char, char, char**, int, int);

int main()
{
    int n, m;
    int result = 2500;
    char **board;
    cin >> n >> m;
    board = new char*[n];
    for(int i = 0; i < n; ++i)
    {
        board[i] = new char[m];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n-CHESS_SIZE+1; ++i)
    {
        for(int j = 0; j < m-CHESS_SIZE+1; ++j)
        {
            result = min(result, CheckMinPainting('B', 'W', board, i, j));
            result = min(result, CheckMinPainting('W', 'B', board, i , j));
        }
    }

    cout << result;

    return 0;
}

int CheckMinPainting(char first, char second, char** board, int n, int m)
{
    int cnt = 0;
    int i, j;
    for(i = n; i < n+CHESS_SIZE; ++i)
    {
        for(j = m; j < m+CHESS_SIZE;++j)
        {
            if((i+j-n-m) % 2 == 0)
            {
                if(board[i][j] != first) { ++cnt; }
            }
            else
            {
                if(board[i][j] != second) { ++cnt; }
            }
        }
    }
    return cnt;
}