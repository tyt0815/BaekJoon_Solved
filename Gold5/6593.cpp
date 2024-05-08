#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct FVector
{
    int X;
    int Y;
    int Z;
};

FVector SixDirection[] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { -1, 0, 0 }, { 0, -1, 0 }, { 0, 0, -1 } };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        FVector BuildingSize, StartPosition;
        cin >> BuildingSize.X >> BuildingSize.Y >> BuildingSize.Z;
        if(BuildingSize.X == 0 && BuildingSize.Y == 0 && BuildingSize.Z == 0) break;
        vector<vector<vector<char>>> Building(BuildingSize.X, vector<vector<char>>(BuildingSize.Y, vector<char>(BuildingSize.Z, ' ')));
        for(int i = 0; i < BuildingSize.X; ++i)
        {
            for(int j = 0; j < BuildingSize.Y; ++j)
            {
                for(int k = 0; k < BuildingSize.Z; ++k)
                {
                    cin >> Building[i][j][k];
                    if(Building[i][j][k] == 'S') StartPosition = {i, j, k};
                }
            }
        }

        queue<pair<FVector, int>> q;
        q.push({StartPosition, 0});
        vector<vector<vector<bool>>> bVisited(BuildingSize.X, vector<vector<bool>>(BuildingSize.Y, vector<bool>(BuildingSize.Z, false)));
        bVisited[StartPosition.X][StartPosition.Y][StartPosition.Z] = true;
        bool bEscaped = false;
        int ElapsedTime = 0;
        while(!q.empty())
        {
            FVector Pos = q.front().first;
            int Time = q.front().second;
            q.pop();
            for(int i = 0; i < 6; ++i)
            {
                FVector Next = {Pos.X + SixDirection[i].X, Pos.Y + SixDirection[i].Y, Pos.Z + SixDirection[i].Z};
                if(Next.X < 0 || Next.X >= bVisited.size() ||
                 Next.Y < 0 || Next.Y >= bVisited[Next.X].size() ||
                 Next.Z < 0 || Next.Z >= bVisited[Next.X][Next.Y].size() ||
                 bVisited[Next.X][Next.Y][Next.Z] || Building[Next.X][Next.Y][Next.Z] == '#'
                )
                {
                    continue;
                }
                if(Building[Next.X][Next.Y][Next.Z] == 'E')
                {
                    ElapsedTime = Time + 1;
                    bEscaped = true;
                    goto EndWhile;
                }
                bVisited[Next.X][Next.Y][Next.Z] = true;
                q.push({Next, Time + 1});
            }
        }
        EndWhile:;
        if(bEscaped) cout << "Escaped in "<< ElapsedTime << " minute(s).";
        else cout << "Trapped!";
        cout << '\n';
    }

    return 0;
}