#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct FPosition
{
    int X;
    int Y;
};

class P9328
{
public:
    P9328()
    {
        cin >> h >> w;
        Map = vector<vector<char>>(h, vector<char>(w));
        for(vector<char>& Row : Map)
        {
            for(char& Value : Row)
            {
                cin >> Value;
            }
        }

        string KeyString;
        cin >> KeyString;
        if(KeyString != "0")
        {
            for(int i = 0; i < KeyString.length(); ++i)
            {
                Keys.insert(KeyString[i]);
            }
        }
    }

    int Solve()
    {
        // 입구 찾기
        for(int i = 0; i < h; ++i)
        {
            SmartEnqueuePosition({i, 0});
            SmartEnqueuePosition({i, w - 1});
        }
        for(int j = 0; j < w; ++j)
        {
            SmartEnqueuePosition({0, j});
            SmartEnqueuePosition({h - 1, j});
        }

        while(!ExplorePositionQueue.empty())
        {
            FPosition CurrentPos = ExplorePositionQueue.front();
            ExplorePositionQueue.pop();
            int X = CurrentPos.X;
            int Y = CurrentPos.Y;
            SmartEnqueuePosition({X + 1, Y});
            SmartEnqueuePosition({X - 1, Y});
            SmartEnqueuePosition({X, Y+ 1});
            SmartEnqueuePosition({X, Y - 1});
        }

        return Count;
    }
    
private:
    void SmartEnqueuePosition(FPosition Position)
    {
        if(Position.X < 0 || Position.X >= h || Position.Y < 0 || Position.Y >= w)
        {
            return;
        }

        char& Value = Map[Position.X][Position.Y];

        if(Value == '*')
        {
            return;
        }
        else if(Value == '$')
        {
            ++Count;
            Value = '.';
        }
        else if('a' <= Value && Value <= 'z')
        {
            Keys.insert(Value);
            char TargetDoor = toupper(Value);

            for(const FPosition& DoorPos : LockedDoors[TargetDoor])
            {
                Map[DoorPos.X][DoorPos.Y] = '*';
                ExplorePositionQueue.push(DoorPos);
            }

            LockedDoors[TargetDoor].clear();

            Value = '.';
        }
        else if('A' <= Value && Value <= 'Z')
        {
            char TargetKey = tolower(Value);
            if(Keys.find(TargetKey) == Keys.end())
            {
                LockedDoors[Value].push_back(Position);
            }
            else
            {
                Value = '.';
            }
        }

        if(Value == '.')
        {
            Value = '*';
            ExplorePositionQueue.push(Position);
        }
    }

    vector<vector<char>> Map;
    unordered_set<char> Keys;
    unordered_map<char, vector<FPosition>> LockedDoors;
    queue<FPosition> ExplorePositionQueue;
    int h;
    int w;
    int Count = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--)
    {
        P9328 Problem;

        cout << Problem.Solve() << '\n';
    }

    return 0;
}