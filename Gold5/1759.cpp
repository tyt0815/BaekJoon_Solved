#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MakePassword(int Depth, int TargetDepth, bool bVowel, int ConsonantCnt, vector<int>& Indices, const vector<char>& Alphabets);
inline bool IsVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, c;
    cin >> l >> c;
    vector<char> Alphabets(c, 0);
    for(int i = 0; i < c; ++i) cin >> Alphabets[i];
    sort(Alphabets.begin(), Alphabets.end());

    vector<int> Indices(l, 0);
    MakePassword(0, l, false, 0, Indices, Alphabets);

    return 0;
}

void MakePassword(int Depth, int TargetDepth, bool bVowel, int ConsonantCnt, vector<int> &Indices, const vector<char> &Alphabets)
{
    if(Depth == TargetDepth)
    {
        if(bVowel && ConsonantCnt > 1)
        {
            for(int i = 0; i < Indices.size(); ++i) cout << Alphabets[Indices[i]];
            cout << '\n';
        }
        return;
    }
    int i = 0;
    if(Depth > 0) i = Indices[Depth - 1] + 1;
    for(; i + TargetDepth - Depth - 1 < Alphabets.size(); ++i)
    {
        Indices[Depth] = i;
        if(IsVowel(Alphabets[i])) MakePassword(Depth + 1, TargetDepth, true, ConsonantCnt, Indices, Alphabets);
        else MakePassword(Depth + 1, TargetDepth, bVowel, ConsonantCnt + 1, Indices, Alphabets);
    }
}
