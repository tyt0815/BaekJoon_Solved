#include <iostream>
#include <vector>

using namespace std;

void f(vector<int> Numbers, vector<bool> IsVisited,  const vector<char>& InequalitySigns, vector<int>& MinOut, vector<int>& MaxOut);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<char> InequalitySigns(k, ' ');
    for(int i = 0; i < k; ++i) cin >> InequalitySigns[i];

    vector<int> MinOut;
    vector<int> MaxOut;
    for(int i = 0; i < 10; ++i)
    {
        vector<bool> IsVisited(10, false);
        IsVisited[i] = true;
        f({i}, IsVisited, InequalitySigns, MinOut, MaxOut);
    }

    for(int i = 0; i <= k; ++i) cout << MaxOut[i];
    cout << '\n';
    for(int i = 0; i <= k; ++i) cout << MinOut[i];

    return 0;
}

void f(vector<int> Numbers, vector<bool> IsVisited, const vector<char> &InequalitySigns, vector<int> &MinOut, vector<int> &MaxOut)
{
    if(Numbers.size() > InequalitySigns.size())
    {
        if(MinOut.size() < Numbers.size())
        {
            MinOut = Numbers;
        }
        MaxOut = Numbers;
        return;
    }

    int LastNumber = Numbers.back();
    char InequalitySign = InequalitySigns[Numbers.size() - 1];
    Numbers.push_back(0);
    for(int i = 0; i < 10; ++i)
    {
        if(IsVisited[i]) continue;
        if((InequalitySign == '<' && LastNumber < i) || (InequalitySign == '>' && LastNumber > i))
        {
            IsVisited[i] = true;
            Numbers[Numbers.size() - 1] = i;
            f(Numbers, IsVisited, InequalitySigns, MinOut, MaxOut);
            IsVisited[i] = false;
        }
    }
}
