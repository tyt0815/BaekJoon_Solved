#include <iostream>
#include <vector>
#define MAXLEN 1000
constexpr int NumberLen = MAXLEN * 2;

using namespace std;

inline int Char2Int(char C) { return C - '0'; }

struct FLongNumber
{
public:
    FLongNumber(): Number(vector<int8_t>(NumberLen, '0')), Sign('+') {}

public:
    void InputNumber();
    void SetNumber(string A);
    void PrintNumber();
    inline char GetSign() const { return Sign; }
    inline int GetStartIndex() const
    {
        int i = 0;
        while(Number[i] == '0' && i < Number.size() - 1) ++i;
        return i;
    }
    inline void SetSign(char c) { Sign = c; }
    inline static FLongNumber Sum(FLongNumber A, FLongNumber B) { return SumInternal(A, B); }
    inline static FLongNumber Subtract(FLongNumber A, FLongNumber B) { return SubtractInternal(A, B); }
    inline static FLongNumber Multiply(FLongNumber A, FLongNumber B) { return MultiplyInternal(A, B); }

    int8_t& operator [] (int Index) { return Number[Index]; }

private:
    static FLongNumber SumInternal(FLongNumber &A, FLongNumber &B);
    static FLongNumber SubtractInternal(FLongNumber &A, FLongNumber &B);
    static FLongNumber MultiplyInternal(FLongNumber &A, FLongNumber &B);

    vector<int8_t> Number;
    char Sign;
};

int main()
{
    FLongNumber A, B;
    A.InputNumber();
    B.InputNumber();
    FLongNumber::Sum(A, B).PrintNumber();
    FLongNumber::Subtract(A, B).PrintNumber();
    FLongNumber::Multiply(A, B).PrintNumber();

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
    int i = GetStartIndex();
    if(Number[i] == '0') cout << 0;
    else
    {
        if(Sign == '-') cout << '-';
        for(; i < Number.size(); ++i) cout << Number[i];
    }
    cout << '\n';
}

FLongNumber FLongNumber::SumInternal(FLongNumber &A, FLongNumber &B)
{
    if(A.GetSign() == '-')
    {
        A.SetSign('+');
        return FLongNumber::SubtractInternal(B, A);
    }
    else if(B.GetSign() == '-')
    {
        B.SetSign('+');
        return FLongNumber::SubtractInternal(A, B);
    }
    else
    {
        FLongNumber C;
        for(int i = 0; i < MAXLEN; ++i)
        {
            int Index = NumberLen - 1 - i;
            int Temp = A[Index] - '0' + B[Index] - '0' + C[Index] - '0';
            C[Index] = Temp % 10 + '0';
            C[Index - 1] = Temp / 10 + '0';
        }
        return C;
    }
}

FLongNumber FLongNumber::SubtractInternal(FLongNumber &A, FLongNumber &B)
{
    if(A.GetSign() == '-')
    {
        A.SetSign('+');
        FLongNumber C = FLongNumber::SumInternal(A, B);
        C.GetSign() == '+' ? C.SetSign('-') : C.SetSign('+');
        return C;
    }
    else if(B.GetSign() == '-')
    {
        B.SetSign('+');
        return FLongNumber::SumInternal(A, B);
    }
    else
    {
        FLongNumber C;
        char CSign = '+';
        int a = A.GetStartIndex(), b = B.GetStartIndex();
        FLongNumber *TempA, *TempB;
        if(a > b) CSign = '-';
        else if(a == b)
        {
            while(a < NumberLen)
            {
                if(A[a] < B[a])
                {
                    CSign = '-';
                    break;
                }
                else if(A[a] > B[a]) break;
                ++a;
            }
        }
        if(CSign == '+')
        {
            TempA = &A;
            TempB = &B;
        }
        else
        {
            TempA = &B;
            TempB = &A;
        }
        for(int i = 0; i < MAXLEN; ++i)
        {
            int Index = NumberLen - 1 - i;
            int Temp = (*TempA)[Index] - '0' - ((*TempB)[Index] - '0') + (C[Index] - '0');
            if(Temp >= 0) C[Index] =  Temp + '0';
            else
            {
                C[Index] = 10 + Temp + '0';
                C[Index - 1] = -1 + '0';
            }
        }
        C.SetSign(CSign);
        return C;
    }
}

FLongNumber FLongNumber::MultiplyInternal(FLongNumber &A, FLongNumber &B)
{
    char CSign;
    (A.GetSign() == '+' && B.GetSign() == '+') || (A.GetSign() == '-' && B.GetSign() == '-') ? CSign = '+' : CSign = '-';
    A.SetSign('+');
    B.SetSign('+');
    // 구현
    FLongNumber C;

    for(int i = 0; i < MAXLEN; ++i)
    {
        for(int j = 0 ; j < MAXLEN; ++j)
        {
            int AIndex = NumberLen - 1 - i, BIndex = NumberLen - 1 - j, CIndex = AIndex - j;
            if(CIndex < 0) break;
            int Temp = (A[AIndex] - '0') * (B[BIndex] - '0');
            for(int k = 0; Temp > 0; ++k)
            {
                Temp += C[CIndex - k] - '0';
                C[CIndex - k] = Temp % 10 + '0';
                Temp /= 10;
            }
        }
    }

    C.SetSign(CSign);
    return C;
}