#include <iostream>
#include <unordered_map>
#include <algorithm>

bool CanMake(std::string From, std::string To)
{
    if(From.length() == To.length())
    {
        return From == To;
    }
    else
    {
        if(From.back() == 'A')
        {
            std::string Temp = From.substr(0, From.length() - 1);
            
            if(CanMake(Temp, To))
            {
                return true;
            }
        }
        if(From[0] == 'B')
        {
            std::string Temp = From.substr(1, From.length() - 1);
            std::reverse(Temp.begin(), Temp.end());
            return CanMake(Temp, To);
        }
    }

    return false;
}

int main()
{
    std::string S;
    std::string T;
    std::cin >> S >> T;

    std::cout << CanMake(T, S);
    
    return 0;
}