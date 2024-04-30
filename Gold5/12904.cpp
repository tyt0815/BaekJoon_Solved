#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int Start = 0, End = T.length() - 1;
    bool bReverse = false;
    while(abs(End - Start) > S.length() - 1)
    {
        if(T[End] == 'A')
        {
            End = bReverse ? End + 1 : End - 1;
        }
        else
        {
            End = bReverse ? End + 1 : End - 1;
            bReverse = bReverse ? false : true;
            swap(Start, End);
        }
    }
    int a = Start < End ? 1 : -1, Target = abs(End - Start) + 1;
    for(int i = 0; i < Target; ++i)
    {
        if(S[i] != T[Start + (i * a)])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}