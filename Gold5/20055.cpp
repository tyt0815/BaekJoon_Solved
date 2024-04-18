#include <iostream>
#include <vector>

using namespace std;

struct FBelt
{
    int Durability = 0;
    bool bEmpty = true;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<FBelt> Belt(2 * N, FBelt());
    for(int i = 0; i < Belt.size(); ++i) cin >> Belt[(i + 1) % Belt.size()].Durability;  // 2N은 Belt[0]

    int Start = 1, Level = 0, Cnt = 0;
    // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
    while(Cnt < K)
    {
        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        Start = (Start - 1 + Belt.size()) % Belt.size();
        int End = (Start + N - 1) % Belt.size();
        Belt[End].bEmpty = true;
        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        
        for(int i = 1; i < N - 1; ++i)
        {
            int Target = (End + Belt.size() - i) % Belt.size(), TargetFront = (Target + 1) % Belt.size();
            if(!Belt[Target].bEmpty && Belt[TargetFront].bEmpty && Belt[TargetFront].Durability > 0)
            {
                Belt[Target].bEmpty = true;
                Belt[TargetFront].bEmpty = false;
                --Belt[TargetFront].Durability;
                if(Belt[TargetFront].Durability == 0) ++Cnt;
            }
        }
        Belt[End].bEmpty = true;
        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if(Belt[Start].Durability > 0)
        {
            Belt[Start].bEmpty = false;
            --Belt[Start].Durability;
            if(Belt[Start].Durability == 0) ++Cnt;
        }
        ++Level;
    }

    cout << Level;

    return 0;
}