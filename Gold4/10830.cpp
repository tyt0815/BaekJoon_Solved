#include <iostream>
#include <vector>

using namespace std;

vector<vector<uint64_t>> MatPowMod(vector<vector<uint64_t>> Mat, uint64_t x);
vector<vector<uint64_t>> MatMulMod(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t n, b;
    cin >> n >> b;
    vector<vector<uint64_t>> A;
    A.resize(n);
    for(uint64_t i = 0; i < n; ++i)
    {
        A[i].resize(n);
        for(uint64_t j = 0 ; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }
    
    vector<vector<uint64_t>> Result;
    Result = MatPowMod(A, b);
    for(uint64_t i = 0; i < n; ++i)
    {
        for(uint64_t j = 0 ; j < n; ++j)
        {
            cout << Result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

vector<vector<uint64_t>> MatPowMod(vector<vector<uint64_t>> Mat, uint64_t x)
{
    if(x == 1)
    {
        int n = Mat.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                Mat[i][j] %= 1000;
            }
        }
        return Mat;
    }

    if(x % 2 == 0)
    {
        return MatPowMod(MatMulMod(Mat, Mat), x / 2);
    }
    else
    {
        return MatMulMod(MatPowMod(MatMulMod(Mat, Mat), x / 2), Mat);
    }
}

vector<vector<uint64_t>> MatMulMod(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B)
{
    vector<vector<uint64_t>> Result;
    int n = A.size();

    Result.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Result[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            Result[i][j] = 0;
            for(int k = 0; k < n; ++k)
            {
                Result[i][j] += A[i][k] * B[k][j];
            }
            Result[i][j] %= 1000;
        }
    }

    return Result;
}
