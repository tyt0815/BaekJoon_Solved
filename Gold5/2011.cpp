#include <iostream>
#include <vector>
#define MOD 1000000

using namespace std;

vector<int> Cache;

int Decode(int i, const string &Code);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Code;
    cin >> Code;
    Cache.resize(Code.length());
    Cache.assign(Cache.size(), -1);
    cout << Decode(0, Code);

    return 0;
}

int Decode(int i, const string &Code)
{
    if(i == Code.length()) return 1;
    if(Cache[i] != -1) return Cache[i];
    int Result = 0;
    if(Code[i] > '0') Result = Decode(i + 1, Code) % MOD;
    if(i < Code.length() - 1 && (Code[i] == '1' || (Code[i] == '2' && Code[i + 1] < '7')))  Result = (Result + Decode(i + 2, Code)) % MOD;
    Cache[i] = Result;
    return Result;
}
