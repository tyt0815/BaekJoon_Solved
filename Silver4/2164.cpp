#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n;
    list<int> card;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        card.push_back(i+1);
    }
    list<int>::iterator iter = card.begin();
    for(;card.size() != 1;)
    {
        list<int>::iterator temp = iter;
        ++iter;
        if(iter == card.end()) { iter = card.begin(); }
        ++iter;
        if(iter == card.end()) { iter = card.begin(); }
        card.erase(temp);
    }

    cout << *card.begin();

    return 0;
}