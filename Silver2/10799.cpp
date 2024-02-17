#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Parens;
    cin >> Parens;
    int TotalSticks = 1, Stick = 1;
    for(int i = 1; i < Parens.length(); ++i)
    {
        char Curr = Parens[i], Pre = Parens[i - 1];
        if(Curr == '(')
        {
            ++TotalSticks;
            ++Stick;
        }
        else if(Curr == ')')
        {
            // 레이저
            if(Pre == '(')
            {
                --TotalSticks;
                --Stick;
                TotalSticks += Stick;
            }
            else
            {
                --Stick;
            }
        }
        else break;
        Pre = Curr;
    }

    cout << TotalSticks;

    return 0;
}