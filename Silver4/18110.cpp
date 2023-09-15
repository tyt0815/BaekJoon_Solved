#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    int Avg = 0;
    int* Eval;

    cin >> N;
    Eval = new int[N];

    for(int i = 0; i < N; ++i)
    {
        cin >> Eval[i];
    }

    sort(Eval, Eval + N);

    int Cut = (int)floor(((float)N * 0.15) + 0.5);

    for(int i = Cut; i < N-Cut; ++i)
    {
        Avg += Eval[i];
    }

    N -= (2 * Cut);

    Avg = (int)floor(((float)Avg / (float)N) + 0.5);

    cout << Avg;

    return 0;
}
