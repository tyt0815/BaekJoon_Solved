#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void CountNumberOfPapers(int r, int c, int Size, const vector<vector<int>>& Mat, int* Count);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> Mat;
    int Count[3] = {0, 0, 0};
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            int m;
            cin >> m;
            Mat[i][j] = m + 1;
        }
    }

    CountNumberOfPapers(0, 0, n, Mat, Count);

    cout << Count[0] << '\n';
    cout << Count[1] << '\n';
    cout << Count[2] << '\n';

    return 0;
}

void CountNumberOfPapers(int r, int c, int Size, const vector<vector<int>>& Mat, int *Count)
{
    int PaperType = Mat[r][c];

    bool bNeedCut = false;
    for(int i = 0; i < Size; ++i)
    {
        for(int j = 0; j < Size; ++j)
        {
            if(Mat[r + i][c + j] != PaperType)
            {
                bNeedCut = true;
                goto EndLoop;
            }
        }
    }
    EndLoop:;
    if(bNeedCut)
    {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                CountNumberOfPapers(r + (Size / 3) * i, c + (Size / 3) * j, Size / 3, Mat, Count);
    }
    else
    {
        ++Count[PaperType];
    }
}
