#include <iostream>

using namespace std;

void CheckColor(uint32_t StartI, uint32_t StartJ, uint32_t Width);

int n;
uint32_t ColorCnt[2] = {0, 0};
short int** Mat;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    Mat = new short int*[n];
    for(int i = 0; i < n; ++i)
    {
        Mat[i] = new short int[n];
        for(int j = 0; j < n; ++j)
        {
            cin >> Mat[i][j];
        }
    }

    CheckColor(0, 0, n);

    cout << ColorCnt[0] << '\n' << ColorCnt[1];

    for(int i = 0; i < n; ++i)
    {
        delete[] Mat[i];
    }
    delete[] Mat;
    return 0;
}

void CheckColor(uint32_t StartI, uint32_t StartJ, uint32_t Width)
{
    short int Color = Mat[StartI][StartJ];
    for(uint32_t i = StartI; i < StartI + Width; ++i)
    {
        for(uint32_t j = StartJ; j < StartJ + Width; ++j)
        {
            if(Color != Mat[i][j])
            {
                CheckColor(StartI, StartJ, Width/2);
                CheckColor(StartI + Width/2, StartJ, Width/2);
                CheckColor(StartI, StartJ + Width/2, Width/2);
                CheckColor(StartI + Width/2, StartJ + Width/2, Width/2);
                return;
            }
        }
    }
    ++ColorCnt[Color];
}