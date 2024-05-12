#include <iostream>
#define MAXLEN 4000

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    int Length = 0;
    int p[MAXLEN + 1][MAXLEN + 1] = { 0 };
    int N = A.length(), M = B.length();
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(A[i - 1] == B[j - 1])
            {
                p[i][j] = p[i - 1][j - 1] + 1;
                Length = max(Length, p[i][j]);
            }
        }
    }    

    cout << Length;

    return 0;
}