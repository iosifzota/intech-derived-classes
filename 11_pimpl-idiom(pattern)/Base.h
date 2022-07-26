#include <iostream>

using namespace std;

struct Base
{
    int val;
    Base();

    void foo(char)
    {
        cout << "Derived::foo(char)" << endl;
    }

private:
    class BaseImpl;
    BaseImpl * m_impl;
};