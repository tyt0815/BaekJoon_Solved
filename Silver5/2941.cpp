#include <iostream>

int main()
{
    std::string Alphabet;
    std::cin >> Alphabet;

    int Count = 0;
    for(int i = 0; i < Alphabet.length(); ++i)
    {
        std::string Two = Alphabet.substr(i, 2);
        std::string Three = Alphabet.substr(i, 3);

        if(Two == "c=")
        {
            ++Count;
            ++i;
        }
        else if(Two == "c-") 
        {
            ++Count;
            ++i;
        }
        else if(Two == "d-") 
        {
            ++Count;
            ++i;
        }
        else if(Two == "lj") 
        {
            ++Count;
            ++i;
        }
        else if(Two == "nj") 
        {
            ++Count;
            ++i;
        }
        else if(Two == "s=") 
        {
            ++Count;
            ++i;
        }
        else if(Two == "z=") 
        {
            ++Count;
            ++i;
        }
        else if(Three == "dz=") 
        {
            ++Count;
            i += 2;
        }
        else
        {
            ++Count;
        }
    }

    std::cout << Count;

    return 0;
}