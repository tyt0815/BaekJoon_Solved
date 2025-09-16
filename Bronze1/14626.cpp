#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string ISBN;
    std::cin >> ISBN;

    int check_sum = 0;
    int fault_index = 0;
    for(int i = 0; i < ISBN.length(); ++i)
    {
        if(ISBN[i] == '*')
        {
            fault_index = i;
        }
        else
        {
            int n = ISBN[i] - '0';
            if(i % 2 == 0)
            {
                check_sum += n;
            }
            else
            {
                check_sum += 3 * n;
            }
        }
        
    }

    int remainder = check_sum % 10;
    // std::cout << "remainder: " << remainder << std::endl;

    int result;
    if(fault_index % 2 == 0)
    {
        result = (10 - remainder) % 10;
    }
    else
    {
        int x = (10 - remainder) % 10;
        for(int i = 0; i < 10; ++i)
        {
            if((3 * i) % 10 == x)
            {
                result = i;
            }
        }
    }

    std::cout << result;

    return 0;
}