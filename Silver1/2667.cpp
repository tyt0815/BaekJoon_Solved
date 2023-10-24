#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Postion
{
    int x;
    int y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<vector<char>> Mat;
    priority_queue<int, vector<int>, greater<int>> Answer;

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
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(Mat[i][j] == '1')
            {
                int Cnt = 0;
                Mat[i][j] = '0';
                queue<Postion> q;
                Postion Pos;
                Pos.x = i; Pos.y = j;
                q.push(Pos);
                while(!q.empty())
                {
                    ++Cnt;
                    Pos = q.front();
                    q.pop();
                    Postion Temp;
                    for(int k = -1; k < 2; k +=2)
                    {
                        Temp.x = Pos.x + k; Temp.y = Pos.y;
                        if(Temp.x > -1 && Temp.x < n && Mat[Temp.x][Temp.y] == '1')
                        {
                            Mat[Temp.x][Temp.y] = '0';
                            q.push(Temp);
                        }
                    }
                    for(int k = -1; k < 2; k +=2)
                    {
                        Temp.x = Pos.x; Temp.y = Pos.y + k;
                        if(Temp.y > -1 && Temp.y < n && Mat[Temp.x][Temp.y] == '1')
                        {
                            Mat[Temp.x][Temp.y] = '0';
                            q.push(Temp);
                        }
                    }
                }
                Answer.push(Cnt);
            }
        }
    }

    int Size = Answer.size();
    cout << Size << '\n';
    for(int i = 0; i < Size; ++i)
    {
        cout << Answer.top() << '\n';
        Answer.pop();
    }

    return 0;
}