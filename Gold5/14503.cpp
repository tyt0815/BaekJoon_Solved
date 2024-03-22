#include <iostream>
#include <vector>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DIRTY '0'
#define WALL '1'
#define CLEAN '2'

using namespace std;

struct FPosition
{
    int r;
    int c;
};

struct FRobotState
{
    FPosition Position;
    int8_t Direction;
};

vector<vector<char>> Mat;

FPosition GetRobotForwardPosition(FRobotState RobotState);
FPosition GetRobotBackwardPosition(FRobotState RobotState);
void MoveRobotForward(FRobotState& RobotState);
void MoveRobotBackward(FRobotState& RobotState);
void TurnRobot(FRobotState& RobotState, int Times = 1);
inline bool IsInRange(const FPosition Position) { return Position.r >= 0 && Position.r < static_cast<int>(Mat.size()) && Position.c >= 0 && Position.c < static_cast<int>(Mat[Position.r].size()); }
inline char GetFloorState(const FPosition Position) { return IsInRange(Position) ? Mat[Position.r][Position.c] : WALL; }
inline void SetFloorState(FPosition& Position, char FloorState) { if(IsInRange(Position)) Mat[Position.r][Position.c] = FloorState; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    FRobotState RobotState;
    cin >> RobotState.Position.r >> RobotState.Position.c >> RobotState.Direction;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(m);
        for(int j = 0; j < m; ++j) cin >> Mat[i][j];
    }

    int CleaningCount = 0;
    while(true)
    {
        switch(GetFloorState(RobotState.Position))
        {
            case DIRTY:
            {
                SetFloorState(RobotState.Position, CLEAN);
                ++CleaningCount;
                break;
            }
            case CLEAN:
            {
                for(int i = 0; i < 4; ++i)
                {
                    TurnRobot(RobotState);
                    if(GetFloorState(GetRobotForwardPosition(RobotState)) == DIRTY)
                    {
                        MoveRobotForward(RobotState);
                        goto ENDSWITCH;
                    }
                }
                if(GetFloorState(GetRobotBackwardPosition(RobotState)) != WALL) MoveRobotBackward(RobotState);
                else goto ENDWHILE;
                break;
            }
            default:
            {
                goto ENDWHILE;
                break;
            }
        }ENDSWITCH:;
    }ENDWHILE:;
    cout << CleaningCount;

    return 0;
}

FPosition GetRobotForwardPosition(FRobotState RobotState)
{
    switch (RobotState.Direction)
    {
    case NORTH:
        RobotState.Position.r -= 1;
        break;
    case EAST:
        RobotState.Position.c += 1;
        break;
    case SOUTH:
        RobotState.Position.r += 1;
        break;
    case WEST: 
        RobotState.Position.c -= 1;
        break;
    default: break;
    }
    return RobotState.Position;
}

FPosition GetRobotBackwardPosition(FRobotState RobotState)
{
    TurnRobot(RobotState, 2);
    return GetRobotForwardPosition(RobotState);
}

void MoveRobotForward(FRobotState &RobotState)
{
    if(IsInRange(GetRobotForwardPosition(RobotState))) 
        RobotState.Position = GetRobotForwardPosition(RobotState);
}

void MoveRobotBackward(FRobotState &RobotState)
{
    if(IsInRange(GetRobotBackwardPosition(RobotState)))
        RobotState.Position = GetRobotBackwardPosition(RobotState);
}

void TurnRobot(FRobotState &RobotState, int Times)
{
    Times = max(min(Times, 4), 0);
    RobotState.Direction = (RobotState.Direction + 4 - Times) % 4;
}
