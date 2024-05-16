#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> Numbers(N);
    for(auto &Number : Numbers) cin >> Number;
    sort(Numbers.begin(), Numbers.end());

    int64_t A = 0, B = 0;
    int64_t Result = INT64_MAX;
    while(A <= B && B < N)
    {
        if(Numbers[B] - Numbers[A] >= M)
        {
            Result = min(Result, Numbers[B] - Numbers[A]);
            ++A;
        }
        else ++B;
    }
    cout << Result;

    return 0;
}