// 문제: https://www.acmicpc.net/problem/18185
// 풀이: 

// #include <iostream>
// #define B 3
// #define C 2

// using namespace std;

// typedef struct
// {
//     int b;
//     int c;
//     int c2;
// }ramen;


// void printAry(int* ary, int end)
// {
//     for(int i = 0; i < end; ++i) cout << ary[i] << " ";
//     cout << endl;
// }

// int main()
// {
//     int n, value = 0;
//     ramen *amount;
//     cin >> n;
//     amount = new ramen[n];
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> amount[i].b;
//         amount[i].c = amount[i].c2 = 0;
//     }

//     for(int i = 0; i < n - 1; ++i)
//     {
//         int update_amount = min(amount[i].b, amount[i+1].b);
//         amount[i+1].b -= update_amount;
//         amount[i+1].c += update_amount;
//         if(i > 0)
//         {
//             update_amount = min(amount[i].c, amount[i+1].b);
//             amount[i+1].b -= update_amount;
//             amount[i+1].c2 += update_amount;
//         }
//     }

//     for(int i = 0; i < n; ++i)
//     {
//         value += amount[i].b * B + amount[i].c * C + amount[i].c2 * C;
//     }

//     cout << value;

//     return 0;
// }

#include <iostream>

using namespace std;

struct Ramen
{
    Ramen():
        Cnt(0), A(0), B(0), C(0)
    {}
    uint32_t Cnt;
    uint32_t A;
    uint32_t B;
    uint32_t C;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n, Count = 0;
    Ramen *Factory;

    cin >> n;
    Factory = new Ramen[n];

    for(uint32_t i = 0; i < n; ++i)
    {
        cin >> Factory[i].Cnt;
    }

    Factory[0].A = Factory[0].Cnt;
    if(n > 1)
    {
        Factory[1].B = min(Factory[0].A, Factory[1].Cnt);
        Factory[1].A = Factory[1].Cnt - Factory[1].B;
    }

    for(uint32_t i = 2; i < n; ++i)
    {
        Factory[i].B = min(Factory[i - 1].A, Factory[i].Cnt);
        Factory[i].C = min(Factory[i-1].B, Factory[i].Cnt - Factory[i].B);
        Factory[i].A = Factory[i].Cnt - Factory[i].B - Factory[i].C;
    }

    for(uint32_t i = 0; i < n; ++i)
    {
        Count += (Factory[i].A * 3 + (Factory[i].B + Factory[i].C) * 2);
    }

    cout << Count;

    return 0;
}