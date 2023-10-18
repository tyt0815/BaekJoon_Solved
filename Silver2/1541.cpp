#include <iostream>
#include <string.h>

using namespace std;

long long ToMin(string Expression);
string ExtractNumber(string Expression, uint32_t Offset);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string Expression;
    long long Answer;

    cin >> Expression;
    Answer = ToMin(Expression);

    cout << Answer;

    return 0;
}
    

long long ToMin(string Expression)
{
    long long Number = 0;
    long long ToMinus = 0;
    bool IsNegative = false;
    uint32_t i = 0;
    while (true)
    {
        if(i >= Expression.length()) { return Number - ToMinus; }
        string NumbString = ExtractNumber(Expression, i);
        if(IsNegative)
        {
            ToMinus += stoi(NumbString);
            uint32_t NextIndex = i + NumbString.length();
            if(NextIndex < Expression.length() && Expression[NextIndex] == '-')
            {
                Number -= ToMinus;
                ToMinus = 0;
            }
        }
        else
        {
            Number += stoi(NumbString);
            uint32_t NextIndex = i + NumbString.length();
            if(NextIndex < Expression.length() && Expression[NextIndex] == '-')
            {
                IsNegative = true;
            }
        }

        i += NumbString.length() + 1;
    }
}

string ExtractNumber(string Expression, uint32_t Offset)
{
    uint32_t i = 0;
    while(true)
    {

        if(Offset + i >= Expression.length() || Expression[Offset + i] == '-' || Expression[Offset + i] == '+')
        {
            return Expression.substr(Offset, i);
        }
        ++i;
    }
}