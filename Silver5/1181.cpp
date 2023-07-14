/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
단, 중복된 단어는 하나만 남기고 제거해야 한다.

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<string> stringSort(string* input, int start, int end);
int CompareString(string s1, string s2);


int main()
{
    int n;
    string *input;

    vector<string> sorted;

    cin >> n;
    input = new string[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    sorted = stringSort(input, 0, n);

    vector<string>::iterator iter = sorted.begin();
    for(;iter != sorted.end(); ++iter)
    {
        cout << *iter << "\n";
    }

    return 0;
}

vector<string> stringSort(string* input, int start, int end)   // 마지막 인덱스 == end-1
{
    if (start >= end - 1) 
    { 
        vector<string> v;
        v.push_back(input[start]);
        return v;
    }
    
    int mid = (start + end) / 2;

    vector<string> v1 = stringSort(input, start, mid);
    vector<string> v2 = stringSort(input, mid, end);

    vector<string> sorted;
    
    vector<string>::iterator iter1 = v1.begin(), iter2 = v2.begin();
    while(iter1 != v1.end() && iter2 != v2.end())
    {
        int result = CompareString(*iter1, *iter2);
        if(result < 0)    // iter1이 앞
        {
            sorted.push_back(*iter1);
            ++iter1;
        }
        else if(result > 0)    // iter2가 앞
        {
            sorted.push_back(*iter2);
            ++iter2;
        }
        else    // 둘이 같음
        {
            sorted.push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }

    while(iter1 != v1.end())
    {
        sorted.push_back(*iter1);
        ++iter1;
    }
    while(iter2 != v2.end())
    {
        sorted.push_back(*iter2);
        ++iter2;
    }
    return sorted;
}

int CompareString(string s1, string s2)
{
    if(s1.length() < s2.length())
    {
        return -1;
    }
    else if(s1.length() > s2.length())
    {
        return 1;
    }
    else
    {
        int result = s1.compare(s2);
        if(result < 0)
        {
            return -1;
        }
        else if(result > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}