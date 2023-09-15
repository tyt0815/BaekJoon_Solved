#include <iostream>
#include <algorithm>

using namespace std;

struct POINT
{
    int x;
    int y;
};


int main()
{
    int Num;
    POINT* Points;

    cin >> Num;
    Points = new POINT[Num];

    for(int i = 0; i < Num; ++i)
    {
        cin >> Points[i].x >> Points[i].y;
    }

    sort(Points, Points + Num,
        [](POINT a, POINT b){
            if(a.y != b.y)
            {
                return a.y < b.y;
            }
            else
            {
                return a.x < b.x;
            }
        }
    );

    for(int i = 0; i < Num; ++i)
    {
        cout << Points[i].x << " " << Points[i].y << "\n";
    }

    return 0;
}