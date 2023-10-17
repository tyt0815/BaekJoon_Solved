#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t TestCase, n;

    cin >>TestCase;

    for(uint32_t i = 0; i < TestCase; ++i)
    {
        cin >> n;
        map<string, uint32_t> m;
        uint32_t Answer = 1;
        for(uint32_t j = 0; j < n; ++j)
        {
            string ClothName, ClothType;
            cin >> ClothName >> ClothType;
            if(m.find(ClothType) == m.end())
            {
                m[ClothType] = 0;
            }
            m[ClothType] += 1;
        }
        map<string, uint32_t>::iterator It = m.begin();
        for(; It != m.end(); ++It)
        {
            Answer *= ((*It).second + 1);
        }
        Answer -= 1;
        cout << Answer << '\n';
    }

    return 0;
}