#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string FizzBuzz[4];
    int N, Offset = 0;
    std::cin >> FizzBuzz[0] >> FizzBuzz[1] >> FizzBuzz[2];

    for(int i = 0; i < 3; ++i)
    {
        if(FizzBuzz[i] != "Fizz" && FizzBuzz[i] != "Buzz" && FizzBuzz[i] != "FizzBuzz")
        {
            N = atoi(FizzBuzz[i].c_str());
            Offset = 3 - i;
            break;
        }
    }

    N += Offset;
    if(N % 3 == 0 && N % 5 == 0)
    {
        FizzBuzz[3] = "FizzBuzz";
    }
    else if(N % 3 == 0)
    {
        FizzBuzz[3] = "Fizz";
    }
    else if(N % 5 == 0)
    {
        FizzBuzz[3] = "Buzz";
    }
    else
    {
        FizzBuzz[3] = std::to_string(N);
    }

    std::cout << FizzBuzz[3];

}