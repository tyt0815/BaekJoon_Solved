#include <iostream>
#include <vector>

using namespace std;

struct SPos
{
    int x;
    int y;
};

int MinChickenDist(const int Top, const int Select, vector<int> CurrMinDist, const int& HouseNumb, const int& ChickenNumb, const int& SelectingChickenNumb, const vector<vector<int>>& ChickenDist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<vector<short>> Mat;
    vector<SPos> Houses;
    vector<SPos> Chickens;
    vector<vector<int>> ChickenDist;
    vector<pair<int, vector<int>>> p;
    cin >> n >> m;
    Mat.resize(n);
    for(int i = 0;i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> Mat[i][j];
            if(Mat[i][j] == 1)
            {
                Houses.push_back({i, j});
            }
            else if(Mat[i][j] == 2)
            {
                Chickens.push_back({i, j});
            }
        }
    }
    ChickenDist.resize(Houses.size());
    for(int i = 0; i < ChickenDist.size(); ++i)
    {
        ChickenDist[i].resize(Chickens.size());
        for(int j = 0; j < ChickenDist[i].size(); ++j)
        {
            ChickenDist[i][j] = abs(Houses[i].x - Chickens[j].x) + abs(Houses[i].y - Chickens[j].y);
        }
    }
    int HouseNumb = ChickenDist.size();
    int ChickenNumb = ChickenDist[0].size();
    vector<int> MinHouseToChicken(HouseNumb, INT32_MAX);
    cout << MinChickenDist(0, 0, MinHouseToChicken, HouseNumb, ChickenNumb, m, ChickenDist);

    return 0;
}

int MinChickenDist(const int Top, const int Select, vector<int> CurrMinDist, const int& HouseNumb, const int& ChickenNumb, const int& SelectingChickenNumb, const vector<vector<int>>& ChickenDist)
{
    if(Top == SelectingChickenNumb)
    {
        int Sum = 0;
        for(int i = 0; i < HouseNumb; ++i)
        {
            Sum += CurrMinDist[i];
        }
        return Sum;
    }

    int MinDist = INT32_MAX;
    int k = ChickenNumb - SelectingChickenNumb + Top + 1;
    vector<int> Temp(HouseNumb);
    for(int i = Select; i < k; ++i)
    {
        for(int j = 0; j < HouseNumb; ++j)
        {
            Temp[j] = min(CurrMinDist[j], ChickenDist[j][i]);
        }
        MinDist = min(MinDist, MinChickenDist(Top + 1, i + 1, Temp, HouseNumb, ChickenNumb, SelectingChickenNumb, ChickenDist));
    }
    return MinDist;
}
