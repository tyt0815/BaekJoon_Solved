#include <iostream>
#include <vector>

constexpr int TURN_LIMIT = 10;

using namespace std;

class FBoard
{
public:
    FBoard()
    {
        cin >> N >> M;
        Board = vector<vector<char>>(N, vector<char>(M));
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                cin >> Board[i][j];
                if(Board[i][j] == 'R')
                {
                    RedX = i;
                    RedY = j;
                }
                else if(Board[i][j] == 'B')
                {
                    BlueX = i;
                    BlueY = j;
                }
            }
        }
    }

    int Left()
    {
        if(RedY < BlueY)
        {
            Move_Recursive(0, -1, RedX, RedY);
            Move_Recursive(0, -1, BlueX, BlueY);
        }
        else
        {
            Move_Recursive(0, -1, BlueX, BlueY);
            Move_Recursive(0, -1, RedX, RedY);
        }
        return GetState();
    }

    int Right()
    {
        if(RedY > BlueY)
        {
            Move_Recursive(0, 1, RedX, RedY);
            Move_Recursive(0, 1, BlueX, BlueY);
        }
        else
        {
            Move_Recursive(0, 1, BlueX, BlueY);
            Move_Recursive(0, 1, RedX, RedY);
        }
        return GetState();
    }

    int Up()
    {
        if(RedX < BlueX)
        {
            Move_Recursive(-1, 0, RedX, RedY);
            Move_Recursive(-1, 0, BlueX, BlueY);
        }
        else
        {
            Move_Recursive(-1, 0, BlueX, BlueY);
            Move_Recursive(-1, 0, RedX, RedY);
        }
        return GetState();
    }

    int Down()
    {
        if(RedX > BlueX)
        {
            Move_Recursive(1, 0, RedX, RedY);
            Move_Recursive(1, 0, BlueX, BlueY);
        }
        else
        {
            Move_Recursive(1, 0, BlueX, BlueY);
            Move_Recursive(1, 0, RedX, RedY);
        }
        return GetState();
    }

    int GetState() const
    {
        if(BlueX < 0)
        {
            return -1;
        }
        else if(RedX < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Print() const
    {
        cout << '\n';
        for(const vector<char>& Row : Board)
        {
            for(const char Value : Row)
            {
                cout << Value;
            }
            cout << '\n';
        }
    }

    int RedX;
    int RedY;
    int BlueX;
    int BlueY;

private:
    // Red, Blue의 위치에 따라 순서에 맞게 호출해야함
    void Move_Recursive(int OffsetX, int OffsetY, int& X, int& Y)
    {
        if(Board[X + OffsetX][Y + OffsetY] == 'O')
        {
            Board[X][Y] = '.';
            X = -1;
            Y = -1;
        }
        else if(Board[X + OffsetX][Y + OffsetY] == '.')
        {
            OffsetX = OffsetX == 0 ? 0 : OffsetX > 0 ? OffsetX + 1 : OffsetX - 1;
            OffsetY = OffsetY == 0 ? 0 : OffsetY > 0 ? OffsetY + 1 : OffsetY - 1;
            Move_Recursive(OffsetX, OffsetY, X, Y);
        }
        else
        {
            OffsetX = OffsetX == 0 ? 0 : OffsetX > 0 ? OffsetX - 1 : OffsetX + 1;
            OffsetY = OffsetY == 0 ? 0 : OffsetY > 0 ? OffsetY - 1 : OffsetY + 1;

            char Temp = Board[X][Y];
            Board[X][Y] = '.';
            Board[X + OffsetX][Y + OffsetY] = Temp;

            X += OffsetX;
            Y += OffsetY;
        }

        // Print();
    }

    vector<vector<char>> Board;
    int N;
    int M;
};

int Solve(int Turn, const FBoard& GameBoard)
{
    static vector<vector<vector<vector<vector<int>>>>> DP(
        TURN_LIMIT, vector<vector<vector<vector<int>>>>(
            10, vector<vector<vector<int>>>(
                10, vector<vector<int>>(
                    10, vector<int>(10, TURN_LIMIT + 1)
                )
            )
        )
    );
    
    if(GameBoard.GetState() == 1)
    {
        return Turn;
    }
    else if(Turn >= TURN_LIMIT || GameBoard.GetState() == -1)
    {
        return TURN_LIMIT + 1;
    }
    else
    {
        int& DPValue = DP[Turn][GameBoard.RedX][GameBoard.RedY][GameBoard.BlueX][GameBoard.BlueY];
        if(DPValue <= TURN_LIMIT)
        {
            return DPValue;
        }

        FBoard LeftBoard = GameBoard;
        LeftBoard.Left();
        DPValue = min(DPValue, Solve(Turn + 1, LeftBoard));
        FBoard RightBoard = GameBoard;
        RightBoard.Right();
        DPValue = min(DPValue, Solve(Turn + 1, RightBoard));
        FBoard UpBoard = GameBoard;
        UpBoard.Up();
        DPValue = min(DPValue, Solve(Turn + 1, UpBoard));
        FBoard DownBoard = GameBoard;
        DownBoard.Down();
        DPValue = min(DPValue, Solve(Turn + 1, DownBoard));

        return DPValue;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FBoard GameBoard;
    
    int MinTurn = Solve(0, GameBoard);
    cout << ((MinTurn <= TURN_LIMIT) ? MinTurn : -1);

    return 0;
}