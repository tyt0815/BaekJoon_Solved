#include <iostream>

using namespace std;

int main()
{
    int *table = new int[10];
    int i, a, b, c, result;

    for(i = 0; i < 10; ++i)
    {
        table[i] = 0;
    }

    cin >> a >> b >> c;

    result = a * b * c;

    string s = to_string(result);
    int l = s.length();

    for(i = 0; i < l; ++i)
    {
        ++table[s[i] - '0'];
    }
    for(i = 0; i < 10; ++i)
    {
        cout << table[i] << endl;
    }

    return 0;
}