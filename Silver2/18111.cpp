#include <iostream>

using namespace std;

struct BlockInfo
{
    uint64_t Height;
    uint64_t Num;
};

void CountBlockNum(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block);
void RemoveBlock(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block, uint64_t& WorkingTime, uint64_t& b);
void StackBlock(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block, uint64_t& WorkingTime, uint64_t& b);

int main()
{
    uint64_t n, m, b;
    uint64_t WorkingTime = 0;
    uint64_t **HomeGround;

    BlockInfo Tallest, Smallest;
    Tallest.Height = 0; Tallest.Num = 0;
    Smallest.Height = UINT32_MAX; Smallest.Num = 0;

    cin >> n >> m >> b;
    HomeGround = new uint64_t*[n];
    for(int i = 0; i < n; ++i)
    {
        HomeGround[i] = new uint64_t[m];
        for(int j = 0; j < m; ++j)
        {
            cin >> HomeGround[i][j];
            if(Tallest.Height < HomeGround[i][j])
            {
                Tallest.Height = HomeGround[i][j];
                Tallest.Num = 1;
            }
            else if(Tallest.Height == HomeGround[i][j])
            {
                ++Tallest.Num;
            }
            if(Smallest.Height > HomeGround[i][j])
            {
                Smallest.Height = HomeGround[i][j];
                Smallest.Num = 1;
            }
            else if(Smallest.Height == HomeGround[i][j])
            {
                ++Smallest.Num;
            }
        }
    }

    while(true)
    {
        if(Smallest.Height == Tallest.Height) { break; }
        if(Smallest.Num > b || (Smallest.Num <= b && Smallest.Num > Tallest.Num * 2))
        {
            RemoveBlock(HomeGround, n, m, Tallest, WorkingTime, b);
        }
        else
        {
            StackBlock(HomeGround, n, m, Smallest, WorkingTime, b);
        }
    }

    cout << WorkingTime << " " << Tallest.Height;

    return 0;
}

void CountBlockNum(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block)
{
    Block.Num = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(HomeGround[i][j] == Block.Height)
            {
                ++Block.Num;
            }
        }
    }
}

void RemoveBlock(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block, uint64_t& WorkingTime, uint64_t& b)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(HomeGround[i][j] == Block.Height)
            {
                --HomeGround[i][j];
                WorkingTime += 2;
                ++b;
            }
        }
    }
    --Block.Height;
    CountBlockNum(HomeGround, n, m, Block);
}

void StackBlock(uint64_t** HomeGround, uint64_t n, uint64_t m, BlockInfo& Block, uint64_t& WorkingTime, uint64_t& b)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(HomeGround[i][j] == Block.Height)
            {
                ++HomeGround[i][j];
                WorkingTime += 1;
                --b;
            }
        }
    }
    ++Block.Height;
    CountBlockNum(HomeGround, n, m, Block);
}