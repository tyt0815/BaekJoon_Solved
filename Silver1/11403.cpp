#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    vector<vector<int>> Mat;

    cin >> n;
    Mat.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Mat[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> Mat[i][j];
        }
    }
    
    // for(int a = 0; a < n; ++a)
    // {
    //     bool NoChage = true;
    //     for(int i = 0; i < n; ++i)
    //     {
    //         for(int j = 0; j < n; ++j)
    //         {
    //             for(int k = 0; k < n; ++k)
    //             {
    //                 if(Mat[i][j] == 1 && Mat[j][k] == 1 && Mat[i][k] != 1)
    //                 {
    //                     Mat[i][k] = 1;
    //                     NoChage = false;
    //                 }
    //             }
    //         }
    //     }
    //     if(NoChage)
    //     {
    //         break;
    //     }
    // }

    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(Mat[i][k] == 1 && Mat[k][j] == 1)
                {
                    Mat[i][j] = 1;
                }
            }
        }
    }
    

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << Mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}