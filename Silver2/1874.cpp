#include <iostream>
#include <vector>
#include <stack>

using namespace  std;

int main()
{
    uint64_t n;
    uint64_t* Sequence;
    stack<uint64_t> s;
    vector<char> Result;
    
    cin >> n;
    Sequence = new uint64_t[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> Sequence[i];
    }

    uint64_t PushNum = 1;
    uint64_t SeqIndex = 0;
    while (true)
    {
        if(SeqIndex >= n) { break; }
        if(PushNum <= Sequence[SeqIndex])
        {
            s.push(PushNum++);
            Result.push_back('+');
        }
        else
        {
            if(s.top() == Sequence[SeqIndex])
            {
                s.pop();
                ++SeqIndex;
                Result.push_back('-');
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }

    for(int i = 0; i < Result.size(); ++i)
    {
        cout << Result[i] << '\n';
    }
    

    delete[] Sequence;
    return 0;
}