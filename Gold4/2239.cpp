#include <iostream>
#include <vector>

using namespace std;

int Sudoku[9][9];
bool bRowCheck[9][10];
bool bColCheck[9][10];
bool bSquareCheck[9][10];
vector<pair<int, int>> BlankList;

bool SolveSudoku(int Depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 9; ++i)
    {
        string Line;
        cin >> Line;
        for(int j = 0; j < 9; ++j)
        {
            Sudoku[i][j] = Line[j] - '0';
            int SquareNumb = (i / 3) * 3 + j / 3;
            if(Sudoku[i][j] == 0) 
            {
                BlankList.push_back({i, j});
                bRowCheck[i][Sudoku[i][j]] = bColCheck[j][Sudoku[i][j]] = bSquareCheck[SquareNumb][Sudoku[i][j]] = false;
            }
            else bRowCheck[i][Sudoku[i][j]] = bColCheck[j][Sudoku[i][j]] = bSquareCheck[SquareNumb][Sudoku[i][j]] = true;
        }
    }

    SolveSudoku(0);
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << Sudoku[i][j];
        }
        cout << '\n';
    }

    return 0;
}

bool SolveSudoku(int Depth)
{
    if(Depth == BlankList.size()) return true;

    int i = BlankList[Depth].first, j = BlankList[Depth].second;
    int SquareNumb = (i / 3) * 3 + j / 3;

    for(int x = 1; x <= 9; ++x)
    {
        if(bRowCheck[i][x] || bColCheck[j][x] || bSquareCheck[SquareNumb][x]) continue;
        Sudoku[i][j] = x;
        bRowCheck[i][x] = bColCheck[j][x] = bSquareCheck[SquareNumb][x] = true;
        if(SolveSudoku(Depth + 1)) return true;
        bRowCheck[i][x] = bColCheck[j][x] = bSquareCheck[SquareNumb][x] = false;
    }

    return false;
}
