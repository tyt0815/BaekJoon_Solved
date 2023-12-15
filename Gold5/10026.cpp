#include <iostream>
#include <queue>
#include <vector>
#define POSDEBUG(Pos) cout << Pos.x << ' ' << Pos.y << '\n';
#define TWODIMVEC(v, Pos) v[Pos.x][Pos.y]

using namespace std;

struct Pos
{
    int x;
    int y;
};

int n;

int f(vector<vector<char> > Section);

int main()
{
    vector<vector<char> > NormalEyes;
    vector<vector<char> > AbnormalEyes;
    cin >> n;
    NormalEyes.resize(n);
    AbnormalEyes.resize(n);
    for(int i = 0; i < n; ++i)
    {
        NormalEyes[i].resize(n);
        AbnormalEyes[i].resize(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> NormalEyes[i][j];
            AbnormalEyes[i][j] = NormalEyes[i][j];
            if(AbnormalEyes[i][j] == 'G')
            {
                AbnormalEyes[i][j] = 'R';
            }
        }
    }

    cout << f(NormalEyes) << ' ' << f(AbnormalEyes);

    return 0;
}

int f(vector<vector<char> > Section)
{
    queue<Pos> Curr, Next;
    Pos CurrPos = {0, 0};
    char CurrColor;
    int SectionCnt = 0;
    
    Next.push(CurrPos);
    while(!Next.empty())
    {
        CurrPos = Next.front();
        Next.pop();
        if(TWODIMVEC(Section, CurrPos) != '0')
        {
            ++SectionCnt;
            CurrColor = TWODIMVEC(Section, CurrPos);
            TWODIMVEC(Section, CurrPos) = '0';
            Curr.push(CurrPos);
            while(!Curr.empty())
            {
                CurrPos = Curr.front();
                Curr.pop();
                for(int i = -1; i < 2; ++i)
                {
                    Pos Temp;
                    Temp.x = CurrPos.x + i;
                    Temp.y = CurrPos.y;
                    if(Temp.x > -1 && Temp.x < n && TWODIMVEC(Section, Temp) != '0')
                    {
                        if(TWODIMVEC(Section, Temp) == CurrColor)
                        {
                            Curr.push(Temp);
                            TWODIMVEC(Section, Temp) = '0';
                        }
                        else
                        {
                            Next.push(Temp);
                        }
                    }
                    Temp.x = CurrPos.x;
                    Temp.y = CurrPos.y + i;
                    if(Temp.y > -1 && Temp.y < n && TWODIMVEC(Section, Temp) != '0')
                    {
                        if(TWODIMVEC(Section, Temp) == CurrColor)
                        {
                            Curr.push(Temp);
                            TWODIMVEC(Section, Temp) = '0';
                        }
                        else
                        {
                            Next.push(Temp);
                        }
                    }
                }
            }
        }
    }

    return SectionCnt;
}