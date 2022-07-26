#include "Base.h"

struct Base::BaseImpl
{
    void foo(float)
    {
        cout << "Base::BaseImpl::foo(float)" << endl;
    }
};

Base::Base() : m_impl{new BaseImpl}
{
}



// Base(const Base &) { cout << "Base::Base(const Base&)" << endl; }
// Base &operator=(const Base &)
// {
//     cout << "Base::operator=(const Base&)" << endl;
//     return *this;
// }
// Base(Base &&) noexcept { cout << "Base::Base(Base&&)" << endl; }
// Base &operator=(Base &&) noexcept
// {
//     cout << "Base::operator=(Base&&)" << endl;
//     return *this;
// }
// ~Base() { cout << "Base::~Base()" << endl; }