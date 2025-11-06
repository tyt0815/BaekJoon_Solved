// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;
//     cin >> N;
//     vector<int> Sequence(N);
//     for(int& Value : Sequence)
//     {
//         cin >> Value;
//     }

//     vector<int> LIS[2];
//     int LISIndex = 0;
//     LIS[1].push_back(Sequence[N]);

//     for(int i = 1; i < N; ++i)
//     {
//         vector<int>& CurrentLIS = LIS[LISIndex];
//         vector<int>& NextLIS = LIS[(LISIndex + 1) % 2];

//         if(lower_bound(CurrentLIS.begin(), CurrentLIS.end(), Sequence[i]) == CurrentLIS.end())
//         {
//             CurrentLIS.push_back(Sequence[i]);
//         }
//         else
//         {

//         }
//     }

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Sequence(N);
    for(int& Value : Sequence)
    {
        cin >> Value;
    }

    vector<int> LIS(1, Sequence[0]);
    vector<int> LISIndicesToSequence(1, 0);
    vector<int> LISPrevIndicesToSequence(N, -1);

    for(int i = 1; i < N; ++i)
    {
        int j = lower_bound(LIS.begin(), LIS.end(), Sequence[i]) - LIS.begin();
        if(j < LIS.size())
        {
            LISPrevIndicesToSequence[i] = j > 0 ? LISIndicesToSequence[j - 1] : -1;
            LIS[j] = Sequence[i];
            LISIndicesToSequence[j] = i;
        }
        else
        {
            LIS.push_back(Sequence[i]);
            LISIndicesToSequence.push_back(i);
            LISPrevIndicesToSequence[i] = LISIndicesToSequence[j - 1];
        }
    }

    cout << LIS.size() << endl;
    vector<int> Answer;
    for(int i = LISIndicesToSequence.back(); i >= 0; i = LISPrevIndicesToSequence[i])
    {
        Answer.push_back(Sequence[i]);
    }

    for(int i = Answer.size() - 1; i >= 0; --i)
    {
        cout << Answer[i] << ' ';
    }

    return 0;
}