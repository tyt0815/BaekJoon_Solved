#include <iostream>
#include <vector>

int main()
{
    std::string A;
    std::string B;
    std::string C;
    std::cin >> A >> B >> C;
    A.insert(A.begin(), ' ');
    B.insert(B.begin(), ' ');
    C.insert(C.begin(), ' ');

    std::vector<std::vector<std::vector<int>>> DP(A.length(), std::vector<std::vector<int>>(B.length(), std::vector<int>(C.length(), 0)));
    
    for(int i = 1; i < DP.size(); ++i)
    {
        const char& a = A[i];
        for(int j = 1; j < DP[i].size(); ++j)
        {
            const char& b = B[j];
            for(int k = 1; k < DP[i][j].size(); ++k)
            {
                const char& c = C[k];
                DP[i][j][k] = std::max(DP[i - 1][j][k], std::max(DP[i][j - 1][k], DP[i][j][k - 1]));
                if(a == b && b == c)
                {
                    DP[i][j][k] = std::max(DP[i][j][k], DP[i - 1][j - 1][k - 1] + 1);
                }
            }
        }
    }

    std::cout << DP.back().back().back();

    return 0;
}