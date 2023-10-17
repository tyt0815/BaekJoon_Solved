// 문제: https://www.acmicpc.net/problem/1074
// 풀이: https://www.notion.so/tyt0815/1074-967d48aac8ac41d2a402fcda3e65c570?pvs=4

#include <iostream>
#include <cmath>

using namespace std;

uint64_t f(uint32_t x, uint32_t y, uint32_t n)
{
    if(x == 0 && y == 0){ return 0; }
    else if(x == 0 && y == 1) { return 1; }
    else if(x == 1 && y == 0) { return 2; }
    else if(x == 1 && y == 1) { return 3; }

    uint64_t over = pow(2, n);
    uint64_t under = over/2;
    
    if(x < under && y < under) {return f(x,y, n-1); }
    else if(x < under && y >= under && y < over){ return f(x, y - under, n-1) + pow(4, n-1); }
    else if(x >= under && x < over && y < under){ return f(x - under, y, n-1) + pow(4,n-1)*2; }
    else { return f(x - under, y - under, n-1) + pow(4,n-1)*3; }

}

int main()
{
    uint32_t n, x, y;
    cin >> n >> x >> y;

    cout << f(x, y, n);

    return 0;
}