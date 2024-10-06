#include <iostream>
#include <string>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << A + B - C << '\n';
    std::cout << atoi(std::to_string(A).append(std::to_string(B)).c_str()) - C;    
    return 0;
}