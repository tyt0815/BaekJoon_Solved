#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<int> BlockHeights(w, 0);
    for(int i = 0; i < w; ++i) cin >> BlockHeights[i];

    int Water = 0;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w - 2;)
        {
            if(BlockHeights[j] > i && BlockHeights[j + 1] <= i)
            {
                int k = j + 2;
                for(int k = j + 2; k < w; ++k)
                {
                    if(BlockHeights[k] > i)
                    {
                        Water += k - j - 1;
                        break;
                    }
                }
                j = k;
            }
            else ++j;
        }
    }
    cout << Water;

    return 0;    
}
