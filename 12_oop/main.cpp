#include <iostream>

using namespace std;

using fPtr_t = void (*)();

void impl1()
{
    cout << "impl1()" << endl;
}

void impl2()
{
    cout << "impl2()" << endl;
}


struct Base
{
    Base() : m_fPtr{&impl1} { cout << "Base::Base()" << endl; }
    Base(fPtr_t fPtr) : m_fPtr{fPtr} { cout << "Base::Base(fPtr_t)" << endl; }

    Base(const Base &) { cout << "Base::Base(const Base&)" << endl; }
    Base &operator=(const Base &) { cout << "Base::operator=(const Base&)" << endl; return *this; }
    Base(Base &&) noexcept { cout << "Base::Base(Base&&)" << endl; }
    Base &operator=(Base &&) noexcept { cout << "Base::operator=(Base&&)" << endl; return *this; }
    virtual ~Base() { cout << "Base::~Base()" << endl; }

    // non-virtual interface (NVI) pattern (idiom == pattern)
    void foo() { this->impl(); }

    fPtr_t m_fPtr;

private:
    // dynamic binding (using VTABLE)
    virtual void impl() { cout << "Base::impl()" << endl; }
};

struct Derived : Base
{  
    Derived() : Base{&impl2} { cout << "Derived::Derived()" << endl; }
    Derived(const Derived &) { cout << "Derived::Derived(const Derived&)" << endl; }
    Derived &operator=(const Derived &) { cout << "Derived::operator=(const Derived&)" << endl; return *this; }
    Derived(Derived &&) noexcept { cout << "Derived::Derived(Derived&&)" << endl; }
    Derived &operator=(Derived &&) noexcept { cout << "Derived::operator=(Derived&&)" << endl; return *this; }
    ~Derived() { cout << "Derived::~Derived()" << endl; }

private:
    void impl() override { cout << "Derived::impl()" << endl; }
};

int main()
{
    Base * bPtr = new Derived;
    bPtr->foo();

    delete bPtr;
    return 0;
}








int old()
{
    cout << "isImpl1: ";

    bool isImpl1;
    cin >> isImpl1;

    void (* fPtr)() = isImpl1 ? impl1 : impl2;
    (*fPtr)();

    return 0;
}