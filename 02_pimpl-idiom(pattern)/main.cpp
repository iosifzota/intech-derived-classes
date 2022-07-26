#include <iostream>
#include "Lib.h"
#include "Base.h"

using namespace std;

struct Derived : Base
{
    int derivedVal;
    Derived() { cout << "Derived::Derived()" << endl; }
    Derived(const Derived &) { cout << "Derived::Derived(const Derived&)" << endl; }
    Derived &operator=(const Derived &) { cout << "Derived::operator=(const Derived&)" << endl; return *this; }
    Derived(Derived &&) noexcept { cout << "Derived::Derived(Derived&&)" << endl; }
    Derived &operator=(Derived &&) noexcept { cout << "Derived::operator=(Derived&&)" << endl; return *this; }
    ~Derived() { cout << "Derived::~Derived()" << endl; }
};

int main()
{
    Derived d;
    Base * b = &d;

    float var1 = 1.f;
    foo(var1);

    return 0;
}