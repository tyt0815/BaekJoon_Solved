#include <iostream>

using namespace std;

class BaseClass
{
public:
    virtual void f1()
    {
        cout << "b1" << endl;
    }

    void f2()
    {
        cout << "b2"<< endl;
    }
};

class DClass : public BaseClass
{
public:
    virtual void f1() override
    {
        cout << "d1"<< endl;
    }
    void f2()
    {
        cout << "d2"<< endl;
    }
};

int main()
{
    BaseClass b, *a;
    DClass d;

    b = BaseClass();
    d = DClass();
    a = dynamic_cast<BaseClass*>(&d);

    b.f1();
    d.f1();
    a->f1();
    b.f2();
    d.f2();
    a->f2();

    return 0;

}