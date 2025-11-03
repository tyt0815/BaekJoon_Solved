#include <iostream>
#include <vector>

using namespace std;

class F2048Game
{
public:
    F2048Game()
    {
        cin >> N;
        Board = vector<vector<int>>(N, vector<int>(N));

        for(vector<int>& Row : Board)
        {
            for(int& Value : Row)
            {
                cin >> Value;
            }
        }
    }

    void Left()
    {
        MoveHorizontal(-1);
    }

    void Right()
    {
        MoveHorizontal(1);
    }

    void Up()
    {
        MoveVertical(-1);
    }

    void Down()
    {
        MoveVertical(1);
    }

    int GetMaxValue() const
    {
        int MaxValue = 0;
        for(const vector<int>& Row : Board)
        {
            for(const int Value : Row)
            {
                MaxValue = max(MaxValue, Value);
            }
        }

        return MaxValue;
    }

    void Print() const
    {
        cout << endl;
        for(const vector<int>& Row : Board)
        {
            for(const int Value : Row)
            {
                cout << Value << ' ';
            }
            cout << endl;
        }
    }

    int DFS(int Depth)
    {
        if(Depth == 0)
        {
            return GetMaxValue();
        }
        int MaxValue = 0;

        F2048Game Next_Left = *this;
        Next_Left.Left();
        MaxValue = max(MaxValue, Next_Left.DFS(Depth - 1));
        F2048Game Next_Right = *this;
        Next_Right.Right();
        MaxValue = max(MaxValue, Next_Right.DFS(Depth - 1));
        F2048Game Next_Up = *this;
        Next_Up.Up();
        MaxValue = max(MaxValue, Next_Up.DFS(Depth - 1));
        F2048Game Next_Down = *this;
        Next_Down.Down();
        MaxValue = max(MaxValue, Next_Down.DFS(Depth - 1));

        return MaxValue;
    }

private:
    void MoveHorizontal(int Dir)
    {
        if(Dir != 0)
        {
            Dir = Dir / abs(Dir);
            int TargetCol = Dir < 0 ? 0 : N - 1;

            for(int i = 0; i < N; ++i)
            {
                int TargetCellJ = TargetCol;
                for(int Count = 1; Count < N; ++Count)
                {
                    int j = TargetCol - Dir * Count;
                    if(Board[i][j] == 0)
                    {
                        continue;
                    }

                    int Value = Board[i][j];
                    Board[i][j] = 0;

                    if(Board[i][TargetCellJ] == 0)
                    {
                        Board[i][TargetCellJ] = Value;
                    }
                    else if(Board[i][TargetCellJ] == Value)
                    {
                        Board[i][TargetCellJ] *= 2;
                        TargetCellJ -= Dir;
                    }
                    else
                    {
                        TargetCellJ -= Dir;
                        Board[i][TargetCellJ] = Value;
                    }
                }
            }
        }
    }

        void MoveVertical(int Dir)
    {
        if(Dir != 0)
        {
            Dir = Dir / abs(Dir);
            int TargetRow = Dir < 0 ? 0 : N - 1;

            for(int j = 0; j < N; ++j)
            {
                int TargetCellI = TargetRow;
                for(int Count = 1; Count < N; ++Count)
                {
                    int i = TargetRow - Dir * Count;
                    if(Board[i][j] == 0)
                    {
                        continue;
                    }

                    int Value = Board[i][j];
                    Board[i][j] = 0;

                    if(Board[TargetCellI][j] == 0)
                    {
                        Board[TargetCellI][j] = Value;
                    }
                    else if(Board[TargetCellI][j] == Value)
                    {
                        Board[TargetCellI][j] *= 2;
                        TargetCellI -= Dir;
                    }
                    else
                    {
                        TargetCellI -= Dir;
                        Board[TargetCellI][j] = Value;
                    }
                }
            }
        }
    }

    int N;
    vector<vector<int>> Board;

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    F2048Game Game;

    cout << Game.DFS(5);

    return 0;
}