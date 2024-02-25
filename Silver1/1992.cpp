#include <iostream>
#include <vector>
#define COMPRESSIONSIZE 8192

using namespace std;

void CompressByQuadTree(const vector<vector<char>>& Img, int x, int y, int Size, char* Compression, int& CprIndex);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<vector<char>> Mat;
    char Compression[COMPRESSIONSIZE];
    cin >> n;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j) cin >> Mat[i][j];
    }

    int i = 0;
    CompressByQuadTree(Mat, 0, 0, n, Compression, i);

    cout << Compression;

    return 0;
}

void CompressByQuadTree(const vector<vector<char>>& Img, int x, int y, int Size, char *Compression, int &CprIndex)
{
    for(int i = 0; i < Size; ++i)
        for(int j = 0; j < Size; ++j)
        {
            if(Img[x][y] != Img[x + i][y + j])
            {
                Compression[CprIndex++] = '(';
                CompressByQuadTree(Img, x, y, Size / 2, Compression, CprIndex);
                CompressByQuadTree(Img, x, y + Size / 2, Size / 2, Compression, CprIndex);
                CompressByQuadTree(Img, x + Size / 2, y, Size / 2, Compression, CprIndex);
                CompressByQuadTree(Img, x + Size / 2, y + Size / 2, Size / 2, Compression, CprIndex);
                Compression[CprIndex++] = ')';
                Compression[CprIndex] = '\0';
                return;
            }
        }
    
    Compression[CprIndex++] = Img[x][y];
    Compression[CprIndex] = '\0';
    return;
}
