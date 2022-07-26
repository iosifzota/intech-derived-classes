#include <iostream>

using namespace std;

struct Base
{
    Base(int) { cout << "Base::Base(int)" << endl; }
    Base(const Base &) { cout << "Base::Base(const Base&)" << endl; }
    Base &operator=(const Base &) { cout << "Base::operator=(const Base&)" << endl; return *this; }
    Base(Base &&) noexcept { cout << "Base::Base(Base&&)" << endl; }
    Base &operator=(Base &&) noexcept { cout << "Base::operator=(Base&&)" << endl; return *this; }
    ~Base() { cout << "Base::~Base()" << endl; }
};

struct Derived1Base : virtual Base
{
    Derived1Base() : Base{1} { cout << "Derived1Base::Derived1Base()" << endl; }
    Derived1Base(const Derived1Base &) : Base{1} { cout << "Derived1Base::Derived1Base(const Derived1Base&)" << endl; }
    Derived1Base &operator=(const Derived1Base &) { cout << "Derived1Base::operator=(const Derived1Base&)" << endl; return *this; }
    Derived1Base(Derived1Base &&) noexcept : Base{1} { cout << "Derived1Base::Derived1Base(Derived1Base&&)" << endl; }
    Derived1Base &operator=(Derived1Base &&) noexcept { cout << "Derived1Base::operator=(Derived1Base&&)" << endl; return *this; }
    ~Derived1Base() { cout << "Derived1Base::~Derived1Base()" << endl; }
};

struct Derived2Base : virtual Base
{
    Derived2Base() : Base{2} { cout << "Derived2Base::Derived2Base()" << endl; }
    Derived2Base(const Derived2Base &) : Base{2} { cout << "Derived2Base::Derived2Base(const Derived2Base&)" << endl; }
    Derived2Base &operator=(const Derived2Base &) { cout << "Derived2Base::operator=(const Derived2Base&)" << endl; return *this; }
    Derived2Base(Derived2Base &&) noexcept : Base{2} { cout << "Derived2Base::Derived2Base(Derived2Base&&)" << endl; }
    Derived2Base &operator=(Derived2Base &&) noexcept { cout << "Derived2Base::operator=(Derived2Base&&)" << endl; return *this; }
    ~Derived2Base() { cout << "Derived2Base::~Derived2Base()" << endl; }
};

/*
             Base
          /       \
Derived1Base      Derived2Base
          \       /      
           Derived
*/

struct Derived : Derived1Base, Derived2Base
{
    Derived() : Base{4}, Derived1Base{}, Derived2Base{} { cout << "Derived::Derived()" << endl; }
    // Derived(int) : b{}, b2{} { cout << "Derived::Derived()" << endl; }
    Derived(const Derived &) : Base{4} { cout << "Derived::Derived(const Derived&)" << endl; }
    Derived &operator=(const Derived &) { cout << "Derived::operator=(const Derived&)" << endl; return *this; }
    Derived(Derived &&) noexcept : Base{4} { cout << "Derived::Derived(Derived&&)" << endl; }
    Derived &operator=(Derived &&) noexcept { cout << "Derived::operator=(Derived&&)" << endl; return *this; }
    ~Derived() { cout << "Derived::~Derived()" << endl; }
};

int main()
{
    Derived d;
    return 0;
}