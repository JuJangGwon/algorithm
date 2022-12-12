#include <iostream>

using namespace std;


struct A
{
    virtual void f() { cout << "A-f" << endl;}
    virtual void g() { cout << "A-g" << endl;}
};
struct B : virtual A
{
    void f() { cout << "B-f" << endl;}
    virtual void g() { cout << "B-g" << endl;}
};
void h(A o, A&r)
{
    o.f();
    r.f();
    r.g();
}


int main()
{
    B b;
    h(b,b);
    return 0;
}
