#include <iostream>

using namespace std;

int main()
{   
    int n, i, j, k, iter;
    string s;
    cin >> n;
    for(i = 0; i < n; ++i)
    {
        cin >> iter >> s;
        for(j = 0; j < s.length(); ++j)
        {
            for(k = 0; k < iter; ++k)
            {
                cout << s[j];
            }
        }
        cout << endl;
    }

    return 0;
}