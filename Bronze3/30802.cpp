#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t N, Demands[6], T, P, TShirt;
    std::cin >> N;
    for(int i = 0; i < 6; ++i)
    {
        std::cin >> Demands[i];
    }
    std::cin >> T >> P;

    TShirt = 0;
    for(int64_t Demand : Demands)
    {
        int Temp = Demand / T;
        Temp = Demand % T == 0 ? Temp : Temp + 1;
        TShirt += Temp;
    }

    std::cout << TShirt << '\n' << N / P << ' ' << N % P;

    return 0;
}