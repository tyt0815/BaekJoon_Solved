#include <iostream>
#include <vector>

using namespace std;

class P1509
{
public:
    P1509()
    {
        cin >> TargetString;
        DP = vector<vector<int>>(TargetString.length(), vector<int>(TargetString.length(), 0));
    }

    int Solve()
    {
        return Solve_Internal(0, TargetString.length() - 1);
    }

private:
    int Solve_Internal(const int i, const int j)
    {
        if(DP[i][j] > 0)
        {
            return DP[i][j];
        }
        else if(i == j)
        {
            return DP[i][j] = 1;
        }
        else if(i > j)
        {
            return DP[i][j] = 0;
        }
        else if(TargetString[i] == TargetString[j] && Solve_Internal(i + 1, j - 1) <= 1)
        {
            return DP[i][j] = 1;
        }
        else
        {
            DP[i][j] = j - i + 1;
            
            for(int m = i + 1; m <= j; ++m)
            {
                int Left = Solve_Internal(i, m - 1);
                int Right = Solve_Internal(m, j);

                DP[i][j] = min(DP[i][j], Left + Right);
            }

            return DP[i][j];
        }
    }

    string TargetString;
    vector<vector<int>> DP;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    P1509 Problem;
    cout << Problem.Solve();

    return 0;
}
