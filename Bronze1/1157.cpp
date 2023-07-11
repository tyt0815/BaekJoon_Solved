/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/

#include <iostream>
#include <set>
#define aminusA 32

using namespace std;

bool checkAlp(char a, char b)
{
    int X = a < 'a' ? a : a - aminusA;
    int Y = b < 'a' ? b : b - aminusA;
    // cout << char(X) << char(Y) << (X == Y) << endl;
    return X==Y;
}

int main()
{
    string s;
    int maxCnt = 0;
    char maxChar = '?';
    
    cin >> s;
    int l = s.length();
    bool *checkTable = new bool[l];

    for(int i = 0; i < l; ++i)
    {
        checkTable[i] = false;
    }

    for(int i = 0; i < l; ++i)
    {
        if(checkTable[i]) continue;
        int cnt = 0;
        for(int j = i; j < l; ++j)
        {
            if(checkAlp(s[i],s[j]))
            {
                checkTable[j] = true;
                ++cnt;
            }
        }
        // cout << maxCnt << " " << cnt << endl;
        if(maxCnt < cnt)
        {
            maxCnt = cnt;
            maxChar = s[i] < 'a' ? s[i] : s[i] - aminusA;;
        }
        else if(maxCnt == cnt)
        {
            maxChar = '?';
        }
    }

    cout << maxChar;


    return 0;
}