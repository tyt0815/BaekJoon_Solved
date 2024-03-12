#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> TMatrix;

void InputMatrix(TMatrix &Mat);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    TMatrix A(n, vector<char>(m, 0)), B(n, vector<char>(m, 0));
    InputMatrix(A);
    InputMatrix(B);

    if(A == B)
    {
        cout << 0;
        return 0;
    }

    int Count = 0;
    for(int i = 0; i < n - 2; ++i)
    {
        for(int j = 0; j < m - 2; ++j)
        {
            if(A[i][j] != B[i][j])
            {
                ++Count;
                for(int a = 0; a < 3; ++a)
                {
                    for(int b = 0; b < 3; ++b)
                    {
                        A[i + a][j + b] = A[i + a][j + b] == '0' ? '1' : '0';
                    }
                }
            }
            if(A == B)
            {
                cout << Count;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
void InputMatrix(TMatrix &Mat)
{
    for (int i = 0; i < Mat.size(); ++i)
    {
        for (int j = 0; j < Mat[i].size(); ++j)
        {
            cin >> Mat[i][j];
        }
    }
}