#include <iostream>
#include <vector>
#define MAXLEN 1000

using namespace std;

inline int Char2Int(char C) { return C - '0'; }

struct FLongNumber
{
public:
    FLongNumber(int MaxSize)
    {
        Number = vector<char>(MaxSize);
    }

public:
    void InputNumber();
    void SetNumber(string A);
    void PrintNumber();
    inline char GetSign() const { return Sign; }
    inline char SetSign(char c) { Sign = c; }
    inline static void Sum(FLongNumber A, FLongNumber B, FLongNumber &C) { SumInternal(A, B, C); }
    inline static void Subtract(FLongNumber A, FLongNumber B, FLongNumber &C) { SubtractInternal(A, B, C); }
    inline static void Multiply(FLongNumber A, FLongNumber B, FLongNumber &C) { MultiplyInternal(A, B, C); }

private:
    static void SumInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C);
    static void SubtractInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C);
    static void MultiplyInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C);

    vector<char> Number;
    int StartIndex;
    char Sign;
};

int main()
{
    FLongNumber A(MAXLEN), B(MAXLEN), C(MAXLEN * MAXLEN);
    A.InputNumber();
    B.InputNumber();
    FLongNumber::Sum(A, B, C);
    C.PrintNumber();
    FLongNumber::Subtract(A, B, C);
    C.PrintNumber();
    FLongNumber::Multiply(A, B, C);
    C.PrintNumber();

    return 0;
}

void FLongNumber::InputNumber()
{
    string Temp;
    cin >> Temp;
    SetNumber(Temp);
}

void FLongNumber::SetNumber(string A)
{
    int i = 0;
    if(A[0] == '-')
    {
        Sign = '-';
        ++i;
    }
    else Sign = '+';
    for(; i < A.length(); ++i)
    {
        Number[Number.size() - A.length() + i] = A[i];
    }
}

void FLongNumber::PrintNumber()
{
    if(Sign == '-') cout << '-';
    for(int i = StartIndex; i < Number.size(); ++i) cout << Number[i];
    cout << '\n';
}

void FLongNumber::SumInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C)
{
    if(A.GetSign() == '-')
    {
        A.SetSign('+');
        FLongNumber::SubtractInternal(B, A, C);
        return;
    }
    else if(B.GetSign() == '-')
    {
        B.SetSign('+');
        FLongNumber::SubtractInternal(A, B, C);
        return;
    }
    else
    {

    }
}

void FLongNumber::SubtractInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C)
{
    if(A.GetSign() == '-')
    {
        A.SetSign('+');
        FLongNumber::SumInternal(A, B, C);
        C.GetSign() == '+' ? C.SetSign('-') ? C.SetSign('+');
        return;
    }
    else if(B.GetSign() == '-')
    {
        B.SetSign('+');
        FLongNumber::SumInternal(A, B, C);
        return;
    }
    else
    {

    }
}

void FLongNumber::MultiplyInternal(FLongNumber &A, FLongNumber &B, FLongNumber &C)
{
    char CSign;
    (A.GetSign() == '+' && B.GetSign() == '+') || (A.GetSign() == '-' && B.GetSign() == '-') ? CSign = '+' : CSign = '-';
    A.SetSign('+');
    B.SetSign('+');
    // 구현


    C.SetSign(CSign);
}
