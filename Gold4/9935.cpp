#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Str;
    string Bomb;
    cin >> Str >> Bomb;
    string Result;
    Result.resize(Str.length() + 1);

    for(int i = 0, j = i; i < Str.length(); ++i, ++j)
    {
        Result[j] = Str[i];

        if(j >= Bomb.length() - 1)
        {
            bool IsBoom = true;
            for(int k = 0; k < Bomb.length(); ++k)
            {
                if(Bomb[k] != Result[j - Bomb.length() + k + 1])
                {
                    IsBoom = false;
                    break;
                }
            }
            if(IsBoom)
            {
                j = j - Bomb.length();
            }
        }
        Result[j + 1] = '\0';
    }

    if(Result[0] == '\0')
    {
        cout << "FRULA";
    }
    else
    {
        for(int i = 0; Result[i] != '\0'; ++i)
        {
            cout << Result[i];
        }
    }

    return 0;
}