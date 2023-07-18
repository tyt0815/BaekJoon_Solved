/*
과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다. 주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
*/

#include <iostream>

using namespace std;

bool isRightTriangle(int a, int b, int c);

int main()
{
    while(true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b && b == c && c == 0) { break; }
        if(isRightTriangle(a, b, c)){ cout << "right\n"; }
        else { cout << "wrong\n"; }
    }
    return 0;
}

bool isRightTriangle(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0) { return false; }
    if(a*a == b*b + c*c) { return true; }
    if(b*b == a*a + c*c) { return true; }
    if(c*c == b*b + a*a) { return true; }
    return false;
}