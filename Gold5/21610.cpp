#include <iostream>
#include <vector>

using namespace std;

pair<int, int> Directions[] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
pair<int, int> Diagonal[] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> Buckets(N, vector<int>(N, 0));
    for(auto &Rows : Buckets)
    {
        for(auto &Bucket : Rows) cin >> Bucket;
    }
    vector<pair<int, int>> Clouds(4);
    Clouds[0] = {N - 1, 0};
    Clouds[1] = {N - 1, 1};
    Clouds[2] = {N - 2, 0};
    Clouds[3] = {N - 2, 1};

    for(int i = 0; i < M; ++i)
    {
        int D, S;
        cin >> D >> S;
        vector<vector<bool>> bRained(N, vector<bool>(N, false));
        for(auto &Cloud : Clouds)
        {
            // 1. 모든 구름이 di 방향으로 si칸 이동한다.
            Cloud = {(Cloud.first + Directions[D].first * S + N * 25) % N, (Cloud.second + Directions[D].second * S + N * 25) % N};
            // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
            Buckets[Cloud.first][Cloud.second] += 1;
            bRained[Cloud.first][Cloud.second] = true;
        }   // 3. 구름이 모두 사라진다.
        for(auto &Cloud : Clouds)
        {
            // 4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 
            // 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
            // 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
            int CopyAmount = 0;
            for(int j = 0; j < 4; ++j)
            {
                int X = Cloud.first + Diagonal[j].first, Y = Cloud.second + Diagonal[j].second;
                if(X >= 0 && X < N && Y >= 0 && Y < N && Buckets[X][Y] > 0) ++CopyAmount;
            }
            Buckets[Cloud.first][Cloud.second] += CopyAmount;
        }
        // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
        Clouds.clear();
        for(int x = 0; x < N; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                if(!bRained[x][y] && Buckets[x][y] > 1)
                {
                    Buckets[x][y] -= 2;
                    Clouds.push_back({x, y});
                }
            }
        }
    }
    int Amount = 0;
    for(auto & Rows : Buckets)
    {
        for(auto &Bucket : Rows)
        {
            Amount += Bucket;
        }
    }
    cout << Amount;

    return 0;
}