#include <iostream>

using namespace std;

void CheckColor(uint32_t Start, uint32_t Width);

int n;
uint32_t White = 0, Blue = 0;
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

    CheckColor(0, n);
    

    for(int i = 0; i < n; ++i)
    {
        delete[] Mat[i];
    }
    delete[] Mat;
    return 0;
}

void CheckColor(uint32_t Start, uint32_t Width)
{

}