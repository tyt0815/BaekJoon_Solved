#include <iostream>
#include <vector>

using namespace std;

struct RGB
{
    int R;
    int G;
    int B;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<RGB> p;
    vector<RGB> Price;
    cin >> n;
    p.resize(n);
    Price.resize(n);
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> Price[i].R >> Price[i].G >> Price[i].B;
    }

    p[0].R = Price[0].R;
    p[0].G = Price[0].G;
    p[0].B = Price[0].B;

    for(int i = 1; i < n; ++i)
    {
        p[i].R = Price[i].R + min(p[i - 1].G, p[i - 1].B);
        p[i].G = Price[i].G + min(p[i - 1].R, p[i - 1].B);
        p[i].B = Price[i].B + min(p[i - 1].R, p[i - 1].G);
    }

    cout << min(min(p[n-1].R, p[n - 1].G), p[n-1].B);

    return 0;
}