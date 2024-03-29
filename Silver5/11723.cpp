#include <iostream>
#include <set>

using namespace std;

class MySet
{
public:
    void Add(uint32_t Value)
    {
        mSet.insert(Value);
    }
    void Remove(uint32_t Value)
    {
        mSet.erase(Value);
    }
    bool Check(uint32_t Value)
    {
        return mSet.find(Value) != mSet.end() ? true : false;
    }
    void Toggle(uint32_t Value)
    {
        if(Check(Value))
        {
            Remove(Value);
        }
        else
        {
            Add(Value);
        }
    }
    void All()
    {
        for(int i = 1; i <= 20; ++i)
        {
            Add(i);
        }
    }
    void Empty()
    {
        mSet.clear();
    }

private:
    set<uint32_t> mSet;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint64_t m;
    MySet s;

    cin >> m;

    for(uint64_t i = 0; i < m; ++i)
    {
        string Cmd;
        uint32_t Value;
        cin >> Cmd;
        if(!Cmd.compare("add"))
        {
            cin >> Value;
            s.Add(Value);
        }
        else if(!Cmd.compare("remove"))
        {
            cin >> Value;
            s.Remove(Value);
        }
        else if(!Cmd.compare("check"))
        {
            cin >> Value;
            cout << (s.Check(Value) ? 1 : 0) << '\n';
        }
        else if(!Cmd.compare("toggle"))
        {
            cin >> Value;
            s.Toggle(Value);
        }
        else if(!Cmd.compare("all"))
        {
            s.All();
        }
        else if(!Cmd.compare("empty"))
        {
            s.Empty();
        }
    }

    return 0;
}