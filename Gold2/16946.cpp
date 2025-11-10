#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P16946
{
public:
    P16946()
    {
        cin >> N >> M;
        Map.resize(N);
        for(string& Row : Map)
        {
            cin >> Row;
        }
    }

    void Solve()
    {
        Area = vector<vector<int>>(N, vector<int>(M, 0));
        Count = vector<int>(1, 0);

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                if(Map[i][j] == '1' || Area[i][j] != 0)
                {
                    continue;
                }

                Count.push_back(0);
                DFS(i, j, Count.size() - 1);
            }
        }

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                if(Map[i][j] == '0')
                {
                    cout << 0;
                }
                else
                {
                    int Sum = 1;
                    vector<int> VisitTable;
                    if(i - 1 >= 0)
                    {
                        Sum += Count[Area[i - 1][j]];
                        VisitTable.push_back(Area[i - 1][j]);
                    }
                    if(i + 1 < N && find(VisitTable.begin(), VisitTable.end(), Area[i + 1][j]) == VisitTable.end())
                    {
                        Sum += Count[Area[i + 1][j]];
                        VisitTable.push_back(Area[i + 1][j]);
                    }
                    if(j - 1 >= 0 && find(VisitTable.begin(), VisitTable.end(), Area[i][j - 1]) == VisitTable.end())
                    {
                        Sum += Count[Area[i][j - 1]];
                        VisitTable.push_back(Area[i][j - 1]);
                    }
                    if(j + 1 < M && find(VisitTable.begin(), VisitTable.end(), Area[i][j + 1]) == VisitTable.end())
                    {
                        Sum += Count[Area[i][j + 1]];
                        VisitTable.push_back(Area[i][j + 1]);
                    }
                    
                    cout << (Sum % 10);
                }
            }
            cout << '\n';
        }
    }

private:
    void DFS(int i, int j, int AreaNumber)
    {
        if(i < 0 || i >= N || j < 0 || j >= M || Map[i][j] == '1' || Area[i][j] != 0)
        {
            return;
        }

        Area[i][j] = AreaNumber;
        ++Count[AreaNumber];

        DFS(i + 1, j, AreaNumber);
        DFS(i - 1, j, AreaNumber);
        DFS(i, j + 1, AreaNumber);
        DFS(i, j - 1, AreaNumber);
    }

    void PrintArea() const
    {
        for(const vector<int>& Row : Area)
        {
            for(const int Value : Row)
            {
                cout << Value;
            }
            cout << endl;
        }
    }

    int N;
    int M;
    vector<string> Map;
    vector<vector<int>> Area;
    vector<int> Count;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    P16946 Problem;
    Problem.Solve();

    return 0;
}