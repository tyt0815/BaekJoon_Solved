#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void DrawStar11(int n, int h);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        DrawStar11(n, i);
        for(int j = 0; j < n - i; ++j) 
            cout << ' ';
        if(i != n - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}

void DrawStar11(int n, int h)
{
    
    if(n == 1)
    {
        if(h == 0)
        {
            cout << "*";
        }
        else if(h == 1)
        {
            cout << "* *";
        }
        else if(h == 2)
        {
            cout << "*****";
        }
        return;
    }
    
    int Blank;
    if(h < 3)
    {
        Blank = n - h - 1;
        for(int i = 0; i < Blank; ++i)
        {
            cout << ' ';
        }
        DrawStar11(1, h);
        return;
    }

    int k = log2(h / 3);
    int NextN = 3 * pow(2, k);
    int NextH = h - 3 * pow(2, k);
    Blank = n - NextN * 2;
    for(int i = 0; i < Blank; ++i)
    {
        cout << ' ';
    }
    DrawStar11(NextN, NextH);
    int pow2k = pow(2, k);
    Blank = 6 * pow2k - 1;
    Blank /= 2;
    Blank -= (NextH - 1);
    for(int i = 0; i < Blank; ++i)
    {
        cout << ' ';
    }
    DrawStar11(NextN, NextH);
}