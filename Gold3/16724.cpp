#include <iostream>
#include <vector>

using namespace std;

void Move(int i, int j, char Direction, int &a, int &b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> Mat(N, vector<char>(M));
    vector<vector<int>> State(N, vector<int>(M, 0));
    for(vector<char> &Row : Mat) for(char &Element : Row) cin >> Element;

    int Count = 0, RouteNum = 1;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(State[i][j] != 0) continue;
            
            int a = i, b = j;
            int NextA, NextB;
            while(true)
            {
                State[a][b] = RouteNum;
                Move(a, b, Mat[a][b], NextA, NextB);
                if(State[NextA][NextB] != 0) break;
                a = NextA;
                b = NextB;
            }
            if(State[NextA][NextB] == RouteNum) ++Count;
            ++RouteNum;
        }
    }

    cout << Count;

    return 0;
}

void Move(int i, int j, char Direction, int &a, int &b)
{
    a = i;
    b = j;
    if(Direction == 'U') --a;
    else if(Direction == 'D') ++a;
    else if(Direction == 'L') --b;
    else ++b;
}