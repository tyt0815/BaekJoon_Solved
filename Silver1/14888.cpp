#include <iostream>
#include <vector>

using namespace std;

void InsertOperator(int i, int Sum, vector<int> OpNum, vector<int>& Numbers, int& MaxNum, int& MinNum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> Numbers, OpNum;
    cin >> n;
    Numbers.resize(n);
    OpNum.resize(4);
    for(int i = 0; i < n; ++i) cin >> Numbers[i];
    for(int i = 0; i < 4; ++i) cin >> OpNum[i];

    int MaxNum = INT32_MIN, MinNum = INT32_MAX;
    InsertOperator(0, Numbers[0], OpNum, Numbers, MaxNum, MinNum);
    cout << MaxNum << '\n' << MinNum;

    return 0;
}

void InsertOperator(int i, int Sum, vector<int> OpNum, vector<int> &Numbers, int &MaxNum, int &MinNum)
{
    if(i == Numbers.size() - 1)
    {
        MaxNum = max(MaxNum, Sum);
        MinNum = min(MinNum, Sum);
        return;
    }
    
    if(OpNum[0] > 0)
    {
        --OpNum[0];
        InsertOperator(i + 1, Sum + Numbers[i + 1], OpNum, Numbers, MaxNum, MinNum);
        ++OpNum[0];
    }
    if(OpNum[1] > 0)
    {
        --OpNum[1];
        InsertOperator(i + 1, Sum - Numbers[i + 1], OpNum, Numbers, MaxNum, MinNum);
        ++OpNum[1];
    }
    if(OpNum[2] > 0)
    {
        --OpNum[2];
        InsertOperator(i + 1, Sum * Numbers[i + 1], OpNum, Numbers, MaxNum, MinNum);
        ++OpNum[2];
    }
    if(OpNum[3] > 0)
    {
        --OpNum[3];
        InsertOperator(i + 1, Sum / Numbers[i + 1], OpNum, Numbers, MaxNum, MinNum);
        ++OpNum[3];
    }

}
