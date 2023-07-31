#include <iostream>
#include <utility>

using namespace std;
typedef pair<int,int> Size;

void Init(int &n, Size **p);
int* Rating(int n, Size *p);
int Compare(Size s1, Size s2);

int main()
{
    int n;
    int *rate;
    Size *p;
    Init(n, &p);

    rate = Rating(n, p);

    for(int i = 0; i < n; ++i)
    {
        cout << rate[i] << '\n';
    }

    return 0;
}

void Init(int &n, Size **p)
{
    cin >> n;
    *p = new Size[n];
    for(int i = 0; i< n; ++i)
    {
        cin >> (*p)[i].first >> (*p)[i].second;
    }
}

int* Rating(int n, Size* p)
{
    int* rate = new int[n];
    for(int i = 0; i < n; ++i)
    {
        rate[i] = 1;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            int result = Compare(p[i], p[j]);
            if(result == -1)
            {
                rate[i] += 1;
            }
            else if(result == 1)
            {
                rate[j] += 1;
            }
        }
    }

    return rate;
}

int Compare(Size s1, Size s2)
{
    /*
    s1 < s2:    return -1
    s2 == s2:   return 0
    s1 > s2:    return 1
    */
   if(s1.first < s2.first && s1.second < s2.second){ return -1; }
   else if(s1.first > s2.first && s1.second > s2.second){ return 1; }
   return 0;
}