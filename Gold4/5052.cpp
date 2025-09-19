// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // A의 길이 < B의 길이 라 가정한다.
// // B의 접두사부분이 A와 같은지 확인한다.
// bool EvaluateCallNumber(const string& A, const string& B)
// {
//     for(int i = 0; i < A.length(); ++i)
//     {
//         if(A[i] != B[i])
//         {
//             return true;
//         }
//     }
//     return false;
// }

// // CallNumbers는 string의 길이 순으로 정렬되어 들어온다 가정한다.
// bool EvaluateCallNumberList(const vector<string>& SortedCallNumbers)
// {
//     for(int i = 0; i < SortedCallNumbers.size() - 1; ++i)
//     {
//         int j = i + 1;
//         while(SortedCallNumbers[i].length() == SortedCallNumbers[j].length() && j < SortedCallNumbers.size())
//         {
//             ++j;
//         }

//         while(j < SortedCallNumbers.size())
//         {
//             if(!EvaluateCallNumber(SortedCallNumbers[i], SortedCallNumbers[j++]))
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;      // 테스트 케이스의 개수
//     cin >> T;

//     while(T--)
//     {
//         int N;      // 전화번호의 수
//         cin >> N;    
//         vector<string> CallNumbers(N);
//         for(string& Number : CallNumbers)
//         {
//             cin >> Number;
//         }

//         sort(CallNumbers.begin(), CallNumbers.end(), [](string A, string B) { return A.length() < B.length(); });

//         cout << (EvaluateCallNumberList(CallNumbers) ? "YES" : "NO") << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;

        vector<string> CallNumbers(N);
        for(string& Number : CallNumbers)
        {
            cin >> Number;
        }

        sort(CallNumbers.begin(), CallNumbers.end());

        
        for(int i = 0; i < N - 1; ++i)
        {
            if(CallNumbers[i + 1].substr(0, CallNumbers[i].length()) == CallNumbers[i])
            {
                cout << "NO" << '\n';
                goto ENDWHILE;
            }
        }
        cout << "YES" << '\n';
        ENDWHILE:;
    }

    return 0;
}