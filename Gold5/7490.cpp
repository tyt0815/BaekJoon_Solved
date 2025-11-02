#include <iostream>
#include <vector>

using namespace std;

void PrintIfEquationEqualsZero(vector<char>& Equation, int i)
{
    if(Equation.size() > i)
    {
        Equation[i] = ' ';
        PrintIfEquationEqualsZero(Equation, i + 2);
        Equation[i] = '+';
        PrintIfEquationEqualsZero(Equation, i + 2);
        Equation[i] = '-';
        PrintIfEquationEqualsZero(Equation, i + 2);
    }
    else
    {
        int Sum = Equation[0] - '0';
        int j = 1;
        while(j < i && Equation[j] == ' ')
        {
            Sum = Sum * 10 + Equation[j + 1] - '0';
            j += 2;
        }

        while(j < i)
        {
            int Right = Equation[j + 1] - '0';
            int k = j;
            j += 2;
            while(j < i && Equation[j] == ' ')
            {
                Right = Right * 10 + Equation[j + 1] - '0';
                j += 2;
            }

            if(Equation[k] == '+')
            {
                Sum += Right;
            }
            else
            {
                Sum -= Right;
            }
        }

        if(Sum == 0)
        {
            for(int j = 0; j < Equation.size(); ++j)
            {
                cout << Equation[j];
            }
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;      // 테스트 케이스의 개수(<10)
    cin >> T;
    while(T--)
    {
        int N;      // 자연수 N
        cin >> N;

        vector<char> Equation(2 * N - 1);      // = 0 을 만족하는 수식
        for(int i = 0; i < N; ++i)
        {
            Equation[i * 2] = i + 1 + '0';
        }
        PrintIfEquationEqualsZero(Equation, 1);
        cout << '\n';
    }

    return 0;
}