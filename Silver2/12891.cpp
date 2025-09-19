#include <iostream>

enum
{
    A = 0, C = 1, G = 2, T = 3
};

int EvaluateDNAChar(char c)
{
    switch (c)
    {
    case 'A': return A;
    case 'C': return C;
    case 'G': return G;
    case 'T': return T;
    default: throw;
    }
}

bool IsValidDNAStr(int* Counting, int* Condition)
{
    return Counting[0] >= Condition[0]
        && Counting[1] >= Condition[1]
        && Counting[2] >= Condition[2]
        && Counting[3] >= Condition[3];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int S;      // 임의로 만든 DNA 문자열 길이
    int P;      // 부분 문자열 길이
    std::cin >> S >> P;

    std::string DNAString;
    std::cin >> DNAString;

    int Condition[4] = {0, 0, 0, 0};
    std::cin >> Condition[A] >> Condition[C] >> Condition[G] >> Condition[T];

    int Counting[4] = {0, 0, 0, 0};
    for(int i = 0; i < P; ++i)
    {
        ++Counting[EvaluateDNAChar(DNAString[i])];
    }
    int Count = IsValidDNAStr(Counting, Condition) ? 1 : 0;

    for(int i = 1; i + P <= S; ++i)
    {
        ++Counting[EvaluateDNAChar(DNAString[i + P - 1])];
        --Counting[EvaluateDNAChar(DNAString[i - 1])];

        if(IsValidDNAStr(Counting, Condition))
        {
            ++Count;
        }
    }

    std::cout << Count;

    return 0;
}