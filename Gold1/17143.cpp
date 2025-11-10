#include <iostream>
#include <vector>

using namespace std;

class P17143
{
public:
    P17143()
    {
        int M;
        cin >> R >> C >> M;
        Mat = vector<vector<int>>(R, vector<int>(C, -1));

        for(int i = 0; i < M; ++i)
        {
            FSharkInfo SharkInfo;
            int Speed;
            int Direction;
            cin >> SharkInfo.R >> SharkInfo.C >> Speed >> Direction >> SharkInfo.Size;
            --SharkInfo.R;
            --SharkInfo.C;
            SharkInfo.VelocityR = Direction == 1 ? -Speed : Direction == 2 ? Speed : 0;
            SharkInfo.VelocityC = Direction == 3 ? Speed : Direction == 4 ? -Speed : 0;
            Mat[SharkInfo.R][SharkInfo.C] = Sharks.size();
            Sharks.push_back(SharkInfo);
        }
    }

    int Solve()
    {
        int SizeSum = 0;
        for(int j = 0; j < C; ++j)
        {
            // cout << endl;
            // Print();
            for(int i = 0; i < R; ++i)
            {
                if(Mat[i][j] >= 0)
                {
                    SizeSum += Sharks[Mat[i][j]].Size;
                    Sharks[Mat[i][j]].Size = 0;
                    Mat[i][j] = -1;
                    break;
                }
            }

            Step();
        }

        return SizeSum;
    }

    void Print()
    {
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                cout << (Mat[i][j] >= 0 ? static_cast<char>(Mat[i][j] + '0') : 'X') << ' ';
            }
            cout << endl;
        }
    }

private:
    struct FSharkInfo
    {
        int PrevR;
        int PrevC;
        int R;
        int C;
        int VelocityR;
        int VelocityC;
        int Size;
    };
    
    int R;
    int C;
    vector<vector<int>> Mat;
    vector<FSharkInfo> Sharks;

    void Step()
    {
        MoveSharks();
        UpdateMat();
    }

    void MoveSharks()
    {
        for(int i = 0; i < Sharks.size(); ++i)
        {
            if(Sharks[i].Size == 0)
            {
                continue;
            }

            MoveShark(Sharks[i]);
        }
    }

    void MoveShark(FSharkInfo& SharkInfo)
    {
        SharkInfo.PrevR = SharkInfo.R;
        SharkInfo.PrevC = SharkInfo.C;
        int SharkIndex = Mat[SharkInfo.R][SharkInfo.C];

        int RemainMoveR = SharkInfo.VelocityR;
        while(true)
        {
            int Move;
            if(RemainMoveR == 0)
            {
                SharkInfo.VelocityR *= -1;
                break;
            }
            else if(RemainMoveR > 0)
            {
                if(SharkInfo.R + RemainMoveR < R)
                {
                    Move = RemainMoveR;
                }
                else
                {
                    Move = R - 1 - SharkInfo.R;
                }
            }
            else
            {
                if(SharkInfo.R + RemainMoveR >= 0)
                {
                    Move = RemainMoveR;
                }
                else
                {
                    Move = -SharkInfo.R;
                }
            }

            SharkInfo.R += Move;
            RemainMoveR -= Move;
            RemainMoveR *= -1;
            SharkInfo.VelocityR *= -1;
        }

        int RemainMoveC = SharkInfo.VelocityC;
        while(true)
        {
            int Move;
            if(RemainMoveC == 0)
            {
                SharkInfo.VelocityC *= -1;
                break;
            }
            else if(RemainMoveC > 0)
            {
                if(SharkInfo.C + RemainMoveC < C)
                {
                    Move = RemainMoveC;
                }
                else
                {
                    Move = C - 1 - SharkInfo.C;
                }
            }
            else
            {
                if(SharkInfo.C + RemainMoveC >= 0)
                {
                    Move = RemainMoveC;
                }
                else
                {
                    Move = -SharkInfo.C;
                }
            }

            SharkInfo.C += Move;
            RemainMoveC -= Move;
            RemainMoveC *= -1;
            SharkInfo.VelocityC *= -1;
        }
    }

    void UpdateMat()
    {
        for(int i = 0 ; i < Sharks.size(); ++i)
        {
            if(Sharks[i].Size == 0)
            {
                continue;
            }

            if(Mat[Sharks[i].PrevR][Sharks[i].PrevC] == i)
            {
                Mat[Sharks[i].PrevR][Sharks[i].PrevC] = -1;
            }
            
            int DestValue = Mat[Sharks[i].R][Sharks[i].C];
            
            if(DestValue == -1 || DestValue >= i)
            {
                Mat[Sharks[i].R][Sharks[i].C] = i;
            }
            else
            {
                FSharkInfo& Another = Sharks[DestValue];
                if(Another.Size < Sharks[i].Size)
                {
                    Mat[Sharks[i].R][Sharks[i].C] = i;
                    Another.Size = 0;
                }
                else
                {
                    Sharks[i].Size = 0;
                }
            }
        }
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    P17143 Problem;
    cout << Problem.Solve();

    return 0;
}